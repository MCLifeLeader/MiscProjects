// bitpusher2.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "bitpusher2Dlg.h"
#include "File_IO.h"
#include "logging.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cbitpusher2App

BEGIN_MESSAGE_MAP(Cbitpusher2App, CWinApp)
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

// Cbitpusher2App construction

Cbitpusher2App::Cbitpusher2App()
{	
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only Cbitpusher2App object

Cbitpusher2App theApp;

// Cbitpusher2App initialization

BOOL Cbitpusher2App::InitInstance()
{	
	int returnVal;
	char *logPath = NULL;
	char *logFile = NULL;
	LARGE_INTEGER liFileLen;
	
	// Need to pull this value from a configuration file for resetting the log file
	liFileLen.QuadPart = 204800; // allow for a 200K log file then reset the log file to Zero
			
	returnVal = errLogging.OpenTheFile( "bitpusher.log", logPath );
	int testval = 0;
	
	// Get the file length of the Log file
	if( errLogging.GetFileSize( ).QuadPart >= liFileLen.QuadPart )
	{
		// If the Log file is to big then close it.
		if( errLogging.CloseFileHandle( ) )
		{
			// reopen a compleatly new logfile overwritting the old one if the current log file is to big
			if( returnVal = errLogging.OpenANewFile( ) == 0 )
			{
				// errLogging.bFirstOpen == true
				
				// write the delimeter data for parsing
				if( WriteLogFile( "Day:Month:Year:Hour:Minute:Second:Millisecond : Parsable Text" ) )
					DisplayErrorMsg( "int Cbitpusher2App::InitInstance There was a problem writing to the LogFile.\n" );

				// Give the user a reason for deleting the log file and starting over.
				if( WriteLogFile( "*** LogFile size exceeded LogFile was Reset ***" ) )
					DisplayErrorMsg( "int Cbitpusher2App::InitInstance There was a problem writing to the LogFile.\n" );
			}
		}
		else
			DisplayErrorMsg( "int Cbitpusher2App::InitInstance There was a problem Closing the LogFile.\n" );
	}
	
	if( errLogging.bFirstOpen == true )
	{
		// This is the first time the log file has ever been executed give the user some
		// information about the log file in a parsable format.
		if( WriteLogFile( "Day:Month:Year:Hour:Minute:Second:Millisecond : Parsable Text" ) )
			DisplayErrorMsg( "int Cbitpusher2App::InitInstance There was a problem writing to the LogFile.\n" );
	}
	
	if( returnVal == 0 )
		errLogging.MoveHandleToEnd( );
	
	WriteLogFile( "*** Bitpusher Log Opened ***" );
	
	// Check the version of windows being used. It must be a Windows NT based operating System.
	OSVERSIONINFO osvi;	
	osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	
	GetVersionEx (&osvi);
	
	bool bIsWindowsNTorLater = 
		( osvi.dwPlatformId == VER_PLATFORM_WIN32_NT ) &&   
		( ( osvi.dwMajorVersion > 4 ) ||
		( ( osvi.dwMajorVersion == 4 ) && ( osvi.dwMinorVersion > 0 ) ) );		
	// Check the version of windows being used. It must be a Windows 2000 based operating System.
	
	if( bIsWindowsNTorLater == true )
	{
		WriteLogFile( "Windows 2000 or Later Detected" );
		// InitCommonControls() is required on Windows XP if an application
		// manifest specifies use of ComCtl32.dll version 6 or later to enable
		// visual styles.  Otherwise, any window creation will fail.
		InitCommonControls();

		CWinApp::InitInstance();

		if (!AfxSocketInit())
		{
			AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
			return FALSE;
		}

		AfxEnableControlContainer();

		Cbitpusher2Dlg dlg;
		m_pMainWnd = &dlg;
		
		INT_PTR nResponse = dlg.DoModal();
		if (nResponse == IDOK)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with OK
		}
		else if (nResponse == IDCANCEL)
		{
			// TODO: Place code here to handle when the dialog is
			//  dismissed with Cancel
		}

		// Since the dialog has been closed, return FALSE so that we exit the
		//  application, rather than start the application's message pump.
	}
	else
	{
		DisplayErrorMsg( "This program is only Supported on the Windows 2000 Platform or Later." );
//		MessageBox( NULL, "This program is only Supported on the Windows 2000 Platform or Later.", "File Pusher Alert!", MB_OK | MB_ICONWARNING );
		WriteLogFile( "Alert! Windows 2000 or Later Not Detected." );
	}
	
	WriteLogFile( "*** Bitpusher Log Closed ***" );
	return FALSE;	
}

