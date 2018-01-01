/* reboot computer */

#include "dos.h"

 main()
  {
   int86(0x19,0,0);
 }


