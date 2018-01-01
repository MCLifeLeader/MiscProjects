/* Run lgates.exe from a system command. */

#include "stdio.h"
#include "string.h"

 main()
  {
   char go[80];

   do {
     printf("Enter in run to exicute lgates.exe or exit to exit");
     printf(" this program.");
     printf("Enter in the data now: ");
     gets(go);
     if(!strcmp(go, "run")); {
       system("lgates.exe");
     }
   } while(strcmp(go, "exit"));
 }


