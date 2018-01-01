/****************************************************************************
Program:    ged2sql2.exe
Author:     Mike Carey
Date:			July 1, 2002
Last Mod:	July 3, 2002
Compiler:   Microsoft .NET C++
Email:		mbcarey@trilument.com

****************************************************************************
Comments:

Note: 		
****************************************************************************/
//#pragma once

#ifndef __FILE_IO_H
#define __FILE_IO_H

#include "stdafx.h"

class FileHandler
{
	public:
	FileHandler( );
	~FileHandler( );

	bool bFirstOpen;		// First instance of a file created?  : default = false
	bool bWriteSuccess;	// Did we write the File Successfully : default = false
	bool bReadSuccess;	// Did we read anything from the file : default = false

	bool MoveHandleToEnd( void );
	bool MoveHandleToBegin( void );
	
	int OpenTheFile( char *logName_P, char *logPath );

	int OpenAFile( void );
	int OpenAFile( char* szSrcFile, char *szSrcPath );

	int OpenANewFile( void );
	int OpenANewFile( char* szSrcFile, char *szSrcPath );

	bool CloseFileHandle( void );

	int ParsePath( char *szPathandFileIn, char *&szFileName, char *&szFilePath );

	int ValidateFileandPath( char *szSrcFile, char *szSrcPath );

	DWORD ReadFileIntoBuffer( void );

	DWORD WriteszBuffertoFile( char *szDataBuffer );
	DWORD WriteszBuffertoFile( const char *szConstDataBuffer );

	DWORD WriteBuffertoFile( char *szDataBuffer, DWORD dwBytesToWrite );
	DWORD WriteBuffertoFile( const char *szConstDataBuffer, DWORD dwBytesToWrite );

	LARGE_INTEGER GetFileSize( void ){ return( liFileSize ); }	
	protected:
	HANDLE hFile;					// Handle to my file

	char *szPathandFile;			// The Path and File name
	char *szFBuffer;				// Pointer to the data read in from a file

	DWORD dwFileSize;				// Size of the File
	DWORD dwBufferRead;			// Size of the File Read Buffer. Must be set before call to ReadFileIntoBuffer();
	DWORD dwNumBytesRead;		// Number of Bytes read into memory
	DWORD dwNumBytesWritten;	// Number of Bytes Written	

	LARGE_INTEGER liFileSize;			// Size of File in 64Bit format
	LARGE_INTEGER liFileLeftToRead;	// Size of the File Left to Read in.
	LARGE_INTEGER lpNewFilePtr;		// The new FilePointer position after a call to MoveHandleTo....( void );

	private:
};

#endif //#define __FILE_IO_H
