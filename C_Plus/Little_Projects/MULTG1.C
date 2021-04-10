
 /* Diagostic programming of a block of code */

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


  char *orgate[] = {
    "The truth table for the OR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  0  Boolean Expression\n",
    "  0  1  =  1        A+B\n",
    "  1  0  =  1\n",
    "  1  1  =  1\n"
  };

  char *norgate[] = {
    "The truth table for the NOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1  Boolean Expression\n",
    "  0  1  =  0      !(A+B)\n",
    "  1  0  =  0\n",
    "  1  1  =  0               !=NOT\n"
  };

  char *xorgate[] = {
    "The truth table for the XOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  0  Boolean Expression\n",
    "  0  1  =  1     (A<+>B)\n",
    "  1  0  =  1\n",
    "  1  1  =  0\n"
  };

  char *xnorgate[] = {
    "The truth table for the XNOR gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1  Boolean Expression\n",
    "  0  1  =  0    !(A<+>B)\n",
    "  1  0  =  0\n",
    "  1  1  =  1               !=NOT\n"
  };

  char *andgate[] = {
    "The truth table for the AND gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  0  Boolean Expression\n",
    "  0  1  =  0        A*B\n",
    "  1  0  =  0\n",
    "  1  1  =  1\n"
  };

  char *nandgate[] = {
    "The truth table for the NAND gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  0  0  =  1  Boolean Expression\n",
    "  0  1  =  1      !(A*B)\n",
    "  1  0  =  1\n",
    "  1  1  =  0\n"
  };

  char *notgate[] = {
    "The truth table for the NOT / Inverter gate is.\n",
    "  B  A  =  answer on/off or 1's and 0's\n",
    "  *  0  =  1  Boolean Expression\n",
    "  *  1  =  0         !\n"
  };

  char *lvl1[] = {
    "The format for 3 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG3-- = Answer.\n",
    "=LG2--^\n"
  };

  char *lvl2[] = {
    "The format for 4 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG3--v\n",
    "=LG2--^      v\n",
    "             v\n",
    "1/0----\\_____==LG4-- = Answer.\n"
  };

  char *lvl3[] = {
    "The format for 5 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG4--v\n",
    "=LG2--^      v\n",
    "             v\n",
    "=LG3--\\______==LG5-- Answer.\n"
  };

  char *lvl4[] = {
    "The format for 6 logic gates will be.\n",
    "=LG1--v\n",
    "1/0-\\_==LG4--v\n",
    "=LG2--v      ==LG6-- Answer.\n",
    "      ==LG5--^\n",
    "=LG3--^\n"
  };

  char *lvl5[] = {
    "The format for 7 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG5--v\n",
    "=LG2--^      v\n",
    "             ==LG7-- Answer.\n",
    "=LG3--v      ^\n",
    "      ==LG6--^\n",
    "=LG4--^\n"
  };

  char *lvl6[] = {
    "The format for 8 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG5--v\n",
    "=LG2--^      v\n",
    "             ==LG7--v\n",
    "=LG3--v      ^      v\n",
    "      ==LG6--^      ==LG8-- Answer.\n",
    "=LG4--^             ^\n",
    "1/0-----------------^\n"
  };

  char *lvl7[] = {
    "The format for 9 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG6--v\n",
    "=LG2--^      v\n",
    "         ____==LG8--v\n",
    "=LG3----/           v\n",
    "                    ==LG9-- Answer.\n",
    "=LG4--v        ___/-^\n",
    "      ==LG7---/\n",
    "=LG5--^\n"
  };

  char *lvl8[] = {
    "The format for 10 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG6--v\n",
    "=LG2--^      v\n",
    "         ____==LG8--v\n",
    "=LG3----/           v\n",
    "                 ___==LG9--v\n",
    "=LG4--v       __/          v\n",
    "      ==LG7--/             v\n",
    "=LG5--^       (1/0)--\\____==LG10-- Answer.\n"
  };

  char *lvl9[] = {
    "The format for 11 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG7--v\n",
    "=LG2--^      v\n",
    "             ==LG10--v\n",
    "=LG3--v      ^       v\n",
    "      ==LG8--^       v\n",
    "=LG4--^              ==LG11-- Answer.\n",
    "                     ^\n",
    "=LG5--v       ___/---^\n",
    "      ==LG9--/\n",
    "=LG6--^\n"
  };

 main()
  {
   int utime;
   long ltime;

   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);
   x = rand();
   /* printf("main x = %d\n", x); */
   multi_logic_gates();
 }

 multi_logic_gates()
  {
   char opt[80];
   int option2, clrscr;

   printf("\n\nThis area tests your knowledge of using Boolean Algerbra.\n");
   printf("Random assortments of logic gates will be placed in a sertain\n");
   printf("predetermined pattern. You will need to tell what the out put\n");
   printf("will be. Your score will be shown when you finnish. Have fun\n");
   printf("and good LUCK!!! :-) \n");

   clrscr = 0;
   do {
     if(clrscr>=1) {
       printf("\n\n\n\n");
     }
     clrscr++;

     printf("\n\n1. List of all of the logic gates.\n");
     printf("2. Level 1 Test.\n");
     printf("3. Level 2 Test.\n");
     printf("4. Level 3 Test.\n");
     printf("5. Level 4 Test.\n");
     printf("6. Level 5 Test.\n");
     printf("7. Level 6 Test.\n");
     printf("8. Level 7 Test.\n");
     printf("9. Level 8 Test.\n");
     printf("10. Level 9 Test.\n");
     printf("11. Back to Main Menu.\n");
     printf("\n\n");
     do {
       printf("Please Enter in Your Choice: ");
       gets(opt);
       info = 1;
       option2 = atoi(opt);
       if(option2 <= 0) {
	 option2 = 1;
       }
     } while(option2<1 || option2>11);
     printf("\n\n\n\n");
     switch(option2) {
       case 1:
	 multi_helpmnu();
	 break;
       case 2:
	 lv1();
	 break;
       case 3:
	 lv2();
	 break;
       case 4:
	 lv3();
	 break;
       case 5:
	 lv4();
	 break;
       case 6:
	 lv5();
	 break;
       case 7:
	 lv6();
	 break;
       case 8:
	 lv7();
	 break;
       case 9:
	 lv8();
	 break;
       case 10:
	 lv9();
	 break;
       case 11:
	 break;
     }
   } while(option2!=11);
 }


 multi_helpmnu()
  {
   int l, option, clrscr;
   char opt[80];

   printf("Which logic gate do you need to see?\n");
   do {
     printf("\nThe gates are as follows.\n");
     printf("1. OR gate.\n");
     printf("2. NOR gate.\n");
     printf("3. XOR gate.\n");
     printf("4. XNOR gate.\n");
     printf("5. AND gate.\n");
     printf("6. NAND gate.\n");
     printf("7. NOT / Inverter.\n");
     printf("8. Back to the Menu.\n");
     printf("\n\n");
     do {
       printf("Enter in your choice: ");
       gets(opt);
       option = atoi(opt);
       if(option <= 0) {
	 option = 1;
       }
     } while(option<1 || option>8);
       printf("\n\n");
     switch(option) {
       case 1:
	 for(l=0; l<6; l++) {
	   printf("%s", orgate[l]);
	 }
	 break;
       case 2:
	 for(l=0; l<6; l++) {
	   printf("%s", norgate[l]);
	 }
	 break;
       case 3:
	 for(l=0; l<6; l++) {
	   printf("%s", xorgate[l]);
	 }
	 break;
       case 4:
	 for(l=0; l<6; l++) {
	   printf("%s", xnorgate[l]);
	 }
	 break;
       case 5:
	 for(l=0; l<6; l++) {
	   printf("%s", andgate[l]);
	 }
	 break;
       case 6:
	 for(l=0; l<6; l++) {
	   printf("%s", nandgate[l]);
	 }
	 break;
       case 7:
	 for(l=0; l<4; l++) {
	   printf("%s", notgate[l]);
	 }
	 break;
       case 8:
	 break;
     }
   }while(option!=8);
 }

 lv1()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level1();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv2()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level2();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv3()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level3();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv4()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level4();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv5()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level5();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv6()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level6();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv7()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level7();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv8()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level8();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }

 lv9()
  {
   int display;
   float numb1, numb2, numb3;
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   if(count <= 0) {
     count = 25;
   }
   endcount = count;
   endcount2 = count+endcount2;
   num_right = 0;
   do {
     multi_level9();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   numb1 = num_right;
   numb2 = endcount;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your percent correct is %d\n", display);
   num_right2 = num_right+num_right2;
   printf("Your total over all is %d out of %d\n", num_right2, endcount2);
   numb1 = num_right2;
   numb2 = endcount2;
   numb3 = numb1 / numb2;
   display = numb3 * 100;
   printf("Your total percent correct is %d\n", display);
 }


 multi_level1()
  {
   long ltime;
   int xer2, xer3;
   int x, solve, utime;
   int l, build;
   char input[80], lgxf[10], lgxf2[10];

   if(info==1) {
     info = 20;
     printf("You have chosen level 1 testing.\n");
     printf("You will have to go through %d rounds. Your score will\n", count);
     printf("be accumlatively added per questions answered.\n");
     printf("For help type \"HELP\" \nTo Quit type \"QUIT\" \n");
   }

   else {
     printf("Rounds left %d,  Type \"HELP\" or \"QUIT\" \n", count);
   }

       /*
	* Set this up so that people can not enter in 0 or just
	* hit return to go by that they must enter in a number
	*/
   ltime = time(NULL);             /* Set random number */
   utime = (unsigned int) ltime/2;
   srand(utime);

   solve = 0;
   build = 1;
   do {
   x = rand() % 15;     /* Random number used in random creation of */
     if(x==0) {         /* logical gates. */
       build--;
     }
     if(x == 1 || x == 2) {

       if(build==1) {
	 inpt_or();
	 printf("==OR --v\n");
	 strcpy(lgxf, "OR");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==OR --- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_or();
	 printf("==OR --^\n");
	 strcpy(lgxf2, "OR");
	 b1 = xfer;
       }
     }
     if(x == 3 || x == 4) {

       if(build==1) {
	 inpt_nor();
	 printf("==NOR--v\n");
	 strcpy(lgxf, "NOR");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==NOR--- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_nor();
	 printf("==NOR--^\n");
	 strcpy(lgxf2, "NOR");
	 b1 = xfer;
       }
     }
     if(x == 5 || x == 6) {

       if(build==1) {
	 inpt_xor();
	 printf("==XOR--v\n");
	 strcpy(lgxf, "XOR");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==XOR--- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_xor();
	 printf("==XOR--^\n");
	 strcpy(lgxf2, "XOR");
	 b1 = xfer;
       }
     }
     if(x == 7 || x == 8) {

       if(build==1) {
	 inpt_xnor();
	 printf("==XNOR-v\n");
	 strcpy(lgxf, "XNOR");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==XNOR-- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_xnor();
	 printf("==XNOR-^\n");
	 strcpy(lgxf2, "XNOR");
	 b1 = xfer;
       }
     }
     if(x == 9 || x == 10) {

       if(build==1) {
	 inpt_and();
	 printf("==AND--v\n");
	 strcpy(lgxf, "AND");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==AND--- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_and();
	 printf("==AND--^\n");
	 strcpy(lgxf2, "AND");
	 b1 = xfer;
       }
     }
     if(x == 11 || x == 12) {

       if(build==1) {
	 inpt_nand();
	 printf("==NAND-v\n");
	 strcpy(lgxf, "NAND");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==NAND-- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_nand();
	 printf("==NAND-^\n");
	 strcpy(lgxf2, "NAND");
	 b1 = xfer;
       }
     }
     if(x == 13 || x == 14) {

       if(build==1) {
	 inpt_not();
	 printf("==NOT--v\n");
	 strcpy(lgxf, "NOT");
	 a1 = xfer;
	 xer2 = xfer2;
	 xer3 = xfer3;
       }
       if(build==2) {
	 printf("       ==NOT--- = Answer.\n");
	 /* c1 = xfer; */
       }
       if(build==3) {
	 inpt_not();
	 printf("==NOT--^\n");
	 strcpy(lgxf2, "NOT");
	 b1 = xfer;
       }
     }

   /* if(build==1) {                          Diagnostic help
       printf("a1 round x = %d\n", x);
     }
     if(build==2) {
       printf("b1 round x = %d\n", x);
     }
     if(build==3) {
       printf("c1 round x = %d\n", x);
     }
     printf("build before %d\n", build); */

     if(build==3) {
       solve = x;
     } build++;
   } while(build!=4);

   /*  printf("build last %d\n", build); */

  if(solve == 1 || solve == 2) {    /* OR */
    ans_or();
  }
  if(solve == 3 || solve == 4) {    /* NOR */
    ans_nor();
  }
  if(solve == 5 || solve == 6) {    /* XOR */
    ans_xor();
  }
  if(solve == 7 || solve == 8) {    /* XNOR */
    ans_xnor();
  }
  if(solve == 9 || solve == 10) {   /* AND */
    ans_and();
  }
  if(solve == 11 || solve == 12) {  /* NAND */
    ans_nand();
  }
  if(solve == 13 || solve == 14) {  /* NOT */
    ans_not();
  }
  printf("The LG1's input=%s is a=%d and b=%d\n\n", lgxf, xer3, xer2);
  printf("The LG2's input=%s is a=%d and b=%d\n", lgxf2, xfer3, xfer2);

      /* Diagnostic help */
  /*
   *  printf("%d= a1 %d= b1 %d= c1\n", a1, b1, c1);
   *  printf("%d = answer\n", answer);
   */

  printf("\n\nWhat is the answer 1 or 0? ");
  gets(input);
  for(l=0; input[l]; l++) input[l] = toupper(input[l]);
  if(!strcmp(input, "HELP")) {
    for(l=0; l<4; l++) {
      printf("%s", lvl1[l]);
    }
    printf("\n\n");
  }
  if(!strcmp(input, "QUIT")) {
    count = 1;
  }
  answer = atoi(input);
  if(answer==xfer) {
    printf("\n\nCongradulations!!! That was the right answer!\n");
    num_right++;
  }
  else {
    printf("\n\nSorry wrong answer.\n");
  }
 }


 multi_level2()
  {

 }

 multi_level3()
  {

 }

 multi_level4()
  {

 }

 multi_level5()
  {

 }

 multi_level6()
  {

 }

 multi_level7()
  {

 }

 multi_level8()
  {

 }

 multi_level9()
  {

 }

 ans_or()
  {
   answer = (b1 || a1);
   xfer = answer;
 }
 ans_nor()
  {
   answer = !(b1 || a1);
   xfer = answer;
 }
 ans_xor()
  {
   answer = ( xor(b1, a1));
   xfer = answer;
 }
 ans_xnor()
  {
   answer = ( xnotor(b1, a1));
   xfer = answer;
 }
 ans_and()
  {
   answer = (b1 && a1);
   xfer = answer;
 }
 ans_nand()
  {
   answer = !(b1 && a1);
   xfer = answer;
 }
 ans_not()
  {
   answer = !((b1) && (a1));
   xfer = answer;
 }

 inpt_or()
  {
   int a, b;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     b = 0;
     a = 0;
   }
   if(x == 2 || x == 3) {
     b = 1;
     a = 0;
   }
   if(x == 4 || x == 5) {
     b = 0;
     a = 1;
   }
   if(x == 6 || x == 7) {
     b = 1;
     a = 1;
   }
  /* printf(" or x = %d\n", x); */
   xfer2 = b;
   xfer3 = a;
   xfer = (b || a); /* or */
 }

 inpt_nor()
  {
   int a, b;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     b = 0;
     a = 0;
   }
   if(x == 2 || x == 3) {
     b = 1;
     a = 0;
   }
   if(x == 4 || x == 5) {
     b = 0;
     a = 1;
   }
   if(x == 6 || x == 7) {
     b = 1;
     a = 1;
   }
   /* printf("nor x = %d\n", x); */
   xfer2 = b;
   xfer3 = a;
   xfer = !(b || a); /* nor */
 }

 inpt_xor()
  {
   int c, d;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     d = 0;
     c = 0;
   }
   if(x == 2 || x == 3) {
     d = 1;
     c = 0;
   }
   if(x == 4 || x == 5) {
     d = 0;
     c = 1;
   }
   if(x == 6 || x == 7) {
     d = 1;
     c = 1;
   }
   /* printf("xor x = %d\n", x); */
   xfer2 = d;
   xfer3 = c;
   xfer = ( xor(d, c)); /* xor */
 }

 inpt_xnor()
  {
   int c, d;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     d = 0;
     c = 0;
   }
   if(x == 2 || x == 3) {
     d = 1;
     c = 0;
   }
   if(x == 4 || x == 5) {
     d = 0;
     c = 1;
   }
   if(x == 6 || x == 7) {
     d = 1;
     c = 1;
   }
   /* printf("xnor x = %d\n", x); */
   xfer2 = d;
   xfer3 = c;
   xfer = ( xnotor(d, c)); /* xnor */
 }

 inpt_and()
  {
   int a, b;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     b = 0;
     a = 0;
   }
   if(x == 2 || x == 3) {
     b = 1;
     a = 0;
   }
   if(x == 4 || x == 5) {
     b = 0;
     a = 1;
   }
   if(x == 6 || x == 7) {
     b = 1;
     a = 1;
   }
   /* printf("and x = %d\n", x); */
   xfer2 = b;
   xfer3 = a;

   xfer = (b && a); /* and */
 }

 inpt_nand()
  {
   int a, b;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     b = 0;
     a = 0;
   }
   if(x == 2 || x == 3) {
     b = 1;
     a = 0;
   }
   if(x == 4 || x == 5) {
     b = 0;
     a = 1;
   }
   if(x == 6 || x == 7) {
     b = 1;
     a = 1;
   }
   /* printf("nand x = %d\n", x); */
   xfer2 = b;
   xfer3 = a;
   xfer = !(b && a); /* nand */
 }

 inpt_not()
  {
   int a;

   x = rand() % 8;
   if(x == 0 || x == 1) {
     a = 0;
   }
   if(x == 2 || x == 3) {
     a = 1;
   }
   if(x == 4 || x == 5) {
     a = 0;
   }
   if(x == 6 || x == 7) {
     a = 1;
   }
   /* printf("not x = %d\n", x); */
   xfer2 = a;
   xfer3 = a;

   xfer = !(a); /* not */
 }


 xor(int b, int a)
  {
  return (b || a) && !(b && a);
 }

 xnotor(int b, int a)
  {
   return !((b || a) && !(b && a));
 }


