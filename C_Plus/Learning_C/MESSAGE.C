/* Message that will self destruct after it has executed */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 main()
  {
   int x, y, z;
   long w;              /* Variable Declaration */
   FILE *fp;
   char ch;

   system("del message.exe\n");

   if((fp = fopen("message.exe", "a+b"))==NULL) {
     printf("Error handling file\n");
     system("del message.exe\n");
     exit(1);
   }

   for(w=0; w<=40000; w++) {
     x++;

     z = x;
     y = ((x+y)/2)+z;
     x = ((x+y)/2)+z;
     ch = x;

     if(x>=255) {
       x = 0;
     }

     /* printf("%d \n", ch); */
     putc(ch, fp);
   }
   system("del message.exe\n");

   for(w=0; w<=200; w++) {
     printf("Get your act in gear! Else you'll loose it!!!!\n");
   }
   printf("\n\n\nYour assentation WILL happen on schedule DAVID O'TOOL!!\n");
   printf("Your choice, Move it!, or loose it!!!.\n");
   printf("1\) Resign your Commission!\n");
   printf("2\) Quit I.S.S.!   :-\(\n");
   printf("3\) Or be assassinated!\n");
   printf("\n\n\t It is your choice.....  :-\)\n");
   printf("\n\n\t\t\t\tBye..........\n");
   printf("\n\n\n\t\t\t\t\t\t\tThe Group.\n");
 }
