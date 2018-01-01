/* using local variables in a function */

#include "stdio.h"

 main()
  {
   char str[]="this is str in main()";

   printf("%s\n", str);
   fl();
   printf("%s\n", str);
  }

  /* second block of code */

  fl()
   {
    char str[80];

    printf("Enter something: ");
    gets(str);
    printf("%s\n", str);
}


