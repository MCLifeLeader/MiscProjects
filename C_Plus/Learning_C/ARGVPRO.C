/* The protram prints all command line argumnets it is called with. */

#include "stdio.h"

 main(int argc, char *argv[])
  {
   int t, i;

   for(t=0; t<argc; ++t) {
     i = 0;
     while(argv[t][i]) {
       printf("%c", argv[t][i]);
       ++i;
     }
     printf(" ");
   }
}


