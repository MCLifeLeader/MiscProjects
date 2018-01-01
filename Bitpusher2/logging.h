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

#ifndef __LOGGING_H
#define __LOGGING_H

#include "File_IO.h"

#define DATETIMELEN 128

DWORD WriteLogFile( char *szLogText );
DWORD WriteLogfile( const char *szConstLogText );

int DisplayErrorMsg( char *szLogText );
int DisplayErrorMsg( const char *szConstLogText );

#ifdef _WINDOWS_
	int DisplayErrorMsg( HWND hWnd, char *szLogText );
	int DisplayErrorMsg( HWND hWnd, const char *szConstLogText );	
#endif // #ifdef _WINDOWS_

extern FileHandler errLogging;

#endif //#define __LOGGING_H
