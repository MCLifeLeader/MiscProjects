
#include "stdio.h"

 main()
  {
   int a=0, b=0, c=0;
   float d=0;

   printf("This program compairs three numbers and chooses the highest\n");
   printf("number of the two choices then finds their avrage.\n");
   printf("\n\n\n");
   printf("Please Enter in the three numbers to compair.\n");

   printf("Number one:");
   scanf("%d", &a);
   printf("Number two:");
   scanf("%d", &b);
   printf("Number three:");
   scanf("%d", &c);

   if((a == b) && (b == c)) {
     printf("All numbers are equal.\n");
   }
   else {
     if((a >= b) && (a >= c)) {
       if(b >= c) {
	 d = ((a+b)/2);
	 printf("Numbers 1 & 2 are larger or the same. Their avrage is %g\n", d);
       }
       else {
	 d = ((a+c)/2);
	 printf("Numbers 1 & 3 are larger or the same. Their avrage is %g\n", d);
       }
     }
     else {
       if(a >= b) {
	 d = ((a+c)/2);
	 printf("Numbers 1 & 3 are larger or the same. Their avrage is %g\n", d);
       }
       else {
	 d = ((b+c)/2);
	 printf("Numbers 2 & 3 are larger or the same. Their avrage is %g\n", d);
       }
     }
   }
 }
