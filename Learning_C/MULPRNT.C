/* How the logic gates need to be aranged */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

 int x, a1, b1, c1, c2, d2;
 int count, info;
 int answer;
 int xfer, xfer2, xfer3;
 int num_right;
 int endcount;
 int endcount2;
 int num_right2;
 char name[80];

 main()
  {
   int utime;
   long ltime;

   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);
   x = rand();
   /* printf("main x = %d\n", x); */
   prntout();
 }

 prntout()
  {
   int a, b;
   char input[80];

   do {
     printf("\n\n\n");
     printf("1. for 3 logic gates\n");
     printf("2. for 4 logic gates\n");
     printf("3. for 5 logic gates\n");
     printf("4. for 6 logic gates\n");
     printf("5. for 7 logic gates\n");
     printf("6. for 8 logic gates\n");
     printf("7. for 9 logic gates\n");
     printf("8. for 10 logic gates\n");
     printf("9. for 11 logic gates\n");
     printf("10. to quit......\n");
     do {
       printf("Enter in your number: ");
       gets(input);
       a = atoi(input);
       printf("\n\n\n");
     } while(a<1 || a>10);
     switch(a) {
       case 1:
	 lg1();
	 break;
       case 2:
	 lg2();
	 break;
       case 3:
	 lg3();
	 break;
       case 4:
	 lg4();
	 break;
       case 5:
	 lg5();
	 break;
       case 6:
	 lg6();
	 break;
       case 7:
	 lg7();
	 break;
       case 8:
	 lg8();
	 break;
       case 9:
	 lg9();
	 break;
       case 10:
	 break;
     }
   } while(a!=10);
 }

 lg1()
  {
   printf("=LG1--v\n");
   printf("      ==LG3-- = Answer.\n");
   printf("=LG2--^\n");
 }

 lg2()
  {
   printf("=LG1--v\n");
   printf("      ==LG3--v\n");
   printf("=LG2--^      v\n");
   printf("             v\n");
   printf("1/0----\\_____==LG4-- = Answer.\n");
 }

 lg3()
  {
   printf("=LG1--v\n");
   printf("      ==LG4--v\n");
   printf("=LG2--^      v\n");
   printf("             v\n");
   printf("=LG3--\\______==LG5-- Answer.\n");
 }

 lg4()
  {
   printf("=LG1--v\n");
   printf("1/0-\\_==LG4--v\n");
   printf("=LG2--v      ==LG6-- Answer.\n");
   printf("      ==LG5--^\n");
   printf("=LG3--^\n");
 }

 lg5()
  {
   printf("=LG1--v\n");
   printf("      ==LG5--v\n");
   printf("=LG2--^      v\n");
   printf("             ==LG7-- Answer.\n");
   printf("=LG3--v      ^\n");
   printf("      ==LG6--^\n");
   printf("=LG4--^\n");
 }

 lg6()
  {
   printf("=LG1--v\n");
   printf("      ==LG5--v\n");
   printf("=LG2--^      v\n");
   printf("             ==LG7--v\n");
   printf("=LG3--v      ^      v\n");
   printf("      ==LG6--^      ==LG8-- Answer.\n");
   printf("=LG4--^             ^\n");
   printf("1/0-----------------^\n");
 }

 lg7()
  {
   printf("=LG1--v\n");
   printf("      ==LG6--v\n");
   printf("=LG2--^      v\n");
   printf("         ____==LG8--v\n");
   printf("=LG3----/           v\n");
   printf("                    ==LG9-- Answer.\n");
   printf("=LG4--v        ___/-^\n");
   printf("      ==LG7---/\n");
   printf("=LG5--^\n");
 }

 lg8()
  {
   printf("=LG1--v\n");
   printf("      ==LG6--v\n");
   printf("=LG2--^      v\n");
   printf("         ____==LG8--v\n");
   printf("=LG3----/           v\n");
   printf("                 ___==LG9--v\n");
   printf("=LG4--v       __/          v\n");
   printf("      ==LG7--/             v\n");
   printf("=LG5--^       (1/0)--\\____==LG10-- Answer.\n");
 }

 lg9()
  {
   printf("=LG1--v\n");
   printf("      ==LG7--v\n");
   printf("=LG2--^      v\n");
   printf("             ==LG10--v\n");
   printf("=LG3--v      ^       v\n");
   printf("      ==LG8--^       v\n");
   printf("=LG4--^              ==LG11-- Answer.\n");
   printf("                     ^\n");
   printf("=LG5--v       ___/---^\n");
   printf("      ==LG9--/\n");
   printf("=LG6--^\n");
 }


