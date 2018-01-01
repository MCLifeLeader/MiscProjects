/* key press command */

#include "stdio.h"
#include "conio.h"

main()
 {
  int i;
  /* print numbers until a key is pressed */
  for(i=0; !kbhit(); i++) printf("%d ", i);
}
