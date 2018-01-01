/* This program finds the prime numbers from 2 to 1000. */

#include "stdio.h"

 main()
  {
   int i, j;

   for(i=2; i<1000; i++) {
     for(j=2; j <= i/2; j++)
       if(!(i%j)) break;
     if(j>i/2) printf("%d is a prime\n", i);
   }
}
