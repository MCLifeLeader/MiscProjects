
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

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

 main()
  {             /* This is the Main Menu of my program. */

   int option, x, y, clrscr, l, stop=1;
   char opt[80];
   FILE *fp;

   fp=fopen("data.dat", "w+");
     for(l=0; l<6; l++) {
       fputs(orgate[l], fp);
     }
     for(l=0; l<6; l++) {
       fputs(norgate[l], fp);
     }
     fclose(fp);
  }
