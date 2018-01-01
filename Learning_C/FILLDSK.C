
  /* Program to create a file to fill up with junk data */

  /* My include files */
#include "stdio.h"
#include "string.h"
#include "direct.h"

 main()  /* The start of my program */
  {
   int l, s, w, x, y, z;  /* Creation of the variable boxes */
   long a;
   FILE *fp;  /* File Pointer */
   char inpt;
	      /* Creation of the data file */
   if((fp = fopen("filit.dat", "a+b"))==NULL) {
     printf("Error handling file \n");
     exit(1);
   }

   a = 0;
   s = 0;
   w = 0;
   do {
     a++;
     w++;

     if(a >= 1024000) {
       s++;
       fclose(fp);
       if((fp = fopen("filit.dat", "a+b"))==NULL) {
	 printf("Error handling file\n");
	 exit(1);
       }
     }

     if(w >= 255) {
       w = 0;
     }                  /* Logarithm to create the junk data */
     inpt = w;
     /* printf("%d \n", inpt); */
     putc(inpt, fp);

     x = ((w+x+y)/3)+z;
     inpt = x;
     /* printf("%d \n", inpt); */
     putc(inpt, fp);

     y = ((w+x+y)/3)+x;
     inpt = y;
     /* printf("%d \n", inpt); */
     putc(inpt, fp);

     z = ((w+x+y)/3)+y;
     inpt = z;
     /* printf("%d \n", inpt); */
     putc(inpt, fp);

   } while((!kbhit()) || (s != 50));
   fclose(fp);                  /* Closeing of the file pointer */
 }


