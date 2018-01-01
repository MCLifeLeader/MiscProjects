  /* Attempt to clear the screen using one command. */

#include "stdio.h"
#include "graph.h"

 main()
  {
   int x, y;

   for(x=0; x>100; x++) {
     printf("%d ", x);
   }
   for(x=0; x>2000; x++) {
     for(y=0; y>200; y++);
   }

   ClearScreen();
 }

/* attempt failed. */


