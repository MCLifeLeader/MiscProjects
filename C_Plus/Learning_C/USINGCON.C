/* using continue */

#include "stdio.h"

 main()
  {
   int x;

   for(x=0; x<=100; x++) {
     if(x%2) continue;
     printf("%d ",x);
   }
}


