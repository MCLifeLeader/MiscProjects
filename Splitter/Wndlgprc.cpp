/****************************************************************************
Program:    SPLITTER.EXE
Author:     Mike Carey
Date:			03/26/98
Last Mod:	01/20/99
Compiler:   Borland C++ 5.02
Email:		mbcarey@owt.com

****************************************************************************
Comments:	This Modual is for the main window and dialog proc support

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

LRESULT CALLBACK WndProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
/****************************************************************************
	Purpose: Main Windows Message handling process.

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
   static int ShowSplash 	= 0;
   static int UpDateFlag 	= 0;
	static int nDspLines		= 0;
	static int nCurPos 		= 0;

	switch( uMsg )
   {
   	case WM_CREATE:
      	// Init File Open/Save Dialog Box Functions
			Init_OpenFileStruct( hWnd );
			Add_Window_String( "" );
			RestoreFlag = 0;

         if( Check_For_Reg_Entry( ) )
         {
				Create_Reg_Entry( );
         }

      break;

		case WM_ACTIVATEAPP:
	      if( wParam == TRUE )
         {
            if( !ShowSplash )
            {
               sprintf( Buffer, "%s\n", FILEVER );
	         	windisplay( Buffer );
		         sprintf( Buffer, "mbcarey2@gte.net\n" );
               windisplay( Buffer );
					sprintf(Buffer, "Large files into Smaller ones.\n");
               windisplay( Buffer );
					sprintf(Buffer, "When copying the split *.ter files be sure to copy the *.spl file.\n");
               windisplay( Buffer );
					sprintf(Buffer, "That file is a control file that is needed to restore your\n");
               windisplay( Buffer );
					sprintf(Buffer, "split file to it's orignal state.\n \n");
               windisplay( Buffer );

               ShowSplash = 1;

					RestoreFlag = 0;

						// Set File Types and open the "Open File" Dialog box.
					OpnFileName.lpstrFilter 			= "Split Files \(*.SPL\)\0*.SPL\0All Files \(*.*\)\0*.*\0\0";
               OpnFileName.lpstrDefExt 			= "SPL";
					OpnFileName.lpstrFileTitle[ 0 ] 	= NULL;
               OpnFileName.lpstrFile 	  [ 0 ] 	= NULL;

               Get_FileName_to_Process( FileName, GetCommandLine( ) );

		         strcpy( OpnFileName.lpstrFileTitle, FileName );
					ProcessFileData( );

		         if( SplitFlag == 3 )
		         {
					   sprintf( TmpString, "Combine SplitFile %s?\n", FileName );

					   if( MessageBox( ghWnd, TmpString, "Windows Splitter Message", MB_YESNO | MB_ICONWARNING ) == IDYES )
					   {
					   	strcpy( TmpString, "y" );
					   }

						if( !stricmp( TmpString, "y" ) )
					   {
				         // Exicute Restore Function
			     	      if( Reconstruct_Files( FileName ) )
			            {
					         fcloseall( );
				   	     	windisplay( "Error in Restore Process\n" );
			           	}
			            else
			            {
				   	      fcloseall( );
								windisplay( "Done...\n" );
						   }
			         }
					}
		         else
		         {
		         	if( SplitFlag == 4 )
		            {
		            	// put up the Size to split files by dialog box
		            	DialogBox( hInst, MAKEINTRESOURCE( 2 ), hWnd, ( DLGPROC )DlgSplitSizeProc );

		               // Exicute Splitting Function
		      			if( Split_Files_Apart( FileName, OpnFileName.lpstrFileTitle, gSplitSize ) )
		               {
			               fcloseall( );
		               	windisplay( "Error in Split Process\n" );
		               }
		               else
		               {
			               fcloseall( );
								windisplay( "Done...\n" );
		               }
		            }
		         }
					SplitFlag = 0;               
            }
         }
      break;

      case WM_SIZE:
      	{
         	RECT rect;
            GetClientRect( hWnd, &rect );

            nDspLines = rect.bottom / 20;

            if( nDspLines < nNumItems )
            {
            	EnableScrollBar( hWnd, SB_VERT, ESB_ENABLE_BOTH );
               SetScrollRange( hWnd, SB_VERT, 0, nNumItems-nDspLines, FALSE );
               SetScrollPos( hWnd, SB_VERT, nCurPos, FALSE );
/*
		        	ShowScrollBar( hWnd, SB_HORZ, TRUE );
		         SetScrollRange( hWnd, SB_HORZ, 0, 10, FALSE );
		         SetScrollPos( hWnd, SB_HORZ, 0, TRUE );
*/
            	EnableScrollBar( hWnd, SB_HORZ, ESB_DISABLE_BOTH );
            }
            else
            {
            	EnableScrollBar( hWnd, SB_VERT, ESB_DISABLE_BOTH );
            	EnableScrollBar( hWnd, SB_HORZ, ESB_DISABLE_BOTH );
            }
         }

      case WM_MOVING:
      case WM_MOVE:
      	UpDateFlag = 1;
      break;

		case WM_SHOWWINDOW:
			if( wParam == TRUE )
         {
         	UpDateFlag = 1;
         }
         else
         {
         	UpDateFlag = 0;
         }

         switch( lParam )
         {
				case SW_OTHERUNZOOM:
				case SW_PARENTOPENING:
		      	UpDateFlag = 1;
            break;
				case SW_OTHERZOOM:
				case SW_PARENTCLOSING:
		      	UpDateFlag = 0;
            break;
         }
		break;

      case WM_ACTIVATE:
      	if( HIWORD( wParam ) == TRUE )
         {
         	UpDateFlag = 0;
            break;
         }
      	switch( LOWORD( wParam ) )
         {
         	case WA_ACTIVE:
         	case WA_CLICKACTIVE:
		      	UpDateFlag = 1;
            break;
            case WA_INACTIVE:
            	UpDateFlag = 0;
         }
      break;

      case WM_VSCROLL:
      	vscroll( hWnd, &nCurPos, LOWORD( wParam ) );
         UpDateFlag = 1;
      break;

      case WM_HSCROLL:
      	hscroll( hWnd, &nCurPos, LOWORD( wParam ) );
         UpDateFlag = 1;
      break;

      case WM_PAINT:
      	{
         	PAINTSTRUCT ps;
            int	i,j;
            int	nNumPaint;
            HFONT hFont, hOldFont;
            ABC	abc[ 2 ];
            RECT rc;

            nNumPaint = min( nCurPos+nDspLines, nNumItems );
            BeginPaint( hWnd, &ps );
            GetClientRect( hWnd, &rc );

            // Init a Font to place Text to Screen.
            hFont = CreateFont( 16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE,
              						  ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                                PROOF_QUALITY, DEFAULT_PITCH | FF_DONTCARE,
                                "Times New Roman" );
			//static_cast<int>(d)
            hOldFont = static_cast<HFONT>(SelectObject( ps.hdc, hFont ));
            GetCharABCWidths( ps.hdc, 'W', 'X', abc );

            SetMapMode( ps.hdc, MM_TEXT );
            SetWindowExtEx( ps.hdc, 100, 100, NULL );
            SetViewportExtEx( ps.hdc, rc.right, rc.bottom, NULL );

//            if( UpDateFlag == 1 )
//            {

            	WnScrollTextBuff = WnScrollTextBuffH;
               j = 0;
               i = nCurPos;

               // Write Text to Screen
            	while( WnScrollTextBuff )
               {
      	         if( i>nNumPaint )
         	      	break;
                  if( WnScrollTextBuff->ShowThisLine == TRUE )
		            	TextOut( ps.hdc, 10, j*20, WnScrollTextBuff->WnTextBuffer, strlen( WnScrollTextBuff->WnTextBuffer ) ) ;

                  i++;
                  j++;

                  if( WnScrollTextBuff->nxt )
	                  WnScrollTextBuff = WnScrollTextBuff->nxt;
                  else
                  	break;
	            }
//            }

            SelectObject( ps.hdc, hOldFont );
	         EndPaint( hWnd, &ps );
            DeleteObject( hFont );

         	UpDateFlag = 0;
			}
      break;

   	case WM_COMMAND:
      	switch( LOWORD( wParam ) )
         {
	         case IDM_NEW:
               {
						RestoreFlag = 0;
						SplitFlag = 1;

               	// Set File Types and open the "Open File" Dialog box.
						OpnFileName.lpstrFilter 			= "All Files \(*.*\)\0*.*\0\0";
					   OpnFileName.lpstrDefExt 			= "SPL";
						OpnFileName.lpstrFileTitle[ 0 ] 	= NULL;
                  OpnFileName.lpstrFile	  [ 0 ]  = NULL;

               	if( !GetOpenFileName( &OpnFileName ) )
                  {
							SplitFlag = 0;
                     break;
                  }
                  ProcessFileData( );
                  windisplay( "New File To Split\n" );
						windisplay( OpnFileName.lpstrFileTitle );
                  windisplay( "\n" );
// New Idea
               // Exicute Splitting Function
	      			if( Split_Files_Apart( FileName, OpnFileName.lpstrFileTitle, gSplitSize ) )
	               {
		               fcloseall( );
	               	windisplay( "Error in Split Process\n" );
	               }
	               else
	               {
		               fcloseall( );
							windisplay( "Done...\n" );
	               }
            	}
            break;

	         case IDM_OPEN:
               {
						RestoreFlag = 1;
						SplitFlag = 0;

						// Set File Types and open the "Open File" Dialog box.
						OpnFileName.lpstrFilter 			= "Split Files \(*.SPL\)\0*.SPL\0All Files \(*.*\)\0*.*\0\0";
                  OpnFileName.lpstrDefExt 			= "SPL";
						OpnFileName.lpstrFileTitle[ 0 ] 	= NULL;
                  OpnFileName.lpstrFile 	  [ 0 ] 	= NULL;

               	if( !GetOpenFileName( &OpnFileName ) )
                  {
							RestoreFlag = 0;
                     break;
                  }
						ProcessFileData( );
                  windisplay( "Open File To Restore\n" );
						windisplay( OpnFileName.lpstrFileTitle );
                  windisplay( "\n" );
// New Idea
               // Exicute Restore Function
         	      if( Reconstruct_Files( FileName ) )
      	         {
		               fcloseall( );
	               	windisplay( "Error in Restore Process\n" );
               	}
            	   else
         	      {
	   	            fcloseall( );
							windisplay( "Done...\n" );
	               }
            	}
            break;

	         case IDM_SPLIT:
            	if( SplitFlag != 1 )
               {
               	note( "Need to Select a New File to Process\n" );
                  break;
               }

               SplitFlag = 0;

               // Exicute Splitting Function
      			if( Split_Files_Apart( FileName, OpnFileName.lpstrFileTitle, gSplitSize ) )
               {
	               fcloseall( );
               	windisplay( "Error in Split Process\n" );
               }
               else
               {
	               fcloseall( );
						windisplay( "Done...\n" );
               }
	         break;

	        	case IDM_COMBINE:
            	if( RestoreFlag != 1 )
               {
               	note( "Need to Open a File to Restore\n" );
                  break;
               }

               RestoreFlag = 0;

               // Exicute Restore Function
               if( Reconstruct_Files( FileName ) )
               {
	               fcloseall( );
               	windisplay( "Error in Restore Process\n" );
               }
               else
               {
	               fcloseall( );
						windisplay( "Done...\n" );
               }
            break;

	         case IDM_FORCE:

					OpnFileName.lpstrFileTitle[ 0 ] 	= NULL;
               OpnFileName.lpstrFile	  [ 0 ]  = NULL;

               RestoreFlag = 0;

               // Exicute Force File Restore Function
		      	if( Force_CRC_Reconstruct( FileName ) )
               {
	               fcloseall( );
               	windisplay( "Error in Forced Restore Process\n" );
               }
               else
               {
	               fcloseall( );
						windisplay( "Done...\n" );
               }
	          break;

            case IDM_EXIT:
            	DestroyWindow( hWnd );
            	break;

            case IDM_ABOUT:
            	// put up the About this Program Dialog Box
	           	DialogBox( hInst, MAKEINTRESOURCE( 3 ), hWnd, ( DLGPROC )DlgAboutSplitProc );
            break;

            case IDM_SETSPLIT:
            	// put up the Size to split files by dialog box
            	DialogBox( hInst, MAKEINTRESOURCE( 2 ), hWnd, ( DLGPROC )DlgSplitSizeProc );
           	break;

         }
         break;

      case WM_DESTROY:
      	PostQuitMessage( WM_QUIT );
         break;

      default:
      	return( DefWindowProc( hWnd, uMsg, wParam, lParam ) );
   }
   return( 0L );
}

