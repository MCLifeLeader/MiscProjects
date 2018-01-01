/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/20/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This Modual is for the registery database.

Note: 		This program is developmental code, so that I can become familare
				with the MS Windows API's, and to Learn how to program in MS
            Windows.
****************************************************************************/

#include "splitter.h"

#if WINCOMP == 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <commdlg.h>

int Check_For_Reg_Entry( void )
/****************************************************************************
	Purpose:

	Input:

   Output:

   Return: 0 is success, 1 is failure

   Parameters:
****************************************************************************/
{
	HKEY hKeyResult = 0;
   DWORD dwDisposition = 0;
   LONG lResult = 0;

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, ".TER", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, ".SPL", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, "WinSplitTer", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, "WinSplitTer\\DefaultIcon", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, "WinSplitSpl", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, "WinSplitSpl\\DefaultIcon", 0, KEY_ALL_ACCESS, &hKeyResult );

   if( lResult != ERROR_SUCCESS )
   {
   	return( 1 );
   }

	return( 0 );
}

int Create_Reg_Entry( void )
/****************************************************************************
	Purpose:

	Input:

   Output:

   Return: 0 is success, 1 is failure

   Parameters:
****************************************************************************/
{
	HKEY hKeyResult = 0;
   DWORD dwDisposition = 0;
   LONG lResult = 0;

   // Create "WinSplit" Sheel interface.

   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, "WinSplitTer\\shell\\open\\command",
   								  0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
                             &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Program the Registery to use the WinSplit Program
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("winspltr.exe %1"),
      								 lstrlen( "winspltr.exe %1" ) );
      RegCloseKey( hKeyResult ); // Close Key to WinSplit
   }
   else
   	return( 1 );

   // Set up the DefaultIcon Information.
   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, "WinSplitTer\\DefaultIcon",
   								  0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
                             &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Program the Registery to use the WinSplit ICON
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("winspltr.exe,0"),
      								 lstrlen( "winspltr.exe,0" ) );
      RegCloseKey( hKeyResult ); // Close Key to WinSplit
   }
   else
   	return( 1 );

   // Create .TER file extenstion
   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, ".TER", 0, "", REG_OPTION_NON_VOLATILE,
   								  KEY_ALL_ACCESS, NULL, &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Connect the .TER exetions with he windsplit file
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("WinSplitTer"),
      								 lstrlen( "WinSplitTer" ) );

      RegCloseKey( hKeyResult );
   }
   else
   	return( 1 );

   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, "WinSplitSpl\\shell\\open\\command",
   								  0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
                             &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Program the Registery to use the WinSplit Program
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("winspltr.exe %1"),
      								 lstrlen( "winspltr.exe %1" ) );
      RegCloseKey( hKeyResult ); // Close Key to WinSplit
   }
   else
   	return( 1 );

   // Set up the DefaultIcon Information.
   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, "WinSplitSpl\\DefaultIcon",
   								  0, "", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL,
                             &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Program the Registery to use the WinSplit ICON
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("winspltr.exe,3"),
      								 lstrlen( "winspltr.exe,3" ) );
      RegCloseKey( hKeyResult ); // Close Key to WinSplit
   }
   else
   	return( 1 );

   // Create .SPL file extenstion
   lResult = RegCreateKeyEx( HKEY_CLASSES_ROOT, ".SPL", 0, "", REG_OPTION_NON_VOLATILE,
   								  KEY_ALL_ACCESS, NULL, &hKeyResult, &dwDisposition );

   if( lResult == ERROR_SUCCESS )
   {
   	// Connect the .TER exetions with he windsplit file
   	lResult = RegSetValueEx( hKeyResult, NULL, 0, REG_SZ, reinterpret_cast<const unsigned char *>("WinSplitSpl"),
      								 lstrlen( "WinSplitSpl" ) );

      RegCloseKey( hKeyResult );
   }
   else
   	return( 1 );

	return( 0 );
}

#endif