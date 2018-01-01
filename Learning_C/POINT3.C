/* display pointer addresses in memory. */

#include "stdio.h"

 main()
  {
   char *c, ch[10];
   int *i, j[10];
   float *f, g[10];
   int x;

   c = ch;
   i = j;
   f = g;

   for(x=0; x<10; x++)
     printf("%p %p %p\n",  c+x, i+x, f+x);
}
