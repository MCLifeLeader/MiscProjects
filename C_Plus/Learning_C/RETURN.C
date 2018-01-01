/* A program that uses return. */

#include "stdio.h"

 main()
 {
   int answer;

   answer = mul(10, 11); /* assign return value */

   printf("The answer is %d\n", answer);
}


 /* This function retruns a value. */
 mul(int x, int y)
 {
   return x * y;
}
