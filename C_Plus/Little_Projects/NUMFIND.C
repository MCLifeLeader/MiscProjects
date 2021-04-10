/*
 * Program:     NUMFIND.EXE
 * Source:      numfind.c
 * Author:      Mike Carey
 * Date:        Nov. 11, 1994
 * Version:     1.0r
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To find number values from binary files
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 main(int argc, char *argv[])
  {
				      /* Variable declaration */
   int ch_bytent=0, user=1;
   long ch_byteln=0, i=0;
   double ch_bytedb=0;
   char input[80];

   FILE *fp1, *fp2;
   char ch;

   if(argc!=3) {
     printf("You forgot to enter a filename\n");
     exit(1);
   }

   printf("Enter in the the size of read structer: ");
   gets(input);
   user = atoi(input);

   if(user<=0) {
     user = 1;
   }

   if((fp1=fopen(argv[1], "rb"))==NULL) {       /* Opens the file from */
     printf("Cannot open file \"%s\"\n", argv[1]);  /* dos using name from */
     exit(1);                                   /* users command line. */
   }

   if((fp2=fopen(argv[2], "w+b"))==NULL) {
     printf("Cannot open file \"%s\"\n", argv[2]);
     exit(1);
   }

   rewind(fp1);
   fprintf(fp2,"All values are of int value.\n");
   i = 0;
   do {
     fread(&ch_bytent, sizeof(int), user, fp1);
     i++;
     fprintf(fp2,"%ld:%d\n", i, ch_bytent);
   } while(!feof(fp1));

   rewind(fp1);
   fprintf(fp2,"\n\n\nAll values are of long value.\n");
   i = 0;
   do {
     fread(&ch_byteln, sizeof(long), user, fp1);
     i++;
     fprintf(fp2,"%ld:%ld\n", i, ch_byteln);
   } while(!feof(fp1));

   fprintf(fp2,"End of file\n");

   fclose(fp1);          /* Closes the file opened from the users */
   fclose(fp2);
 }                      /* command line                         */
