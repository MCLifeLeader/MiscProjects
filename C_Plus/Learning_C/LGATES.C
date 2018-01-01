/*
 * Program:     LGATES.EXE
 * Source:      lgates.c
 * Author:      Mike Carey
 * Date:        Jan. 10, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To Familiarize people with Logic gates.
 *
 */

#include "stdio.h"
#include "string.h"

  int count;            /* The total number of trys */
  int num_right;        /* The total number of right answers */
  char name[80];        /* His/Hers name */
  int endcount;         /* The total number of */

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

 main()
  {             /* This is the Main Menu of my program. */

   int option, x, y, clrscr;
   char opt[80];
   author();
   printf("HELLO THERE AND WELCOM TO LOGIGATE!\n");
   printf("Please type in your NAME: ");
   gets(name);

   for(x=0; x<10; x++) {        /* Time delay about 2 secs */
     for(y=0; y<30000; y++);
   }

   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("------> %s\n", name);
   printf("This program will use bit addition through logic gates to help\n");
   printf("you in under standing how logic gates work. You can learn\n");
   printf("that bit addition through logic gates can be under stood\n");
   printf("through Boolean Algerbra.");

		 /* These are the choices that people can make.  */
   clrscr = 0;
   printf(" Feel free to look around.\n");
   do {
     if(clrscr>=1) {
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     };
     clrscr++;
     printf("  Logigate MAIN MENU\n\n\n");
     printf("1. Pick a logic gate.\n");
     printf("2. Look at multiple logic gates.\n");
     printf("3. Design your own logic circuits.\n");
     printf("4. Exit Logigate.\n\n\n\n\n\n\n");
     do {
       printf("Enter your choice: ");
       gets(opt);
       option = atoi(opt);
     } while(option<1 || option>4);
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     switch(option) {
       case 1:                  /* Were the choices go to when chosen.  */
	pick_a_logic_gate();
	break;
      case 2:
	multi_logic_gates();
	break;
      case 3:
	/* own_logic_gates();  */ /* This part of code is disabled     */
	printf("This function is not working now.\n");
	break;
      case 4:
	printf("%s, I hope that this program was of some help", name);
	printf(" for you. \n");
	break;
      }
   } while(option!=4);
 }

 author()
  {
   int g, w;
   char vrsion[10]="v 1.0a";

   printf("Logigate %s\n", vrsion);
   printf("\n\n                  By.\n");
   printf("                     Mike Carey.\n");
   printf("\n\n\n\n\n\n\n\n");
   for(g=0; g<10; g++) {        /* Time delay about 2 secs */
     for(w=0; w<30000; w++);
   }
 }

 pick_a_logic_gate()
  {
   int option2, clrscr;
   char opt[80];
   clrscr = 0;
   do {
     if(clrscr>=1) {
       printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     };
     clrscr++;
     printf("These are the avalible logic gates. You will be able\n");
     printf("to look at and test the gates your self. The Boolean\n");
     printf("equation will be exspressed.\n\n\n");
     printf("The gates are as follows.\n");
     printf("1. OR gate.\n");
     printf("2. NOR gate.\n");
     printf("3. XOR gate.\n");
     printf("4. XNOR gate.\n");
     printf("5. AND gate.\n");
     printf("6. NAND gate.\n");
     printf("7. NOT / Inverter.\n");
     printf("8. Back to Main Menu.\n");
     printf("\n\n\n\n\n\n");
     do {
       printf("Please Enter in Your Choice: ");
       gets(opt);
       option2 = atoi(opt);
     } while(option2<1 || option2>8);
     printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
     switch(option2) {
       case 1:
	 gate_or();
	 break;         /* The different logical gates available. */
       case 2:
	 gate_nor();
	 break;
       case 3:
	 gate_xor();
	 break;
       case 4:
	 gate_xnor();
	 break;
       case 5:
	 gate_and();
	 break;
       case 6:
	 gate_nand();
	 break;
       case 7:
	 gate_not();
	 break;
       case 8:
	 break;
       }
     } while(option2!=8);
 }

 gate_or()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", orgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate OR.\n\n");
       testor();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate OR.\n\n");
       testor();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testor()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int b, a, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     b = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     a = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", b, a);
     printf("The answer is:%d\n\n", b || a);
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", orgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 gate_nor()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", norgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate NOR.\n\n");
       testnor();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate NOR.\n\n");
       testnor();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }


 testnor()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int b, a, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     b = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     a = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", b, a);
     printf("The answer is:%d\n\n", !(b || a));
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", norgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 gate_xor()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", xorgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate XOR.\n\n");
       testxor();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate XOR.\n\n");
       testxor();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testxor()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int d, c, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     d = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     c = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", d, c);
     printf("The answer is:%d\n\n", xor(d, c));
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", xorgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 xor(int b, int a)
  {
    return (b || a) && !(b && a);
 }

 gate_xnor()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", xnorgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate XNOR.\n\n");
       testxnor();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate XNOR.\n\n");
       testxnor();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testxnor()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int d, c, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     d = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     c = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", d, c);
     printf("The answer is:%d\n\n", xnotor(d, c));
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", xnorgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 xnotor(int b, int a)
  {
   return !((b || a) && !(b && a));
 }

 gate_and()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", andgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
     printf("Ok, The logic gate AND.\n\n");
       testand();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate AND.\n\n");
       testand();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testand()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int b, a, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     b = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     a = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", b, a);
     printf("The answer is:%d\n\n", b && a);
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", andgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 gate_nand()
  {

   char input[80];
   int i, l;

   for(l=0; l<6; l++) {         /* This statement prints the information */
     printf("%s", nandgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A or B.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate NAND.\n\n");
       testnand();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate NAND.\n\n");
       testnand();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testnand()
  {
   char numb[80], numa[80], end[80], leave[4]="YES";
   int b, a, i, l;

   printf("Enter in the bit data for A and B. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the B's data bit number: ");
     gets(numb);
     b = atoi(numb);
     printf("Enter in the A's data bit number: ");
     gets(numa);
     a = atoi(numa);
     printf("Your input for B was:%d\nYour input for A was:%d\n", b, a);
     printf("The answer is:%d\n\n", !(b && a));
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<6; l++) {
	 printf("%s", nandgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
 }

 gate_not()
  {

   char input[80];
   int i, l;

   for(l=0; l<4; l++) {         /* This statement prints the information */
     printf("%s", notgate[l]);   /* stored to the pointer called orgate.  */
   }
   do {
     printf("Do you want to try inputting data into A.?\n");
     printf("Yes or No: ");
     gets(input);
     for(i=0; input[i]; i++) input[i] = toupper(input[i]);
     if(!strcmp(input, "YES")) {
       printf("Ok, The logic gate NOT.\n\n");
       testnot();
       printf("Back so soon?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "NO")) {
       printf("Ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "Y")) {
       printf("Ok, The logic gate NOT.\n\n");
       testnot();
       printf("Back already?! Well ok, Back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
     if(!strcmp(input, "N")) {
       printf("Ok, I'm sending you back to the Menu.\n\n");
       strcpy(input, "QUIT");
     }
   } while(strcmp(input, "QUIT"));
 }

 testnot()
  {
   char numa[80], end[80], leave[4]="YES";
   int a, i, l;

   printf("Enter in the bit data for A. All numbers are to be\n");
   printf("One's or Zero's. The logic table is available by typing\n");
   printf("'HELP'.\n");
   do {
     printf("Enter in the A's data bit number: ");
     gets(numa);
     a = atoi(numa);
     printf("Your input was:%d\n", a);
     printf("The answer is:%d\n\n", !(a));
     printf("Do you want to go back to the Menu YES/NO? ");
     gets(end);
     for(i=0; end[i]; i++) end[i] = toupper(end[i]);
     if(!strcmp(end, "HELP")) {
       for(l=0; l<4; l++) {
	 printf("%s", notgate[l]);
       }
     }
     if(!strcmp(end, "Y")) {
       strcpy(leave, end);
     }
   } while(strcmp(end, leave));
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
	 multi_level1();
	 break;
       case 3:
	 multi_level2();
	 break;
       case 4:
	 multi_level3();
	 break;
       case 5:
	 multi_level4();
	 break;
       case 6:
	 multi_level5();
	 break;
       case 7:
	 multi_level6();
	 break;
       case 8:
	 multi_level7();
	 break;
       case 9:
	 multi_level8();
	 break;
       case 10:
	 multi_level9();
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

 multi_level1()
  {
   printf("You have chosen three logic gate test.\n");
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
