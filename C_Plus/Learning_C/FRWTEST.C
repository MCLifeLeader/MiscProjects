
#include "stdio.h"
#include "stdlib.h"

 main()
  {
   FILE *fp;
   double d = 12.24;
   int i = 101;
   long l = 123023L;

   if((fp=fopen("test", "wb+"))==NULL) {
     printf("cannot open file\n");
     exit(1);
   }

 /*  fwrite(&d, sizeof(double), 1, fp); */
   fwrite(&i, sizeof(int), 1, fp);
 /*  fwrite(&l, sizeof(long), 1, fp); */

   rewind(fp);

   /* fread(&d, sizeof(double), 1, fp); */
   fread(&i, sizeof(int), 1, fp);
   /* fread(&l, sizeof(long), 1, fp); */

   printf("%d", i);
   fclose(fp);
  }

