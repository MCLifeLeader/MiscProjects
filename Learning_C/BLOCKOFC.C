/* This program demonstrates a block of code. */

#include "stdio.h"

 main()
 {
   int a, b;

   printf("enter first number: ");
   scanf("%d", &a);
   printf("enter second number: ");
   scanf("%d", &b);

   if(a < b) {
     printf("First number is less than the second.\n");
     printf("Their difference is: %d", b-a);
   }
}
