/* general form of a call to strlen() */

#include "stdio.h"
#include "string.h"

 main()
  {
   char str[80];

   printf("Enter a string: ");
   gets(str);

   printf("%d", strlen(str));

}
