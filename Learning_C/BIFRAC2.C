/* Bifraction problem 2 */

#include "stdio.h"

 main()
  {
   double newpop, oldpop;
   double col, row;
   double rate;

   printf("Enter starting population: ");
   scanf("%f", &oldpop);
   printf("Enter rate: ");
   scanf("%f", &rate);
   do {
     newpop = rate * oldpop * (1-oldpop);
     col = oldpop * rate;
     row = newpop;
     printf("col %f row %f\n", col, row);
   } while (!kbhit());
}
