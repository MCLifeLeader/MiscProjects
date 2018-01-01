/* process devide then percent */

    /* This peace of code was used to creat the logical pattern
     * for the program lgates.c so that the information of how
     * well the person being tested could see there results.
     */

#include "stdio.h"

 main()
  {
   int endcount;
   int num_right;            /* variable declaration */
   int display;
   float numb1;
   float numb2;
   float numb3;

   endcount = 25;     /* This makes sure that the program is */
   num_right = 12;    /* operating how it should be */

   printf("endcount = %d num_right = %d\n", endcount, num_right);

   numb1 = num_right;
   printf("numb1 = %f\n", numb1);

   numb2 = endcount;
   printf("numb2 = %f\n", numb2);

   numb3 = numb1 / numb2;
   printf("numb3 = %f\n", numb3);

   display = numb3 * 100;
   printf("display %d\n", display);
 }





