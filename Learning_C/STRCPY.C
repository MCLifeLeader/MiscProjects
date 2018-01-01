/* global variables ini */

#include "stdio.h"

 main()
  {
   fl(); fl();
  }
  fl()
  {
   char s[80]="This is a test\n";

   printf(s);
   strcpy(s, "hello");
   printf(s);
}
