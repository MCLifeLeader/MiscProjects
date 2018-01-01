
#include "stdio.h"
#include "graph.h"

 main()
  {
   int a;

   _clearscreen(_GCLEARSCREEN);

   for(a=1; a<=5000; a++) {
     _settextposition(10, 10);
     printf("Hello %d\n", a);
   }
 }

