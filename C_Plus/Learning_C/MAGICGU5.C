/* Magic number program: finnal improvement. 32767 is highest number
   possable for entering in a number */

#include "stdio.h"
#include "stdlib.h"

 main()
  {
   int option;
   int magic;

   magic = rand();

   do {
     printf("1. Get a new magic number\n");
     printf("2. Play\n");
     printf("3. Quit\n");
     do {
       printf("Enter your choice: ");
       scanf("%d", &option);
     } while(option<1 || option>3);

     switch(option) {
       case 1:
	 magic = rand();
	 break;
       case 2:
	 play(magic);
	 break;
       case 3:
	 printf("Goodbye\n");
	 break;
       }
     } while(option!=3);
   }
   play(int m)
    {
     int t, x;

     for(t=0; t<100; t++) {
       printf("No number will be above 32767\n");
       printf("Guess the number: ");
       scanf("%d", &x);
       if(x==m) {
	 printf("*** Right *** ");
	 return;
       }
       else {
	 if(x>m) printf("Too high\n");
	 else printf("Too low\n");
       }
      }
     printf("You used up all your guesses...try again\n");
}
