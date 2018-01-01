/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/20/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This program is designed to Split up large files into smaller ones

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

#if defined (WIN32)
   #define IS_WIN32 TRUE
#else
   #define IS_WIN32 FALSE
#endif

// Windows Macros for IDing what windows Platform is running.
#define IS_NT		IS_WIN32 && (BOOL)(GetVersion() < 0x80000000)
#define IS_WIN32S	IS_WIN32 && (BOOL) (!(IS_NT) && \
												 (LOBYTE(LOWORD(GetVersion()))<4))
#define IS_WIN95	(BOOL)(!(IS_NT) && !(IS_WIN32S)) & IS_WIN32

LPCTSTR lpszAppName 	= "SplitApp";
LPCTSTR lpszTitle		= "Windows File Splitter";

HINSTANCE hInst;
HMENU hMenu;
HWND ghWnd;
OPENFILENAME OpnFileName;

char *Buffer;
char *gFileName;
char *gSFileName;
char *FileName;
char *TmpString;

int gSplitTotal 	= NULL;
int RestoreFlag 	= NULL;
int SplitFlag 		= NULL;
int nNumItems 		= NULL;
int *nNumRows		= NULL;

long gSplitSize = DEFUALTFILESZ;

WNSCROLLTEXTBUFF *WnScrollTextBuffH = NULL;
WNSCROLLTEXTBUFF *WnScrollTextBuff = NULL;

BOOL RegisterWin95( CONST WNDCLASS* lpwc );

int APIENTRY WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
                      LPTSTR lpCmdLine, int nCmdShow )
/****************************************************************************
Purpose: Main Windows Entery Point

Input:

Output:

Return:

Parameters:
****************************************************************************/
{
   MSG      msg;
   HWND     hWnd;
   WNDCLASS wc;

   gFileName 	= new char [ FILENAME ];
   gSFileName	= new char [ FILENAME ];
   Buffer 		= new char [ FILENAME ];
   FileName 	= new char [ FILENAME ];
   TmpString	= new char [ LARGBUFF ];

   nNumRows		= new int  [ MAXITEMS ];

   Buffer	 [ 0 ] 	= NULL;
   gFileName [ 0 ] 	= NULL;
   gSFileName[ 0 ]	= NULL;
   FileName	 [ 0 ] 	= NULL;
   nNumRows	 [ 0 ] 	= NULL;

	// Set the base Windows Class information.
   if ( !hPrevInstance )
   {
	   wc.style				= CS_HREDRAW | CS_VREDRAW;
	   wc.lpfnWndProc		= (WNDPROC)WndProc;
	   wc.cbClsExtra		= 0;
	   wc.cbWndExtra		= 0;
	   wc.hInstance		= hInstance;
	   wc.hIcon				= LoadIcon ( hInstance, MAKEINTRESOURCE( 1 ) );
	   wc.hCursor			= LoadCursor( NULL, IDC_ARROW );
	   wc.hbrBackground 	= ( HBRUSH )( COLOR_WINDOW+1 );
	   wc.lpszMenuName 	= MAKEINTRESOURCE( 1 );
	   wc.lpszClassName 	= lpszAppName;

	   if ( IS_WIN95 )
	   {
	   	if ( !RegisterWin95(&wc) )
         {
			   delete [] TmpString;
			   delete [] gFileName;
            delete [] gSFileName;
		   	delete [] Buffer;
			  	delete [] FileName;
            delete [] nNumRows;

	      	return( FALSE );
         }
	   }
	   else
      {
      	if (! RegisterClass( &wc ) )
         {
			   delete [] TmpString;
			   delete [] gFileName;
            delete [] gSFileName;
   			delete [] Buffer;
			  	delete [] FileName;
            delete [] nNumRows;

	   		return( FALSE );
         }
      }
   }

   // Application ID
   hInst = hInstance;

	// Create Main Application Window init vars
   hWnd  = CreateWindow( lpszAppName,
  								lpszTitle,
                        WS_OVERLAPPEDWINDOW | WS_VSCROLL | WS_HSCROLL,
   							CW_USEDEFAULT,
                        0,
                        CW_USEDEFAULT,
                        0,
                        NULL,
                        NULL,
                        hInstance,
                        NULL );

	ghWnd = hWnd;  // Set a Global Var to the handle of the window

   // Memory clean up
   if ( !hWnd )
	{
   	// Clean up memory and quit
	   delete [] TmpString;
	   delete [] gFileName;
      delete [] gSFileName;
   	delete [] Buffer;
	  	delete [] FileName;
      delete [] nNumRows;

   	return ( FALSE );
   }

   ShowWindow( hWnd, nCmdShow );
   UpdateWindow( hWnd );

   // Windows Message Dispatch
   while( GetMessage( &msg, NULL, 0, 0 ) )
   {
   	TranslateMessage( &msg );
      DispatchMessage( &msg );
   }

   CleanUp_Window_Strings();

	delete [] TmpString;
   delete [] gFileName;
   delete [] gSFileName;
  	delete [] Buffer;
  	delete [] FileName;
	delete [] nNumRows;
	delete [] OpnFileName.lpstrFile;
   delete [] OpnFileName.lpstrFileTitle;

   return( msg.wParam );
}

