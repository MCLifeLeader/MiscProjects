
#include "stdio.h"
#include "graph.h"

 main()
  {
   int i=0;
   unsigned long number=0;

   _clearscreen(_GCLEARSCREEN);

   for(number=0; number<400000000; number++) {
     _settextposition(24,1);
     printf("%ld\n", number);
     i++;
     if(i==2000) {
       _settextposition(24,1);
       printf("GIVE\n");
       _settextposition(24,1);
       printf("    \n");
     }
     if(i==4000) {
       _settextposition(24,1);
       printf("MIKE\n");
       _settextposition(24,1);
       printf("    \n");
     }
     if(i==6000) {
       _settextposition(24,1);
       printf("CAREY\n");
       _settextposition(24,1);
       printf("     \n");
     }
     if(i==8000) {
       _settextposition(24,1);
       printf("ALL\n");
       _settextposition(24,1);
       printf("   \n");
     }
     if(i==10000) {
       _settextposition(24,1);
       printf("OF\n");
       _settextposition(24,1);
       printf("  \n");
     }
     if(i==12000) {
       _settextposition(24,1);
       printf("YOUR\n");
       _settextposition(24,1);
       printf("    \n");
     }
     if(i==14000) {
       _settextposition(24,1);
       printf("MONEY\n");
       _settextposition(24,1);
       printf("     \n");
       i = 0;
     }
   }
 }
