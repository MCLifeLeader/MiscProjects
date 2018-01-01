
 /* Test to test directory structure dovelopment. */

 #include "stdio.h"
 #include "direct.h"
 #include "string.h"

 main()
  {
   chdir("\\");                 /* operations to create far out dir */
   if(mkdir("cadd6") == -1) {
     chdir("cadd6");
   }
   if(mkdir("3dd") == -1) {
     chdir("3dd");
   }
   if(mkdir("cm3") == -1) {
     chdir("cm3");
   }
   if(mkdir("prvt") == -1) {
     exit(1);
   }
   else {
     chdir("\\");
   }
 }

