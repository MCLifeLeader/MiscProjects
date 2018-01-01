
#include "stdio.h"
#include "graph.h"
#include "stdlib.h"
#include "string.h"

 main()
  {
   int a=0, b=0, c=0, d=0, utime=0;
   int e=0, f=0, impt1=0, impt2=0;
   long ltime=0;
   char input[80];

   ltime = time(NULL);                  /* Set seed random time */
   utime = (unsigned int) ltime/2;
   srand(utime);

   do {
     printf("Enter in the number to attack1-3: ");
     gets(input);
     impt1 = atoi(input);

     if((impt1 >=3 ) || (impt1 <=1)) {
       b = (rand()%6) + 1;
       c = (rand()%6) + 1;
       d = (rand()%6) + 1;
     }
     printf("Enter in the number to defenend1-2: ");
     gets(input);
     impt2 = atoi(input);

     if((impt2 >= 2) || (impt2 <=1)) {
       e = (rand()%6) + 1;
       f = (rand()%6) + 1;
     }
     _clearscreen(_GCLEARSCREEN);
     if(impt1 == 1) {
       printf("Attack:%d\n", b);
     }

     if(impt1 == 2) {
       printf("Attack:%d\n", b);
       printf("Attack:%d\n", c);
     }

     if(impt1 == 3) {
       printf("Attack:%d\n", b);
       printf("Attack:%d\n", c);
       printf("Attack:%d\n", d);
     }

     if(impt2 == 1) {
       printf("Defend:%d\n", e);
     }

     if(impt2 == 2) {
       printf("Defend:%d\n", e);
       printf("Defend:%d\n", f);
     }
   } while(impt1 != 9);
 }
