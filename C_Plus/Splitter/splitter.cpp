/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/20/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This program is designed to Split up large files into smaller ones
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "splitter.h"

void Get_Next_Name( char *output );
void Get_Next_Name_New( char *output );
void Get_Next_Name_Old( char *output );

int Check_Next_Name( char *output );

int  Read_Cfg_Info( FILE **fp, struct CFGFILEINFO *CfgFileInfo );
void Write_Cfg_Info( FILE **fp, struct CFGFILEINFO *CfgFileInfo );
void Strip_Extra_File_Name_Info( struct CFGFILEINFO *CfgFileInfo );

int Restore_Split_File( FILE **fpout, unsigned long FileSize, unsigned long SplitSize, struct CFGFILEINFO *CfgFileInfo );
int Restore_Splt_File_No_CRC( FILE **fpout, unsigned long FileSize, unsigned long SplitSize, long ToTSplit, struct CFGFILEINFO *CfgFileInfo );
int Create_Split_File( FILE **fpin, unsigned long SplitSize, struct CFGFILEINFO *CfgFileInfo );

int Set_FileVer_Info( unsigned long VerNumber );

#if WINCOMP == 1
#  include <windows.h>
#endif

/*
	Before the TERFVER Number is changed you need to update the FileVerIndex[]
	variable with the old TERFVER Number. This Verable should stay in the splitter
   Module. This count needs to equil the number of entries in the var FileVerIndex[]
*/

#define TERFVER 6

int FVIndex = TERFVER;

unsigned long FileVerIndex[ ] =
{
	NULL,
   1,
   2,
   3,	// V1.05.xx
   4, // V1.06.xx
   5, // V1.07.xx
   6, // V1.08.xx
   7, // V1.09.xx // Not Finnished
	TERFVER
};

int Displayit;

int Force_CRC_Reconstruct( char *FileName )
/****************************************************************************
	Purpose: Force a file resotre, setup init function

	Input: char *FileName

   Output:

   Return: 0,1   0 success, 1 fail

   Parameters:
   	char *FileName - FileName of new output filename
****************************************************************************/
{
	FILE *fpout, *splitinfo;
	char *input;
   char *Buffer;
	int SplitCheck;
	unsigned long FileSize = 0;
	unsigned long FileCRC = 0;
	struct CFGFILEINFO CfgFileInfo;

   input  = new char [ 48 ];
   Buffer = new char [ DSPLBUFF ];

   // clear this Structure element
	CfgFileInfo.FileSize 		= NULL;
	CfgFileInfo.SplitSize 		= NULL;
	CfgFileInfo.FileCRC	 		= NULL;
	CfgFileInfo.SplitTotal 		= NULL;
   CfgFileInfo.SplitVer			= TERFVER;
	CfgFileInfo.FileName[ 0 ] 	= NULL;
   CfgFileInfo.TerStart[ 0 ] 	= NULL;
   CfgFileInfo.TerEnd  [ 0 ] 	= NULL;


	sprintf( Buffer, "\n\t\t\tWarning!\nReconstructing File with out CRC Checks can Leave Errors in Restored File\n\t\t\t\"\(Y\)es\" or \"\(N\)o\": " );
   input[ 0 ] = NULL;

#if WINCOMP == 1
   char *message;
   message = new char [ DSPLBUFF ];

   sprintf( message,"%s\n", Buffer );

   if( MessageBox( ghWnd, message, "Windows Splitter Message", MB_YESNO | MB_ICONWARNING ) == IDYES )
   {
   	strcpy( input, "y" );
   }

   delete [] message;

#endif
#if DOSCOMP == 1 || OS2COMP == 1
	note( Buffer );
	gets( input );
#endif
	if( !stricmp( input, "y" ) )
   {
		if( ( splitinfo=fopen( FileName, "rb" ) ) == NULL )
      {
#if DOSCOMP == 1 || OS2COMP == 1
        	/* If Control file is corrupt get user supplied information */
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - Cannot open Control file \"%s\"\n\n\nYou will need to provide File Data\nEnter File Break Size Defualt=%ld :", FileName, DEFUALTFILESZ );
			windisplay( Buffer );
#endif

#if WINCOMP == 1
 			GETDATAINFOAGAIN:  // use of goto call, need to get data info again. point is down.

        	if( DialogBox( hInst, MAKEINTRESOURCE( 1 ), ghWnd, ( DLGPROC )DlgForceFixProc ) == IDCANCEL )
         {
				delete [] Buffer;
            delete [] input;

         	return( 1 );
         }

			CfgFileInfo.SplitSize  = gSplitSize;
			CfgFileInfo.SplitTotal = gSplitTotal;
			strcpy( CfgFileInfo.FileName, gFileName );
         strcpy( CfgFileInfo.TerStart, gSFileName );
#endif
         Buffer[ 0 ] = CfgFileInfo.FileName[ strlen( CfgFileInfo.FileName ) -4 ];
         Buffer[ 1 ] = CfgFileInfo.FileName[ strlen( CfgFileInfo.FileName ) -3 ];
         Buffer[ 2 ] = CfgFileInfo.FileName[ strlen( CfgFileInfo.FileName ) -2 ];
         Buffer[ 3 ] = CfgFileInfo.FileName[ strlen( CfgFileInfo.FileName ) -1 ];
         Buffer[ 4 ] = CfgFileInfo.FileName[ strlen( CfgFileInfo.FileName ) ];

			int DotFlg = 0;

         for( int a=0; a<4; a++ )
         {
         	if(Buffer[a] == '.')
            {
            	DotFlg++;
            }
         }

         if(DotFlg)
         {
         	if( ( !stricmp( Buffer, ".TER" ) ) || ( !stricmp( Buffer, ".SPL" ) ) ) {
            	CfgFileInfo.FileName[ 0 ] = NULL;

               sprintf( Buffer, "Cannot allow output filename to be of *.spl or *.ter" );
			  		note( Buffer );
            }
         }

#if DOSCOMP == 1 || OS2COMP == 1
			gets( input );

			CfgFileInfo.SplitSize = atol( input );
			if( CfgFileInfo.SplitSize == 0 ) {
				CfgFileInfo.SplitSize = DEFUALTFILESZ;
			}
			sprintf( Buffer, "Enter the Number of split *.TER files: " );
			windisplay( Buffer );

			gets( input );

			CfgFileInfo.SplitTotal = atoi( input );
			sprintf( Buffer, "Enter the output FileName: " );
			windisplay( Buffer );

			gets( CfgFileInfo.FileName );

         if( !CfgFileInfo.TerStart[ 0 ] )
         {
	         sprintf( Buffer, "Enter Starting Ter FileName: " );
	         windisplay( Buffer );

   	      gets( CfgFileInfo.TerStart );
         }
#endif
			if( ( CfgFileInfo.SplitSize == NULL ) ||
				 ( CfgFileInfo.SplitTotal == NULL ) ||
				 ( CfgFileInfo.FileName[0] == NULL ) )
         {
				sprintf( Buffer, "Not enough information was provided\n" );
				note( Buffer );
#if WINCOMP == 1
	         goto GETDATAINFOAGAIN;	// use of goto function point is up
#else if DOSCOMP == 1 || OS2COMP == 1
				delete [] Buffer;
            delete [] input;

				return( 1 );
#endif
			}
		}
		else
      {
      				/* Read Configureation informaiton if available */
			if( !Read_Cfg_Info( &splitinfo, &CfgFileInfo ) )
         {
         	sprintf( Buffer, "Incorrect Splitter Version\n" );
				windisplay( Buffer );

#if WINCOMP == 1
				note( Buffer );
#endif
				return( 1 );
         }
		}
        	/* Check to see if the output file exists */
		if( ( fpout=fopen( CfgFileInfo.FileName, "rb" ) ) != NULL )
      {
        	fclose( fpout );
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - Cannot Create file \"%s\"\nFile Already Exisits Remove File \"%s\"?\n\"\(Y\)es\" or \"\(N\)o\": ", CfgFileInfo.FileName, CfgFileInfo.FileName );
         input[ 0 ] = NULL;

#if WINCOMP == 1
		   char *message;
		   message = new char [ DSPLBUFF ];

		   sprintf( message,"%s\n", Buffer );

		   if( MessageBox( ghWnd, message, "Windows Splitter Message", MB_YESNO | MB_ICONWARNING )== IDYES )
		   {
	   		strcpy( input, "y" );
		   }

         delete [] message;

#endif
#if DOSCOMP == 1 || OS2COMP == 1
			windisplay( Buffer );
			gets( input );
#endif
			if( !stricmp( input, "y" ) ) {
				sprintf( Buffer, "Removing File %s\n", CfgFileInfo.FileName );
				windisplay( Buffer );

#if WINCOMP == 1
				DeleteFile( CfgFileInfo.FileName );
#else if DOSCOMP == 1 || OS2COMP == 1
				remove( CfgFileInfo.FileName );
#endif
			}
			else
         {
				sprintf( Buffer, "Done...\n" );
				windisplay( Buffer );

				delete [] Buffer;
            delete [] input;

				return( 1 );
			}
		}
			/* Create Output File */
		if( ( fpout=fopen( CfgFileInfo.FileName, "w+b" ) ) == NULL )
      {
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - Cannot Creat file \"%s\"\n", CfgFileInfo.FileName );
			windisplay( Buffer );
