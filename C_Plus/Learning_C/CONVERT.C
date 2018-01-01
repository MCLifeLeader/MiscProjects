/*
 *
 * Compiler:    Ansi C   MicroSoft Quick C
 * Program:     convert.c
 * Purpose:     to convert decimal hexidecimal and octidecimal numbers
 * Programmer:  Mike Carey
 * Date:        Oct. 17, 1993
 * Last Mod:    Jan. 08, 1994
 *
 */


#include "stdio.h"
#include "stdlib.h"

 long int dec;              /* Setting the global variables */
 long int hex;              /* Note. These variables could easly */
 long int oct;              /* have been placed in side each of the */
			    /* differnt program blocks used for the */
			    /* conversion of the numbers */
 main()
  {
   int opt;
   int s;

			    /* Setting up the main menu of my program */
   do {
     printf("Numbering system converter for Decimal Hexidecimal");
     printf(" Octdecimal.\n\n");
     printf("1. Decimal input\n");
     printf("2. Hexdecimal input\n");
     printf("3. Octdecimal input\n");
     printf("4. Exit.\n");
     do {
       printf("Enter your choice: ");  /* This is were the choice is made */
       scanf("%d", &opt);              /* And is exicuted */
     } while(opt<1 || opt>4);

     switch(opt) {
       case 1:
	 decimal();                    /* Here are the differnt program */
	 break;                        /* Blocks used to convert the */
       case 2:                         /* input values of numbers */
	 hexidecimal();
	 break;
       case 3:
	 octidecimal();
	 break;
       case 4:
	 s=41;
	 printf("The programmer Mike Carey says bye.   :-%c\n", s);
	 break;
     }
   } while(opt!=4);
  }

  /* This is the first program block for Decimal to ? conversion */

  decimal()
   {
    int x;


    do {
      printf("Enter whole number to convert: ");
      scanf("%d", &dec);
      printf("1. Decimal to Hexidecimal.\n");         /* users choice of */
      printf("2. Decimal to Octidecimal.\n");         /* conversion      */
      printf("3. Back to main menu.\n");
      do {
	printf("Enter your Choice: ");
	scanf("%d", &x);
      } while(x<1 || x>3);
					/* Conversion Exicution */
      switch(x) {
	case 1:
	  printf("Decimal to Hexidecimal conversion\n");
	  printf("%ld %lx\n\n", dec, dec);
	  break;
	case 2:
	  printf("Decimal to Octidecimal conversion\n");
	  printf("%ld %lo\n\n", dec, dec);
	  break;
	case 3:
	  printf("\n\n\n");
	  break;
      }
    } while(x!=3);
   }

   /* This is the second program block for Hexidecimal to ? conversion */

   hexidecimal()
   {
    int x;


    do {
      printf("Enter whole number to convert: ");
      scanf("%x", &hex);
      printf("1. Hexidecimal to Decimal.\n");         /* users choice of */
      printf("2. Hexidecimal to Octidecimal\n");      /* conversion      */
      printf("3. Back to main menu.\n");
      do {
	printf("Enter your Choice: ");
	scanf("%d", &x);
      } while(x<1 || x>3);
					/* Conversion Exicution */
      switch(x) {
	case 1:
	  printf("Hexidecimal to Decimal conversion\n");
	  printf("%lx %ld\n\n", hex, hex);
	  break;
	case 2:
	  printf("Hexidecimal to Octidecimal conversion\n");
	  printf("%lx %lo\n\n", hex, hex);
	  break;
	case 3:
	  printf("\n\n\n");
	  break;
      }
    } while(x!=3);
   }

  /* This is the theird program block for Octidecimal to ? conversion */

   octidecimal()
   {
    int x;


    do {
      printf("Enter whole number to convert: ");
      scanf("%o", &oct);
      printf("1. Octidecimal to Decimal.\n");         /* users choice of */
      printf("2. Octdecimal to Hexidecimal.\n");      /* conversion      */
      printf("3. Back to main menu.\n");
      do {
	printf("Enter your Choice: ");
	scanf("%d", &x);
      } while(x<1 || x>3);
					/* Conversion Exicution */
      switch(x) {
	case 1:
	  printf("Octdecimal to Decimal conversion\n");
	  printf("%lo %ld\n\n", oct, oct);
	  break;
	case 2:
	  printf("Decimal to Octidecimal conversion\n");
	  printf("%lo %lx\n\n", oct, oct);
	  break;
	case 3:
	  printf("\n\n\n");
	  break;
      }
    } while(x!=3);
   }

