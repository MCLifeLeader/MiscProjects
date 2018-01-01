/* A greeting for cotton when He gets to home to use the computer */
/* Written by Mike Carey */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 main()
  {
   char cls[80], dir[80], input[80];
   char cd[80], md[80], copy[80], telix[80];
   char a[80], b[80], c[80], d[80];
   char leave[]="exit";
   int x, y, z;

   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

   do {
     printf("D:\\>");
     gets(input);               /* This is were I execute the joke */
     if(!strcmp(input, "cls")) {
       printf("I'm NOT going to clear the screen for you sucker\n");
     }
     if(!strcmp(input, "dir")) {
       printf("List what directory there are none. ha ha ha\n");
     }
     if(!strcmp(input, "cd")) {
       printf("Change to what Directory\n");
     }
     if(!strcmp(input, "md")) {
       printf("I didn't know you knew how to make directories\n");
     }
     if(!strcmp(input, "copy")) {
       printf("Copy what! I feel Violated, because you used me in a way\n");
       printf("that I didn't like hands off!!!\n");
     }
     if(!strcmp(input, "a:")) {
       printf("There is no disk in A drive!!\n");
     }
     if(!strcmp(input, "b:")) {
       printf("Thre is no disk in B drive silly.\n");
     }
     if(!strcmp(input, "c:")) {
       printf("Ha thats funny I really thought there was something here?\n");
     }
     if(!strcmp(input, "d:")) {
       printf("Now why would I let you in a drive that");
       printf(" you are already on?\n");
     }
     if(!strcmp(input, "telix")) {
       printf("Were not home, if you would please leave your");
       printf(" name and number\n");
       printf("After the BEEEP!!.........BEEEEEEP...BEEEEP....");
       printf("BEEEEEEEAAAAEEAP\n");
     }
     if(!strcmp(input, input)) {
       printf("I do only what I want NAA NAA NAA\n");
     }
   } while(strcmp(input, leave));
}
