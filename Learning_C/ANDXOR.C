/* This program demonstrates the xor() function. */
#include "stdio.h"

 main()
 {
   int p, q;

   printf("Enter P (0 or 1): ");
   scanf("%d", &p);
   printf("Enter Q (0 or 1): ");
   scanf("%d", &q);

   printf("P AND Q: %d\n", p && q);
   printf("P AND Q: %d\n", p || q);
   printf("P AND Q: %d\n", xor(p, q));
 }

 xor(int a, int b)
 {
   return (a || b) && !(a && b);
}

