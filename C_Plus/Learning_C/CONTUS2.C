/* Exiting loops using break */

#include "stdio.h"

 main()
  {
   int t;

   /* loop until user enters 10 */
   for(; ; ) {
     scanf("%d", &t);
     if(t==10) break;
   }
}
