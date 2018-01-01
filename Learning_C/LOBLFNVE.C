/* This program illustrates how variables can be local to a block.
 *
 *  This program is incorrect and will give the person comipling it
 *  An Error.
 */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 main()
  {
   char str[80];
   int choice;

   printf("(1) add number or \n");
   printf("(2) concatenate Strings? (N or S): ");
   gets(str);
   choice = atoi(str);
   printf("\n");

   if(choice == 1) {
     int a, b; /* activate two integer vars */
     printf("Enter two numbers: ");
     scanf("%d%d", &a, &b);
     printf("the sum is %d", a+b);
   }
   else {
     char s1[80], s2[80]; /* activate two strings */
     printf("Enter two strings: ");
     gets(s1);
     gets(s2);
     strcat(s1, s2);
     printf("the sum is   %s", s1);
   }
   a = 10;  /* This line will be flagged as an error
	     * by the compiler.
	     */
}





