
	/* Test of graphics */

#include "graph.h"
#include "stdio.h"

 main()
  {
   _setvideomode(_ERESCOLOR);        /* Used to clear the screen */
   printf("Hello there I just wanted to see what the screen would\n");
   printf("look like if I placed the screen on ega graphics?\n");
   printf("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n");
   while(!kbhit());
   _setvideomode(_DEFAULTMODE);
 }


