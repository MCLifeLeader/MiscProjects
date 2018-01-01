/* initialized sqrs array */

#include "stdio.h"

 main()
  {
   int i, j;

   printf("Enter a number between 1 and 10: ");
   scanf("%d", &i);

   /* look up i */
   for(j=0; j<10; j++)
     if(sqrs[j][0]==i) break;
   printf("The square of %d is %d\n", i, sqrs[j][1]);
}

