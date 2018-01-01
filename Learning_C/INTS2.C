/*
 *
 * Compiler:    Ansi C   MicroSoft Quick C
 * Program:     intrest.c
 * Purpose:     To caluculate interst over many years
 * Programmer:  Mike Carey
 * Date:        Dec. 5, 1993
 *
 */

#include "stdio.h"
#include "stdlib.h"

 float gearned, first, gfirst;        /* The variables are created here */
 float started, interest, earned, ended;
 int times, n=0;
			 /* beging to the program of the interest program */
 main()
  {
	       /* The switch option is created so that you can choose which
		* funciton you want the program to preforum
		*/
   int option;

   printf("\nThis is a interest calculating program you will be asked some\n");
   printf("questions so that you will be able to calculate your interest\n");
   printf("gained this program can acnolage that you are placing in a \n");
   printf("regular amount of money per itteration\n\n");

   do {                                         /* The choices */
     printf("\n1. Enter in the numbers\n");
     printf("2. Start the caculations\n");
     printf("3. Store the numbers temporaroly\n");
     printf("4. Start the caculations with temp numbers\n");
     printf("5. Print the ending caculations\n");
     printf("6. End this program\n");
     do {
       printf("Enter your choice: ");           /* How the choices are */
       scanf("%d", &option);                    /* exicuted            */
     } while(option<1 || option>6);

		/* This area of my program is the devidor of my program
		 * so that each of the individual funcitons can be run
		 * and cause a smooth look to the program
		 */

     switch(option) {
       case 1:
	   enter_values();
	   break;
       case 2:
	 if(n!=1) {
	   calc();           /* This defines that the stored information  */
	   n=1;              /* of the variable of **first** not be over- */
	 }                   /* -run with more inforamtion                */
	 else {
	   calculatio();
	 }
	 break;
       case 3:
	 printf("This part only stores the total money earned during\n");
	 printf("the time earned.\n\n");
	 gearned = ended;
	 break;
       case 4:
	 if(n!=1) {
	   calc2();          /* This difines that the stored information  */
	   n=1;              /* of the variable of **first** not be over- */
	 }                   /* -run with more information                */
	 else {
	   calculatio2();
	 }
	 break;
       case 5:               /* This gives the calculated amounts */
	 printf("\nThe caculations are....\n");
	 printf("Starting amount %f\n", first);
	 printf("The rate of interest %f\n", interest);
	 printf("The number of times calculated %d\n", times);
	 printf("Your total earnings are %f\n\n", ended);
	 break;
       case 6:
	 printf("GoodBye\n");
	 break;
     }                /* This is the exit to the program */
   } while(option!=6);
 }
		   /* This block of code determines what variables */
 enter_values()    /* will be assigned with the numbers choosen */
  {
   int y=0, answ, x=0, z=0;

   n=0;
   do {
     printf("Enter the starting amount: ");
     scanf("%f", &started);
     if(started<=0) {
       y=2;
       printf("You did not enter in a correct amount!!!\n");
     }
     else {                        /* This code protects the user from */
       y=1;                        /* Entering in invalid numbers */
     }
   } while(y!=2);
   do {
     printf("Enter in the interest rate: ");
     scanf("%f", &interest);
     if(interest=0) {
       x=2;
       printf("Enter in a value that is not zero\n");
     }
     else {
       x=1;
     }
   } while(x!=2);
   do {
     printf("Enter in the amount of times it should calculate: ");
     scanf("%d", &times);
     if(times<=0) {
       z=2;
       printf("The entered value is incorrect\n");
     }
     else {
       z=1;
     }
   } while(z!=2);
     printf("Do you want the regular amount per itteration?\n");
     printf("1. For yes.  2. For no.");
     scanf("%d", &answ);
     if(answ<=1) {
       gfirst = started;
     }
     else {
       gfirst = 0;
     }
  }

	     /* This is the first block of code that dose the calculations */
 calc()
  {
   int x=0;
   first = started;
   do {
     x++;
     earned = started*interest;   /* The interest equation */
     ended = earned+started;
     started = ended+gfirst;
   } while(x!=times);
  }

 calc2()     /* This is my second block of code that dos the calculations */
  {          /* But adds the stored amount of the last calculations into  */
   int x=0;  /* this equation */
   first = started;
   started = started+gearned;

   do {
     x++;
     earned = started*interest;
     ended = earned+started;
     started = ended+gfirst;
   } while(x!=times);
 }

	     /* This is the first block of code that dose the calculations */
 calculatio()
  {
   int x=0;
   do {
     x++;
     earned = started*interest;
     ended = earned+started;
     started = ended+gfirst;
   } while(x!=times);
  }
  calculatio2()  /* This is my second block of code that dose the       */
  {              /* calculations But adds the stored amount of the last */
   int x=0;        /* calculations into this equation                     */
   started = started+gearned;
   do {
     x++;
     earned = started*interest;
     ended = earned+started;
     started = ended+gfirst;
   } while(x!=times);
}