/* Dialog box control functions. */
LRESULT CALLBACK DlgSplitSizeProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
/****************************************************************************
	Purpose: Enter Split Dialog Process Loop

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	switch( uMsg )
   {
   	case WM_INITDIALOG:
     	{
      	ltoa( gSplitSize, Buffer, 10 );
      	SetDlgItemText( hWnd, IDC_SPLITSIZE, Buffer );
      }
      break;
   	case WM_COMMAND:
      	switch( LOWORD( wParam ) )
         {
         	case IDOK:
            {
               GetDlgItemText( hWnd, IDC_SPLITSIZE, Buffer, FILENAME - 1 );

               gSplitSize = atol(Buffer);

					// Keep the file size within tolorance
	            if( gSplitSize < FILESIZELIMIT )
	            {
	            	sprintf( Buffer, "FileSize Too Low must be greater than %ld\n", FILESIZELIMIT );
	            	note( Buffer );
                  gSplitSize = FILESIZELIMIT;
			      	return( FALSE );
	            }
	            EndDialog( hWnd, IDOK );
            }
            break;

         	case IDCANCEL:
	            EndDialog( hWnd, IDCANCEL );
            break;

            case IDHELP:
            break;
         }
         break;
      case WM_DESTROY:
         break;

      default:
      	return( FALSE );
   }
   return( TRUE );
}

LRESULT CALLBACK DlgForceFixProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
/****************************************************************************
	Purpose: Force Fix Dialog Box Message Procsess Loop

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	switch( uMsg )
   {
   	case WM_INITDIALOG:
      {
      	ltoa( gSplitSize, Buffer, 10 );
      	SetDlgItemText( hWnd, IDC_SPLITSIZE, Buffer );

      	itoa( gSplitTotal, Buffer, 10 );

         if( gSplitTotal == NULL )
         {
	      	SetDlgItemText( hWnd, IDC_SPLITCOUNT, "1" );
         }
         else
         {
	      	SetDlgItemText( hWnd, IDC_SPLITCOUNT, Buffer );
         }

         if( gFileName[ 0 ] == NULL )
         {
	      	SetDlgItemText( hWnd, IDC_OUTFILEN, "repair.FIX" );
         }
         else
         {
	      	SetDlgItemText( hWnd, IDC_OUTFILEN, gFileName );
         }

         if( gSFileName[ 0 ] == NULL )
         {
	      	SetDlgItemText( hWnd, IDC_IN_FILEN, "01010000.TER" );
         }
         else
         {
	      	SetDlgItemText( hWnd, IDC_IN_FILEN, gSFileName );
         }
      }
      break;
   	case WM_COMMAND:
      	switch( LOWORD( wParam ) )
         {
         	case IDOK:
            {
               GetDlgItemText( hWnd, IDC_OUTFILEN, gFileName, FILENAME - 1 );

               GetDlgItemText( hWnd, IDC_IN_FILEN, gSFileName, FILENAME - 1 );

               GetDlgItemText( hWnd, IDC_SPLITSIZE, Buffer, FILENAME - 1 );
               gSplitSize = atol( Buffer );

               GetDlgItemText( hWnd, IDC_SPLITCOUNT, Buffer, FILENAME - 1 );
               gSplitTotal = atoi( Buffer );

               // Keep file size within tolerances
	            if( gSplitSize < FILESIZELIMIT )
	            {
	            	sprintf( Buffer, "FileSize Too Low must be greater than %ld\n", FILESIZELIMIT );
	            	note( Buffer );
                  gSplitSize = FILESIZELIMIT;

			      	return( FALSE );
	            }

               if( gSplitTotal < 1 )
               {
               	sprintf( Buffer, "FileSplit Total Too Low Must be 1 or Greater\n" );
                  note( Buffer );
                  gSplitTotal = 1;

			      	return( FALSE );
               }
            }

            EndDialog( hWnd, IDOK );
            break;

         	case IDCANCEL:
               GetDlgItemText( hWnd, IDC_OUTFILEN, gFileName, FILENAME - 1 );

               GetDlgItemText( hWnd, IDC_IN_FILEN, gSFileName, FILENAME - 1 );

               GetDlgItemText( hWnd, IDC_SPLITSIZE, Buffer, FILENAME - 1 );
               gSplitSize = atol( Buffer );

               GetDlgItemText( hWnd, IDC_SPLITCOUNT, Buffer, FILENAME - 1 );
               gSplitTotal = atoi( Buffer );
	            EndDialog( hWnd, IDCANCEL );
            break;

            case IDHELP:
            break;

            case IDC_GETFILEN:
					OpnFileName.lpstrFilter 		= "All Files \(*.*\)\0*.*\0\0";
               OpnFileName.lpstrDefExt 		= "FIX";
					OpnFileName.Flags 				= 	OFN_EXPLORER | OFN_LONGNAMES | OFN_PATHMUSTEXIST;

					OpnFileName.lpstrFileTitle	[ 0 ] = NULL;
               OpnFileName.lpstrFile		[ 0 ] = NULL;

              	if( !GetSaveFileName( &OpnFileName ) )
               {
//	              	note("Error Could not open Dialog Box or Get a File\n");
						RestoreFlag = 0;
                  break;
               }
		      	SetDlgItemText( hWnd, IDC_OUTFILEN, OpnFileName.lpstrFile );
				break;

            case IDC_GETFILEN2:
					OpnFileName.lpstrFilter 		= "All Files \(*.*\)\0*.*\0\0";
               OpnFileName.lpstrDefExt 		= "FIX";
					OpnFileName.Flags 				= 	OFN_EXPLORER | OFN_LONGNAMES | OFN_PATHMUSTEXIST;

					OpnFileName.lpstrFileTitle	[ 0 ] = NULL;
               OpnFileName.lpstrFile		[ 0 ] = NULL;

              	if( !GetSaveFileName( &OpnFileName ) )
               {
//	              	note("Error Could not open Dialog Box or Get a File\n");
						RestoreFlag = 0;
                  break;
               }
		      	SetDlgItemText( hWnd, IDC_IN_FILEN, OpnFileName.lpstrFile );

            break;
         }
         break;
      case WM_DESTROY:
         break;

      default:
      	return( FALSE );
   }
   return( TRUE );
}

/* Dialog box control functions. */
LRESULT CALLBACK DlgAboutSplitProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
/****************************************************************************
	Purpose: About Dialog Box Message Proccess handle

	Input:

   Output:

   Return:

   Parameters:
****************************************************************************/
{
	switch( uMsg )
   {
   	case WM_INITDIALOG:
/*
     	{
      	HBITMAP hBitmap;
         HDC hDC;
         HDC hMemDC;

         hBitmap = LoadBitmap ( hInst, MAKEINTRESOURCE( 1 ) );

         hDC = GetDC( hWnd );
         hMemDC = CreateCompatibleDC( hDC );

         SelectObject( hMemDC, hBitmap );
         BitBlt( hDC, 208, 8, 32, 32, hMemDC, 0, 0, SRCCOPY );

         DeleteDC( hMemDC );
         ReleaseDC( hWnd, hDC );
         DeleteObject( hBitmap );
      }
*/      
      break;
   	case WM_COMMAND:
      	switch( LOWORD( wParam ) )
         {
         	case IDOK:
            {
	            EndDialog( hWnd, IDOK );
            }
            break;

            case IDHELP:
            break;

         	case IDCANCEL:
	            EndDialog( hWnd, IDCANCEL );
            break;

         }
         break;
      case WM_DESTROY:
         break;

      default:
      	return( FALSE );
   }
   return( TRUE );
}

#endif
