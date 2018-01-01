
#include "stdio.h"

 func1(int *);
 func2(int *, int*);

 main()
  {
   int a=15, b=25, c=0;

   a = (func1(&a));
   b = (func2(&a, &b));

   c = (a + b)+5;
   printf("c=%d\n", c);
 }

 func1(int *a1)
  {
   int a=0;
   a = *a1;

   a = (a * 2);
   return(a);
 }

 func2(int *a1, int *b1)
  {
   int a=0, b=0;
   a = *a1;
   b = *b1;

   b = (a + b);
   return(a, b);
 }
