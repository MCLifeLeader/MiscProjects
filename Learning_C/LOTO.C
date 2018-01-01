/*
 * Program:     LOTO.EXE
 * Source:      loto.c
 * Author:      Mike Carey
 * Date:        Aug. 27, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To generate random numbers for loto players :-)
 *
 */

#include "stdio.h"

 main()
  {
   int a, b, c, d, e, f;
   int x, y, utime;
   long ltime;
   char input[80];

   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);

  do {

    x = rand() % 100;     /* Random number generator between 1-100 */
    if((x>=50) || (x<=0)) {
      y = 0;
    }
    else {
      y++;
    }
    if(y==1) {
      a = x;
      if((a>=50) || (a<=0)) {
	y = 0;
      }
    }
    if(y==2) {
      b = x;
      if((b>=50) || (b<=0)) {
	y = 0;
      }
      if(b==a) {
	y--;
      }
    }
    if(y==3) {
      c = x;
      if((c>=50) || (c<=0)) {
	y = 0;
      }
      if((c==a) || (c==b)) {
	y--;
      }
    }
    if(y==4) {
      d = x;
      if((d>=50) || (d<=0)) {
	y = 0;
      }
      if((d==a) || (d==b) || (d==c)) {
	y--;
      }
    }
    if(y==5) {
      e = x;
      if((e>=50) || (e<=0)) {
	y = 0;
      }
      if((e==a) || (e==b) || (e==c) || (e==d)) {
	y--;
      }
    }
    if(y==6) {
      f = x;
      if((f>=50) || (f<=0)) {
	y = 0;
      }
      if((f==a) || (f==b) || (f==c) || (f==d) || (f==e)) {
	y--;
      }
    }
  } while(y!=7);
  printf("Your loto numbers are... %d %d %d %d %d %d\n", a, b, c, d, e, f);
}

