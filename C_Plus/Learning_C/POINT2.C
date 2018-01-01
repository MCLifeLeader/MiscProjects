/* prints 100 101 100 in order using pointers */

#include "stdio.h"

 main()
  {
   int *p, num;

   p = &num;

   *p = 100;

   printf("%d ", num);
   (*p)++;
   printf("%d ", num);
   (*p)--;
   printf("%d ", num);
}

