/*
 * Program:     INSTLGAM.EXE (will vary depending on the game used.)
 * Source:      instlgam.c
 * Author:      Mike Carey
 * Date:        05-11-94
 * Version:     1.0b
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     Game installation/play/de-installation of game
 *              for lemmings game.
 *
 */

  /* My include files */
#include "stdio.h"
#include "direct.h"
#include "stdlib.h"
#include "string.h"
			/* version data */
#define VERSN "\t\t\tv1.0b Mike Carey, 1994\n"

 main()
  {
   int a;               /* Variable data */
   char input[80];

		/* Version Id. */
   printf(VERSN);       /* Print version information */
   printf("\n\n");
   system("set break=off");
   system("c:");

   do {                 /* Get user input */
     printf("Do you want to install this game, Y/N: ");
     gets(input);               /* Change to upper case letters */
     for(a=0; input[a]; a++) input[a] = toupper(input[a]);

		/* user choice of yes or no */
     if((!strcmp(input, "Y")) || (!strcmp(input, "YES"))) {
       printf("\n\t continuing xtraction.\n");
       xstract_game();   /* goto xstract_game() block of code */
       exit(0);
     }                  /* User choice to quit */
     if((!strcmp(input, "N")) || (!strcmp(input, "NO"))) {
       printf("\n\t quitting xtraction.\n");
       exit(0);         /* Exit command to quit */
     }
   } while(a!=-5);
 }
	/* xstract_game() block of code. This block of code extracts */
	/* Arj compressed files specifically for the lemmings game */
 xstract_game()
  {
   int a, b, w, x, y, z;        /* Variables */
   char input[80], drive[80];
   char inpt[] = {
     "y\n"
   };
			/* File pointer variables */
   FILE *fp, *fp2;
   char ch;

   do {
     b = 0;
     printf("Drive letter installing from A,B,C: ");
     gets(drive);                       /* Change words to uppercase */
     for(a=0; drive[a]; a++) drive[a] = toupper(drive[a]);

			/* Gets Drive from user to install from. */
     if((!strcmp(drive, "C")) || (!strcmp(drive, "C:"))) {
       printf("Installing from C-Drive...\n");
       b = 1;           /* The variable switch */

       do {             /* get user input if they want to continue */
			/* or if they wish to stop and make a */
			/* duplicate of there file */
	 printf("\n\n this will delete your original from C-Drive\n");
	 printf("Do you wish to continue Y/N: ");
	 gets(input);
	 for(a=0; input[a]; a++) input[a] = toupper(input[a]);

	 if((!strcmp(input, "Y")) || (!strcmp(input, "YES"))) {
	   printf("Continuing...\n");
	   a = -5;      /* Continue switch */
	 }
	 if((!strcmp(input, "N")) || (!strcmp(input, "NO"))) {
	   printf("Quitting...\n");
	   exit(0);     /* Exit command quit program */
	 }
       } while(a != -5);
			/* Copy lemmings.arj c:\ and set b variable */
			/* switch for drive install */
       system("copy c:lemmings.arj c:\\ > nul");
       if(system("del c:lemmings.arj > nul") == -1) {
	 printf("Error deleting file...\n");
	 exit(0);
       }
       /* printf("%d 1\n", b); */
     }
			/* To set b variable switch for drive install */
     if((!strcmp(drive, "B")) || (!strcmp(drive, "B:"))) {
       printf("Installing from B-Drive...\n");
       b = 2;           /* The variable switch */
       /* printf("%d 2\n", b); */
     }
			/* To set b variable switch for drive install */
     if((!strcmp(drive, "A")) || (!strcmp(drive, "A:"))) {
       printf("Installing from A-Drive...\n");
       b = 3;           /* The variable switch */
       /* printf("%d 3\n", b); */
     }
   } while(b==0);

   system("c:");        /* Makes the directories c:\games\lemmings */
   system("cd\\");
			/* Make dir games if not there */
   if(mkdir("games") == -1) {
     printf("Directory already exists\n");
   }                    /* Change dir to games */
   chdir("games");
			/* Make dir lemmings */
   if(mkdir("lemmings") == -1) {
     printf("Error making directory.\n");
   }
			/* Change dir to lemmings */
   chdir("lemmings");
			/* Variable switch used to change drives */
   if(b==1) {
     /* printf("%d 1", b); */
     system("c:");
     system("copy c:\\lemmings.arj c:\\games\\lemmings > nul");
     if(system("del c:\\lemmings.arj > nul") == -1) {
       printf("Error deleting file...\n");
       exit(0);
     }
   }
			/* Variable switch used to change drives */
   if(b==2) {
     /* printf("%d 2", b); */
     system("b:");
   }
			/* Variable switch used to change drives */
   if(b==3) {
     /* printf("%d 3\n", b); */
     system("a:");
   }

   system("arj x -g? lemmings c:");     /* extracting of lemmings game */
   system("c:");                        /* from arj compressed file */
   system("vgalemmi.exe");
				/* Creates delete data file */
   if((fp = fopen("config.dat", "a"))==NULL) {  /* Dir wipe info */
     printf("Error handling file remove.dat\n");
     exit(1);
   }

   for(a=0; inpt[a]; a++) putc(inpt[a], fp);
   fclose(fp);

   system("attrib *.* -h -r");  /* file attribute changer */
   system("del *.* < config.dat > nul");      /* Deleting of files */
				/* The files that are to be wiped */
   if((fp = fopen("vgalemmi.exe", "a+b"))==NULL) {
     printf("Error handling file.\n");
     system("del *.exe");
     exit(1);
   }                            /* The files that are to be wiped */
   if((fp = fopen("egalemmi.exe", "a+b"))==NULL) {
     printf("Error handling file.\n");
     system("del *.exe");
     exit(1);
   }
			/* This sets the wipefile size */
   for(a=0; a>10000; a++) {
     w++;

     if(w>=255) {
       w = 0;
     }                  /* Logarithm to create the junk data */
     ch = w;            /* for wiping the exe file or files. */
     /* printf("%d \n", ch); */
     putc(ch, fp);
     putc(ch, fp2);

     x = ((w+x+y)/3)+z;
     ch = x;
     /* printf("%d \n", ch); */
     putc(ch, fp);
     putc(ch, fp2);

     y = ((w+x+y)/3)+x;
     ch = y;
     /* printf("%d \n", ch); */
     putc(ch, fp);
     putc(ch, fp2);

     z = ((w+x+y)/3)+y;
     ch = z;
     /* printf("%d \n", ch); */
     putc(ch, fp);
     putc(ch, fp2);

   }
   fclose(fp);                  /* Closing of the file pointer */
   fclose(fp2);

   remove("vgalemmi.exe");      /* Removing of the two wiped files */
   remove("egalemmi.exe");

   chdir("..");                 /* Changing dir to .. */
   rmdir("lemmings");           /* Removing dir lemmings */
   chdir("\\");                 /* Changing dir to c:\ (root dir) */

 }

