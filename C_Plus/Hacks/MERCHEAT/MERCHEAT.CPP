/****************************************************************************
Program:    MERCHEAT.EXE
Output:     mercheat.obj
Source:     mercheat.cpp
Author:     Mike Carey
Date:       11-16-97
Last Mod:   11-16-97
Compiler:   Borland C++ 4.5

****************************************************************************
Comments:       This source code is public domain as long as my authorship
                  (Mike Carey) is in this file.
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//#define MYDEBUG 1
// version number
#define MERCHEAT "2.7.4"

   void   Write_MercMoneyinfo_Data(FILE *msf);
   int    Check_MercSave_File(FILE *msf);

#ifndef MYDEBUG
int main(int argc, char *argv[]);

int main(int argc, char *argv[])
#else
int main(void)
#endif
{
   int Version, option;
#ifndef MYDEBUG
   int FileOpen = 0;
#endif
   char opt[80];
   FILE *msf;
#ifndef MYDEBUG
   printf("NERCHEAT.EXE V%s\n", MERCHEAT);
   printf("MechWarrior 2 Mercenaries, (c) Activision & FASA corp\n");
   printf("MW 2 Mercs is a Trademark of FASA Cort.\n");

   if ( argc < 2 ) {
      do {
         printf("\n\n");
         printf("\tThis will only modify the Mechwarrior 2 Mercs Save game\n");
         printf("1. Open File\n");
         printf("2. Save Changes\n");
         printf("3. Quit with out Saving\n");
         do {
            printf("Enter your choice: ");
                                printf(":");
            gets(opt);
            option = atoi(opt);
         } while(option < 1 || option > 3);
         switch(option) {
            case 1:
               printf("Enter FileName: ");
               gets(opt);
               if( ( msf = fopen(opt, "r+b" ) ) == NULL ) {
                  printf("error opening file %s\n", opt);
                  break;
               }
               FileOpen = 1;
               Version = Check_MercSave_File(msf);
               break;
            case 2:
                  if( FileOpen ) {
                     if( ( Version == 1 ) ) {
                        Write_MercMoneyinfo_Data(msf);
                     }
                  }
                  else
                     printf("You forgot to open the file\n");
                  break;
            case 3:
               printf("Everyone likes a Cheater?! \n");
               break;
         }
      } while(option != 3);
   }
   else {
#endif
#ifndef MYDEBUG
      if( ( msf = fopen(argv[1], "r+b" ) ) == NULL ) {
         printf("error opening file %s\n", argv[1]);
#else
      if( ( msf = fopen("mersave1.sav", "r+b" ) ) == NULL ) {
#endif
         exit(1);
      }

      Version = Check_MercSave_File(msf);

      if( ( Version == 1 ) ) {
         Write_MercMoneyinfo_Data(msf);
      }
#ifndef MYDEBUG
   }
#endif
   return(0);
}

/* Make sure that the file opend is a real Mercs Save File */

int    Check_MercSave_File(FILE *msf)
{
   register int a, Hit;

   rewind(msf);

   char Header[6];
   char Header0[6]; // = { 00, FF, NULL

   Header0[0] = 0x00;
   Header0[1] = 0x01;
   Header0[2] = NULL;

   for(a=0; a<4; a++) {
      Header[a] = getc(msf);
   }

   for(a=0, Hit=0; a<4; a++)
   {
      if(Header0[a] == Header[a])
      {
         Hit++;
      }
   }

   if(Hit == 2) {
      return(1);
   }

   printf("Wrong Mercs Save Game file!!!!\n");
   return(0);
}

/* Write the Money data to disk (this section is hard coded) */

void   Write_MercMoneyinfo_Data(FILE *msf)
{
   rewind(msf);

   if(!fseek(msf, 0x12A, SEEK_SET)) {  // Money is located between Hex 0x12a and 0x12d
      putc(0x7F,msf);
      putc(0x7F,msf);
      putc(0x7F,msf);
      putc(0x7F,msf);
   }

   // money is now set near 2,100,000,000 credits
}


