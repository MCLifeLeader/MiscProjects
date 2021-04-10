/****************************************************************************
Program:    DSCHEAT2.EXE
Output:     dscheat2.obj
Source:     dscheat2.cpp
Author:     Mike Carey
Date:       01-26-96
Last Mod:   08-30-97
            04-10-21
Compiler:   Borland C++ 4.5

****************************************************************************
Comments:       This source code is public domain as long as my authorship
                  (Mike Carey) is in this file.
****************************************************************************/
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
using namespace std;

// Suppressing the deprectation warning related to the use of 'fopen()'
#pragma warning(disable : 4996)

// version number
#define DSCHEATR "2.1.9"

void   Write_Descent1_Data(FILE* dsf, int MainW);
void   Write_Descent2_Data(FILE* dsf, int MainW);
int    Check_Descent_Version(FILE* dsf);
int    Check_Descent2_NetGame(char*);

int NetGame = 0;
int Players = 0;

int main(int argc, char* argv[]);

int main(int argc, char* argv[])
{
   int Version, option, LaserLevel = 0, FileOpen = 0;
   char opt[80];
   FILE* dsf = NULL;

   printf("DSCHEATR.EXE V%s\n", DSCHEATR);
   printf("Descent1 and Descent2 (c) 1995 and 1996 Parallax Software\n");
   printf("Descent is a Trademark of Interplay Productions.\n");

   if (argc > 1)
   {
      NetGame = Check_Descent2_NetGame(argv[1]);
   }

   if (argc < 2)
   {
      do
      {
         printf("\n\n");
         printf("\tThis will only modify the registered versions of Descent 1 and 2\n");
         printf("\tDescent 1 (tm) Ver 1.0, 1.4, 1.5\n\tDescent 2 (tm) Ver 1.0, 1.1, 1.2\n");
         printf("1. Set Laser level\n");
         printf("2. Open File\n");
         printf("3. Save Changes\n");
         printf("4. Quit with out Saving\n");
         do
         {
            printf("Enter your choice: ");
            printf(":");

             cin >> opt;
            //gets(opt);
            option = atoi(opt);
         } while (option < 1 || option > 4);
         switch (option)
         {
         case 1:
            printf("Enter New Laser Level: ");
            cin >> opt;
            //gets(opt);
            LaserLevel = atoi(opt);
            break;
         case 2:
            printf("Enter FileName: ");
            cin >> opt;
            //gets(opt);
            if ((dsf = fopen(opt, "r+b")) == NULL)
            {
               printf("error opening file %s\n", opt);
               break;
            }
            FileOpen = 1;
            Version = Check_Descent_Version(dsf);
            NetGame = Check_Descent2_NetGame(opt);
            break;
         case 3:
            if (FileOpen)
            {
               if ((Version == 1))
               {
                  Write_Descent1_Data(dsf, LaserLevel);
               }
               else
               {
                  if (Version == 2)
                  {
                     Write_Descent2_Data(dsf, LaserLevel);
                  }
               }
            }
            else
               printf("You forgot to open the file\n");
            break;
         case 4:
            printf("Everyone likes a Cheater?! \n");
            break;
         }
      } while (option != 4);
   }
   else
   {
      if ((dsf = fopen(argv[1], "r+b")) == NULL)
      {
         printf("error opening file %s\n", argv[1]);
         exit(1);
      }

      Version = Check_Descent_Version(dsf);

      LaserLevel = atoi(argv[2]);

      if ((Version == 1))
      {
         Write_Descent1_Data(dsf, LaserLevel);
      }
      else
      {
         if (Version == 2)
         {
            Write_Descent2_Data(dsf, LaserLevel);
         }
      }
   }

   return(0);
}

int    Check_Descent2_NetGame(char* FileName)
{
   register int a = 0;
   char* UserInput;

   UserInput = new char[80];

   while (FileName[a]) {
      a++;
   }
   a--;
   /* You need to know the correct number of players that were in
   the game at the time you saved it during CoOp multiplay */

   if (((FileName[a - 2] == 'm') && (FileName[a - 1] == 'g')) ||
      ((FileName[a - 2] == 'M') && (FileName[a - 1] == 'G')))
   {
      printf("Enter the Number of Players? ");
      cin >> UserInput;
      //gets(UserInput);
      Players = atoi(UserInput);

      delete[] UserInput;
      return(1);
   }

   delete[] UserInput;
   return(0);
}

