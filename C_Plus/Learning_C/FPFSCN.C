
/* A siple accounts payable database using fscanf() and fprinf() */

#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"
#include "ctype.h"

 void add_acct(void), lookup(void);
 int menu(void);

 main()
  {
   char choice;

   do {
     choice = menu();
     switch(choice) {
       case 'a':
	 add_acct();
	 break;
       case 'l':
	 lookup();
	 break;
     }
   } while (choice != 'q');
 }

  /* Display menu and get request. */
 menu(void)
  {
   char ch;
   do {
     printf("\(A\)dd, \(L\)ookup, or \(Q\)uit: ");
     ch = tolower(getche());
     printf("\n");
   } while((ch != 'q') && (ch != 'a') && (ch != 'l'));
   return ch;
 }

  /* Add an account and balance to the database. */
 void add_acct(void)
  {
   FILE *fp;
   char name[80];
   double balance;

   /* open it for append */
   if((fp=fopen("acct.dat", "a"))==NULL) {
     printf("Cannot open file\n");
     exit(1);
   }

   printf("Enter name and balance: ");
   fscanf(stdin, "%s%lf", name, &balance);
   fscanf(stdin, "%*c"); /* remove CR from input stream */

   /* write to file */
   fprintf(fp, "%s %lf\n", name, balance);
   fclose(fp);
 }

  /* Report balance given name. */
 void lookup(void)
  {
   FILE *fp;
   char name[80], name2[80];
   double balance;

   /* open it for read */
   if((fp=fopen("acct.dat", "r")) == NULL) {
     printf("Cannot open file\n");
     exit(1);
   }

   printf("Name? ");
   gets(name);

   /* look for account and balance */
   while(!feof(fp)) {
     fscanf(fp, "%s%lf", name2, &balance);
     if(!strcmp(name, name2)) {
       printf("%s: $%7.2lf\n", name, balance);
       break;
     }
   }
   fclose(fp);
 }

