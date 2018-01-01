/* do/while statements and functions */

#include "stdio.h"

 main()
  {
   int i;

   printf("1. Check Spelling\n");
   printf("2. Correct Spelling Errors\n");
   printf("3. Display Spelling Errors\n");
   printf("Strike Any Other Key to Skip\n");
   printf("      Enter your choice: ");
   do {
     scanf("%d", &i);
     switch(i) {
       case 1:
	 check_spelling();
	 break;
       case 2:
	 correct_errors();
	 break;
       case 3:
	 display_errors();
	 break;
     }
   } while(i!=1 && i!=2 && i!=3);
}
