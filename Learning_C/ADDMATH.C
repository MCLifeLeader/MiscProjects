/* A simple addition drill program. */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 int count; /* count and num_right are global. */
 int num_right;
 char name[80];
 int endcount;

 main()
  {

   printf("Hello there please type in your name: ");
   gets(name);

   printf("How many practice problems: ");
   scanf("%d", &count);
   endcount = count;
   num_right = 0;
   do {
     drill();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
  }

 drill()
  {
   int count; /* this count is local and unrelated
	       * to the global one
	       */
   int a, b, ans;

   /* generate two numbers between 0 and 99 */
   a = rand() % 100;
   b = rand() % 100;

   /* The user three tries to get it right */
   for(count=0; count<3; count++) {
     printf("What is %d + %d? ", a, b);
     scanf("%d", &ans);
     if(ans==a+b) {
       printf("Right\n");
       num_right++;
       return;
     }
   }
   printf("Sorry %s you used up all of your tries\n", name);
   printf("The answer is %d: \n", a+b);
}





