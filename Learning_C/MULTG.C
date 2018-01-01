

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

 int count;
 int xfer;
 int num_right;
 int endcount;
 int endcount2;
 int num_right2;
 char name[80];

  char *lvl1[] = {
    "The format for 3 logic gates will be.\n",
    "=LG1--v\n",
    "      ==LG3-- = Answer.\n",
    "=LG2--^\n"
  };

 main()
  {
   lv1();
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
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };
     };
     if(x == 3 || x == 4) {
       printf("==NOR--");
       inpt_nor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     if(x == 5 || x == 6) {
       printf("==XOR--");
       inpt_xor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     if(x == 7 || x == 8) {
       printf("==NXOR-");
       inpt_nxor();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     if(x == 9 || x == 10) {
       printf("==AND--");
       inpt_and();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     if(x == 11 || x == 12) {
       printf("==NAND-");
       inpt_nand();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     if(x == 13 || x == 14) {
       printf("==NOT--");
       inpt_not();

       if(build=1) {
	 printf("v\n");
	 a1 = xfer;
       };

       if(build=3) {
	 printf("^\n");
	 b1 = xfer;
       };

       if(build=2) {
	 printf("- = Answer.\n");
	 c1 = xfer;
       };

     };

     build++;
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


 inpt_or()
  {
   printf("In inpt_or\n");
 }

 inpt_nor()
  {
   printf("In inpt_nor\n");
 }

 inpt_xor()
  {
   printf("In inpt_xor\n");
 }

 inpt_nxor()
  {
   printf("In inpt_xnor\n");
 }

 inpt_and()
  {
   printf("In inpt_and\n");
 }

 inpt_nand()
  {
   printf("In inpt_nand\n");
 }

 inpt_not()
  {
   printf("In inpt_not\n");
 }