/* Make sure that the file opend is a real Descent Save File */

int    Check_Descent_Version(FILE* dsf)
{
   register int a, Hit;
   //   char Checkver;

   char Header0[6]; // = { 0x44, 0x47, 0x53, 0x53, 0x06}; Descent V1.0
   char Header1[6]; // = { 0x44, 0x47, 0x53, 0x53, 0x07}; Descent V1.4, V1.5
   char Header2[6]; // = { 0x44, 0x47, 0x53, 0x53, 0x16}; Descent V1.0, V1.1, V1.2
   char Header[7];

   Header0[0] = 0x44;
   Header0[1] = 0x47;
   Header0[2] = 0x53;
   Header0[3] = 0x53;
   Header0[4] = 0x06;
   Header0[5] = NULL;

   Header1[0] = 0x44;
   Header1[1] = 0x47;
   Header1[2] = 0x53;
   Header1[3] = 0x53;
   Header1[4] = 0x07;
   Header1[5] = NULL;

   Header2[0] = 0x44;
   Header2[1] = 0x47;
   Header2[2] = 0x53;
   Header2[3] = 0x53;
   Header2[4] = 0x16;
   Header2[5] = NULL;

   for (a = 0; a < 6; a++)
   {
      Header[a] = getc(dsf);
   }

   for (a = 0, Hit = 0; a < 5; a++)
   {
      if (Header0[a] == Header[a])
      {
         Hit++;
      }
   }
   if (Hit == 5)
   {
      return(1);
   }
   else
   {
      for (a = 0, Hit = 0; a < 5; a++)
      {
         if (Header1[a] == Header[a])
         {
            Hit++;
         }
      }
      if (Hit == 5)
      {
         return(1);
      }
      else
      {
         for (a = 0, Hit = 0; a < 5; a++)
         {
            if (Header2[a] == Header[a])
            {
               Hit++;
            }
         }
         if (Hit == 5) {
            return(2);
         }
      }
   }

   printf("Wrong Descent Save Game file!!!!\n");
   return(0);
}

/* Write the weapons data to disk (this section is hard coded) */

