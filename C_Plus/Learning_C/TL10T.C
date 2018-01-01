/* break till 10 */

#include "stdio.h"

 main()
  {
   int i;

   for(i=0; i<1000; i++) {
    /* do something */
    if(kbhit()) break;
   }
}
