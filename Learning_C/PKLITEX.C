/*
 * Program:     PKLITEX.EXE
 * Source:      pklitex.c
 * Author:      Mike Carey
 * Date:        Mar. 12, 1994
 * Version:     1.0r
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To make pklited programs unexstractable.
 *
 */
 /************************************************************************
 *      This source code has been freely distrobuted for the use of those
 * who might find this useful. Your use of this program and source code
 * is up to your discression. I only require that my name in part or full
 * NOT be removed from any documentation nor the compiled or uncompiled
 * operational versions being used. If you have questions you can contact
 * me at.
 *              Mike Carey
 *              37104 Sagebrush Pl.
 *              Kennewick, Wa. 99337
 *
 *              Phone#: 509-627-7705
 *
 ************************************************************************/

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
     printf("\n       PKLITEX.EXE     v1.0release\n\n");
     printf("  This program makes the non registered pklited *.exe files \n");
     printf("unexstractable. This program can be freely distrobuted. \n");
     printf("The version requirements are of the 1990-1992 pklite \n");
     printf("version 1.15   7-30-92   using this program on other pklited *.exe files \n");
     printf("could cause damage to the original file. I take no \n");
     printf("responsibilty for the missuse or inability to use this \n");
     printf("software.\n\t\t\t\t\tMike Carey\n");
     printf("\t usage:  \"PKLITEX \[filename.exe\] w\"\n");
     exit(1);
   }

   /* if(argc!=3) {
     printf("You forgot to enter a filename\n");
     exit(1);
   } */

   if((fp=fopen(argv[1], "r+b"))==NULL) {       /* Opens the file from */
     printf("Cannot open file \"%s\"\n", argv[1]);    /* dos using name from */
     exit(1);                                   /* users command line. */
   }

   data_byte = 28;                      /* Seeks for the 28th byte in the */
   fseek(fp, data_byte, SEEK_SET);      /* file declared from the users   */
					/* command line */
   ch_byte = 20;        /* Byte to change to */
   ch = ch_byte;
   putc(ch, fp);        /* Changes the byte */

   ch_byte = 49;        /* Byte to change to */
   ch = ch_byte;
   putc(ch,fp);         /* Changes the byte */

   fclose(fp);          /* Closes the file opened from the users */
 }                      /* command line.                         */
