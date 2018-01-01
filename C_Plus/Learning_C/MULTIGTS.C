
 /* Diagostic programming a block of code */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 int count;
 int xfer;
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
    "             ==LG4-- = Answer.\n",
    "             ^\n",
    "(1 or 0) ----^\n"
  };

  char *lvl3[] = {
    "The format for 5 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG4--v\n",
    "=LG2--^      v\n",
    "             ==LG5-- Answer.\n",
    "             ^\n",
    "=LG3---------^\n"
  };

  char *lvl4[] = {
    "The format for 6 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG4--v\n",
    "=LG2--^      v\n",
    "             ==LG5--v\n",
    "             ^      v\n",
    "=LG3---------^      ==LG6-- Answer.\n",
    "                    ^\n",
    "(1 or 0) -----------^\n"
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
    "      ==LG6--^      v\n",
    "=LG4--^             ==LG8-- Answer.\n",
    "                    ^\n",
    "(1 or 0) -----------^\n"
  };

  char *lvl7[] = {
    "The format for 9 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG6--v\n",
    "=LG2--^      v\n",
    "             ==LG8--v\n",
    "=LG3--v      ^      v\n",
    "      ==LG7--^      v\n",
    "=LG4--^             ==LG9-- Answer.\n",
    "                    ^\n",
    "=LG5----------------^\n"
  };

  char *lvl8[] = {
    "The format for 10 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG6--v\n",
    "=LG2--^      v\n",
    "             ==LG8--v\n",
    "=LG3--v      ^      v\n",
    "      ==LG7--^      v\n",
    "=LG4--^             ==LG9--v\n",
    "                    ^      v\n",
    "=LG5----------------^      ==LG10-- Answer.\n"
    "                           ^\n",
    "(1 or 0)-------------------^\n"
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
    "=LG5--V              ^\n",
    "      ==LG9----------^\n",
    "=LG6--^\n"
  };

 main()
  {
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
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
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
     printf("\n\n\n\n\n\n");
     do {
       printf("Please Enter in Your Choice: ");
       gets(opt);
       option2 = atoi(opt);
     } while(option2<1 || option2>11);
     printf("\n\n\n\n\n\n\n\n\n\n");
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
     printf("\n\n\n\n\n\n");
     do {
       printf("Enter in your choice: ");
       gets(opt);
       option = atoi(opt);
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
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level1();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }
 lv2()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level2();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv3()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level3();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv4()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level4();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv5()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level5();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv6()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level6();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv7()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level7();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 lv8()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level8();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;
 }

 lv9()
  {
   char input2[80];

   printf("How many problems do you want? ");
   gets(input2);
   count = atoi(input2);
   endcount = count;
   endcount2 = count+endcount2;
   num_right2 = 0;
   do {
     multi_level9();
     count--;
   } while(count);
   printf("Congradulations %s,", name);
   printf(" you got %d right out of %d.\n", num_right, endcount);
   num_right2 = num_right+num_right2;

 }

 multi_level1()
  {
   int x, a, b, d, c;
   int l, ans, build;
   int a1, b1, c1;
   char input[80];
   build = 0;

   printf("You have chosen level 1 testing.\n");
   printf("You will have to go through %d rounds. Your score will\n", count);
   printf("be accumlatively added per questions answered.\n");
   printf("For help type \"HELP\" \nTo Quit type \"QUIT\" \n");
   printf("\n\n");
   printf("Do you want help now? ");
   gets(input);
   for(l=0; input[l]; l++) input[l] = toupper(input[l]);

   if(!strcmp(input, "HELP")) {
     for(l=0; l<4; l++) {
       printf("%s", lvl1[l]);
     }
   }

   if(!strcmp(input, "QUIT")) {
     count = 1;
   }
     /*   srand(1); */
   do {
     x = rand() % 14 ;
     if(x == 1 || x == 2) {
       printf("==OR --");
       inpt_or();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 3 || x == 4) {
       printf("==NOR--");
       inpt_nor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 5 || x == 6) {
       printf("==XOR--");
       inpt_xor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 7 || x == 8) {
       printf("==NXOR-");
       inpt_nxor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 9 || x == 10) {
       printf("==AND--");
       inpt_and();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 11 || x == 12) {
       printf("==NAND-");
       inpt_nand();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     }
     if(x == 13 || x == 14) {
       printf("==NOT--");
       inpt_not();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       }
       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       }
       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       }
     } build++;
   } while(build!=3);
  printf("%d=a1  %d=b1  %d=c1\n", a1, b1, c1);
  printf("%d=a1*b1*c1\n", (a1)*(c1)*(b1));
  printf("What is the answer 1 or 0? ");
  gets(input);
  ans = atoi(input);
  if(ans=(a1)*(c1)*(b1)) {
    printf("Congradulations.\n");
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

 inpt_or()
  {
   int a, b, x, y;
   b = rand() % 4;
   a = rand() % 4;
   if(b == 1 || b == 2) {
     b = 0;
   }
   if(b == 3 || b == 4) {
     b = 1;
   }
   if(a == 1 || a == 2) {
     a = 0;
   }
   if(a == 3 || a == 4) {
     a = 1;
   }
  xfer = (b || a); /* or */
 }

 inpt_nor()
  {
   int a, b, x, y;
   b = rand() % 4;
   a = rand() % 4;
   if(b == 1 || b == 2) {
     b = 0;
   }
   if(b == 3 || b == 4) {
     b = 1;
   }
   if(a == 1 || a == 2) {
     a = 0;
   }
   if(a == 3 || a == 4) {
     a = 1;
   }
   xfer = !(b || a); /* nor */
 }

 inpt_xor()
  {
   int d, c, x, y;
   d = rand() % 4;
   c = rand() % 4;
   if(d == 1 || d == 2) {
     d = 0;
   }
   if(d == 3 || d == 4) {
     d = 1;
   }
   if(c == 1 || c == 2) {
     c = 0;
   }
   if(c == 3 || c == 4) {
     c = 1;
   }
   xfer = ( xor(d, c)); /* xor */
 }

 inpt_nxor()
  {
   int d, c, x, y;
   d = rand() % 4;
   c = rand() % 4;
   if(d == 1 || d == 2) {
     d = 0;
   }
   if(d == 3 || d == 4) {
     d = 1;
   }
   if(c == 1 || c == 2) {
     c = 0;
   }
   if(c == 3 || c == 4) {
     c = 1;
   }
   xfer = ( xnotor(d, c)); /* nxor */
 }

inpt_and()
  {
   int a, b, x, y;
   b = rand() % 4;
   a = rand() % 4;
   if(b == 1 || b == 2) {
     b = 0;
   }
   if(b == 3 || b == 4) {
     b = 1;
   }
   if(a == 1 || a == 2) {
     a = 0;
   }
   if(a == 3 || a == 4) {
     a = 1;
   }
   xfer = (b && a); /* and */
 }

 inpt_nand()
  {
   int a, b, x, y;
   b = rand() % 4;
   a = rand() % 4;
   if(b == 1 || b == 2) {
     b = 0;
   }
   if(b == 3 || b == 4) {
     b = 1;
   }
   if(a == 1 || a == 2) {
     a = 0;
   }
   if(a == 3 || a == 4) {
     a = 1;
   }
   xfer = !(b && a); /* nand */
 }

 inpt_not()
  {
   int a, x;
   a = rand() % 4;
   if(a == 1 || a == 2) {
     a = 0;
   }
   if(a == 3 || a == 4) {
     a = 1;
   }
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
