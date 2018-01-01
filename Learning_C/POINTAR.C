/* Tolkenizing program: pointer version. */

#include "stdio.h"

 main()
  {
   char str[80];
   char token[80];
   char *p, *q;

   printf("Enter a sentence: ");
   gets(str);

   p = str;

   /* Read a token at a time from the string. */
   while(*p) {
     q = token; /* set q pointing to start of token */

     /* Read characters until either a space
	or the null terminator is encounterd */

     while(*p!=' ' && *p) {
       *q = *p;
	 q++; p++;
     }
     if(*p) p++; /* advance past the space */
     *q = '\0'; /* null terminate the token */
     printf("%s\n", token);
   }
}

