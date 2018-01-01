/****************************************************************************
Program:    bitpusher.exe
Author:     Mike Carey
Date:			July 1, 2002
Last Mod:	Sept 1, 2002
Compiler:   Microsoft .NET C++
Email:		mbcarey@trilument.com

****************************************************************************
Comments:

Note: 		
****************************************************************************/

#include "File_IO.h"
#include "logging.h"

// ********** Public class Methods

// szPathandFileIn can be the same for szFileName
// if a NULL pointered string was passed in for szFileName or szFilePath this function
// will allocate memory for the return of this value. Remember to clean up that memory.

// -1 Invalid string passed in for szPathandFileIn
int FileHandler::ParsePath( char *szPathandFileIn, char *&szFileName, char *&szFilePath )
{
	int returnVal = 0;
	register int a, b;
	int intPathandFileLen = 0, intFileNameLen = 0, intPathNameLen = 0;	
	char *tFileName = NULL, *tPathName = NULL;
		
	if( szPathandFileIn == NULL )
	{
		returnVal = -1;
	}
	else
	{
		intPathandFileLen = ( int )strlen( szPathandFileIn );

      //Remeber to clean up the memory for any strings returned from this function
		tFileName = new char [ intPathandFileLen + 1 ];
		tPathName = new char [ intPathandFileLen + 1 ];
		
		for( a=0, b=0; a<intPathandFileLen; a++, b++ )
		{
		   // Valid FilePath string examples.
		   
	      // "c:\\myDir\\MyFile.Ged.log"
	      // "\\myDir\\MyFile.Ged.log"
	      // "myFile.Ged.log"
	      // "..\\MyFile.Ged.log"
	      // "\\MyFile.Ged.log"
			if( szPathandFileIn[ a ] == '\\' )
			{
			   b = -1;  // This set the  b  variable as a flag			   
			}
			
			if( b >= 0 ) // This sets  b  up to skip a character as it is being processed
			   tPathName[ a ] = tFileName[ b ] = szPathandFileIn[ a ];
			else
			   tPathName[ a ] = szPathandFileIn[ a ];
		}
		
		tPathName[ a ] = tFileName[ b ] = NULL;
		
		// This removes the FileName from the whole string.
		if( intPathandFileLen >= ( int )strlen( tFileName ) )
		   tPathName[ intPathandFileLen - ( int )strlen( tFileName ) ] = NULL;
		
		if( szFileName == NULL )
		{
			if( szFilePath == NULL )
			{
				// Set The path and FileName
				szFileName = new char [ strlen( tFileName ) + 1 ];
				szFilePath = new char [ strlen( tPathName ) + 1 ];
				
			   sprintf( szFileName, "%s", tFileName );
			   sprintf( szFilePath, "%s", tPathName );
			}
			else
			{
				// Set the FileName
				szFileName = new char [ strlen( tFileName ) + 1 ];
				sprintf( szFileName, "%s", tFileName );
			}
		}
		else
		{
			if( szFilePath == NULL )
			{
				// Set the Path
				szFilePath = new char [ strlen( tPathName ) + 1 ];				
			   sprintf( szFilePath, "%s", tPathName );
			}
		}
	}
	
	if( tFileName )
		delete [] tFileName;
	if( tPathName )
		delete [] tPathName;

   return returnVal;
}

