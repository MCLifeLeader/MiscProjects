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

//#include <atltime.h>	

#include "File_IO.h"
#include "logging.h"

char appDspMessage[] = { "File Pusher Alert!" };

FileHandler errLogging;

DWORD WriteLogFile( char *szLogText )
{
	DWORD returnVal;
	char *szLogMsg = NULL, *szDateTime = NULL;

   SYSTEMTIME systemTime;
	GetSystemTime( &systemTime );		// gets current time
	
	// ie: "September 25th, 2002 12:23:45.67"  length = 32 add a couple for good measure to 48
	
	szDateTime	= new char [ DATETIMELEN ];	
	//GetTimeFormat( LOCALE_SYSTEM_DEFAULT, TIME_FORCE24HOURFORMAT, systemTime, NULL, szDateTime, DATETIMELEN );
	
	sprintf( szDateTime, "%d:%d:%d:%d:%d:%d:%d", systemTime.wDay, systemTime.wMonth, systemTime.wYear,
				systemTime.wHour, systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds );
	
	szLogMsg		= new char [ strlen( szLogText ) + DATETIMELEN + 1 ];
	
	sprintf( szLogMsg, "%s\t: %s\r\n", szDateTime, szLogText );
		
	returnVal = errLogging.WriteszBuffertoFile( szLogMsg );
	
	delete [] szDateTime;
	delete [] szLogMsg;
	
	szLogMsg = szDateTime = NULL;
	
	return( returnVal );	
}

DWORD WriteLogfile( const char *szConstLogText )
{
	DWORD returnVal;
	char *szLogMsg = NULL, *szDateTime = NULL;

   SYSTEMTIME systemTime;
	GetSystemTime( &systemTime );		// gets current time
	
	// ie: "September 25th, 2002 12:23:45.67"  length = 32 add a couple for good measure to 48
	
	szDateTime	= new char [ DATETIMELEN ];	
	//GetTimeFormat( LOCALE_SYSTEM_DEFAULT, TIME_FORCE24HOURFORMAT, systemTime, NULL, szDateTime, DATETIMELEN );
	
	sprintf( szDateTime, "%d:%d:%d:%d:%d:%d:%d", systemTime.wDay, systemTime.wMonth, systemTime.wYear,
				systemTime.wHour, systemTime.wMinute, systemTime.wSecond, systemTime.wMilliseconds );

	szLogMsg		= new char [ strlen( szConstLogText ) + DATETIMELEN + 1 ];
	sprintf( szLogMsg, "%s\t: %s\r\n", szDateTime, szConstLogText );
	
	returnVal = errLogging.WriteszBuffertoFile( szLogMsg );
	
	delete [] szDateTime;
	delete [] szLogMsg;
	
	szLogMsg = szDateTime = NULL;
	
	return( returnVal );	
}

int DisplayErrorMsg( char *szLogText )
{
#	ifdef _WINDOWS_	
		return MessageBox( NULL, szLogText, appDspMessage, MB_OK | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST );
#	else		
		return printf( "%s", szConstLogText );
#	endif // #ifdef _WINDOWS_	
}

int DisplayErrorMsg( const char *szConstLogText )
{
#	ifdef _WINDOWS_
		return MessageBox( NULL, szConstLogText, appDspMessage, MB_OK | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST );
#	else		
		return printf( "%s", szConstLogText );
#	endif // #ifdef _WINDOWS_	
}

#ifdef _WINDOWS_
	int DisplayErrorMsg( HWND hWnd, char *szLogText )
	{
		return MessageBox( hWnd, szLogText, appDspMessage, MB_OK | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST );
	}

	int DisplayErrorMsg( HWND hWnd, const char *szConstLogText )
	{
		return MessageBox( hWnd, szConstLogText, appDspMessage, MB_OK | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST );
	}
#endif // #ifdef _WINDOWS_
