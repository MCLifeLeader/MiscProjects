/* Magic number program: 3rd improvement. */

#include "stdio.h"
#include "stdlib.h"

 main()
  {
   int magic; /* magic number */
   int guess; /* user's guess */

   magic = rand(); /* get a random number */

   do {
     printf("Enter your guess: ");
     scanf("%d", &guess);

     if (guess == magic) {
       printf("** Right **");
       printf(" %d is the magic number\n", magic);
     }
     else {
       printf("..Sorry, you're wrong..");
       if(guess > magic) printf(" Your guess is too high\n");
       else printf(" your guess is to low\n");
     }
   } while(guess != magic);
}