// -1 Invalid FileName
// -2 File Size is Zero or File Error
// -3 Invalid Path
// -4 Invalid Path and FileName
int FileHandler::ValidateFileandPath( char *szFileName, char *szFilePath )
{
	int returnVal = 0;
	DWORD dwPathSize;
	char *szTempFilePath = NULL;
	
	dwFileSize = dwPathSize = 0;
	
	// First try with what we have been given.
	if( szFileName )
	{	
		// Open the file with the given path and file name
		hFile = CreateFile( szFileName, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL );
		if( hFile == INVALID_HANDLE_VALUE )
		{
			if( szFilePath )
			{
				szTempFilePath = new char [ strlen( szFileName ) + strlen( szFilePath ) + 2 ];
				
				// check for the \ as the last character in the path
				if( szFilePath[ strlen( szFilePath ) ] == '\\' )
				{					
					sprintf( szTempFilePath, "%s%s", szFilePath, szFileName );
				}
				else
				{
					sprintf( szTempFilePath, "%s\\%s", szFilePath, szFileName );
				}
				
				// Open the file with the given path and file name
				hFile = CreateFile( szTempFilePath, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL );
				if( hFile == INVALID_HANDLE_VALUE )
				{
					returnVal = -4;	// Bad FileName and Path.
				}
				else if( 0 >= GetFileSizeEx( hFile, &liFileSize ) && NULL == liFileSize.QuadPart ) // GetFileSize
				{
					returnVal = -2;	// Recived read Error or the Size of the File is Zero
				}
			}
			else
			{
				returnVal = -3; // Invalid Path
			}
		}
		else
		{
			// Successfully opened the file set the szTempFilePath variable in the class
			szTempFilePath = new char [ strlen( szFileName ) + 1 ];
			sprintf( szTempFilePath, "%s", szFileName );
		}
		// File Size does not need to be checked here it will be checked later.
		
		// Second try with what we have not been given.
		if( hFile == INVALID_HANDLE_VALUE )
		{	// Try the relative path;
			if( szTempFilePath )
			{
				delete [] szTempFilePath;
				szTempFilePath = NULL;
			}
			
			dwPathSize = GetCurrentDirectory( 0, NULL ) + strlen( szFileName ) + 2;
			szTempFilePath = new char [ dwPathSize ];
			
			if( szTempFilePath )
			{
				// Get the location from where this program was executed from... ?
				GetCurrentDirectory( dwPathSize, szTempFilePath );
				
				strcat( szTempFilePath, "\\" );
				strcat( szTempFilePath, szFileName );
				
				// Open the file
				hFile = CreateFile( szTempFilePath, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL );
				if( hFile == INVALID_HANDLE_VALUE )
				{
					returnVal = -1; // Invalid File the Path is wrong because there is no File to find the path for.
				}
				else if( 0 >= GetFileSizeEx( hFile, &liFileSize ) && NULL == liFileSize.QuadPart ) // GetFileSize
				{
					returnVal = -2;	// Recived Error or the Size of the File is Zero
				}
			}
			else
			{
				returnVal = -3;	// Invalid Path
			}
		}
		else if( 0 >= GetFileSizeEx( hFile, &liFileSize ) && NULL == liFileSize.QuadPart ) // GetFileSize
		{
			returnVal = -2;	// Recived read Error or the Size of the File is Zero
		}
	}
	else
	{
		returnVal = -1;		
	}

	if( returnVal == 0 )
	{
		// Check to see if the FilePath was found
		if( szTempFilePath )
		{
			// Check to see if FileName and Path was good present and free the memory
			if( szPathandFile )
				delete [] szPathandFile;
			
			// Create some new memory for the new path and filename
			szPathandFile = new char [ strlen( szTempFilePath ) + 1 ];

			// Copy the FilePath and Name into the Class Variable szPathandFile
			sprintf( szPathandFile, "%s", szTempFilePath );
		}
		else
			szPathandFile = NULL;
		
		liFileLeftToRead = liFileSize;
		
		// This sets dwFileSize only if the actual FileSize is less than the sizeof( DWORD );
		// LARGE_INTEGER.HighPart is the High DWORD
		// LARGE_INTEGER.LowPart is the Low DWORD
		// LARGE_INTEGER.QuadPart is the combinded 64 bit value of both the HighPart and LowPart		
		if( liFileSize.HighPart == NULL )
			dwFileSize = liFileSize.LowPart;
		else
			dwFileSize = NULL; // else set dwFileSize to 0
	}	
	
	if( szTempFilePath )	// Free up some memory if allocated.
		delete [] szTempFilePath;
		
	return( returnVal );	// File and Path are Correct
}

// 0 = Created a new file if one did not exist
// -1 = Invalid file
// -2 = File Already Open
// -3 = No File and Path information in Class::szPathandFile Variable
int FileHandler::OpenAFile( void )
{
	int returnVal = 0;
	
	if( szPathandFile )
	{
		if( hFile == INVALID_HANDLE_VALUE )
		{
			// Open the file or Create one
			hFile = CreateFile( szPathandFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, 0, NULL );		
			if( hFile == INVALID_HANDLE_VALUE )
			{
				returnVal = -1; // Invalid File the Path is wrong because there is no File to find the path for.
			}
		}
		else
		{
			returnVal = -2;	// Files is already open
		}
	}
	else
	{
		returnVal = -3;
	}
	
	return returnVal;
}

