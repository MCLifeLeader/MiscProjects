/* Program prints the alphabet inreverse order. */

#include "stdio.h"

 main()
 {
   char letter;

   for(letter = 'Z'; letter >= 'A'; letter--)
     printf("%c ", letter);
}
