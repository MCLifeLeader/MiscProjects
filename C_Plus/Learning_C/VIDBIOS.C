/* reboot computer */

#include "dos.h"

 main()
  {
   int86(0x10, 0, 0);
 }


