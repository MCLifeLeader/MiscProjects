/*
 * Program:     CIVWRT.EXE
 * Source:      civwrt.c
 * Author:      Mike Carey
 * Date:        Nov. 17, 1994
 * Version:     1.0a
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Quick write data for civil#.sve files
 *
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 main(int argc, char *argv[])
  {
   long data_byte;              /* Variable declaration */
   int ch_byte;
   FILE *fp;
   char ch;

   if(argc!=3) {
     printf("You forgot to enter a filename\n");
     exit(1);
   }

   if((fp=fopen(argv[1], "r+b"))==NULL) {       /* Opens the file from */
     printf("Cannot open file \"%s\"\n", argv[1]); /* dos using name from */
     exit(1);                                   /* users command line. */
   }

   data_byte = 318;                     /* Seeks for the 318th byte in the */
   fseek(fp, data_byte, SEEK_SET);      /* file declared from the users   */
					/* command line */
   ch_byte = 48;        /* Byte to change to */
   ch = ch_byte;
   putc(ch, fp);        /* Changes the byte */

   ch_byte = 117;       /* Byte to change to */
   ch = ch_byte;
   putc(ch, fp);        /* Changes the byte */

   fclose(fp);          /* Closes the file opened from the users */
 }                      /* command line.                         */
