/* while do=while continue staements and loops */

#include "stdio.h"

 main()
  {
   int i, x;

   printf("Enter 100 to quit\n");
   for(i=0, x=0; i<100 && x!=100; i++) {
     printf(": ");
     scanf("%d", &x);
     if(x<0) continue;
     printf("%d ", x);
   }
}