#if WINCOMP == 1
			note( Buffer );
#endif
			delete [] Buffer;
         delete [] input;

			return( 1 );
		}

		sprintf( Buffer, "Split FileSize=%ld\n", CfgFileInfo.SplitSize );
		windisplay( Buffer );

	   Strip_Extra_File_Name_Info( &CfgFileInfo );
			/* Start File Reconstruction with out CRC checking */
		SplitCheck = Restore_Splt_File_No_CRC( &fpout, CfgFileInfo.FileSize, CfgFileInfo.SplitSize, CfgFileInfo.SplitTotal, &CfgFileInfo );

		Get_File_Stats( &fpout, &FileSize, &FileCRC );
			/* Print Error Messages if needed */
		if( FileSize != CfgFileInfo.FileSize )
      {
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - FileSize Does not Match, Orig=%ld, New=%ld\n", CfgFileInfo.FileSize, FileSize );
			windisplay( Buffer);
		}
		if( FileCRC != CfgFileInfo.FileCRC )
      {
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - FileCRC Fail, Orig=0x%lX, New=0x%lX\n", CfgFileInfo.FileCRC, FileCRC );
			windisplay( Buffer );
		}
		if(SplitCheck != CfgFileInfo.SplitTotal)
      {
			sprintf( Buffer, "Error:  Force_CRC_Reconstruct - File Split numbers in=%d and out=%d do not match\n", CfgFileInfo.SplitTotal, SplitCheck );
			windisplay( Buffer );
		}
		fcloseall( );

      delete [] Buffer;
      delete [] input;

		return( 0 );
	}
   delete [] Buffer;
   delete [] input;

	return( 1 );
}