BOOL RegisterWin95( CONST WNDCLASS* lpwc )
/****************************************************************************
	Purpose: Register the Class so that the system knows how to handle the windows functions

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	WNDCLASSEX wcex;

   wcex.style				= lpwc->style;
   wcex.lpfnWndProc		= lpwc->lpfnWndProc;
   wcex.cbClsExtra		= lpwc->cbClsExtra;
   wcex.cbWndExtra		= lpwc->cbWndExtra;
   wcex.hInstance			= lpwc->hInstance;
   wcex.hIcon				= lpwc->hIcon;
   wcex.hCursor			= lpwc->hCursor;
   wcex.hbrBackground 	= lpwc->hbrBackground;
	wcex.lpszMenuName		= lpwc->lpszMenuName;
   wcex.lpszClassName	= lpwc->lpszClassName;
   wcex.cbSize 			= sizeof( WNDCLASSEX );
   wcex.hIconSm			= LoadIcon( wcex.hInstance, MAKEINTRESOURCE( 2 ) );

   return RegisterClassEx( &wcex );
}

void Init_OpenFileStruct( HWND hWnd )
/****************************************************************************
	Purpose:	Initlize the Open file/Save File Data Structure

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	OpnFileName.lStructSize 			= sizeof( OPENFILENAME );
	OpnFileName.hwndOwner 				= hWnd;
	OpnFileName.hInstance 				= hInst;
	OpnFileName.lpstrFilter 			= "All Files \(*.*\)\0*.*\0\0";
	OpnFileName.Flags 					= 	OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_LONGNAMES |
	                         				OFN_PATHMUSTEXIST | OFN_READONLY | OFN_HIDEREADONLY;
   OpnFileName.lpstrFile 				= new char [ FILENAME ];
   OpnFileName.lpstrFile[ 0 ]			= NULL;
   OpnFileName.nMaxFile 				= FILENAME;
   OpnFileName.lpstrFileTitle 		= new char [ SMALBUFF ];
   OpnFileName.lpstrFileTitle[ 0 ] 	= NULL;
   OpnFileName.nMaxFileTitle 			= SMALBUFF;
   OpnFileName.lpstrDefExt 			= new char [ 5 ];
   strcpy( OpnFileName.lpstrDefExt, "SPL" );
}

//#pragma warn -par
void ProcessFileData( void )
/****************************************************************************
	Purpose: Chagne the File name entered to the *.spl extention

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	int flag, a, b;

   strcpy( FileName, OpnFileName.lpstrFileTitle );

	flag = 0;

	/* Find the file out of the path */
	for( a=0, b=0; a < strlen( OpnFileName.lpstrFileTitle ); a++ )
	{
		FileName[ b   ] = OpnFileName.lpstrFileTitle[ a ];
		FileName[ b+1 ] = NULL;
		b++;
		if( FileName[ a ] == '\\' )
	   {
			b = 0;
      }
	}

	for( a=0; FileName[ a ]; a++ )
   {
		if( FileName[ a ] == '.' )
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
	if( !flag )
   {
		FileName[ a   ] = '.';
		FileName[ a+1 ] = 'S';
		FileName[ a+2 ] = 'P';
		FileName[ a+3 ] = 'L';
		FileName[ a+4 ] = NULL;
	}
}
//#pragma warn .par

void Get_FileName_to_Process( char *ReturnStr, char *InputStr )
/****************************************************************************
	Purpose: Check for the *.SPL file Extension.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	char *TmpString, *Buffer;

/*
   Buffer 		= new char [ strlen ( "c:\\code\\splitter\\moo2v131.spl" ) + 1 ];
   TmpString 	= new char [ strlen ( "c:\\code\\splitter\\moo2v131.spl" ) + 1 ];

   sprintf( TmpString, "c:\\code\\splitter\\moo2v131.spl" ); // Debug line Remove later
*/

   Buffer 		= new char [ strlen( InputStr ) + 1 ];
   TmpString 	= new char [ strlen( InputStr ) + 1 ];

   sprintf( TmpString, "%s", InputStr );

