/*

Memory test program This program will use ALL available memory in the system and will cause
the system to crash, Running this program is at your own risk.

*/

#define MAXSTRSIZE 32767

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct MEMCHEW {
	MEMCHEW *nxt;
   char *FillBuff;
};

MEMCHEW *HMemChew = NULL;

int main(int argc, char *argv[]);
int Eat_All_Memory( void );

int main(int argc, char *argv[])
{
	char input[80];
   
	printf("This program WILL use ALL memory on your system bringing it to it knees.\n");
   printf("Your system can and will most likly crash when you run this program.\n");
   printf("If you do not save and quit all other applications you could suffer loss of data.\n");
   printf("By the fact that you are running this program you can and may suffer data loss or sys Crash\n");
   printf("By Accepting you are willing to let your system crash \(Y/N): ");
   gets(input);

   if( !stricmp( input, "y" ) )
   {
   	return( Eat_All_Memory( ) );
   }

   return(0);
}

int Eat_All_Memory( void )
{
	MEMCHEW *tMemChew, *TmpMemChew;
 	tMemChew = TmpMemChew = NULL;

   HMemChew = new MEMCHEW;

   tMemChew = HMemChew;
   tMemChew->FillBuff = new char [ MAXSTRSIZE ];

   tMemChew->nxt = NULL;

	while( !kbhit( ) )
   {
   	tMemChew->nxt = new MEMCHEW;
      tMemChew = tMemChew->nxt;
      tMemChew->FillBuff = new char [ MAXSTRSIZE ];
      tMemChew->nxt = NULL;
   }

   tMemChew = HMemChew;

   while( !tMemChew->nxt )
   {
   	TmpMemChew = tMemChew;

      tMemChew = tMemChew->nxt;

      delete [] TmpMemChew->FillBuff;
      delete TmpMemChew;
   }

   return( 1 );
}



