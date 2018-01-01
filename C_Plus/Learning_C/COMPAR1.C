/*  comparison example */

#include "stdio.h"
#include "conio.h"

 main()
  {
   char str[10];
   char *start, *end;

   start = str;
   end = &str[9];

   while(start!=end) {
     *start = getche();
     start++;
   }
   start = str; /* reset the starting pointer */
   while(start!=end) {
     printf("%c", *start);
     start++;
   }
}


