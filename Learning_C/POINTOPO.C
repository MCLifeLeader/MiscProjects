/* pointer to a pointer application and exsample */

#include "stdio.h"

 main()
  {
   int x, *p, **q;

   x=10;
   p=&x;
   q=&p;

   printf("%d", **q); /* print the value of x */

}
