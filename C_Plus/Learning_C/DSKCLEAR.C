/*
 * Program:     DSKCLEAR.EXE
 * Source:      dskclear.c
 * Author:      Mike Carey
 * Date:        04-24-94
 * Version:     1.0alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Security clear a disk drive
 *
 */

#include "stdio.h"
#include "dos.h"
#include "graph.h"
#include "string.h"
#include "stdlib.h"

 main()
  {
   int a, b, c;
   int l, s, w, x, y, z;  /* Creation of the variable boxes */
   char input[80], inpti[80], data1[80], data2[80], data3[80];
   char data4[80], data5[80];
   char *cleardrv[] = {
     "y\n",
     "\n",
     "n\n"
   };
   FILE *fp1, *fp2, *fp3;
   char inpt;

   printf("\t\t * * * WARNING * * *\n");
   printf("This program will wipe every thing off from the selected drive.\n");
   printf("Everything on the disk that is wiped will be unrecoverable\n");
   printf("\n\n\tEnter in a drive letter A --> Z: ");
   gets(input);
   strcpy(data5, input);
   for(a=0; input[a]; a++) input[a]=toupper(input[a]);


   strcpy(data1, "runit.bat");
   strcpy(data2, "inpts.dat");
   strcpy(data3, " /u/q < inpts.dat");
   strcpy(data4, "format ");

   strcat(input, data2);
   if((fp3=fopen(data5, "w"))==NULL) {
     printf("cannot open file %s\n", input);
     exit(1);
   }

   for(a=0; cleardrv[a]; a++) {
     putc(cleardrv[a], fp3);
   }
   fclose(fp3);

   printf("This will format the diskdrive using dos's format utility\n");
   printf("If you wish to continue enter Y to quit enter N\n");
   gets(inpt);
   if(inputi=="N") {
     exit();
   }

   if((fp1=fopen(data1, "w"))==NULL) {
     exit(1);
   }

   b=0;
   c=0;

   printf("Now wipeing drive %c\n", input);
   printf("To stop press any key\n");

   if((fp2 = fopen(filestring, "a+b"))==NULL) {
     printf("cannot open file %s\n", fp2);
     exit(1);
   }

   w = 0;
   do {
     w++;
     b++;
     if(b==20000) {
       b = 0;
       c++;
       _moveto(10,30);
       printf("%d", c);
     }

     if(w>=255) {
       w = 0;
     }                  /* Logarithm to create the junk data */
     inpt = w;
     /* printf("%d \n", inpt); */
     putc(inpt, fp2);

     x = ((w+x+y)/3)+z;
     inpt = x;
     /* printf("%d \n", inpt); */
     putc(inpt, fp2);

     y = ((w+x+y)/3)+x;
     inpt = y;
     /* printf("%d \n", inpt); */
     putc(inpt, fp2);

     z = ((w+x+y)/3)+y;
     inpt = z;
     /* printf("%d \n", inpt); */
     putc(inpt, fp2);

   } while(!kbhit());
   fclose(fp2);                  /* Closeing of the file pointer */
   remove(filestring);
 }



