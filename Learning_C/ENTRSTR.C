/* Enter and display strings. */

#include "stdio.h"

 main()
  {
   int t, i;
   char text[100][80];

   for(t=0; t<100; t++) {
     printf("%d: ", t);
     gets(text[t]);
     if(!text[t][0]) break; /* quit on blank line */
   }

   /* redisplay the strings */
   for(i=0; i<t; i++)
     printf("%s\n", text[i]);
}
