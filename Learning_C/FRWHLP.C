/* for while loops */

#include "stdio.h"

 main()
  {
   int len;

   printf("enter length (1 to 79)");
   scanf("%d", &len);

   while(len>0 && len<80) {
     printf(".");
     len--;
   }
}

