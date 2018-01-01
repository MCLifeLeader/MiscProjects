
 /* To test multipilcation and devision */

#include "stdio.h"

 main()
  {
   int a0, b0, c0, d0, answer0, answer2;
   float a1, b1, c1, d1, answer1, answer3;

   a0 = 23;
   a1 = 23;
   b0 = 45;
   b1 = 45;
   c0 = 23;
   c1 = 23;
   d0 = 45;
   d1 = 45;

   answer0 = a0 / b0;
   printf("int int answer1 %d\n", answer0);
   answer1 = a1 / b1;
   printf("float float answer2 %f\n", answer1);
   answer2 = c1 / d0;
   printf("float int answer3 %d\n", answer2);
   answer3 = c0 / d1;
   printf("int float answer4 %f\n", answer3);
   answer3 = a0 / b0;
   printf("int int to a float answer5 %f\n", answer3);
 }

