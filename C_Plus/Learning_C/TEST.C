/* A test of file I/O intreacting with dos. To see if I could get the
 * computer to creat a directory and the do a dir to it. */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 main()
  {
   char input[]="attrib miketemp +h";
   mkdir("MIKETEMP");
   system(input);
  }
