/*
 * Program:     SCRIPTUR.EXE
 * Source:      scriptur.c
 * Author:      Mike Carey
 * Date:        Nov. 08, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Help scripture mastery students memorize their
 *              scriptures.
 *
 */

#include "stdio.h"
#include "ctype.h"
#include "direct.h"
#include "stdlib.h"
#include "string.h"

#define DEBUGL 0
#define MYCODE "Scripture Mastery program V1.0A\n"

 int b_of_mormon(int *);
 int dandc(int *);
 prlfgpaold_tstemnt(int *);
 int new_testement(int *);

 void main(void)
  {
   int usr_inpt=0, rndm=0, utime=0;
   long ltime=0;
   char usr_input[80];
   char *thgt4theday[]={
     "Remeber who you are.\n",
     "If you drink from the Lords well, you will never thirst\n"
   };

					/* Set random number */
   ltime = time(NULL);
   utime = (unsigned int) ltime/2;
   srand(utime);

   do {
     printf(MYCODE);
     printf("\n\n");
     printf("Scripture mastery Tutor.\n");
     printf("1. Book of Mormon\n");
     printf("2. Doctrine and Covenants\n");
     printf("3. Pearl of Great Price and Old Testement\n");
     printf("4. New Testement\n");
     printf("5. To Quit\n");
     printf("Enter in the Number for which you need studying\n");
     do {
	printf("Enter your number here: ");
	gets(usr_input);
	usr_inpt = atoi(usr_input);
     } while(usr_inpt<0 || usr_inpt>5);
     rndm = rand();
     switch(usr_inpt) {
       case 1:
	 b_of_mormon(&rndm);
	 break;
       case 2:
	 dandc(&rndm);
	 break;
       case 3:
	 prlfgpaold_tstemnt(&rndm);
	 break;
       case 4:
	 new_testement(&rndm);
	 break;
       case 5:
	 rndm = (rand()%2);
	 printf("%s", thgt4theday[rndm]);
	 break;
     }
   } while(usr_inpt != 5);
 }

 b_of_mormon(int *rndm)
  {
   printf("b_of_mormon\n");
 }

 dandc(int *rndm)
  {
   printf("d&c\n");

 }

 prlfgpaold_tstemnt(int *rndm)
  {
   printf("prlofgp&old_testement\n");
 }

 new_testement(int *rndm)
  {
   printf("new_testement\n");
 }
