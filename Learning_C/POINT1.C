/* This fragment of code will not work correctly */

#include "stdio.h"

 main()
  {
   float x, y;
   int *p;

   x = 123.23;
   p = &x;
   y = *p;
   printf("%f", y);
}
