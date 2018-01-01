/*
 * Program:     RACECAR.EXE
 * Source:      racecar.c
 * Author:      Mike Carey
 * Date:        Oct. 25, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     A half had chance to make a race car game.
 *
 */

#include "stdio.h"
#include "bios.h"
#include "graph.h"
#include "stdlib.h"

 int levelofdiff(int *);
 int lapstocomplet(int *);
 int rungame(int *, int *);
 int makeroad(int *, int *, int *);
 int obsitcle(int *, int *);
 int getmove(int *, int *);

 long bgd=0;
 char buffer[80];
					/* The main part of the program */
 main()
  {
   int choice=0, speed=0, laps=0;       /* Variable Declaration */
   char input[80];

   _setvideomode(_TEXTC80);
   _clearscreen(_GCLEARSCREEN);

   do {
     printf("\t\t\tGreetings and welcome to race day!\n\n\n");
     printf("\t1. Choose level of difficulty.\n");
     printf("\t2. Number of laps to compleate.\n");
     printf("\t3. Play the game.\n");
     printf("\t4. To quit.\n");
     do {                                       /* Choice is entered here */
       printf("Enter in your choice here: ");
       gets(input);
       choice = atoi(input);
     } while(choice<1 || choice>4);

     switch(choice) {                           /* The choices */
       case 1:
	 speed = (levelofdiff(&speed));
	 break;
       case 2:
	 laps = (lapstocomplet(&laps));
	 break;
       case 3:
	 if((speed==0) || (laps==0)) {
	   printf("You need to Enter in a value for speed and laps\n");
	   speed = 1;
	   laps = 50;
	 }
	 else {
	   rungame(&speed, &laps);
	 }
	 break;
       case 4:
	 printf("BYE..\n");
	 /* printf("Speed = %d,  Laps = %d\n", speed, laps); */
	 break;
     }
   } while(choice!=4);
 }
				/* Level of difficulty setting */
 int levelofdiff(int *tspeed)
  {
   char input[80];
   int tspeed1=0;

   do {
     _clearscreen(_GCLEARSCREEN);
     printf("Enter a value between 1 and 10, 1 being fastest\n");
     printf("Enter a value here: ");
     gets(input);
     tspeed1 = atoi(input);
   } while(tspeed1<=0 || tspeed1>=11);
   _clearscreen(_GCLEARSCREEN);
   return(tspeed1);
 }
				/* Number of laps to compleate */
 int lapstocomplet(int *tlaps)
  {
   char input[80];
   int tlaps1=0;

   do {
     _clearscreen(_GCLEARSCREEN);
     printf("Enter a value between 1 and 100: ");
     gets(input);
     tlaps1 = atoi(input);

   } while(tlaps1<=0 || tlaps1>=101);
   _clearscreen(_GCLEARSCREEN);
  return(tlaps1);
 }
					/* The block of code that controls */
					/* The game. */
 int rungame(int *playspeed, int *playlaps)
  {                                     /* Variable Declaration */
   int carpos=15, movecar=0, lives=500, flag1=0, flag2=0, utime=0;
   int wally1=40, wx2=25, rwall=0, objects=0, i=24, j=0;
   int speed=0, speed1=0, speed2=0, laps=0, lapsc=0, rounds=0;
   int wall[33]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   long ltime=0;

   ltime = time(NULL);                  /* Set seed random time */
   utime = (unsigned int) ltime/2;
   srand(utime);

   speed = *playspeed;
   laps = *playlaps;
   speed = speed * 50;
   movecar = wally1 + 5;

   _clearscreen(_GCLEARSCREEN);
   do {
     /* _GCURSOROFF;
     _setbkcolor( bgd );
     _settextcolor( 6 ); */

     rounds++;

     if(rounds >= 100) {
       lapsc++;
       rounds = 0;
     }

     /*
     for(speed1=0; speed1<speed; speed1++) {
       for(speed2=0; speed2<500; speed2++);
     }
     */
     rwall = (rand()%100);
     wally1 = (makeroad1(&wx2, &wally1, &rwall));

     objects = (obsitcle(&wx2, &wally1));

     movecar = (getmove(&movecar, &carpos));

     if(wall[0] == 0) {         /* Reset wall[0] with wally1 */
       for(i=0; i<33; i++) {
	 wall[i] = wally1;
       }
     }

     for(i=33; i>1; i--) {
       j = wall[i];
       wall[i-1] = j;

       j = wall[carpos];

       _settextposition(carpos, j);
       printf("*");
       _settextposition(carpos, j+10);
       printf("*");

       if((carpos == i) && (j == movecar)) {
	 lives--;
       }
       if((carpos == i) && (j+10 == movecar)) {
	 lives--;
       }
     }

     wall[33] = wally1;        /* Set array value 24 to wally1 */

     if(movecar <= -5) {
       flag1 = 1;
       flag2 = 1;
     }

     if(lapsc >= laps) {
       flag1 = 1;
       flag2 = 2;
     }
     if(lives < 0) {
       flag1 = 2;
       flag2 = 1;
     }
     _settextposition(25, 80);          /* Screen scroll */
     printf("\n");

     _settextposition(25, 1);
     printf("j=%d, Lives=%d, Lwall=%d", j, lives, wally1);

   } while((flag1 == 0) && (flag2 == 0));

   if(flag1 == 1) {
     printf("You won. %d laps compleated\n", lapsc);
     flag1 = 0;
     flag2 = 0;
   }
   if(flag2 == 1) {
     printf("Sorry... only %d laps compleated\n", lapsc);
     flag1 = 0;
     flag2 = 0;
   }
   _clearscreen(_GCLEARSCREEN);
 }

 int makeroad1(int *x1, int *y1, int *rwall)
  {
   int wallpos=0, xwall=0, ywall=0;
   long ltime=0;

   xwall = *x1;
   ywall = *y1;
   wallpos = *rwall;

   wallpos = (rand()%100);
   if(wallpos <= 33) {
     ywall++;
   }
   if(wallpos >= 67) {
     ywall--;
   }
   if(ywall<=1) {
     ywall++;
   }
   if((ywall+10) >= 80) {
     ywall--;
   }

   /* _GCURSOROFF;
   _setbkcolor( bgd );
   _settextcolor( 6 ); */

   _settextposition(xwall, ywall);
   sprintf(buffer, "%c", 177);
   _outtext( buffer );

   _settextposition(xwall, ywall+10);
   sprintf(buffer, "%c", 177);
   _outtext( buffer );
   return(ywall);
 }

 obsitcle(int *x1, int *y1)
  {
   int xwall=0, ywall=0, object=0, choose=0;
   xwall = *x1;
   ywall = *y1;

   choose = (rand()%100);

   if(choose <= 10) {
     object = (rand()%10);
     object = ywall+object;

     /* _GCURSOROFF;
     _setbkcolor( bgd );
     _settextcolor( 13 ); */

     _settextposition(xwall, object);
     sprintf(buffer, "X");
     _outtext( buffer );
   }
    else {
      object = 0;
    }
   return(object);
 }

 int getmove(int *movecary, int *carxy)
  {
   int ypos=0, carpos=0, i=0;
   char movexy=0;

   ypos = *movecary;
   carpos = *carxy;

   movexy = _bios_keybrd(_KEYBRD_READ);

   if((movexy=='q') || (movexy=='Q')) {
     ypos = -100;
   }

   else {
     if((movexy=='j') || (movexy=='J')) {
       ypos--;
     }

     if((movexy=='l') || (movexy=='L')) {
       ypos++;
     }

     if(ypos <= 1) {
       ypos++;
     }

     if(ypos >= 80) {
       ypos--;
     }

     /* _GCURSOROFF;
     _setbkcolor( bgd );
     _settextcolor( 9 ); */

     _settextposition(carpos, ypos);
     sprintf(buffer, "%c", 153);
     _outtext( buffer );

     /* _GCURSOROFF;
     _setbkcolor( bgd );
     _setcolor( 0 ); */

     /* _settextposition(carpos, ypos);
     sprintf(buffer, " ");
     _outtext( buffer ); */
   }
   return(ypos);
 }


