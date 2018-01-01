 /* Using the random statement. */

#include "stdio.h"
#include "time.h"

 main()
  {
   int i;
   int utime;
   long ltime;

   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);

   for(i=0; i<15; i++)
     printf("%d\n", rand() % 8);
 }
