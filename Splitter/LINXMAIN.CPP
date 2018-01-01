/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/01/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This program is designed to Split up large files into smaller ones
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitter.h"

#if WINCOMP == 1
#  include <windows.h>
#endif

#if LINUXOS == 1

int main( int argc, char *argv[] )
/****************************************************************************
	Purpose:	Main program entry point.

	Input: int argc, char *argv[]

   Output:

   Return: 0,1  0 successful, 1 fail

   Parameters:
   	int argc - paramiter count
      char *argv[] - paramiters contained same number in count
****************************************************************************/
{
	char *FileName, *SplitFile;
	int a, b;
	int flag = 0;
	long SplitSize;

   FileName  = new char [ FILENAME ];
   SplitFile = new char [ FILENAME ];

  	strcpy( FileName, argv[ 1 ] );
	strcpy( SplitFile, argv[ 1 ] );

	printf( "%s\n", FILEVER );
	printf( "mbcarey2@gte.net http://www.owt.com/users/mbcarey\n\n" );

	if( argc < 3 )
   {
		printf("Large files into Smaller ones.\n");
		printf("When copying the split *. ter files be sure to copy the *.spl file.\n");
		printf("That file is a control file that is needed to restore your\n");
		printf("split file to it's orignal state.\n\nUsage\n\n");
		printf("splitter filetosplit sizetosplit -s  [Split File]\n");
		printf("splitter fileCFG.SPL -r [Reconstruct File]\n");
		printf("splitter fileCFG.SPL -f [Force Reconstruct of File]\n");

      delete [] FileName;
      delete [] SplitFile;

      return( 1 );
	}

	flag = 0;
		/* Find the file out of the path */
	for( a=0, b=0; a<strlen( argv[1] ); a++ )
   {
		FileName[ b ] = argv[ 1 ][ a ];
		FileName[ b+1 ] = NULL;
		b++;

		if( FileName[a] == '\\' )
      {
			b = 0;
		}
	}

	for( a=0; FileName[a]; a++ )
   {
		if( FileName[a] == '.' )
      {
			FileName[ a   ] = '.';
			FileName[ a+1 ] = 'S';
			FileName[ a+2 ] = 'P';
			FileName[ a+3 ] = 'L';
			FileName[ a+4 ] = NULL;

			flag = 1;
			break;
		}
	}
	if( flag != 1 )
   {
		FileName[ a   ] = '.';
		FileName[ a+1 ] = 'S';
		FileName[ a+2 ] = 'P';
		FileName[ a+3 ] = 'L';

		FileName[ a+4 ] = NULL;
	}
		/* Determine what code switch was used to force file reconstruction */
	if( ( !stricmp( argv[ 2 ], "-f" ) ) || ( !stricmp( argv[ 1 ], "-f" ) ) )
   {
      a = Force_CRC_Reconstruct( FileName );

      delete [] FileName;
      delete [] SplitFile;

		return( a );
	}
   	/* Recontruct Files Back to Their Original Parts */
	if( !stricmp( argv[ 2 ], "-r" ) ) {
		if( Reconstruct_Files( FileName ) ) {
//			remove( argv[ 1 ] );	// This Causes the *.spl file to be removed in some cases.

	      delete [] FileName;
   	   delete [] SplitFile;

			return( 1 );
		}
	}
		/* Split the file up in to smaller chuncks */
	if( ( !stricmp( argv[ 3 ], "-s" ) ) || ( !stricmp( argv[ 2 ], "-s" ) ) )
   {
		if( !strcmp( argv[ 2 ], "-s" ) )
      {
			/* Set it to the Defualt file size for Splitting */
			SplitSize = DEFUALTFILESZ;
		}
		else
      {
			SplitSize = atol( argv[ 2 ] );
		}
      a = Split_Files_Apart( FileName, SplitFile, SplitSize );

      delete [] FileName;
      delete [] SplitFile;

		return( a );
	}
   delete [] FileName;
   delete [] SplitFile;

	return( 0 );
}

void note( char *String )
/****************************************************************************
	Purpose:	print text to screen. (To be more compatiable with win95 when compiled forit)

	Input: char *String

   Output:

   Return:

   Parameters:
   	char *String - a String of text to print to screen
****************************************************************************/
{
	if( String[ 0 ] )
		printf( "%s", String );
}

void windisplay( char *String )
/****************************************************************************
	Purpose:	print text to screen. (To be more compatiable with win95 when compiled forit)

	Input: char *String

   Output:

   Return:

   Parameters:
   	char *String - a String of text to print to screen
****************************************************************************/
{
	if( String[ 0 ] )
		printf( "%s", String );
}

#endif