int Reconstruct_Files( char *FileName )
/****************************************************************************
	Purpose:	Restore File back to original state.

	Input:	char *FileName

   Output:

   Return: 0,1   0 success, 1 fail

   Parameters:
   	char *FileName - FileName and Path of file to restore
****************************************************************************/
{
	FILE *fpout, *splitinfo;
	char *input, *Buffer;
   long SplitCheck;
	unsigned long FileSize = 0;
	unsigned long FileCRC = 0;
	struct CFGFILEINFO CfgFileInfo;

   input  = new char [ 48 ];
   Buffer = new char [ DSPLBUFF ];

   // clear this Structure element
	CfgFileInfo.FileSize 	= NULL;
	CfgFileInfo.SplitSize 	= NULL;
	CfgFileInfo.FileCRC	 	= NULL;
	CfgFileInfo.SplitTotal 	= NULL;
   CfgFileInfo.SplitVer		= TERFVER;
	CfgFileInfo.FileName[ 0 ] = NULL;
   CfgFileInfo.TerStart[ 0 ] = NULL;
   CfgFileInfo.TerEnd  [ 0 ] = NULL;

	if( ( splitinfo=fopen( FileName, "rb" ) ) == NULL )
   {
		sprintf( Buffer, "Error:  Reconstruct_Files - Cannot open Control file \"%s\"\n", FileName );
		windisplay( Buffer );
#if WINCOMP == 1
		note(Buffer);
#endif
      delete [] Buffer;
      delete [] input;

		return( 1 );
	}
      /* Read file Configureation information */
	if( !Read_Cfg_Info( &splitinfo, &CfgFileInfo ) )
   {
      sprintf( Buffer, "Incorrect Splitter Version\n" );
		windisplay( Buffer );

#if WINCOMP == 1
		note( Buffer );
#endif
		return( 1 );
   }

		/* Check to see if the output file exists */
	if( ( fpout=fopen( CfgFileInfo.FileName, "rb" ) ) != NULL )
   {
     	fclose( fpout );
		sprintf( Buffer, "Error:  Reconstruct_Files - Cannot Create file \"%s\"\nFile Already Exisits Remove File \"%s\"?\n\"\(Y\)es\" or \"\(N\)o\": ", CfgFileInfo.FileName, CfgFileInfo.FileName );
      input[ 0 ] = NULL;

#if WINCOMP == 1
	   char *message;
	   message = new char [ 1024 ];

	   sprintf( message,"%s\n", Buffer );

	   if( MessageBox( ghWnd, message, "Windows Splitter Message", MB_YESNO | MB_ICONWARNING )== IDYES )
	   {
	   	strcpy( input, "y" );
	   }

	   delete [] message;

#endif
#if DOSCOMP == 1 || OS2COMP == 1
		windisplay( Buffer );
		gets( input );
#endif
		if( !stricmp( input,"y" ) )
      {
			sprintf( Buffer, "Removing File %s\n", CfgFileInfo.FileName );
			windisplay( Buffer );
#if WINCOMP == 1
				DeleteFile( CfgFileInfo.FileName );
#else if DOSCOMP == 1 || OS2COMP == 1
				remove( CfgFileInfo.FileName );
#endif
		}
		else
      {
			sprintf( Buffer, "Done...\n" );
			windisplay( Buffer );

			delete [] Buffer;
         delete [] input;

			return( 1 );
		}
	}
		/* Create Output File */
	if( ( fpout=fopen( CfgFileInfo.FileName, "w+b" ) ) == NULL )
   {
		sprintf( Buffer, "Cannot Creat output file \"%s\"\n", CfgFileInfo.FileName );
		windisplay( Buffer );
#if WINCOMP == 1
		note( Buffer );
#endif
      delete [] Buffer;
      delete [] input;

		return( 1 );
	}

	sprintf( Buffer, "Split FileSize=%ld\n", CfgFileInfo.SplitSize );
	windisplay( Buffer );
      /* Reconsturct file using CRC checks for file. */
	SplitCheck = Restore_Split_File( &fpout, CfgFileInfo.FileSize, CfgFileInfo.SplitSize, &CfgFileInfo );

	Get_File_Stats( &fpout, &FileSize, &FileCRC );
		/* Print Error Messages if needed */
	if( FileSize != CfgFileInfo.FileSize )
   {
		sprintf( Buffer, "Error:  Reconstruct_Files - FileSize Does not Match, Orig=%ld, New=%ld\nRemoving %s\n", CfgFileInfo.FileSize, FileSize, CfgFileInfo.FileName );
#if WINCOMP == 1
		DeleteFile( CfgFileInfo.FileName );
#else if DOSCOMP == 1 || OS2COMP == 1
		remove( CfgFileInfo.FileName );
#endif
		windisplay( Buffer );

		delete [] Buffer;
      delete [] input;

		return( 1 );
	}
	if( FileCRC != CfgFileInfo.FileCRC )
   {
		sprintf( Buffer, "Error:  Reconstruct_Files - FileCRC Fail, Orig=0x%lX, New=0x%lX\nRemoving %s\n", CfgFileInfo.FileCRC, FileCRC, CfgFileInfo.FileName );
#if WINCOMP == 1
		DeleteFile( CfgFileInfo.FileName );
#else if DOSCOMP == 1 || OS2COMP == 1
		remove( CfgFileInfo.FileName );
#endif
		windisplay( Buffer );

      delete [] Buffer;
      delete [] input;

		return( 1 );
	}
	if( SplitCheck != CfgFileInfo.SplitTotal )
   {
		sprintf(Buffer, "Error:  Reconstruct_Files - File Split numbers in=%d and out=%d do not match\nRemoving %s\n", CfgFileInfo.SplitTotal, SplitCheck, CfgFileInfo.FileName);
#if WINCOMP == 1
		DeleteFile( CfgFileInfo.FileName );
#else if DOSCOMP == 1 || OS2COMP == 1
		remove( CfgFileInfo.FileName );
#endif
		windisplay( Buffer );

		delete [] Buffer;
      delete [] input;

		return( 1 );
	}
   delete [] Buffer;
   delete [] input;

	fcloseall( );

	return( 0 );
}

int Split_Files_Apart( char *FileName, char *SplitFile, unsigned long SplitSize )
/****************************************************************************
	Purpose:	Split Files Apart into smaller fregments CRC 32

	Input:	char *FileName, char *SplitFile, long SplitSize

   Output:

   Return: 0,1   0 Success, 1 fail

   Parameters:
   	char 	*FileName - FileName of Config File
      char 	*SplitFile - Name of the file to split apart
      long 	SplitSize - size of the file being split apart
****************************************************************************/
{
	FILE *fpin, *splitinfo;
   char *Buffer;//, *input;
	struct CFGFILEINFO CfgFileInfo;
	Displayit = 1;
//   input  = new char [ 48 ];
   Buffer = new char [DSPLBUFF];

   // clear this Structure element
	CfgFileInfo.FileSize 		= NULL;
	CfgFileInfo.SplitSize 		= SplitSize;
	CfgFileInfo.FileCRC	 		= NULL;
	CfgFileInfo.SplitTotal 		= NULL;
   CfgFileInfo.SplitVer			= TERFVER;
	CfgFileInfo.FileName[ 0 ] 	= NULL;
   CfgFileInfo.TerStart[ 0 ] 	= NULL;
   CfgFileInfo.TerEnd  [ 0 ] 	= NULL;

   strcpy( CfgFileInfo.FileName, SplitFile );

	if( ( fpin=fopen( SplitFile, "rb" ) ) == NULL )
   {
		sprintf( Buffer, "Error:  Split_Files_Apart - Cannot open file \"%s\"\n", SplitFile );
		windisplay( Buffer );
#if WINCOMP == 1
		note( Buffer );
#endif
		delete [] Buffer;

		return( 1 );
   }

   if( ( splitinfo=fopen( FileName, "rb" ) ) != NULL )
   {
		sprintf( Buffer, "Error:  Split_Files_Apart - Control file \"%s\" already exsits\n", FileName );
  		windisplay( Buffer );
#if WINCOMP == 1
		note( Buffer );
#endif
		delete [] Buffer;

		return( 1 );
	}
   if( ( splitinfo=fopen( FileName, "w+b" ) ) == NULL )
   {
		sprintf( Buffer, "Error:  Split_Files_Apart - Cannot Create Control file \"%s\"\n", FileName );
		windisplay( Buffer );
#if WINCOMP == 1
		note( Buffer );
#endif
		delete [] Buffer;

		return( 1 );
	}

	Get_File_Stats( &fpin, &CfgFileInfo.FileSize, &CfgFileInfo.FileCRC );

     	/* Check to see if the split size is Exceeds the size of the infile */
	if( CfgFileInfo.SplitSize >= CfgFileInfo.FileSize )
   {
		sprintf( Buffer, "File Split Size Exeeds Original file Limit\nSplitSize=%ld\nFileSize=%ld\n", CfgFileInfo.SplitSize, CfgFileInfo.FileSize );
		windisplay( Buffer);

      delete [] Buffer;

		return( 1 );
	}
	else
   {
        	/* Check to see if the split size is too small */
		if( CfgFileInfo.SplitSize < FILESIZELIMIT )
      {
			sprintf( Buffer, "File Split size too low\nSplitSize=%ld\nFileSizeLimit=%ld\n", CfgFileInfo.SplitSize, FILESIZELIMIT );
			windisplay( Buffer );

			delete [] Buffer;

			return( 1 );
		}
	}

	sprintf( Buffer, "Split FileSize=%ld\n", CfgFileInfo.SplitSize );
	windisplay( Buffer );

		/* Split the file up, return the results */
   CfgFileInfo.SplitTotal = Create_Split_File( &fpin, CfgFileInfo.SplitSize, &CfgFileInfo );

     	/* Write out the file reconstruct information */
	Write_Cfg_Info( &splitinfo, &CfgFileInfo );

   delete [] Buffer;

	return( 0 );
}

