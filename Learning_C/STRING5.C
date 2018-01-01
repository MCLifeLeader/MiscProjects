/* Print a string backwards. */

#include "stdio.h"
#include "string.h"

 main()
  {
   char str[80];
   int i;

   printf("Enter a message: ");
   gets(str);

   for(i=strlen(str)-1; i>0; i--) printf("%c", str[i]);
}
