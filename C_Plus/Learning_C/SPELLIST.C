/*
 * Program:     SPELLIST.EXE
 * Source:      spellist.c
 * Author:      Mike Carey
 * Date:        Nov. 04, 1994
 * Modified:    Jan. 26, 1995
 * Version:     1.0Alfa
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To take a text data file of words and reorder them to
 *                make a randomly generated spelling list.
 */

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "string.h"

#define __MYOWN__  "Version 1.0 Alfa"

 main()
  {
   int a=0, b=0, c=0;
   long rwnd=0;
   char input1[80], input2[80], input3[80], holdword1[50], holdword2[50];
   FILE *fp1, *fp2, *fp3, *fp4;
   char ch = 0;

   printf("\t %s \n\t %s \n\n", __FILE__, __MYOWN__);
   printf("The code for this program was written by Michael Carey.\n");
   printf("This program is shareware and can be freely distrobuted.\n");
   printf("\n\n");
   printf("This program was created to generate a word list from a text file.\n");
   printf("\n\n\n");
   printf("Source file: ");
   gets(input1);
   printf("Alphbetical word list file: ");
   gets(input2);
   printf("Psydo random word list file: ");
   gets(input3);

   if((remove(input2)) == 1) {
     printf("Unable to remove %s\n", input2);
     exit(1);
   }
   if((remove(input3)) == 1) {
     printf("Unable to remove %s\n", input3);
     exit(1);
   }
   if((remove("templdat.a01")) == 1) {
     printf("Unable to remove templdat.a01");
     exit(1);
   }
   if((fp1 = fopen(input1, "rb")) == NULL) {
     printf("Unable to open/create file %s\n", input1);
     exit(1);
   }
   if((fp2 = fopen(input2, "w+")) == NULL) {
     printf("Unable to open/create file %s\n", input2);
     exit(1);
   }
   if((fp3 = fopen(input3, "w+")) == NULL) {
     printf("Unable to open/create file %s\n", input3);
     exit(1);
   }
   if((fp4 = fopen("templdat.a01", "w+")) == NULL) {
     printf("Unable to open/create file templdat.a01\n");
     exit(1);
   }

   printf("Processing sourcefile.\n");
   while(!feof(fp1)) {
     ch = getc(fp1);
     printf("r");

     if((ch > 31) && (ch < 123)) {
       holdword1[a] = ch;
       holdword1[a+1] = 0;
       a++;

       if((ch == 26) || (holdword1[a-1] == 32)) {
	 holdword1[a-1] = 0;
	 a = 0;
	 fprintf(fp4, "%s\n", holdword1);
	 printf("w");
       }
     }
   }

   printf("Removing duplicate words.\n");
   rewind(fp4);
   a = 0;
   b = 0;
   c = 0;

   while(!feof(fp4)) {
     fscanf(fp4, "%s", holdword1);
     printf("r");
     rwnd = 0;

     if(b == 0) {
       fprintf(fp3, "%s\n", holdword1);
       printf("w");
     }
     rewind(fp3);
     c = 1;
     while(!feof(fp3)) {
       if(b == 1) {
	 if(c == 1) {
	   rewind(fp3);
	 }
	 c = 0;
	 fscanf(fp3, "%s", holdword2);
	 printf("r");
	 if(stricmp(holdword1, holdword2)) {
	   rwnd++;
	   if(fseek(fp3, rwnd, SEEK_CUR)) {
	     printf("seek error\n");
	     exit(1);
	   }
	   a = 0;
	 }
	 else {
	   a = 1;
	 }
       }

       else {
	 rwnd++;
	 if(fseek(fp3, rwnd, SEEK_CUR)) {
	   printf("seek error\n");
	   exit(1);
	 }
       }
     }
     if(a == 1) {
       fprintf(fp3, "%s\n", holdword1);
       printf("w");
     }
     b = 1;
   }


   printf("Alphebetizing word list.\n");
   rewind(fp3);

   while(!feof(fp3)) {
     fscanf(fp3, "%s", holdword1);
     printf("r");
     rewind(fp2);
     do {
       fscanf(fp2, "%s", holdword2);
       printf("r");
       rwnd = strlen(holdword2);
       if(stricmp(holdword1, holdword2) == 1) {
	 if(fseek(fp2, -rwnd, SEEK_CUR)) {
	   printf("Seek error 1.\n");
	   exit(1);
	 }
	 rwnd = 1;
	 fprintf(fp2, "\n");
	 printf("w");
	 if(fseek(fp2, -rwnd, SEEK_CUR)) {
	   printf("Seek error 2.\n");
	   exit(1);
	 }
	 fprintf(fp2, "%s\n", holdword1);
	 printf("w");
       }
     } while(!feof(fp2));
   }
   fclose(fp1);
   fclose(fp2);
   fclose(fp3);
   fclose(fp4);
   remove("templdat.a01");
   printf("Spelling list creation process compleate.\n");
   printf("Your output files are %s and %s.\n", input2, input3);
 }
