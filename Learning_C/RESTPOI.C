/* This program is wrong. Can you fix it ? */

#include "stdio.h"
#include "string.h"

 main()
  {
   char s[80];
   char *p1;
   p1 = s; /* p1 = s; should be down there. */

   do {

     /* p1 = s; */

     gets(s); /* read a string */
     /* print the ASCII values of each character */
     while(*p1) printf(" %d ", *p1++);
   } while(strcmp(s, "done"));
}