void   Write_Descent1_Data(FILE* dsf, int MainW)
{
   if (fseek(dsf, 0x13D9, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0X0C, dsf);

   if (fseek(dsf, 0x13DA, SEEK_SET))
   {
      exit(1);
   }
   putc(0x04, dsf);
   if (fseek(dsf, 0x13DF, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0x7F, dsf);
   if (fseek(dsf, 0x13E3, SEEK_SET))
   {		// Energy
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0x7F, dsf);
   if (fseek(dsf, 0x13E5, SEEK_SET))
   {		// Shield
      exit(1);
   }
   putc(0x0A, dsf);         // lives This is set to 10 lives

   if (fseek(dsf, 0x13E7, SEEK_SET))
   {
      exit(1);
   }
   if (MainW) {
      printf("Writting Descent 1 Cheat Data\nwith Laser Level %d.\n", MainW);
      if (MainW < 1) {
         MainW = 1;
      }
      putc(MainW - 1, dsf);     // laser level
   }
   else {
      printf("Writting Descent 1 Cheat Data\nwith Laser Level 4.\n");
      putc(0x03, dsf);      // laser level
   }

   if (fseek(dsf, 0x13EB, SEEK_SET))
   {
      exit(1);
   }
   putc(0x1F, dsf);
   if (fseek(dsf, 0x13EC, SEEK_SET))
   {
      exit(1);
   }
   putc(0x1F, dsf);
   if (fseek(dsf, 0x13EF, SEEK_SET))
   {  // vulcan
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0x7F, dsf);
   if (fseek(dsf, 0x13F7, SEEK_SET))
   {  // concusion
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);
   if (fseek(dsf, 0x13F9, SEEK_SET))
   {  // homing
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);
   if (fseek(dsf, 0x13FB, SEEK_SET))
   {  // prox bombs
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);
   if (fseek(dsf, 0x13FD, SEEK_SET))
   {  // smart missles
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);
   if (fseek(dsf, 0x13FF, SEEK_SET))
   {  // mega missles
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);

   if (fseek(dsf, 0x1437, SEEK_SET))
   {  // disables cheater flag
      exit(1);
   }
   putc(0x00, dsf);
   if (fseek(dsf, 0x1403, SEEK_SET))
   {	// Cloaking? or Cloaking Timmer Settings
      putc(0xFF, dsf);
      putc(0x6F, dsf);
   }
   if (fseek(dsf, 0x1407, SEEK_SET))
   {  // Invul? or Invul Timmer Setting
      putc(0xFF, dsf);
      putc(0x6F, dsf);
   }
}

/* Write the weapons data to disk (this section is hard coded) */

void   Write_Descent2_Data(FILE* dsf, int MainW)
{
   int ShiftVal = 0;

   if (NetGame)
   {
      if (Players == 2)
         ShiftVal = 0x3C8;       // two game players offset
      else
         if (Players == 3)
            ShiftVal = 0x456;    // three game players offset
         else
            if (Players == 4)
               ShiftVal = 0x4E4; // four game players offset
   }

   if (fseek(dsf, 0x16D9 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   //      putc(0x8E,dsf);         // all keys ammo rack
   putc(0xCF, dsf);
   putc(0x3F, dsf);
   if (fseek(dsf, 0x16DA + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0x37, dsf);         // afterburn, energy converter, quad laser, all map
   if (fseek(dsf, 0x16DF + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0x7F, dsf);         // energy
   if (fseek(dsf, 0x16E3 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0x7F, dsf);         // shield
   if (fseek(dsf, 0x16E5 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0x0A, dsf);         // lives This is set to 10 lives

   if (fseek(dsf, 0x16E7 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   if (MainW)
   {
      printf("Writting Descent 2 Cheat Data\nwith Laser Level %d.\n", MainW);
      if (MainW < 1)
      {
         MainW = 1;
      }
      putc(MainW - 1, dsf);     // laser level
   }
   else {
      printf("Writting Descent 2 Cheat Data\nwith Laser Level 6.\n");
      putc(0x05, dsf);      // laser level
   }

   if (fseek(dsf, 0x16EB + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);         // primary weapons
   putc(0x03, dsf);
   if (fseek(dsf, 0x16ED + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);         // Secondary weapons
   putc(0x03, dsf);
   if (fseek(dsf, 0x16F1 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);     // Vulcan/Gause ammo
   if (fseek(dsf, 0x1703 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);     // Concussion missl
   if (fseek(dsf, 0x170D + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // Flash
   if (fseek(dsf, 0x1705 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // homing
   if (fseek(dsf, 0x170F + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // guided
   if (fseek(dsf, 0x1707 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // ProxBomb
   if (fseek(dsf, 0x1711 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // SmartBomb
   if (fseek(dsf, 0x1709 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // Smartmissl
   if (fseek(dsf, 0x170B + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // ?
   if (fseek(dsf, 0x170D + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // Mega missl(disable in demo ver)
   if (fseek(dsf, 0x170F + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // ?
   if (fseek(dsf, 0x1713 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // mercury missl(disable in demo ver)
   if (fseek(dsf, 0x1715 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   putc(0xFF, dsf);
   putc(0xFF, dsf);         // Earth Shaker(disabled in demo ver)

   if (fseek(dsf, 0x1751 + ShiftVal, SEEK_SET))
   {
      exit(1);
   }
   if (!NetGame)
      putc(0x00, dsf);      // Disables cheater flag

   if (fseek(dsf, 0x172B, SEEK_SET))
   {	// Cloaking? or Cloaking Timmer Settings
      putc(0xFF, dsf);
      putc(0x6F, dsf);
   }
   if (fseek(dsf, 0x172F, SEEK_SET))
   {	// Invul? or Invul Timmer Setting
      putc(0xFF, dsf);
      putc(0x6F, dsf);
   }

}