//   note( TmpString );

   if( strlen( TmpString ) > 2 )
   {
      Buffer[ 0 ] = TmpString[ strlen( TmpString ) -2 ];
      Buffer[ 1 ] = TmpString[ strlen( TmpString ) -1 ];
      Buffer[ 2 ] = TmpString[ strlen( TmpString ) ];

      Buffer[ 3 ] = NULL;

      if( !stricmp( Buffer, " -S" ) )
      {
      	strcpy( ReturnStr, TmpString );
         FileName[ strlen( TmpString ) - 2 ] = NULL;
      	SplitFlag = 4;
      }
      else
      {
		   if( strlen( TmpString ) > 4 )
		   {
		      Buffer[ 0 ] = TmpString[ strlen( TmpString ) -4 ];
		      Buffer[ 1 ] = TmpString[ strlen( TmpString ) -3 ];
		      Buffer[ 2 ] = TmpString[ strlen( TmpString ) -2 ];
		      Buffer[ 3 ] = TmpString[ strlen( TmpString ) -1 ];
		      Buffer[ 4 ] = TmpString[ strlen( TmpString ) ];

            Buffer[ 5 ] = NULL;

		   	if( !stricmp( Buffer, ".SPL" ) )
	         {
	           	strcpy( ReturnStr, TmpString );
		      	SplitFlag = 3;
	         }
		   }
      }
   }

//   delete [] Buffer;
//   delete [] TmpString;
}

