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
#include "conio.h"
#include "graph.h"
#include "stdlib.h"
#include "string.h"

 int levelofdiff(int *);
 int lapstocomplet(int *);
 int rungame(int *, int *);
 int getmove(int *, int *, char *);
 int makeroad(int *, int *);

					/* The main part of the program */
 main()
  {
   int choice=0, speed=0, laps=0;       /* Variable Declaration */
   char input[80];

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
	   break;
	 }
	 else {
	   rungame(&speed, &laps);
	   break;
	 }
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
   int carpos=15, movecar=0, lives=500, flag1=0, flag2=0;
   int wally1=40, wx1=25, i=0, wall[24]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   int speed=0, speed1=0, speed2=0, laps=0, lapsc=0, rounds=0;
   char moveit=0, smdrcn=0;

   speed = *playspeed;
   laps = *playlaps;
   speed = speed * 50;
   movecar = wally1 + 5;

   _clearscreen(_GCLEARSCREEN);
   do {
     rounds++;

     if(rounds >= 50) {
       lapsc++;
       rounds = 0;
     }
     for(speed1=0; speed1<speed; speed1++) {
       for(speed2=0; speed2<500; speed2++);
     }
     if((moveit = getch()) == 0) {
       moveit = smdrcn;
     }

     else {
       smdrcn = moveit;
     }

     movecar = (getmove(&movecar, &carpos, &moveit));
     wally1 = (makeroad1(&wx1, &wally1));

     if(wall[0]==0) for(i=0; i<24; i++) wall[i] = wally1;

     for(i=1; i<carpos; i++) {
       wall[i] = wall[i-1];
     }
     wall[0] = wally1;

     _settextposition(1, 1);
     printf("Lives=%d", lives);

     _settextposition(carpos+1, wall[carpos+1]);
     printf("*");
     _settextposition(carpos+1, wall[carpos+1]+10);
     printf("*");
     _settextposition(carpos, wally1);
     printf("@");
     _settextposition(carpos, wally1+10);
     printf("@");

  /*
   * if((movecar == wall[carpos+1]) || (movecar == (wall[carpos+1] + 10))) {
   *   lives--;
   * }
   *
   */
     if(movecar+1 == wally1 || movecar-1 == wally1+10) {
       lives--;
     }

     if(lapsc >= laps) {
       flag1 = 1;
       flag2 = 2;
     }
     if(movecar <= -5) {
       flag1 = 1;
       flag2 = 1;
     }

     if(lives < -100) {
       flag1 = 2;
       flag2 = 1;
     }
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


 int getmove(int *movecary, int *carxy, char *move)
  {
   int ypos=0, carpos=0;
   char movexy=0;

   ypos = *movecary;
   carpos = *carxy;
   movexy = *move;

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

     _settextposition(carpos, ypos);
     printf("V");
   }
   return(ypos);
 }

 int makeroad1(int *x1, int *y1)
  {
   int wallpos=0, xwall=0, ywall=0, flag=0, utime=0;
   long ltime=0;

   xwall = *x1;
   ywall = *y1;

   ltime = time(NULL);
   utime = (unsigned int) ltime/2;
   srand(utime);

   wallpos = (rand()%100);
   if(wallpos <= 33) {
     flag = 1;
     ywall++;
   }
   if((wallpos >= 34) && (wallpos <= 66)) {
     flag = 2;
   }
   if(wallpos >= 67) {
     flag = 3;
     ywall--;
   }
   if(ywall<=1) {
     ywall++;
     flag = 2;
   }
   if((ywall+10) >= 80) {
     ywall--;
     flag = 2;
   }
   _settextposition(25, 80);
   printf("\n");
   _settextposition(xwall, ywall-10);

   if(flag==1) {
     printf("\\");
   }
   if(flag==2) {
     printf("|");
   }
   if(flag==3) {
     printf("/");
   }

   _settextposition(xwall, ywall);

   if(flag==1) {
     printf("\\");
   }
   if(flag==2) {
     printf("|");
   }
   if(flag==3) {
     printf("/");
   }
   return(ywall);
 }
