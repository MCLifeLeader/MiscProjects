
#include "stdio.h"
#include "bios.h"

 main()
  {
   int a=0, b=0, c=0;
   char kbin=0;

   do {
     a = inp(_bios_keybrd(_NKEYBRD_READY));

     printf("%d\", a);
   } while(kbin!='q');
 }

