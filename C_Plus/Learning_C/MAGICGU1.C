/* Magic number gussing game */


#include "stdio.h"
#include "stdlib.h"

 main()
 {
   int magic; /* magic number */
   int guess; /* user's guess */

   magic = rand(); /* get a random number */

   printf("Enter your guess?: ");
   scanf("%d", &guess);

   if (guess == magic)
     printf("***RIGHT!!***");
}

