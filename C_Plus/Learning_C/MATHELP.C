/*
 * Program:     MATHELP.EXE
 * Source:      mathelp.c
 * Author:      Mike Carey
 * Date:        Aug. 11, 1994
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To help a friend learn basic math
 *
 */

#include "stdio.h"

 main()
  {
   int x;
   char input[80];
						/* Main menu */
   do {
     printf("\t\t\t!!!Main menu!!!\n\n\n\n");
     printf("1. About this program.\n");
     printf("2. Learn the materials\n");
     printf("3. Get a quiz on the materials\n");
     printf("4. Quit....\n");
     do {
       printf("Enter your selection: ");        /* Choice entered here */
       gets(input);
       x = atoi(input);
     } while(x<1 || x>4);
     switch(x) {                                /* To jump from one area */
       case 1:                                  /* to the next */
	 about_this_program();
	 break;
       case 2:
	 learn_the_materials();
	 break;
       case 3:
	 get_quized();
	 break;
       case 4:
	 printf("Good Bye\n");
	 break;
     }
   } while(x!=4);
 }

 /* Short discription of what the program is trying to do for the user */

 about_this_program()
  {
   printf("This program was desgned in order to teach people basic math so \n");
   printf("that they might be able to progress in school and achieve the scores that \n");
   printf("deserve in math. This program is not fancey but will educate you in \n");
   printf("basic uses of addition, subtraction, multiplication, and devision. \n");
   printf("I hope that this program will be of some use to you....\n");
   printf("\t\t\t\t\t Sincerly the programmer\n\n\n\n\n\n");
   printf("This program was written by Mike Carey\n");
   while(!kbhit());
 }

 /* Sub menu program on the learning of the materials */

 learn_the_materials()
  {
   int x;
   char input[80];

   do {
     printf("\t\t\t Learn the materials\n\n\n\n");
     printf("1. Addition\n");
     printf("2. Subtraction\n");
     printf("3. Multiplication\n");
     printf("4. Devision\n");
     printf("5. Back to main menu...\n");
     do {
       printf("Enter in your selection: ");
       gets(input);
       x = atoi(input);
     } while(x<1 || x>5);
     switch(x) {
       case 1:
	 l_add();
	 break;
       case 2:
	 l_sub();
	 break;
       case 3:
	 l_mult();
	 break;
       case 4:
	 l_dev();
	 break;
       case 5:
	 printf("Back to main menu.....\n\n\n\n\n");
	 break;
     }
   } while(x!=5);
 }

 /* Quiz time...  This is a menu for different quiz types.. */

 get_quized()
  {
   int x;
   char input[80];

   do {
     printf("\t\t\t Quiz Time.... \n\n\n\n");
     printf("1. Addition \n");
     printf("2. Subtraction \n");
     printf("3. Multiplication \n");
     printf("4. Devision \n");
     printf("5. Back to main menu...\n");
     do {
       printf("Enter your selction: ");
       gets(input);
       x = atoi(input);
     } while(x<1 || x>5);
     switch(x) {
       case 1:
	 q_add();
	 break;
       case 2:
	 q_sub();
	 break;
       case 3:
	 q_mult();
	 break;
       case 4:
	 q_dev();
	 break;
       case 5:
	 printf("Back to main menu.....\n\n\n\n\n\n");
	 break;
     }
   } while(x!=5);
 }

 /* The next four main blocks of code will be for the learning of the math
    that people will need to study on. */

 l_add()
  {
   printf("l_add block of code\n");

 }

 l_sub()
  {
   printf("l_sub block of code\n");

 }

 l_mult()
  {
   printf("l_mult block of code\n");

 }

 l_dev()
  {
   printf("l_dev block of code\n");

 }

 /* The next four main blocks of code will be for the quizing of the person
    who will be using the program to learn about math. */

 q_add()
  {
   printf("q_add block of code\n");

 }

 q_sub()
  {
   printf("q_sub block of code\n");

 }

 q_mult()
  {
   printf("q_mult block of code\n");
 }

 q_dev()
  {
   printf("q_dev block of code\n");

 }











 /*  This is the end of my program */