// 0 = Created a new file if one did not exist
// -1 = Invalid file
// -2 = File Already Open
// szSrcPath is optional but must be a NULL pointer'd Variable if nothing used.
int FileHandler::OpenAFile( char *szSrcFile, char *szSrcPath )
{
	int returnVal = 0;
	char *szSourceFile = NULL;
	
	if( szSrcFile )
	{
		if( szSrcPath )
		{
			szSourceFile = new char [ strlen( szSrcFile ) + strlen( szSrcPath ) + 2 ];
			
			if( szSrcPath[ strlen( szSrcPath ) - 1 ] == '\\' )
				szSrcPath[  strlen( szSrcPath ) - 1 ] = NULL;

			sprintf( szSourceFile, "%s\\%s", szSrcPath, szSrcFile );
		}
		else
		{
			szSourceFile = new char [ strlen( szSrcFile ) + 1 ];
			sprintf( szSourceFile, "%s", szSrcFile );
		}
			
		if( hFile == INVALID_HANDLE_VALUE )
		{
			// Open the file or Create one
			hFile = CreateFile( szSourceFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, 0, NULL );
			if( hFile == INVALID_HANDLE_VALUE )
			{
				returnVal = -1; // Invalid File, the Path is wrong because there is no File to find the path for.
			}
			else
			{
				if( szPathandFile )
					delete [] szPathandFile;
				
				szPathandFile = new char [ strlen( szSourceFile ) + 1 ];
				// Put the valid filename info into the Class variable szPathandFile
				sprintf( szPathandFile, "%s", szSourceFile );
			}
		}
		else
		{
			returnVal = -2;	// Files is already open
		}
	}
	else
	{
		returnVal = -1;	// No File Specified
	}
	
	if( szSourceFile )
		delete [] szSourceFile;
	
	szSourceFile = NULL;
	return returnVal;
}

// 0 = Created a new
// -1 = Invalid file
// -2 = File Already Open
// -3 = No File and Path information in Class::szPathandFile Variable
int FileHandler::OpenANewFile( void )
{
	int returnVal = 0;
	
	if( szPathandFile )
	{
		if( hFile == INVALID_HANDLE_VALUE )
		{
			// Open the file or Create one
			hFile = CreateFile( szPathandFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, 0, NULL );		
			if( hFile == INVALID_HANDLE_VALUE )
			{
				returnVal = -1; // Invalid File the Path is wrong because there is no File to find the path for.
			}
		}
		else
		{
			returnVal = -2;	// Files is already open
		}
	}
	else
	{
		returnVal = -3;
	}
	
	return returnVal;
}

// 0 = Created a new file
// -1 = Invalid file
// -2 = File Already Open
// szSrcPath is optional but must be a NULL pointer'd Variable if nothing used.
int FileHandler::OpenANewFile( char *szSrcFile, char *szSrcPath )
{
	int returnVal = 0;
	char *szSourceFile = NULL;
	
	if( szSrcFile )
	{
		if( szSrcPath )
		{
			szSourceFile = new char [ strlen( szSrcFile ) + strlen( szSrcPath ) + 2 ];
			
			if( szSrcPath[ strlen( szSrcPath ) - 1 ] == '\\' )
				szSrcPath[  strlen( szSrcPath ) - 1 ] = NULL;

			sprintf( szSourceFile, "%s\\%s", szSrcPath, szSrcFile );
		}
		else
		{
			szSourceFile = new char [ strlen( szSrcFile ) + 1 ];
			sprintf( szSourceFile, "%s", szSrcFile );
		}
			
		if( hFile == INVALID_HANDLE_VALUE )
		{
			// Open the file or Create one
			hFile = CreateFile( szSourceFile, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, 0, NULL );
			if( hFile == INVALID_HANDLE_VALUE )
			{
				returnVal = -1; // Invalid File, the Path is wrong because there is no File to find the path for.
			}
			else
			{
				if( szPathandFile )
					delete [] szPathandFile;
				
				szPathandFile = new char [ strlen( szSourceFile ) + 1 ];
				// Put the valid filename info into the Class variable szPathandFile
				sprintf( szPathandFile, "%s", szSourceFile );
			}
		}
		else
		{
			returnVal = -2;	// Files is already open
		}
	}
	else
	{
		returnVal = -1;	// No File Specified
	}
	
	if( szSourceFile )
		delete [] szSourceFile;
	
	szSourceFile = NULL;
	return returnVal;
}

