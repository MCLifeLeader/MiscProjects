
/*
 *
 * Program:     CIRCLE.EXE
 * Code:        circle.c
 * Author:      Michael Bryce Carey
 * Date:        Oct. 12, 1994
 * Version:     V1.0Release
 * Bref:        This program was created as a teaching tool
 *                so as to become familar with graphics
 */

#include "stdio.h"
#include "graph.h"
#include "math.h"
			/* Set DEBUGL to 1 so as to see debug information */
			/* after compilation */
#define DEBUGL 0

 main()
  {
		/* Variable Declaration */
   int maxx=0, maxy=0, maxc=0, color=0, swtit=0;
   int utime=0;

   long ltime=0;

   float x=0, y=0, x1=0, y1=0;
   float x2=0, y2=0, xl=0, yl=0;
   float rc=0, pi=3.1415926, midx=0, midy=0;
   float r=0, t=0, rate=.05;

   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);

   if((_setvideomode(_VRES16COLOR)) == NULL) {    /* Check for Screen and */
     if((_setvideomode(_MRES16COLOR)) == NULL) { /* change from VGA to EGA */
       printf("Your monitor does not support VGA or EGA\n");
       exit(1);
     }
     else {
       maxx = 320;              /* Set Screen Max Size */
       maxy = 200;
       maxc = 16;               /* For EGA */
     }
   }

   else {
     maxx = 640;                /* Set Screen Max Size */
     maxy = 480;
     maxc = 16;                 /* For VGA */
   }

   printf("This Program is ShareWare \t Code by Michael B. Carey\n");

 #if DEBUGL == 1
   printf("Graphics Information...\n");
   printf(" maxxpix:%d\n maxypix:%d\n maxcolor:%d\n", maxx, maxy, maxc);
   printf(" File:%s\n Date:%s\n Time:%s\n Number of Lines in source code:%d\n",__FILE__, __DATE__, __TIME__, __LINE__);
 #endif

   /* _clearscreen(_GCLEARSCREEN); */

   midx = maxx/2;       /* Find Center of Screen */
   midy = maxy/2;

   do {
				/* Circle Diamiter changes from max size */
     rc = (10*(sin(10*t)+1));   /* to min size back to max size */
     r = (r + rate);            /* Rate of Circle Expantion */
     t = (t + (pi/360));        /* Find Cercumfrence of a Circle */
     if(swtit == 1) {
       x = (midx + (r * sin(t))); /* Find xcord for Spiral plot */
       y = (midy + (r * cos(t))); /* Find ycord for Spiral plot */
     }
     else {
       x = (midx + (r * cos(t))); /* Find xcord for Spiral plot */
       y = (midy + (r * sin(t))); /* Find ycord for Spiral plot */
     }
     color = (rand()%maxc);     /* Random Color Generator */
     _setcolor(color);          /* Set Random Color */

				/* Sets the size of each ellipse */
     x1 = ((x - rc)-rate);
     x2 = ((x + rc)+rate);

     y1 = ((y - rc)-rate);
     y2 = ((y + rc)+rate);
				/* Draw ellipse */
     _ellipse(_GBORDER, x1, y1, x2, y2);
     _setpixel(x, y);

     xl = (rand()%maxx);
     yl = (rand()%maxy);
     _setpixel(xl, yl);

 #if DEBUGL == 1
   _settextposition(29, 0);
   printf("x position:%g, y position:%g\n", x, y);
   printf("t:%g   a:%d   r:%g", t, a, r);
 #endif

     if(_getpixel(x,y) == -1) {            /* Randomness generator */
       _clearscreen(_GCLEARSCREEN);

       midx = (rand()%maxx);
       midy = (rand()%maxy);

       t = (rand()%100);
       swtit = (rand()%100);

       rate = t / 160;
       r = 0;
       t = 0;

       if(swtit >= 50) {
	 swtit = 1;
       }
       else {
	 swtit = 0;
       }
     }
   } while(!kbhit());                          /* Wait till key press */

   _setvideomode(_DEFAULTMODE);
   _clearscreen(_GCLEARSCREEN);
 }
