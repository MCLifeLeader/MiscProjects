/*
 * Program:     ENCRYPT.EXE
 * Source:      encrypt.c
 * Author:      Mike Carey
 * Date:        04-05-94
 * Version:     1.0a
 * Language:    Ansi C   MicroSoft Quick C
 * Purpose:     To be able to encrypt and dencrypt data
 *
 */
  /* My include files */
#include "stdio.h"
#include "direct.h"
#include "graph.h"
#include "stdlib.h"
#include "string.h"

#define VERSN "\t\t\tv1.0a Mike Carey, 1994\n"

 main()
  {
   printf(VERSN);          /* disclamer */
   printf("\tWARNING!!!!  This program is experimental if you do not know\n");
   printf("the dencryption password you could loose all data that was\n");
   printf("encrypted.\n\n");
   printf("\tThis program uses a simple but effective encryption methode\n");
   printf("the encryption methode will be descussed in the documentation\n");
   printf("provided with this program.\n");
   while(!kbhit());
   _setvideomode(_ERESCOLOR);   /* Clear the Screen */
   _setvideomode(_DEFAULTMODE);
   printf("Be sure that you are in the same drive and directory of the\n");
   printf("file that you want to be encrypted......\n\n\n");

   get_file();
   get_password();
   encrypt();
   wipe_file();
 }

 get_file()
  {
   int *flag;
   char *input[80];
   FILE *fp;

   printf("Enter file Name: ");
   gets(*input);
   if((fp = fopen(*input, "rb"))==NULL) {
     printf("Error opening file %s\n", input);
     exit(1);
   }
   fclose(fp);
   *flag = 1;
 }


 get_password()
  {
   int *flag;
   char *input[80];
   char *password1[80], *password2[80];

   if(*flag==1) {
     do {
       printf("Enter password: ");
       gets(*password1);
       printf("Enter password: ");
       gets(*password2);
       if(strcmp(*password1, *password2)) {
	 printf("Passwords do not match.\n");
	 *flag = 0;
       }
       else {
	 *flag = 1;
       }
     while(*flag!=0);
   }
 }

 encrypt()
  {
   int *flag, x, y, z;
   char inpt[80], *input[80];
   char *password1[80], *password2[80]


 }

 wipe_file()
  {

 }
