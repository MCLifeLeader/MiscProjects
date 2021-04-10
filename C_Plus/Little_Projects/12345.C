/*
 * Program:     12345.EXE
 * Source:      12345.c
 * Author:      Mike Carey
 * Date:        Nov. 1, 1994
 * Version:     1.0Release
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To generate random dice rolls for RPG gamming.
 *
 */
 /************************************************************************
 *      This source code has been freely distrobuted for the use of those
 * who might find this useful. Your use of this program and source code
 * is up to your discression. I only require that my name in part or full
 * NOT be removed from any documentation nor the compiled or uncompiled
 * operational versions being used. If you have questions you can contact
 * me at.
 *              Mike Carey
 *              37104 Sagebrush Pl.
 *              Kennewick, Wa. 99337
 *
 *              Phone#: 509-627-7705
 *
 ************************************************************************/

#define CLEARSCREEN printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

				/* C compiler include library files */
#include "time.h"
#include "stdio.h"
//#include "graph.h"
#include "conio.h"
#include "io.h"
#include "stdlib.h"
#include "string.h"
				/* Pre compiler directive */
#define MYOWN "Dice rolling program V1.0r By. Michael Carey\n"

				/* Function declaration */
 int numtimestoroll(void);
 int di_four(int *);
 int di_six(int *);
 int di_eight(int *);
 int di_ten(int *);
 int di_twelve(int *);
 int di_twenty(int *);
 int di_thirty(int *);
 int di_fifty(int *);
 int di_one_hundred(int *);
 int di_user_define(int *, int *);
				/* Global varaibles */
 int utime=0;
 long ltime=0;
				/* The start of my program */
 void main(void)
  {                             /* Local variable Declaration */
   int option1=0, di_roll=0, di_value=0;
   char input[80];

   ltime = time(NULL);                  /* Set seed random time */
   utime = (unsigned int) ltime/2;
   srand(utime);
   do {                         /* A (do / while) loop until user exit */
     CLEARSCREEN
     printf(MYOWN);
     printf("This program was designed for people to generate random numbers for RPG\n");
     printf("Character generation. Type in the di number desired, then enter\n");
     printf("the number of times that the di should be rolled or added up to.\n");
     printf("\n\n");
     printf("\t1. 1d4\n");
     printf("\t2. 1d6\n");
     printf("\t3. 1d8\n");
     printf("\t4. 1d10\n");
     printf("\t5. 1d12\n");
     printf("\t6. 1d20\n");
     printf("\t7. 1d30\n");
     printf("\t8. 1d50\n");
     printf("\t9. 1d100\n");
     printf("\t10. 1d(user value)\n");
     printf("\t11 to QUIT\n");
     do {
       printf("Enter in the Di value to roll");
       printf(": ");
       gets(input);
       option1 = atoi(input);
     } while(option1<1 || option1>11);          /* Number boundry testing */

     switch(option1) {                          /* The choices */

       case 1:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_four(&di_roll);
	 break;

       case 2:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_six(&di_roll);
	 break;

       case 3:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_eight(&di_roll);
	 break;

       case 4:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_ten(&di_roll);
	 break;

       case 5:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_twelve(&di_roll);
	 break;

       case 6:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_twenty(&di_roll);
	 break;

       case 7:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_thirty(&di_roll);
	 break;

       case 8:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_fifty(&di_roll);
	 break;

       case 9:
	 di_roll = numtimestoroll();
	 CLEARSCREEN
	 di_roll = di_one_hundred(&di_roll);
	 break;

       case 10:
	 di_roll = numtimestoroll();
	 do {
	   di_value = 0;
	   printf("Define the number of dice sides: ");
	   gets(input);
	   di_value = atoi(input);
	 } while(di_value == 0);

	 CLEARSCREEN
	 di_roll = di_user_define(&di_roll, &di_value);
	 break;

       case 11:
	 printf("BYE...\n");
	 break;
     }
   }while(option1 != 11);
 }
			/* This function gets the user input on the */
			/* number of times this program needs to add up */
			/* the multiple rolles of the random number */
			/* generated */
 numtimestoroll(void)
  {
   int di_roll = 0;
   char input[80];
   do {
     di_roll = 0;
     printf("Enter in the Number of times to roll: ");
     gets(input);
     di_roll = atoi(input);
   }while(di_roll==0);
			/* This returns the users value back to the */
			/* previous block of code it was called from */
   return(di_roll);
 }
			/* This function generates a random number between */
			/* 1 and 4 then displays the accumlative of the */
			/* number of times rolled */
 di_four(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%4);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d4 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 6 then displays the accumlative of the */
			/* number of times rolled */
 di_six(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%6);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d6 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 8 then displays the accumlative of the */
			/* number of times rolled */
 di_eight(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%8);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d8 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 10 then displays the accumlative of the */
			/* number of times rolled */
 di_ten(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%10);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d10 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 12 then displays the accumlative of the */
			/* number of times rolled */
 di_twelve(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%12);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d12 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 20 then displays the accumlative of the */
			/* number of times rolled */
 di_twenty(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0, value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%20);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d20 %d times, Your roll = %d\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 30 then displays the accumlative of the */
			/* number of times rolled */
 di_thirty(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0;
   long value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%30);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d30 %d times, Your roll = %ld\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 50 then displays the accumlative of the */
			/* number of times rolled */
 di_fifty(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0;
   long value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%50);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d50 %d times, Your roll = %ld\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 and 100 then displays the accumlative of the */
			/* number of times rolled */
 di_one_hundred(int *roll)
  {
   int i=0, rolltimes=0, tvalue=0;
   long value=0;

   rolltimes = *roll;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%100);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d100 %d times, Your roll = %ld\n", rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }
			/* This function generates a random number between */
			/* 1 to user defined value then displays the */
			/* accumlative of the number of times rolled */
 di_user_define(int *roll, int *sides)
  {
   int i=0, rolltimes=0, numsides=0, tvalue=0;
   long value=0;

   rolltimes = *roll;
   numsides = *sides;

   for(i=0; i<rolltimes; i++) {
     tvalue = (rand()%numsides);
     value = value+tvalue+1;
   }
   printf("\n\n\n");
   printf("You chose to roll a 1d%d %d times, Your roll = %ld\n", numsides, rolltimes, value);
   printf("Press a key to continue\n");

   while(!kbhit());
   return(value);
 }

