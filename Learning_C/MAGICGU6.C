/* Magic number program: final improvement, exercise version. */

#include "stdio.h"
#include "stdlib.h"

 main()
  {
   int option;
   int magic;

   magic = rand();

   do {
     printf("1. Get anew magic number\n");
     printf("2. Play\n");
     printf("3. Quit\n");
     do {
       printf("Enter your chice: ");
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
      printf("Guess the number: ");
      scanf("%d", &x);
      if(x==m) {
	printf("*** Right ***\n");
	printf("You used %d guesses.\n", t+1);
	return;
      }
      else
	if(x>m) printf("Too high\n");
	else printf("Too low\n");
      }
      printf("You used up all your guesses...try again\n");
}
