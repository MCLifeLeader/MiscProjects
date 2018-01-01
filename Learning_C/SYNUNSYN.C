/* This program shows the difference between signed and
  unsigned integers. */

#include "stdio.h"

 main()
 {
   int i;  /* na signed integer */
   unsigned int j; /* an unsigned integer */

   j = 60000;
   i = j;
   printf("%d %u", i, j);
}
