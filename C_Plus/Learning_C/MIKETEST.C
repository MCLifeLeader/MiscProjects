/* I am going to try something A program filled with nothing
 *
 * Program:             miketest.c
 * Purpose:             To test my knowledge in C programming
 * Programmer:          Mike Carey
 * Date:                Oct. 13, 1993
 */

#include "stdio.h"
#include "stdlib.h"

 main()                 /* This is the starting point for my programs */
  {                     /* Main form of exicution. */
   int x, z, a;
   char y;

   y = 76;

   do {
     printf("Will you enter in a number between 1 and 5\n");
     do {
       printf("Enter choice: ");         /* This is were the user inputs */
       scanf("%d", &a);                  /* His/Her command. option */
     } while(a<1 || a>5);

     switch(a) {
       case 1:
	 printf("Hi there you are a real nice person.\n\n");
	 break;
       case 2:                            /* This is were my case switch */
	 printf("%d\n\n", y);             /* Statements are set up to take */
	 break;                           /* User input from list. */
       case 3:
	 for(z=0; z<10; z++); {
	   printf("Joe nose nothin\n");
	 }
	 break;
       case 4:
	 printf("Enter in a second number between 1 and 10: ");
	 scanf("%d", &x);
	 if(x>=7) {
	   printf("7 or up\n");
	 }
	 else {
	   printf("lower than 7\n");
	 }
	 break;
       case 5:
	 printf("The end\n");
	 satement2();
	 break;
       }
     } while(a!=5);
  }
		   /* Second Block of code */
 satement2()
  {
   int x;

   x = 5;
   printf("%d %d\n ", x, x+x);
   printf("End of the road");
}






