/* Test of I/O with Disk program called lgates.exe */

#include "stdio.h"
#include "string.h"

 main()
  {
   char runit[80];

   do {
     printf("Going to open the file lgates.exe for reading\n");
     printf("Type in GO: ");
     gets(runit);
     if(!strcmp(runit, "GO")) {
       exicute();
     }
   } while(strcmp(runit, "EXIT"));
 }

 exicute()
  {
   FILE *fp;
   int b;

   printf("In exicute block of code.\n");
   fp = fopen("lgates.exe", "rb");
   fclose(fp);
  }

