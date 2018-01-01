/* Magic number program: 2nd improvment. with include test.*/

#include "stdio.h"
#include "stdlib.h"


 main()
 {
   int magic; /* magic number */
   int guess; /* user's guess */

   printf("Enter your guess: ");
   scanf("%d", &guess);

   if (guess == magic) {
     printf("***RIGHT***");
     printf(" %d is the magic number\n", magic);
   }
   else {
     printf("..Sorry, your wrong..");
     if(guess > magic)
       printf(" Your guess is to high\n");
     else
      printf(" Your guess is too low\n");
   }
}

