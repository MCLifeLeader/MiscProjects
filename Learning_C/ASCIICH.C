/* This program displays all printable characters,
   includeing the extended character set, if one
   exists. */

#include "stdio.h"

 main()
  {
   char ch;

   ch = 1;
   while(ch!=0) {
     printf("%c", ch);
     ch++;
   }
}
