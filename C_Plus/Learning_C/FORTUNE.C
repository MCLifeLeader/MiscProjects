/* Fortune cookie program */

#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

 char *fortunes[] = {
   "Soon, you will come into some money.\n",
   "A new love will enter your life.\n",
   "You will live long and prosper.\n",
   "Now is a good time to invest for the future.\n",
   "A close friend will ask for a favor.\n"
 };

 main()
  {
   int chance;

   printf("To see your fortune, press a key: ");
   /* Randomize the random number generator */
   while(!kbhit()) rand();
   printf("\n");

   chance = rand();
   chance = chance % 5;
   printf("%s", fortunes[chance]);

}

