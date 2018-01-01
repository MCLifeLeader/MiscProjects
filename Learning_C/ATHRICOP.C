/* athithmitic operator test */

#include "stdio.h"

 main()
 {
   int x, y;

   x = 10;
   y = 3;
   printf("%d", x/y);  /* will display 3 */
   printf("%d", x%y);  /* will display 1, the remander
			  of the interger division */

   x = 1;
   y = 2;
   printf("%d %d", x/y, x%y); /* will display 0 1 */

}


