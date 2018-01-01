
#include "stdio.h"

 main()
  {
   int s, w, x, y, z;
   unsigned char inpt;

   w = 0;
   do {
     w++;

     if(w>=255) {
       w = 0;
     }
     inpt = w;
     printf("%d\n", inpt);

     x = ((w+x+y)/3)+z;
     inpt = x;
     printf("%d\n", inpt);

     y = ((w+x+y)/3)+x;
     inpt = y;
     printf("%d\n", inpt);

     z = ((w+x+y)/3)+y;
     inpt = z;
     printf("%d\n", inpt);

   } while(s != 1);
 }