// If there is no path use a NULL pointer'd string for the input value for logPath
int FileHandler::OpenTheFile( char *logName_P, char *logPath )
{
	int returnVal = 0;
	char *szBuffLogName	= NULL;	// A Buffer containing the Name of the logFile to be.
	char *szBuffPathName	= NULL;	// A Buffer containing the path information
	char *szVolitile1		= NULL;	// Dealing with volitile memory issues
	char *szVolitile2		= NULL;	// Dealing with volitile memory issues
	char *logName			= NULL;	// Name of the actual log file
	
	if( ( logPath != NULL ) && ( logName_P != NULL ) )
	{
		// create the logName file with the same file name plus the word LOG at the end.
		// ie "MyGedFile.Ged.log"	
		logName = new char [ strlen( logName_P ) + 5 ];
		sprintf( logName, "%s.log", logName_P );
		
		returnVal = ValidateFileandPath( logName, logPath );
	
		if( returnVal < 0 )
		{
			// logName and logPath should be stored in FileHandler Class at this point from the call to
			//	ValidateFileandPath( char *, char * ) if not then call the overloaded function OpenAFile
			// passing the FileName and Path; Path is optional but must be a NULL pointer if nothing used.
			returnVal = OpenAFile( );
			if( returnVal < 0 )
			{
				returnVal = OpenAFile( logName, logPath );
				if( returnVal == 0 )
					bFirstOpen = true;
			}
		}
	}
	else
	{
		if( logName_P == NULL )	// If this is not NULL then logPath is the only one that could be NULL
		{
			returnVal = -1;
		}
		else
		{
			if( logPath == NULL )	// Check logPath just to be sure that it really is NULL
			{
				// Parse the Path
				returnVal = ParsePath( logName_P, szVolitile1, szVolitile2 );
				
				szBuffLogName = new char [ strlen( szVolitile1 ) + 1 ];
				szBuffPathName = new char [ strlen( szVolitile2 ) + 1 ];
				
				sprintf( szBuffLogName, "%s", szVolitile1 );
				sprintf( szBuffPathName, "%s", szVolitile2 );
				
				if( szVolitile1 )
					delete [] szVolitile1;
				if( szVolitile2 )
					delete [] szVolitile2;
					
				szVolitile1 = szVolitile2 = NULL;
				
				if( strlen( szBuffPathName ) <= 0 )
				{
					delete [] szBuffPathName;
					szBuffPathName = NULL;
				}
				
				if( returnVal == 0 )
				{
					// See if the path is good.

					logName = new char [ strlen( szBuffLogName ) + 5 ];
					sprintf( logName, "%s.log", szBuffLogName );

					if( szBuffLogName )
						delete [] szBuffLogName;
					
					returnVal = ValidateFileandPath( logName, szBuffPathName );
					
					if( returnVal < 0 )
					{
						// logName and logPath should be stored in FileHandler Class at this point from the call to
						//	ValidateFileandPath( char *, char * ) if not then call the overloaded function OpenAFile
						// passing the FileName and Path; Path is optional but must be a NULL pointer if nothing used.
						returnVal = OpenAFile( );						
						if( returnVal < 0 )
						{
							// try again to open the log file.
							returnVal = OpenAFile( logName, szBuffPathName );
							if( returnVal == 0 )
								bFirstOpen = true;
						}
					}
				}
			}
		}
	}
	
	if( returnVal == 0 )
		MoveHandleToEnd( );

	if( logName )
		delete [] logName;
		
	logName = NULL;
	return returnVal;
}

bool FileHandler::CloseFileHandle( void ) 
{
	bool returnVal = CloseHandle( hFile );
	
	if( returnVal == true )
		hFile = INVALID_HANDLE_VALUE;
	
	return( returnVal ); 
}


// Move the File Pointer to the Begining of the File
bool FileHandler::MoveHandleToBegin( void )
{
	LARGE_INTEGER liDistToMove;	
	liDistToMove.QuadPart = NULL;	
	
	if( hFile != INVALID_HANDLE_VALUE )
		return( SetFilePointerEx( hFile, liDistToMove, &lpNewFilePtr, FILE_BEGIN ) );

	return( false );
}

// Move the File Pointer to the End of the File
bool FileHandler::MoveHandleToEnd( void )
{
	LARGE_INTEGER liDistToMove;	
	liDistToMove.QuadPart = NULL;	
	
	if( hFile != INVALID_HANDLE_VALUE )
		return( SetFilePointerEx( hFile, liDistToMove, &lpNewFilePtr, FILE_END ) );

	return( false );
}

