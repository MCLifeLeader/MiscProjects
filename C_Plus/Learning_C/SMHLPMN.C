/* A simple C keyword help program. */

#include "stdio.h"
#include "string.h"

 char *keyword[][2] = {
   "for", "for(initialization; condition; increment)",
   "if", "if(condition)...else...",
   "switch", "switch(value) { case list }",
   "while", "while(condition)...",
   "", "" /* terminate the list with nulls */

   };

 main()
  {
   char str[80];
   int i;

   printf("Enter key word: ");
   gets(str);
   for(i=0; keyword[i][0]; i++)
     if(!strcmp(keyword[i][0], str))
       printf(keyword[i][1]);
}
