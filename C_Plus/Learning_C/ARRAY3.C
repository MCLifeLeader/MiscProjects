/* assigning arrays. this program creates an array of ten elements. */

#include "stdio.h"
#include "stdlib.h"

 main()
  {
   int i, min_value, max_value;
   int list[10];

   for(i=0; i<10; i++) list[i] = rand();

   /* find minimum value */
   min_value =32767;
   for(i=0; i<10; i++)
     if(min_value>list[i]) min_value = list[i];
   printf("minimum value generated is %d\n", min_value);

   /* find maximum value */
   max_value = 0;
   for(i=0; i<10; i++)
     if(max_value<list[i]) max_value = list[i];
   printf("maximum value generated is %d\n", max_value);
}
