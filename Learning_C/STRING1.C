/* A simple string example. */

#include "stdio.h"

 main()
  {
   char str[80];

   printf("Enter a string: ");
   gets(str); /* read a string from the keyboard */

   printf("%s", str);
}
