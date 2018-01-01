/* An example using variable initeilization. */

#include "stdio.h"

 main()
 {
   int t;

   printf("Enter a number: ");
   scanf("%d", &t);
   total(t);
 }

 total(int x)
 {
   int sum=0; /* initialize sum */
   int i, count;

   for(i=0; i<x; i++)  {
     sum = sum + i;
     for(count=0; count<10; count++) printf(".");
     printf("then current sum is %d\n", sum);
     }
}