int Restore_Split_File( FILE **fpout, unsigned long FileSize, unsigned long SplitSize, struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose:	Restore the file using 32 bit CRC's for Checks report errors.

	Input: FILE *fpout, unsigned long FileSize, unsigned long SplitSize

   Output:

   Return: 0,1   0 success, 1 fail

   Parameters:
   	FILE *fpout - output pointer
      unsigned long FileSize - Total FileSize
      unsigned long SplitSize - Size to split the file to
****************************************************************************/
{
	FILE *fpin;
   int Init_Flag = 1;
	unsigned long TFileSize = 0, TSplitSize = 0, GFileSize = 0;
	unsigned long FileCRC, SFileCRC;
	char *FileName, *Buffer, ch;
	long Split = 0;

   FileName = new char [ FILENAME ];
   Buffer 	= new char [ DSPLBUFF ];

   FileName[ 0 ] = NULL;

	sprintf( Buffer, "Working..." );
	windisplay( Buffer );

	while( TFileSize < FileSize )
   {
		sprintf( Buffer, "." );
		windisplay( Buffer );

		FileCRC = 0;
		TSplitSize = 0;
		Split++;

      if( Init_Flag == 1 )
      {
      	Init_Flag = 0;
	      if( CfgFileInfo->TerStart[ 0 ] != NULL )
	      {
	      	sprintf( FileName, "%s", CfgFileInfo->TerStart );
	      }
	      else
	      {
	      	FileName[ 0 ] = NULL;
				Get_Next_Name( FileName );
         }
      }
      else
      {
			Get_Next_Name( FileName );
      }

		if( ( fpin=fopen( FileName, "rb" ) ) == NULL )
      {
			sprintf( Buffer, "Last File Found\n" );
         windisplay( Buffer );
#if WINCOMP == 1
			note( Buffer );
#endif
			delete [] Buffer;
         delete [] FileName;

			return( Split );
		}

   		/* Get File information */
		Get_File_Stats( &fpin, &GFileSize, NULL );
		rewind( fpin );
			/* Account for the 32 bit CRC */
		GFileSize -= 4;
	   if( FileVerIndex[3] <= FileVerIndex[ FVIndex ] )
      {
			GFileSize -= 4;
      }

   		/* Fail if there is a file missmatch */
		if( GFileSize > SplitSize )
      {
			sprintf( Buffer, "Error:  Restore_Split_File - FileSize does not Match File %s failed @ %ld Orig=%ld\n", FileName, GFileSize, SplitSize );
			windisplay( Buffer );

			delete [] Buffer;
         delete [] FileName;

			return( -1 );
		}
			/* Read the file and copy the data into the other file */
		while( TSplitSize < GFileSize )
      {
			TFileSize++;
			TSplitSize++;

			ch = getc( fpin );

			FileCRC += ch;
			if( feof( fpin ) )
         {
				/* fseek(fpin, NULL, SEEK_END); */
				break;
			}
			if( !feof( fpin ) )
         {
				putc(ch, *fpout);
			}
		}

		fread( &SFileCRC, sizeof( unsigned long ), 1, fpin );

	   	/* Check to see if the CRC is intact For that Ter File. */
		if( FileCRC != SFileCRC )
      {
			sprintf( Buffer, "Error:  Restore_Split_File - FileCRC for %s is corrupt or failed @ 0x%lX Orig=0x%lX\n", FileName, FileCRC, SFileCRC );
			windisplay( Buffer );

			delete [] Buffer;
         delete [] FileName;

			return( -1 );
		}

      if( FileVerIndex[ 3 ] <= FileVerIndex[ FVIndex ] )
      {
			fread( &SFileCRC, sizeof( unsigned long ), 1, fpin );

   	   	/* Check Event Tag, use FileCRC from Original File */
			if( CfgFileInfo->FileCRC != SFileCRC )
	      {
				sprintf( Buffer, "Error:  Restore_Split_File - FileTag for %s Corrupt @ 0x%lX Orig=0x%lX\n", FileName, FileCRC, SFileCRC );
				windisplay( Buffer );

				delete [] Buffer;
	   	   delete [] FileName;

				return( -1 );
			}
      }

		fclose( fpin );

      if( !stricmp( FileName, CfgFileInfo->TerEnd ) )
      {
      	break;
      }
	}
   delete [] Buffer;
   delete [] FileName;

	return( Split );
}

int Restore_Splt_File_No_CRC( FILE **fpout, unsigned long FileSize, unsigned long SplitSize, long ToTSplit, struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose: Restore the file with out CRC checks and report errors

	Input: FILE *fpout, unsigned long FileSize, unsigned long SplitSize, int ToTSplit

   Output:

   Return: 0,1   0 success, 1 fail

   Parameters:
   	FILE *fpout    - Pointer to output file
      unsigned long FileSize  - Guessed FileSize
      unsigned long SplitSize - Guess Split File Sizes
      int ToTSplit   - Guess number of files to put back together.
****************************************************************************/
{
	FILE *fpin;
   int Init_Flag = 1;
	unsigned long TFileSize = 0, TSplitSize = 0, GFileSize = 0, FileCheck;
	unsigned long FileCRC, SFileCRC;
	char *FileName, *Buffer, ch;
	long Split = 0;

   FileName = new char [ FILENAME ];
   Buffer 	= new char [ DSPLBUFF ];

	if( FileSize < FILESIZELIMIT )
   {
		FileCheck = FileSize + ( SplitSize * ToTSplit );
	}
	else
   {
		FileCheck = FileSize;
	}

	FileName[ 0 ] = NULL;
	sprintf( Buffer, "Working..." );
		windisplay(Buffer);

	while( TFileSize < FileCheck )
   {
		sprintf(Buffer, ".");
		windisplay(Buffer);

		FileCRC = 0;
		TSplitSize = 0;
		Split++;

      if( Init_Flag == 1 )
      {
      	Init_Flag = 0;
	      if( CfgFileInfo->TerStart[ 0 ] != NULL )
	      {
	      	sprintf( FileName, "%s", CfgFileInfo->TerStart );
	      }
	      else
	      {
	      	FileName[ 0 ] = NULL;
				Get_Next_Name( FileName );
         }
      }
      else
      {
			Get_Next_Name( FileName );
      }

		if((fpin=fopen( FileName, "rb" ) ) == NULL )
      {
			if( Split > ToTSplit )
         {
				sprintf( Buffer, "Ending...\n" );
				windisplay( Buffer );

				delete [] Buffer;
            delete [] FileName;

				return( Split );
			}
			else
         {
				sprintf( Buffer, "File %s Not Found, File *WILL* have Errors\n", FileName );
				windisplay( Buffer );
#if WINCOMP == 1
				note( Buffer );
#endif
			}
		}
		else
      {
      	ToTSplit++;

         	/* Get File information */
			Get_File_Stats( &fpin, &GFileSize, NULL );
			rewind(fpin);
				/* Account for the 32 bit CRC */
				GFileSize -= 4;
	      if( FileVerIndex[ 3 ] <= FileVerIndex[ FVIndex ] )
         {
				GFileSize -= 4;
         }

			if( GFileSize > SplitSize )
         {
				sprintf( Buffer, "Error:  Restore_Splt_File_No_CRC - FileSize does not Match File %s failed @ %ld Orig=%ld\n", FileName, GFileSize, SplitSize );
				windisplay( Buffer );
			}
				/* Copy the information from one file to the next */
			while( TSplitSize < GFileSize )
         {
				TFileSize++;
				TSplitSize++;
				ch = getc( fpin );
				FileCRC += ch;

				if( feof( fpin ) )
            {
					/* fseek(fpin, NULL, SEEK_END); */
					break;
				}
				if( !feof( fpin ) )
            {
					putc( ch, *fpout );
				}
			}
			fread( &SFileCRC, sizeof( unsigned long ), 1, fpin );

			if( FileCRC != SFileCRC )
         {
				sprintf( Buffer, "Error:  Restore_Splt_File_No_CRC - FileCRC for %s is corrupt or failed @ %lX Orig=%lX\n", FileName, FileCRC, SFileCRC );
				windisplay( Buffer );
			}

	      if( FileVerIndex[ 3 ] <= FileVerIndex[ FVIndex ] )
	      {
				fread( &SFileCRC, sizeof( unsigned long ), 1, fpin );

		      	/* Check Event Tag, use FileCRC from Original File */
				if( CfgFileInfo->FileCRC != SFileCRC )
	         {
					sprintf( Buffer, "Error:  Restore_Splt_File_No_CRC - FileTag for %s Corrupt @ 0x%lX Orig=0x%lX\n", FileName, FileCRC, SFileCRC );
					windisplay( Buffer );
				}
         }

			fclose( fpin );

      }

      if( !stricmp( FileName, CfgFileInfo->TerEnd ) )
      {
      	break;
      }
	}
   delete [] Buffer;
   delete [] FileName;

	return(Split);
}

int Create_Split_File( FILE **fpin, unsigned long SplitSize, struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose:	Split the files adding a 32bit CRC for each file

	Input: FILE *fpin, long SplitSize

   Output:

   Return: 0,1   0 success, 1 fail

   Parameters:
   	FILE *fpin - pointer to input file
      long SplitSize - size to split files to.
****************************************************************************/
{
	FILE *fpout;
   int Check_Name = 2, FirstNFlag = 0;
	unsigned long TFileSize = 0, TSplitSize = 0;
	unsigned long FileCRC;
	char *FileName, ch, *Buffer;
	long Split = 0;

   FileName = new char [ FILENAME ];
   Buffer 	= new char [ DSPLBUFF ];

	FileName[ 0 ] = NULL;
	rewind( *fpin );

		/* Continue reading the file until finnished */
	sprintf( Buffer, "Working..." );
	windisplay( Buffer );

	while( !feof( *fpin ) )
   {
		sprintf( Buffer, "." );
		windisplay( Buffer );

		FileCRC = 0;
		TSplitSize = 0;
		Split++;

		Get_Next_Name( FileName );

      if( Check_Name == 2 )
      {
	      Check_Name = Check_Next_Name( FileName );
         if( Check_Name )
	      {
	      	note( "Error:  Create_Split_File - Could not Allocate FileName \n" );
	      	return( Check_Name );
	      }
      }

		if( !FirstNFlag )
      {
      	FirstNFlag++;
      	sprintf( CfgFileInfo->TerStart, "%s", FileName );
      }

     	sprintf( CfgFileInfo->TerEnd, "%s", FileName );

			/* Check to see if there is already a file there */
		if( ( fpout=fopen( FileName, "rb" ) ) != NULL )
	   {
      	fclose( fpout );
			sprintf( Buffer, "Error:  Create_Split_File - Cannot Create File \"%s\", Already Exists\n", FileName );
			windisplay( Buffer );
#if WINCOMP == 1
			note( Buffer );
#endif
			delete [] Buffer;
	      delete [] FileName;

			return( -1 );
   	}

		if( ( fpout=fopen( FileName, "w+b" ) ) == NULL )
	   {
			sprintf( Buffer, "Error:  Create_Split_File - Cannot Create file \"%s\"\n", FileName );
			windisplay( Buffer );
#if WINCOMP == 1
			note( Buffer );
#endif
			delete [] Buffer;
	      delete [] FileName;

			return( -1 );
		}

			/* Make sure the output file size does not exceed the designated limit */
		while( TSplitSize < SplitSize )
      {
			if( feof( *fpin ) )
         {
				break;
			}
			/* Check for File Size and SplitSize For File Checking */
			TFileSize++;
			TSplitSize++;

			ch = getc( *fpin );

			if( feof( *fpin ) )
         {
				break;
			}

			FileCRC += ch;

			if( !feof( *fpin ) )
         {
				putc( ch, fpout );
			}
		}

			/* Write out the CRC */
		fwrite( &FileCRC, sizeof( unsigned long ), 1, fpout );

      if( FileVerIndex[ 3 ] <= FileVerIndex[ FVIndex ] )
      {
	      	/* Write out a File Tag ID using Original File CRC*/
	      FileCRC = CfgFileInfo->FileCRC;
			fwrite( &FileCRC, sizeof( unsigned long ), 1, fpout );
      }

		fclose( fpout );
   }
   delete [] Buffer;
   delete [] FileName;

	return( Split );
}

void Get_Next_Name( char *output )
/****************************************************************************
	Purpose:	To Allow compatibility between the newverions and the old version.

	Input: char *output

   Output: char *output

   Return:

   Parameters:
   	char *output - inits output string, then takes in the output, checks it
      	then updates is and sends the result back out.
****************************************************************************/
{
	if( FileVerIndex[ 5 ] <= FileVerIndex[ FVIndex ] )
   {
	   Get_Next_Name_New( output );
   }
   else
   {
		if( FileVerIndex[ 4 ] <= FileVerIndex[ FVIndex ] )
	   {
			Get_Next_Name_Old( output );
	   }
	   else
	   {
		   if( FileVerIndex[ 3 ] <= FileVerIndex[ FVIndex ] )
	   	{
	   		Get_Next_Name_Old( output );
		   }
      }
   }
}

void Get_Next_Name_New( char *output )
/****************************************************************************
	Purpose:	Create Split FileNames that are more intuitive.

	Input: char *output

   Output: char *output

   Return:

   Parameters:
   	char *output - inits output string, then takes in the output, checks it
      	then updates is and sends the result back out.
****************************************************************************/
{
	int iMonth, iDay, iYear;
	char cMonth[ 4 ], cDay[ 4 ], cYear[ 6 ], *ShiftV;

   /* inital starting Date */
	if( output[ 0 ] == NULL )
   {
   	/* Month */
		output[  0 ]  	= '0';
		output[  1 ]  	= '1';
		/* Day */
		output[  2 ]  	= '0';
		output[  3 ]  	= '1';
      /* Year */
		output[  4 ]  	= '0';
		output[  5 ]  	= '0';
		output[  6 ]  	= '0';
		output[  7 ]  	= '0';
      /* Extension */
		output[  8 ]  	= '.';
		output[  9 ]  	= 'T';
		output[ 10 ] 	= 'E';
		output[ 11 ] 	= 'R';

		output[ 12 ] 	= NULL;

		return;
	}
		/* Extract the Month Day and Year */
	cMonth[ 0 ] = output[ 0 ];
	cMonth[ 1 ] = output[ 1 ];
	cMonth[ 2 ] = NULL;

	cDay[ 0 ] = output[ 2 ];
	cDay[ 1 ] = output[ 3 ];
	cDay[ 2 ] = NULL;

	cYear[ 0 ] = output[ 4 ];
	cYear[ 1 ] = output[ 5 ];
	cYear[ 2 ] = output[ 6 ];
	cYear[ 3 ] = output[ 7 ];
	cYear[ 4 ] = NULL;

	   /* Convert Strings to values */
	iMonth = atoi(cMonth);
	iDay   = atoi(cDay);
	iYear  = atoi(cYear);

	iDay++;
	if( iDay > 99 )
   {
		iDay = 1;
		iMonth++;
		if( iMonth > 99 )
      {
			iMonth = 1;
			iYear++;
			if( iYear > 9999 )
         {
				iYear = 0;
			}
		}
	}

   ShiftV = cMonth;

   if( iMonth < 10 )
   {
   	ShiftV++;
      itoa( iMonth, ShiftV, 10 );    /* Convert Value to a String */
      ShiftV--;
      cMonth[ 0 ] = '0';
   }
   else
   {
   	itoa( iMonth, cMonth, 10 );    /* Convert Value to a String */
   }

	ShiftV = cDay;

   if( iDay < 10 )
   {
		ShiftV++;
		itoa( iDay, ShiftV, 10 );    /* Convert Value to a String */
		ShiftV--;
		cDay[ 0 ] = '0';
   }
	else
   {
		itoa( iDay, cDay, 10 );    /* Convert Value to a String */
	}

	ShiftV = cYear;
   if( iYear < 10 )
   {
		ShiftV++;
		ShiftV++;
		ShiftV++;
		itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
		ShiftV--;
		ShiftV--;
		ShiftV--;
		cYear[ 0 ] = '0';
		cYear[ 1 ] = '0';
		cYear[ 2 ] = '0';
	}
	else
   {
		if( iYear < 100 )
      {
			ShiftV++;
			ShiftV++;
			itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
			ShiftV--;
			ShiftV--;
			cYear[ 0 ] = '0';
			cYear[ 1 ] = '0';
		}
		else
      {
			if( iYear < 1000 )
			{
				ShiftV++;
				itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
				ShiftV--;
				cYear[ 0 ] = '0';
			}
			else {
				itoa( iYear, cYear, 10 );    /* Convert Value to a String */
			}
		}
	}

   /* Output the results */
   /* Month */
	output[  0 ]  	= cMonth[ 0 ];
	output[  1 ]  	= cMonth[ 1 ];
   /* Day */
	output[  2 ]  	= cDay[ 0 ];
	output[  3 ]  	= cDay[ 1 ];
   /* Year */
	output[  4 ]  	= cYear[ 0 ];
	output[  5 ]  	= cYear[ 1 ];
	output[  6 ]  	= cYear[ 2 ];
	output[  7 ]  	= cYear[ 3 ];
   /* Extension */
	output[  8 ]  	= '.';
	output[  9 ]  	= 'T';
	output[ 10 ] 	= 'E';
	output[ 11 ] 	= 'R';

	output[ 12 ] 	= NULL;
}

void Get_Next_Name_Old( char *output )
/****************************************************************************
	Purpose:	Create output filenames in a sudo date format This is reused code
   		   from another program I wrote.

	Input: char *output

   Output: char *output

   Return:

   Parameters:
   	char *output - inits output string, then takes in the output, checks it
      	then updates is and sends the result back out.
****************************************************************************/
{
	int iMonth, iDay, iYear;
	char cMonth[ 4 ], cDay[ 4 ], cYear[ 6 ], *ShiftV;

   /* inital starting Date */
	if( output[ 0 ] == NULL )
   {
   	/* Month */
		output[  0 ]  	= '0';
		output[  1 ]  	= '1';
		/* Day */
		output[  2 ]  	= '0';
		output[  3 ]  	= '1';
      /* Year */
		output[  4 ]  	= '0';
		output[  5 ]  	= '0';
		output[  6 ]  	= '0';
		output[  7 ]  	= '0';
      /* Extension */
		output[  8 ]  	= '.';
		output[  9 ]  	= 'T';
		output[ 10 ] 	= 'E';
		output[ 11 ] 	= 'R';

		output[ 12 ] 	= NULL;

		return;
	}
		/* Extract the Month Day and Year */
	cMonth[ 0 ] = output[ 0 ];
	cMonth[ 1 ] = output[ 1 ];
	cMonth[ 2 ] = NULL;

	cDay[ 0 ] = output[ 2 ];
	cDay[ 1 ] = output[ 3 ];
	cDay[ 2 ] = NULL;

	cYear[ 0 ] = output[ 4 ];
	cYear[ 1 ] = output[ 5 ];
	cYear[ 2 ] = output[ 6 ];
	cYear[ 3 ] = output[ 7 ];
	cYear[ 4 ] = NULL;

	   /* Convert Strings to values */
	iMonth = atoi(cMonth);
	iDay   = atoi(cDay);
	iYear  = atoi(cYear);

	iDay++;
	if( iDay > 31 )
   {
		iDay = 1;
		iMonth++;
		if( iMonth > 12 )
      {
			iMonth = 1;
			iYear++;
			if( iYear > 9999 )
         {
				iYear = 0;
			}
		}
	}

   ShiftV = cMonth;

   if( iMonth < 10 )
   {
   	ShiftV++;
      itoa( iMonth, ShiftV, 10 );    /* Convert Value to a String */
      ShiftV--;
      cMonth[ 0 ] = '0';
   }
   else
   {
   	itoa( iMonth, cMonth, 10 );    /* Convert Value to a String */
   }

	ShiftV = cDay;

   if( iDay < 10 )
   {
		ShiftV++;
		itoa( iDay, ShiftV, 10 );    /* Convert Value to a String */
		ShiftV--;
		cDay[ 0 ] = '0';
   }
	else
   {
		itoa( iDay, cDay, 10 );    /* Convert Value to a String */
	}

	ShiftV = cYear;
   if( iYear < 10 )
   {
		ShiftV++;
		ShiftV++;
		ShiftV++;
		itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
		ShiftV--;
		ShiftV--;
		ShiftV--;
		cYear[ 0 ] = '0';
		cYear[ 1 ] = '0';
		cYear[ 2 ] = '0';
	}
	else
   {
		if( iYear < 100 )
      {
			ShiftV++;
			ShiftV++;
			itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
			ShiftV--;
			ShiftV--;
			cYear[ 0 ] = '0';
			cYear[ 1 ] = '0';
		}
		else
      {
			if( iYear < 1000 )
			{
				ShiftV++;
				itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
				ShiftV--;
				cYear[ 0 ] = '0';
			}
			else {
				itoa( iYear, cYear, 10 );    /* Convert Value to a String */
			}
		}
	}

   /* Output the results */
   /* Month */
	output[  0 ]  	= cMonth[ 0 ];
	output[  1 ]  	= cMonth[ 1 ];
   /* Day */
	output[  2 ]  	= cDay[ 0 ];
	output[  3 ]  	= cDay[ 1 ];
   /* Year */
	output[  4 ]  	= cYear[ 0 ];
	output[  5 ]  	= cYear[ 1 ];
	output[  6 ]  	= cYear[ 2 ];
	output[  7 ]  	= cYear[ 3 ];
   /* Extension */
	output[  8 ]  	= '.';
	output[  9 ]  	= 'T';
	output[ 10 ] 	= 'E';
	output[ 11 ] 	= 'R';

	output[ 12 ] 	= NULL;
}

int Check_Next_Name( char *output )
/****************************************************************************
	Purpose:	To allow multiple split files in the same directory with out
   			overlay.

	Input: char *output

   Output: char *output

   Return: 0,1   0 success, 1 fail

   Parameters:
   	char *output - inits output string, then takes in the output, checks it
      	then updates is and sends the result back out.
****************************************************************************/
{
	int iYear, Check_Flag = 1;
	char cYear[ 6 ], *ShiftV;
   FILE *fpcheck;

	while( Check_Flag )
   {
	   	/* Check to see if the output file exists */
		if( ( fpcheck=fopen( output, "rb" ) ) != NULL )
		{
      	fclose( fpcheck );

			cYear[ 0 ] = output[ 4 ];
			cYear[ 1 ] = output[ 5 ];
			cYear[ 2 ] = output[ 6 ];
			cYear[ 3 ] = output[ 7 ];
			cYear[ 4 ] = NULL;

			iYear  = atoi(cYear);

	      iYear++;

			if( iYear > 9999 )
		      return( 1 );

			ShiftV = cYear;
		   if( iYear < 10 )
		   {
				ShiftV++;
				ShiftV++;
				ShiftV++;
				itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
				ShiftV--;
				ShiftV--;
				ShiftV--;
				cYear[ 0 ] = '0';
				cYear[ 1 ] = '0';
				cYear[ 2 ] = '0';
			}
			else
		   {
				if( iYear < 100 )
		      {
					ShiftV++;
					ShiftV++;
					itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
					ShiftV--;
					ShiftV--;
					cYear[ 0 ] = '0';
					cYear[ 1 ] = '0';
				}
				else
		      {
					if( iYear < 1000 )
					{
						ShiftV++;
						itoa( iYear, ShiftV, 10 );    /* Convert Value to a String */
						ShiftV--;
						cYear[ 0 ] = '0';
					}
					else {
						itoa( iYear, cYear, 10 );    /* Convert Value to a String */
					}
				}
			}

		   /* Year */
			output[  4 ]  	= cYear[ 0 ];
			output[  5 ]  	= cYear[ 1 ];
			output[  6 ]  	= cYear[ 2 ];
			output[  7 ]  	= cYear[ 3 ];
		   /* Extension */
			output[  8 ]  	= '.';
			output[  9 ]  	= 'T';
			output[ 10 ] 	= 'E';
			output[ 11 ] 	= 'R';

			output[ 12 ] 	= NULL;
	   }
	   else
	   {
	   	Check_Flag = 0;
	      break;
	   }
   }

   return( 0 );
}

void Get_File_Stats( FILE **fp, unsigned long *FileSize, unsigned long *FileCRC )
/****************************************************************************
	Purpose: Get File Size, and get Byte Count for CRC

	Input: FILE *fp

   Output: unsigned long FileSize, unsigned long *FileCRC

   Return:

   Parameters:
   	unsigned long *FileSize - Total size of the file
      unsigned long * FileCRC is the byte count of the file
****************************************************************************/
{
	register long lFileSize = 0;
	register unsigned long lFileCRC = 0;
	char ch;

	rewind( *fp );

   if( Displayit )
   {
   	windisplay( "Processing, Please wait, This may take a few moments...\n" );
      Displayit = 0;
   }

   while( !feof( *fp ) )
   {
		ch = getc( *fp );
		lFileCRC += ch;
		lFileSize++;
	}

	if( FileSize )
   {
		*FileSize = lFileSize - 1;
	}
	if( FileCRC )
   {
		*FileCRC = lFileCRC;
	}

	return;
}

void Write_Cfg_Info( FILE **fp, struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose: to write data to the Config File

	Input: FILE *fp, CFGFILEINFO *CfgFileInfo

   Output:

   Return:

   Parameters:
   	FILE *fp - pointer to the config file to write to
      CFGFILEINFO *CfgFileInfo pointer to the struct containg the file info
****************************************************************************/
{
	char *Buffer;
   Buffer = new char [ SMALBUFF ];
	FVIndex = TERFVER;

	fwrite( &CfgFileInfo->SplitVer, sizeof( unsigned long ), 1, *fp );

	fwrite( &CfgFileInfo->FileSize, sizeof( unsigned long ), 1, *fp );
	fwrite( &CfgFileInfo->SplitSize, sizeof( unsigned long ), 1, *fp );
	fwrite( &CfgFileInfo->FileCRC, sizeof( unsigned long ), 1, *fp );
	fwrite( &CfgFileInfo->SplitTotal, sizeof( long ), 1, *fp );

   Strip_Extra_File_Name_Info( CfgFileInfo );

   fprintf( *fp,"%s", CfgFileInfo->TerStart );
   putc( NULL, *fp );
   fprintf( *fp,"%s", CfgFileInfo->TerEnd );
   putc( NULL, *fp );

	fprintf( *fp, "%s", CfgFileInfo->FileName );
   putc( NULL, *fp );

#if DEBUGSPLIT == 1
	sprintf( Buffer, "\nDebug Control File Version ID = %d\n", FileVerIndex[ FVIndex ] );
	windisplay( Buffer );

   sprintf( Buffer,
   	"FileSize=%ld\nSplitSize=%ld\nFileCRC=0x%lX\nSplitTotal=%ld\nSplitVer=%ld\nFileName=%s\nTerStart=%s\nTerEnd=%s\n",
		CfgFileInfo->FileSize,
		CfgFileInfo->SplitSize,
		CfgFileInfo->FileCRC,
		CfgFileInfo->SplitTotal,
	   CfgFileInfo->SplitVer,
		CfgFileInfo->FileName,
	   CfgFileInfo->TerStart,
	   CfgFileInfo->TerEnd
   );

	windisplay( Buffer );
#endif

	delete [] Buffer;
}

int Read_Cfg_Info( FILE **fp, struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose: Fill the values into the CFGFILEINFO Struct.

	Input: FILE *fp

   Output: CFGFILEINFO *CfgFileInfo

   Return:

   Parameters:
   	FILE *fp - pointer to file containing fileinfo
      CFGFILEINFO *CfgFileInfo - Structure to hold data in
****************************************************************************/
{
	register int a = 0;
	char *Buffer;
   Buffer = new char [ SMALBUFF ];

	if( 0 == fread( &CfgFileInfo->SplitVer, sizeof( unsigned long ), 1, *fp ) )
   {
   	CfgFileInfo->SplitVer = 1;
   }

   FVIndex = Set_FileVer_Info( CfgFileInfo->SplitVer );

	if( FVIndex == TERFVER )
	{
		fread( &CfgFileInfo->FileSize, sizeof( unsigned long ), 1, *fp );
		fread( &CfgFileInfo->SplitSize, sizeof( unsigned long ), 1, *fp );
		fread( &CfgFileInfo->FileCRC, sizeof( unsigned long ), 1, *fp );
		fread( &CfgFileInfo->SplitTotal, sizeof( long ), 1, *fp );

	   fscanf( *fp,"%s", CfgFileInfo->TerStart );
	   Buffer[ 0 ] = getc( *fp );
	   fscanf( *fp,"%s", CfgFileInfo->TerEnd );
	   Buffer[ 0 ] = getc( *fp );
	}
   else
   {
   	CfgFileInfo->TerStart[ 0 ] = NULL;
   	CfgFileInfo->TerEnd	[ 0 ] = NULL;
      return( 0 );
   }

   while( !feof( *fp ) )
   {
   	CfgFileInfo->FileName[ a ] 	= getc( *fp );
      CfgFileInfo->FileName[ a+1 ] 	= NULL;
      a++;
   }

/*	// Old code
	fscanf( *fp, "%s", CfgFileInfo->FileName );
   Buffer[ 0 ] = getc( *fp );
*/
#if DEBUGSPLIT == 1
	sprintf( Buffer, "\nDebug Control File Version ID = %d\n", FileVerIndex[ FVIndex ] );
	windisplay( Buffer );

   sprintf( Buffer,
   	"FileSize=%ld\nSplitSize=%ld\nFileCRC=0x%lX\nSplitTotal=%ld\nSplitVer=%ld\FVIndex=%d\nFileName=%s\nTerStart=%s\nTerEnd=%s\n",
		CfgFileInfo->FileSize,
		CfgFileInfo->SplitSize,
		CfgFileInfo->FileCRC,
		CfgFileInfo->SplitTotal,
	   CfgFileInfo->SplitVer,
      FVIndex,
		CfgFileInfo->FileName,
	   CfgFileInfo->TerStart,
	   CfgFileInfo->TerEnd
   );

	windisplay( Buffer );
#endif

	delete [] Buffer;
   return( 1 );
}

void Strip_Extra_File_Name_Info( struct CFGFILEINFO *CfgFileInfo )
/****************************************************************************
	Purpose:	Removes the Path Name from the FileName String in the CfgFileInfo
   				Struction element->FileName

	Input: CFGFILEINFO *CfgFileInfo

   Output: CFGFILEINFO *CfgFileInfo

   Return:

   Parameters:
      CFGFILEINFO *CfgFileInfo - Structure to hold data in
****************************************************************************/
{
	register int a, b;
	char *TmpFileName;

   TmpFileName = new char [ FILENAME ];

   for( a=0, b=0; a < strlen( CfgFileInfo->FileName ); a++ )
   {
   	TmpFileName[ b ] = CfgFileInfo->FileName[ a ];
      TmpFileName[ b+1 ] = NULL;

      if( TmpFileName[ b ] == 0x5C )
      {
      	b = 0;
      }
      else
      	b++;
   }

   sprintf( CfgFileInfo->FileName, "%s", TmpFileName );

   for( a=0, b=0; a < strlen( CfgFileInfo->TerStart ); a++ )
   {
   	TmpFileName[ b ] = CfgFileInfo->TerStart[ a ];
      TmpFileName[ b+1 ] = NULL;

      if( TmpFileName[ b ] == 0x5C )
      {
      	b = 0;
      }
      else
      	b++;
   }

   sprintf( CfgFileInfo->TerStart, "%s", TmpFileName );

   delete [] TmpFileName;
}

int Set_FileVer_Info( unsigned long VerNumber )
/****************************************************************************
	Purpose: Checkes the Version Number for reverse compatiblity with older
   			   ter and spl file versions.

	Input:	unsigned long VerNumber

   Output:

   Return:
   	Returns the Version Number of the current Ter File.

   Parameters:
      unsigned long VerNumber is the Version Number Index.
****************************************************************************/
{
	register int a;

   for( a=0; a<TERFVER+1; a++ )
   {
   	if( VerNumber == FileVerIndex[ a ] )
      {
         return ( a );
      }
   }

   return( 0 );
}


