/* Not is Not needed */

#include "stdio.h"
#include "string.h"

 main()
  {
   char s[80];

   for (;;) {
     printf("Enter a string: ");
     gets(s);
     if(!strcmp("quit", s)) break;
   }
}

