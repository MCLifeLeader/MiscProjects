/*
 * Program:     LOGNAME.EXE
 * Source:      logname.c
 * Author:      Mike Carey
 * Date:        April 11, 1994
 * Version:     1.0 RELEASE VERSION
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Specific design for the use with the Lantastic Network.
 *
 */
				    /* My include files */
#include "stdio.h"
#include "string.h"
#include "direct.h"

 main()
  {                                 /* Variable declarations */
   int l;
   char input[80];
   char setenv1[80];
   FILE *fp;                        /* Setting pointer for read/write files */

   printf("Username: ");            /* User Enters His/Hers name */
   gets(input);
   strcpy(setenv1, "set name=");    /* Environment settings */
   strcat(setenv1, input);

   system("cd \\");                 /* Creation of the directory NETVARS */
   if(mkdir("netvars") == -1) {
     l = 1;
   }
				    /* Creation of the file NETVARG.BAT */
				    /* for read/write */
   if((fp = fopen("c:\\netvars\\setvarg.bat", "w+"))==NULL) {
     printf("Error handling file setvarg.bat\n");
     exit(1);                       /* File error handler exit program */
   }
				    /* Resetting the point in the file to */
   rewind(fp);                      /* the beginning */
   fputs(("echo off\n"), fp);       /* The data being sent to the file */
   fputs(("%s",setenv1), fp);       /* setvarg.bat. The information in */
   fclose(fp);                      /* setenv1 is variable changeable  */
				    /* dealing with the change of a users */
				    /* name or login message. */
 }

