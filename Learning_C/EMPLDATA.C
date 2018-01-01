/* Simple employee database program */

#include "stdio.h"
#include "stdlib.h"

 char name[10][80];  /* array holds emplyee names */
 char phone[10][20]; /* their phone numbers */
 float hours[10];    /* hours worked per week */
 float wage[10];     /* wage */

 main()
  {
   int choice;

   do {
     choice = menu(); /* get selection */
     switch(choice) {
       case 0: break;
       case 1: enter();
	 break;
       case 2: report();
	 break;
       default: printf("try again");
     }
   } while(choice!=0);
  }
  /* Return a user's choice. */
  menu()
   {
    char str[80];
    int i;

    printf("0. Quit\n");
    printf("1. Enter information\n");
    printf("2. Report information\n");
    printf("\nChoose one: ");
    gets(str);
    i = atoi(str);
    printf("\n");
    return i;
   }
   /* Enter employee information */
  enter()
   {
    int i;
    char temp[80];

    for(i=0; i<10; i++) {
      printf("Enter name: ");
      gets(name[i]);
      printf("Enter phone number: ");
      gets(phone[i]);
      printf("Enter number of hours worked: ");
      gets(temp);
      hours[i] = atof(temp);
      printf("Enter wage: ");
      gets(temp);
      wage[i] = atof(temp);
    }
   }
  report()
   {
    int i;

    for(i=0; i<10; i++) {
      if(!*name[i]) break;
      printf("%s %s\n", name[i], phone[i]);
      printf("Pay for the week: %f\n", wage[i]*hours[i]);
    }
}


