/*
 * Program:     MTANK.EXE
 * Source:      mtank.c
 * Author:      Mike Carey & Tim Carey
 * Date:        Nov. 11, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To make an ASCII/ANSI tank game for playing.
 *
 */

#include "stdio.h"
#include "conio.h"
#include "graph.h"
#include "stdlib.h"
#include "string.h"

#define IDINFO "Mtank By Mike & Tim Carey, V1.0A\n"
#define DEBUGL 1

 int get_move(char *);
 int tkfire1(int *);
 int tkfire2(int *);
 int tkptr1(int *);
 int tkptr2(int *);
 int test_boarders();

 int tankx1=10, tanky1=20, tankx2=10, tanky2=60;

 void main(void)
  {
   int mtank=0;
   char mtank_key=0;

   _settextposition(tankx1, tanky1);
   printf("%c%c%c%c", 219, 219, 219, 26);
   _settextposition(tankx2, tanky2);
   printf("%c%c%c%c", 8, 8, 8, 27);
   do {
     mtank_key = getch();
     mtank = get_move(&mtank_key);

   } while((mtank_key != 'q') || (mtank_key != 'Q'));
   printf("Bye...\n");
 }

 get_move(char *move)
  {
   int tnk1=0, tnk2=0;
   char mv=0;
   mv = *move;

   if((mv == 'i') || (mv == 'I')) {
     tankx1--;
     tnk1 = 1;
   }
   if((mv == 'j') || (mv == 'J')) {
     tanky1--;
     tnk1 = 2;
   }
   if((mv == 'k') || (mv == 'K')) {
     tankx1++;
     tnk1 = 3;
   }
   if((mv == 'm') || (mv == 'M')) {
     tankx1++;
     tnk1 = 3;
   }
   if((mv == 'l') || (mv == 'L')) {
     tanky1++;
     tnk1 = 4;
   }
   if((mv == 'y') || (mv == 'Y')) {
     tkfire1(&tnk1);
   }

   if((mv == '8') || (mv == '8')) {
     tankx2--;
     tnk2 = 1;
   }
   if((mv == '4') || (mv == '4')) {
     tanky2--;
     tnk2 = 2;
   }
   if((mv == '5') || (mv == '5')) {
     tankx2++;
     tnk2 = 3;
   }
   if((mv == '2') || (mv == '2')) {
     tankx2++;
     tnk2 = 3;
   }
   if((mv == '6') || (mv == '6')) {
     tanky2++;
     tnk2 = 4;
   }
   if((mv == '7') || (mv == '7')) {
     tkfire2(&tnk2);
   }
   tkptr1(&tnk1);
   tkptr2(&tnk2);

   test_boarders();
   _settextposition(tankx1, tanky1);
   printf("%c%c%c", 219, 219, 219);
   _settextposition(tankx2, tanky2);
   printf("%c%c%c", 8, 8, 8);
 }

 tkptr1(int *ptank1)
  {
   int ptnk1=0;

   ptnk1 = *ptank1;

   if(ptnk1 == 1) {
     _settextposition(tankx1+1, tanky1+1);
     printf("%c", 24);
   }
   if(ptnk1 == 2) {
     _settextposition(tankx1, tanky1-1);
     printf("%c", 27);
   }
   if(ptnk1 == 3) {
     _settextposition(tankx1-1, tanky1+1);
     printf("%c", 25);
   }
   if(ptnk1 == 4) {
     _settextposition(tankx1, tanky1+1);
     printf("%c", 26);
   }
 }

 tkptr2(int *ptank2)
  {
   int ptnk2=0;

   ptnk2 = *ptank2;

   if(ptnk2 == 1) {
     _settextposition(tankx2+1, tanky2+1);
     printf("%c", 24);
   }
   if(ptnk2 == 2) {
     _settextposition(tankx2, tanky2-1);
     printf("%c", 27);
   }
   if(ptnk2 == 3) {
     _settextposition(tankx2-1, tanky2+1);
     printf("%c", 25);
   }
   if(ptnk2 == 4) {
     _settextposition(tankx2, tanky2+1);
     printf("%c", 26);
   }
 }

 tkfire1(int *mtank1)
  {
   int mtnk1=0, x=0, y=0;

   mtnk1 = *mtank1;

   if(mtnk1 == 1) {
     for(x=0; x<6; x++) {
       _settextposition(tankx1-x, tanky1+1);
       printf("*");
     }
   }
   if(mtnk1 == 2) {
     for(y=0; y<6; y++) {
       _settextposition(tankx1, tanky1-y);
       printf("*");
     }
   }
   if(mtnk1 == 3) {
     for(x=0; x<6; x++) {
       _settextposition(tankx1+x, tanky1+1);
       printf("*");
     }
   }
   if(mtnk1 == 4) {
     for(y=0; y<6; y++) {
       _settextposition(tankx1, tanky1+y);
       printf("*");
     }
   }
 }

 tkfire2(int *mtank2)
  {
   int mtnk2=0, x=0, y=0;

   mtnk2 = *mtank2;

   if(mtnk2 == 1) {
     for(x=0; x<6; x++) {
       _settextposition(tankx2-x, tanky2+1);
       printf("*");
     }
   }
   if(mtnk2 == 2) {
     for(y=0; y<6; y++) {
       _settextposition(tankx2, tanky2-y);
       printf("*");
     }
   }
   if(mtnk2 == 3) {
     for(x=0; x<6; x++) {
       _settextposition(tankx2+x, tanky2+1);
       printf("*");
     }
   }
   if(mtnk2 == 4) {
     for(y=0; y<6; y++) {
       _settextposition(tankx2, tanky2+y);
       printf("*");
     }
   }
 }

 test_boarders()
  {
   int tnk1=0, tnk2=0;

   if(tankx1 < 1) {
     tankx1++;
   }
   if(tankx1+2 > 25) {
     tankx1--;
   }
   if(tankx2 < 1) {
     tankx2++;
   }
   if(tankx2+2 > 25) {
     tankx2--;
   }
   if(tanky1 < 1) {
     tanky1++;
   }
   if(tanky1+2 > 80) {
     tanky1--;
   }
   if(tanky2 < 1) {
     tanky2++;
   }
   if(tanky2+2 > 80) {
     tanky2--;
   }
 }

 draw_field()
  {
   int a=0, b=0;
   char wall[81];

   for(a=0; a<81; a++) {
     wall[a] = 178;
   }
   printf("%s", wall);

   for(b=0; b<25; b++) {
     _settextposition(b, 1);
     printf("%c", 178);
     _settextposition(b, 80);
     printf("%c", 178);
   }
   printf("%s", wall);
 }


