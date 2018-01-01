/* Indexing a pointer like an array. */

#include "stdio.h"
#include "ctype.h"

 main()
  {
   char str[20] = "hello tom";
   char *p;
   int i;

   p = str;

   for(i=0; p[i]; i++) printf("%c", toupper(p[i]));
}
