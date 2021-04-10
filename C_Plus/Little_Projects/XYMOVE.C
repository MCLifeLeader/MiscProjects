/*
 * Program:     XYMOVE.EXE
 * Source:      xymove.c
 * Author:      Mike Carey
 * Date:        Nov. 15, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To be able to move an object using the X and Y
 *              Cordinate system on the CRT.
 *
 */

#include "stdio.h"
#include "conio.h"
#include "graph.h"
#include "stdlib.h"

#define MYVER "XYMOVE V1.0a, By. Mike Carey.\n"
#define DEBUGL 1

 int move_obj(char *);
 int moveinxy(int *);
 int fire(int *);

 int gmovex=10, gmovey=40;

 void main(void)
  {
   int endit=0;
   char input=0;

   _clearscreen(_GCLEARSCREEN);

   do {
     input = getch();
     endit = move_obj(&input);

   }while(endit == 0);
 }

 move_obj(char *mv)
  {
   int endit=0, posi=0, retrn=0;
   char move=0;

   move = *mv;

   if((move == 'q') || (move == 'Q')) {
     endit = 1;
   }

   else {
     endit = 0;

     if(move == 'i') {
       gmovex--;
       posi = 1;
     }
     if(move == 'm') {
       gmovex++;
       posi = 2;
     }
     if(move == 'k') {
       gmovex++;
       posi = 2;
     }
     if(move == 'j') {
       gmovey--;
       posi = 3;
     }
     if(move == 'l') {
       gmovey++;
       posi = 4;
     }
     if(move == 'y') {
       retrn = fire(&posi);
     }
     retrn = moveinxy(&posi);
   }
   return(endit);
 }

 moveinxy(int *pos)
  {
   int posi=0, wall=0;

   posi = *pos;

   if(gmovex <= 1) {
     gmovex = 1;
     wall = 1;
   }
   if(gmovex >= 24) {
     gmovex = 24;
     wall = 2;
   }

   if(gmovey <= 1) {
     gmovey = 1;
     wall = 3;
   }
   if(gmovey >= 78) {
     gmovey = 78;
     wall = 4;
   }

   if(posi == 1) {
     _settextposition(gmovex, gmovey);

     _settextposition(gmovex, gmovey);
     printf("%c%c%c", 219, 219, 219);
     _settextposition(gmovex-1, gmovey);
     printf(" %c ", 30);
   }
   if(posi == 2) {
     _settextposition(gmovex, gmovey);
     printf("%c%c%c", 219, 219, 219);
     _settextposition(gmovex+1, gmovey);
     printf(" %c ", 31);
   }

   if(posi == 3) {
     _settextposition(gmovex, gmovey);
     _settextposition(gmovex, gmovey);
     printf("%c%c%c", 219, 219, 219);
     _settextposition(gmovex, gmovey-1);
     printf("%c", 17);
   }
   if(posi == 4) {
     _settextposition(gmovex, gmovey);
     _settextposition(gmovex, gmovey);
     printf("%c%c%c", 219, 219, 219);
     _settextposition(gmovex, gmovey+3);
     printf("%c", 16);
   }

   return(wall);
 }

 fire(int *WPosition)
  {
   int a, b;
   _settextposition(1,1);
   for(a=0; a<25; a++) {
     for(b=0; b<80; b++) {
       printf("%c", 177);
     }
   }
 }

