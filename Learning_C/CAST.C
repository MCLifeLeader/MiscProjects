/* casts and doubles */

#include "stdio.h"

 main() /* print i and i/2 with fractions */
 {
   int i;

   for(i=1; i<=100; ++i )
     printf("%d / 2 is: %f\n",i,(float) i /2);
}
