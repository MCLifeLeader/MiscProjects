/* Convert letters to upper case */

#include "stdio.h"
#include "string.h"
#include "ctype.h"

 main()
  {
   char str[80];
   int i;

   strcpy(str, "this is a test");

   for(i=0; str[i]; i++) str[i] = toupper(str[i]);

   printf("%s", str);
}
