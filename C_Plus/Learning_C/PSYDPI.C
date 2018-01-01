
  /* calculate psydo pie number */

#include "stdio.h"

 main()
  {
   int a, c, d, e, x;
   a = 22;
   x = 0;
   do {
     x++;
     c = a / 7;
     d = c * 7;
     e = a - d;
     a = e * 10;
     printf("%d", c);
     if(x==1) {
       printf(".");
     }
   } while(x != 100);
 }

