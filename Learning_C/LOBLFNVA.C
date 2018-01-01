/* This program illustrates how variables can be local to a block */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 main()
  {
   char str[80];
   int choice;

   printf("(1) add numbers or ");
   printf("(2) concatenate Strings?: ");
   gets(str);
   choice = atoi(str);
   printf("\n");

   if(choice == 1) {
     int a, b;  /* activate two integer vars */
     printf("Enter in two numbers: ");
     scanf("%d%d", &a, &b);
     printf("The sum is %d", a+b);
   }
   else {
     char s1[80], s2[80];  /* activate two strings */
     printf("Enter in two strings: ");
     gets(s1);
     gets(s2);
     strcat(s1, s2);
     printf("The sum %s", s1);
   }
}