// The return value is the total number of bytes not read into memory 0 is success
DWORD FileHandler::ReadFileIntoBuffer( void )
{		
	if( hFile != INVALID_HANDLE_VALUE || dwBufferRead != 0 )
	{
		// Allocate the amount for dwBufferRead for the duration of the file read.
		if( szFBuffer == NULL )
			szFBuffer = new char [ dwBufferRead + 1 ];

		// Check the amount of file left to read and then only read that portion needed
		if( liFileLeftToRead.HighPart == NULL )
		{
			if( liFileLeftToRead.LowPart < dwBufferRead && liFileLeftToRead.LowPart != NULL )
				dwBufferRead = liFileLeftToRead.LowPart;
		}
				
		// Read from the file and then Check for end of file.
		if ( ReadFile( hFile, szFBuffer, dwBufferRead, &dwNumBytesRead, NULL) &&  dwNumBytesRead == NULL )
		{
			bReadSuccess = false;
			// we’re at the end of the file
			return( 0 );
		}		
		else
		{
			bReadSuccess = true;
			szFBuffer[ dwBufferRead + 1 ] = NULL;
			
			liFileLeftToRead.QuadPart -= dwNumBytesRead;
		}
	}
	else
		return( 0 );   

   return( dwBufferRead - dwNumBytesRead );
}

// The return value is the total number of bytes not written 0 is success
DWORD FileHandler::WriteszBuffertoFile( char *szDataBuffer )
{
	DWORD dwBytesToWrite = ( DWORD )strlen( szDataBuffer );
	dwNumBytesWritten = 0;
	
	if( hFile != INVALID_HANDLE_VALUE )
		WriteFile( hFile, szDataBuffer, dwBytesToWrite, &dwNumBytesWritten, NULL );
	else
		DisplayErrorMsg( "Invalid File Handle Found - File Not open.\n" );
	
	return( dwBytesToWrite - dwNumBytesWritten );
}

// The return value is the total number of bytes not written 0 is success
DWORD FileHandler::WriteszBuffertoFile( const char *szConstDataBuffer )
{
	DWORD dwBytesToWrite = ( DWORD )strlen( szConstDataBuffer );	
	dwNumBytesWritten = 0;
	
	if( hFile != INVALID_HANDLE_VALUE )
		WriteFile( hFile, szConstDataBuffer, dwBytesToWrite, &dwNumBytesWritten, NULL );
	else
		DisplayErrorMsg( "Invalid File Handle Found - File Not open.\n" );

	return( dwBytesToWrite - dwNumBytesWritten );
}

// The return value is the total number of bytes not written 0 is success
DWORD FileHandler::WriteBuffertoFile( char *szDataBuffer, DWORD dwBytesToWrite )
{
	DWORD dwNumBytesWritten = 0;
	
	if( hFile != INVALID_HANDLE_VALUE )
		WriteFile( hFile, szDataBuffer, dwBytesToWrite, &dwNumBytesWritten, NULL );
	else
		DisplayErrorMsg( "Invalid File Handle Found - File Not open.\n" );
	
	return( dwBytesToWrite - dwNumBytesWritten );
}

// The return value is the total number of bytes not written 0 is success
DWORD FileHandler::WriteBuffertoFile( const char *szConstDataBuffer, DWORD dwBytesToWrite )
{
	DWORD dwNumBytesWritten = 0;
	
	if( hFile != INVALID_HANDLE_VALUE )
		WriteFile( hFile, szConstDataBuffer, dwBytesToWrite, &dwNumBytesWritten, NULL );
	else
		DisplayErrorMsg( "Invalid File Handle Found - File Not open.\n" );

	return( dwBytesToWrite - dwNumBytesWritten );
}

// ********** Protected class Methods
FileHandler::FileHandler( )
{
	szPathandFile	= NULL;
	szFBuffer		= NULL;

	hFile = INVALID_HANDLE_VALUE;	// Handle to my file	
	dwFileSize				= 0; // Size of the File
	dwBufferRead			= 0; // Size of the File Read Buffer
	dwNumBytesRead			= 0; // Number of Bytes read into memory
	dwNumBytesWritten		= 0; // Number of Bytes written to disk
	liFileSize.QuadPart			= 0; // Size of File in 64Bit format
	liFileLeftToRead.QuadPart	= 0; // The Amount Left to Read from a File.
	lpNewFilePtr.QuadPart		= 0; // The New File Pointer Position after a call to MoveHandleTo.....( void );

	bFirstOpen = bWriteSuccess = bReadSuccess = false;
}

FileHandler::~FileHandler( )
{
	if( szPathandFile )
		delete [] szPathandFile;
	if( szFBuffer )
		delete [] szFBuffer;
	if( hFile != INVALID_HANDLE_VALUE )
		CloseHandle( hFile );
}

// ********** Private class Methods
