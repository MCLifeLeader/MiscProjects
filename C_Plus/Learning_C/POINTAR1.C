/* Tokenizing program: array indexing version. */

#include "stdio.h"

 main()
  {
   char str[80];
   char token[80];
   int i, j;

   printf("Enter a sectence: ");
   gets(str);

   /* Read a token at a time from the string. */
   for(i=0; ; i++) {
     /*  Read characters until either a space
	 or the null terminatro is encountered. */

     for(j=0; str[i]!=' ' && str[i]; j++, i++)
       token[j] = str[i];

     token[j]  ='\0'; /* null terminate the token */
     printf("%s\n", token);
     if(!str[i]) break;
   }
}

