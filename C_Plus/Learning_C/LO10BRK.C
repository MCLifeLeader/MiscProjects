/* loop tests and breaks. */

#include "stdio.h"

 main()
  {
   int t, count;

   for(t=0; t<100; t++) {
     count = 1;
     for(;;) {
       printf("%d ", count);
       count++;
       if(count==10) break;
     }
   }
}


