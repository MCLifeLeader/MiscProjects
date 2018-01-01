
  /* calculate psydo pie number modifed program to alow 1 to 5000
   * insted of 1 to 500
   */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 main()
  {
   int a, b, c, d, e, f, x;
   char input[80];

   printf("Enter in the amount starting to be devided by: ");
   gets(input);
   a = atoi(input);
   if(a<=0 || a>=5001) {
     a = 22;
   }
   printf("Enter in the amount that will devide the starting amount: ");
   gets(input);
   b = atoi(input);
   if(b<=0 || b>=5001) {
     b = 7;
   }
   printf("Number of itterations to calculate out: ");
   gets(input);
   f = atoi(input);
   if(f<=0 || f>=5001) {
     f = 25;
   }
   x = 0;
   do {
     x++;
     c = a / b;
     d = c * b;
     e = a - d;
     a = e * 10;
     printf("%d", c);
    /* if(x==1) {
       printf(".");
     } */
   } while(x != f);
 }

