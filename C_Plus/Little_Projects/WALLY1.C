
#include "stdio.h"
#include "graph.h"
#include "stdlib.h"

int makeroad1(int *, int *, int *);

 main()
  {
   int carpos=15, movecar=0, lives=500, flag1=0, flag2=0, utime=0;
   int wally1=40, wx2=25, rwall=0, objects=0, i=24, j=0;
   int speed=0, speed1=0, speed2=0, laps=0, lapsc=0, rounds=0;
   int wall[33]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   long ltime=0;

   ltime = time(NULL);                  /* Set seed random time */
   utime = (unsigned int) ltime/2;
   srand(utime);

   do {
     rwall = (rand()%100);
     wally1 = (makeroad1(&wx2, &wally1, &rwall));

     if(wall[0] == 0) {         /* Reset wall[0] with wally1 */
       for(i=0; i<24; i++) {
	 wall[i] = wally1;
       }
     }

     for(i=24; i>0; i--) {
       j = wall[i];
       wall[i-1] = j;

       j = wall[i+10];

       _settextposition(15, j);
       printf("*");
       _settextposition(15, j+10);
       printf("*");

       if((carpos == i) && (j == movecar)) {
	 lives--;
       }
       if((carpos == i) && (j+10 == movecar)) {
	 lives--;
       }
     }

     wall[24] = wally1;        /* Set array value 24 to wally1 */

     _settextposition(25,1);
     printf("\n");

   }while(!kbhit());
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

   _settextposition(xwall, ywall);
   printf("%c", 177);

   _settextposition(xwall, ywall+10);
   printf("%c", 177);
   return(ywall);
 }