void hscroll( HWND hWnd, int* pnCurPos, WORD wScroll )
/****************************************************************************
	Purpose: Horizontal screen update handler

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	int nMin, nMax;
   int nPos;

   GetScrollRange( hWnd, SB_HORZ, &nMin, &nMax );
   nPos = GetScrollPos( hWnd, SB_HORZ );
   switch( wScroll )
   {
   	case SB_LINERIGHT:
      	if( *pnCurPos < nMax )
         	*pnCurPos += 1;
         break;

      case SB_LINELEFT:
      	if( *pnCurPos > 0 )
         	*pnCurPos -= 1;
         break;
   }

   if( nPos != *pnCurPos )
   {
   	RECT cltRect;
      HDC hDC = GetDC( hWnd );

      GetClientRect( hWnd, &cltRect );
      cltRect.left 	+= 20;
      cltRect.right 	-= 20;
      cltRect.top		+= 20;
      cltRect.bottom -= 20;

      ScrollDC( hDC, ( *pnCurPos-nPos)*20, 0, NULL, &cltRect, NULL, NULL );

      SetScrollPos( hWnd, SB_HORZ, *pnCurPos, TRUE );
   }
}

void vscroll( HWND hWnd, int* pnCurPos, WORD wScroll )
/****************************************************************************
	Purpose: Vertical screen update handler.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	int nMin, nMax;
   int nPos;

   GetScrollRange( hWnd, SB_VERT, &nMin, &nMax );
   nPos = GetScrollPos( hWnd, SB_VERT );
   switch( wScroll )
   {
   	case SB_LINEDOWN:
      	if( *pnCurPos < nMax )
         	*pnCurPos += 1;
         break;

      case SB_LINEUP:
      	if( *pnCurPos > 0 )
         	*pnCurPos -= 1;
         break;
   }

   if( nPos != *pnCurPos )
   {
   	RECT cltRect;
      HDC hDC = GetDC( hWnd );

      GetClientRect( hWnd, &cltRect );
      cltRect.left 	-= 20;
      cltRect.right 	+= 20;
      cltRect.top		-= 20;
      cltRect.bottom += 20;

      ScrollDC( hDC, ( *pnCurPos-nPos )*20, 0, NULL, &cltRect, NULL, NULL );

      SetScrollPos( hWnd, SB_VERT, *pnCurPos, TRUE );
   }
}

void note( char *String )
/****************************************************************************
	Purpose: Put a message up on the screen. Using a quick Dialog box.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
   char *message;

   message = new char [FILENAME];

   sprintf( message,"%s\n", String );
   MessageBox( ghWnd, message, "Windows Splitter Message", MB_OK );

   delete [] message;
}

void note( const char *String )
/****************************************************************************
	Purpose: Put a Message up on the screen. using a quick Dialog Box

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
   char *message;

   message = new char [ FILENAME ];

   sprintf( message,"%s\n", String );
   MessageBox( ghWnd, message, "Windows Splitter Message", MB_OK );

   delete [] message;
}

void windisplay( char *String )
/****************************************************************************
	Purpose:	Write a message to the main window and send it off to be added to the
   			window update list.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
   register int a,b;
   int LFlag;
   char MoveChar[ 2 ];

   MoveChar[ 0 ] = MoveChar[ 1 ] = NULL;

   for( a=0; a<strlen( String ); a++ )
   {
   	TmpString[ a ] = NULL;
   }

   for( a=0, b=0; a<strlen( String ); a++, b++ )
   {
      if( String[ a ] == '\n' )
      {
		  DisplayTextToScreen( TmpString );
		  nNumItems++;
		  nNumRows[ nNumItems ] = 0;
			
		  String[a] = 0x20;
		  Add_To_Window_String( TmpString );
		  Add_Window_String( "" );
		  TmpString[0] = NULL;

         b = -1;
         LFlag = 0;

         if( String[ a+1 ] == NULL )
         {
         	break;
         }
      }
      else
      {
		
	      nNumRows[nNumItems]++;
		  MoveChar[ 0 ] = TmpString[b] = String[a];
		  TmpString[ b+1 ] = NULL;
		  DisplayTextToScreen( MoveChar );
			LFlag = 1;

         if( String[ a+1 ] == NULL )
         {
				break;
         }
      }
   }

   if( LFlag )
		Add_To_Window_String( TmpString );

//	delete [] TmpString;
   // Force window redraw
	PostMessage( HWND_BROADCAST, WM_PAINT, NULL, NULL );

}

void Add_Window_String( char *String )
/****************************************************************************
	Purpose: Keep track of strings of text entered into the main window. This is
   			is needed if Text is to be restored in the window if the window needs
            to be redrawn.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	if( WnScrollTextBuff )
   {
   	WnScrollTextBuff->nxt 	= new WNSCROLLTEXTBUFF;
      WnScrollTextBuff 			= WnScrollTextBuff->nxt;
   }
   else
   {
   	WnScrollTextBuffH = new WNSCROLLTEXTBUFF;
      WnScrollTextBuff 	= WnScrollTextBuffH;
  	}

//   DisplayTextToScreen( String );

   WnScrollTextBuff->WnTextBuffer = new char [ strlen( String ) + 1 ];
   sprintf( WnScrollTextBuff->WnTextBuffer, "%s", String );
   WnScrollTextBuff->ShowThisLine = TRUE;

   WnScrollTextBuff->nxt = NULL;
}

void Add_To_Window_String( char *String )
/****************************************************************************
	Purpose: Keep track of strings of text entered into the main window. This is
   			is needed if Text is to be restored in the window if the window needs
            to be redrawn.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
   int StrLenVar;
	char *TmpBuffer;

//   DisplayTextToScreen( String );

   StrLenVar = strlen( WnScrollTextBuff->WnTextBuffer ) ;

   if( StrLenVar == 0 )
   	StrLenVar++;

   StrLenVar += strlen( String );

   // allocate new mem for the new string
   TmpBuffer = new char [ StrLenVar + 2 ];

   if( ( WnScrollTextBuff->WnTextBuffer[ 0 ] == 0x20 ) ||
       ( WnScrollTextBuff->WnTextBuffer[ 0 ] == NULL ) )
   {
   	sprintf( TmpBuffer, "%s", String );
   }
   else
   {
		sprintf( TmpBuffer, "%s%s", WnScrollTextBuff->WnTextBuffer, String );
   }

   // Delete the old memory
   delete [] WnScrollTextBuff->WnTextBuffer;

   // Assign the memory allocated to TmpBuffer to new struct var below
   WnScrollTextBuff->WnTextBuffer = TmpBuffer;

   WnScrollTextBuff->ShowThisLine = TRUE;
}

void DisplayTextToScreen( char *String )
{
	HDC hDC;
   HFONT hFont, hOldFont;
	ABC	abc[ 2 ];

	// Init a font to write text to screen
   hFont = CreateFont( 16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
     						  ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                       PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
                       "Times New Roman" );

   hDC = GetDC( ghWnd );

   hOldFont = static_cast<HFONT>(SelectObject( hDC, hFont ));
   GetCharABCWidths( hDC, 'W', 'X', abc );

   // Write text to display
	TextOut( hDC, nNumRows[ nNumItems ]*8, nNumItems*20, String, strlen( String ) ) ;

   SelectObject( hDC, hOldFont );
   ReleaseDC( ghWnd, hDC );
   DeleteObject( hFont );

}

void CleanUp_Window_Strings( void )
/****************************************************************************
	Purpose: Clean Up Memory Windows Scoll buffer data.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	WNSCROLLTEXTBUFF *WnTempBuff;
   WnScrollTextBuff = WnScrollTextBuffH;

   while( WnScrollTextBuff )
   {
   	WnTempBuff = WnScrollTextBuff;

      if( WnTempBuff )
      {
	      delete [] WnTempBuff->WnTextBuffer;
      }
   	WnScrollTextBuff = WnScrollTextBuff->nxt;
   }
}

#endif

