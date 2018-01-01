/* Removes unwanted batch files from the root drive of current drive */

#include "stdio.h"

 main()
  {
   system("attrib autoexec.bat +r");
   system("attrib bootpath.bat +r");
   system("del *.bat");
   system("attrib autoexec.bat -r");
   system("attrib bootpath.bat -r");
 }
