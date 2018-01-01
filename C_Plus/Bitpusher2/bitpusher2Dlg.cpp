// bitpusher2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "bitpusher2Dlg.h"
#include "DialogNetChk.h"
#include "DDestProfile.h"
#include "ErrorRptandPush.h"
#include "DPushProgress.h"
#include "DQueuePush.h"
#include "logging.h"
#include "XML_IO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

bool bShiftDown = false;

// Cbitpusher2Dlg dialog

Cbitpusher2Dlg::Cbitpusher2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cbitpusher2Dlg::IDD, pParent)
{	
	m_Img = 0;
	m_Check = TRUE;
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cbitpusher2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Control(pDX, MAIN_LST_SRC_FILES, m_LstBxSourceFiles);
	DDX_Control(pDX, MAIN_LST_DEST_PROF, m_LstBxDestProfiles);
	DDX_Control(pDX, MAIN_LST_JOB_QUEUE, m_LstBxJobQueue);
	DDX_Control(pDX, MAIN_LST_DEST_PCS, m_LstBxDestPCs);

   DDX_FileEditCtrl(pDX, MAIN_BTN_FILELNK, m_fileeditctrl, FEC_FILE);
	DDV_MinMaxInt(pDX, m_Img, 0, 19);
}

// I am using this to gain access to the Message Loop Process for this Application
BOOL Cbitpusher2Dlg::PreTranslateMessage(MSG* pMsg)
{
	// This is where the message loop handler can be accessed and delt with
	switch( pMsg->message )
	{
		case WM_MOUSEMOVE:			
			if( m_fileeditctrl.m_WasExecuted == true )
				OnBnClickedFileOpen();
		break;
		case WM_KEYDOWN:
			// Testing windows Event messages.
			if( GetKeyState( VK_LSHIFT ) ) DisplayErrorMsg( "Left Shift Key" );
			if( GetKeyState( VK_RSHIFT ) ) DisplayErrorMsg( "Right Shift Key" );
		break;
		case WM_LBUTTONDOWN:
		if( bShiftDown == true )
		{
			
		}
		break;
		case WM_LBUTTONUP:
			if( CDialog::IsDlgButtonChecked( IDC_SUBDIRSEARCH ) )
			{
				// set the MultiFileSelect switch on
				m_fileeditctrl.ModifyFlags(0, FEC_MULTIPLE);
				// set control to accept a folder
				m_fileeditctrl.ModifyFlags(FEC_FILE, FEC_FOLDER);
			}
			else
			{
				// set control to accept files   
				m_fileeditctrl.ModifyFlags(FEC_FOLDER, FEC_FILE);
				// set the MultiFileSelect switch on
				m_fileeditctrl.ModifyFlags(0, FEC_MULTIPLE);
				// set control to accept multiple files
				m_fileeditctrl.ModifyStyleEx(0, WS_EX_ACCEPTFILES);
			}
		break;
		default:
		break;
	}
	return CDialog::PreTranslateMessage( pMsg );
}

BEGIN_MESSAGE_MAP(Cbitpusher2Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(MAIN_BTN_PUSH, OnBnClickedBtnPush)
	ON_BN_CLICKED(MAIN_BTN_PUSHQUEUE, OnBnClickedBtnPushqueue)
	ON_BN_CLICKED(ID_FILE_OPEN, OnBnClickedFileOpen)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(MAIN_BTN_ADD_TO_BATCH, OnBnClickedBtnAddToBatch)
	ON_BN_CLICKED(MAIN_BTN_PROFILES, OnBnClickedBtnProfiles)
	ON_BN_CLICKED(MAIN_BTN_ONLINE_CHK, OnBnClickedBtnOnlineChk)
	ON_BN_CLICKED(MAIN_BTN_ERR_RPT, OnBnClickedBtnErrRpt)
	ON_BN_CLICKED(MAIN_BTN_ONLINE_RFSH, OnBnClickedBtnOnlineRfsh)
	ON_BN_CLICKED(MAIN_BTN_DEL_PROFILES, OnBnClickedBtnDelProfiles)
	ON_BN_CLICKED(MAIN_BTN_DEL_BATCH, OnBnClickedBtnDelBatch)
	ON_BN_CLICKED(MAIN_BTN_CLEAR_FILES, OnBnClickedBtnClearFiles)
	ON_BN_CLICKED(IDC_BTN_CLEAR_ALL_FILES, OnBnClickedBtnClearAllFiles)
	ON_BN_CLICKED(MAIN_BTN_DEL_BATCH_ALL, OnBnClickedBtnDelBatchAll)
END_MESSAGE_MAP()

// Cbitpusher2Dlg message handlers

BOOL Cbitpusher2Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	InitImageLists();
	
   pBuffer = NULL;

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO:   Need to read this from a configuration file not just check it by default.
	CDialog::CheckDlgButton( IDC_SUBDIRSEARCH, BM_SETCHECK );

	// Read in the JOBQUEUE.XML file add them to the m_LstBxJobQueue

	// Read in the PROFILES.XML file add them to the m_LstBxJobQueue

	// Initialize the FileAdd functions for adding / removing files from the list		
	// set control to add trailing \ character to all paths.
   m_fileeditctrl.ModifyFlags(FEC_TRAILINGSLASH, 0);
   // enable control
   m_fileeditctrl.EnableWindow(TRUE);   
   // set control to accept multiple files
   m_fileeditctrl.ModifyStyleEx(0, WS_EX_ACCEPTFILES);
   // enable control, clear readonly status
   m_fileeditctrl.SetReadOnly(FALSE);
   // set control to accept wildcards in file name
   m_fileeditctrl.ModifyFlags(0, FEC_WILDCARDS);
   // set the MultiFileSelect switch on
	m_fileeditctrl.ModifyFlags(0, FEC_MULTIPLE);

	OnBnClickedFileOpen( );
	// Initialize the FileAdd functions for adding / removing files from the list		
	
	m_LstBxSourceFiles.SetImageList(&m_imgNormal);	
	m_LstBxDestProfiles.SetImageList(&m_imgNormal);	
	m_LstBxJobQueue.SetImageList(&m_imgNormal);	
	m_LstBxDestPCs.SetImageList(&m_imgNormal);
	
	m_LstBxSourceFiles.UpdateHzScrollBar( );
	m_LstBxDestProfiles.UpdateHzScrollBar( );
	m_LstBxJobQueue.UpdateHzScrollBar( );
	m_LstBxDestPCs.UpdateHzScrollBar( );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cbitpusher2Dlg::InitImageLists()
{
	CBitmap bmp;
	// normal tree images
	m_imgNormal.Create(16,
				 15,
				 TRUE,
				 20,	// number of initial images
				 20);

	ASSERT(m_imgNormal.m_hImageList);

	bmp.LoadBitmap(IDB_LB_IMG);
	m_imgNormal.Add( &bmp, RGB(255,255,255));
	bmp.DeleteObject();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cbitpusher2Dlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cbitpusher2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void Cbitpusher2Dlg::OnNMCustomdrawPushprogress(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	*pResult = 0;
}
void Cbitpusher2Dlg::OnBnClickedBtnPush()
{
	WriteLogFile( "Push Start..." );
	CDPushProgress dlgPushProg;
	
	INT_PTR nResponse = dlgPushProg.DoModal();

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
	
	WriteLogFile( "Push End..." );
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
}

void Cbitpusher2Dlg::OnBnClickedBtnPushqueue()
{	
	WriteLogFile( "Push Queue Start..." );
	CDQueuePush dlgPushQueueProg;
	
	INT_PTR nResponse = dlgPushQueueProg.DoModal();

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
	
	WriteLogFile( "Push Queue End..." );
	// Since the dialog has been closed, return FALSE so that we exit the
	// application, rather than start the application's message pump.
}

void Cbitpusher2Dlg::OnBnClickedFileOpen()
{
	WriteLogFile( "Add Files Start..." );

	OPENFILENAME *pOFN;  // grab multiple file names from the file open list dialog box
	POSITION pos; // Position data relating tot he multiple file names
	CDC *pDC;
	
	CString str;		// Cstring Buffer to insert strings into listbox
	LPTSTR lpBuffer = NULL;	// String Buffer for use in comparing existing items.
	int iStrLen = 0, iLstBxItems = 0;	// Temp variables used in comparing exisiting items.
	bool bAddString = true;	// by default add the string but fail if a match is found ( no duplicate strings )
	int saved = 0;

	if( m_fileeditctrl.m_WasExecuted == true )
	{
		m_fileeditctrl.m_WasExecuted = false;
		if( CDialog::IsDlgButtonChecked( IDC_SUBDIRSEARCH ) )
		{
			// set control to accept a folder
			m_fileeditctrl.ModifyFlags(FEC_FILE, FEC_FOLDER);

			// verify that the files entered actually exist
			pOFN = m_fileeditctrl.GetOpenFileName();

			if (pOFN)
				pOFN->Flags |= OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;  // Flags set when grabbing file datainfo
				
				pDC = m_LstBxSourceFiles.GetDC();

				saved = pDC->SaveDC();

				pDC->SelectObject(GetFont());

				// call GetStartPosition() to get the position of the first file in the control
				pos = m_fileeditctrl.GetStartPosition();
				
				while (pos)
				{
					// reset the bAddString for the next item to add in the list
					bAddString = true;
					// add the file paths to the list
					str = m_fileeditctrl.GetNextPathName(pos);			

					iLstBxItems = m_LstBxSourceFiles.GetCount( );
					// Find the longest string in the ListBox
					for( int i=0; i<iLstBxItems; i++ )
					{
						if( iStrLen < m_LstBxSourceFiles.GetTextLen( i ) )
						{
							iStrLen = m_LstBxSourceFiles.GetTextLen( i );
						}
					}

					lpBuffer = new char [ iStrLen + 1 ]; // Create some memory for that string which is longest
					// This is so we do not add duplicate strings
					for( int i=0; i<iLstBxItems; i++ )
					{
						m_LstBxSourceFiles.GetText( i, lpBuffer );

						if( !stricmp( lpBuffer, str.GetString( ) ) )	// upper and lower case check
						{
							bAddString = false;	// strings match do not add to listbox
							break; // No need to continue just drop out
						}
					}
					
					if( bAddString == true )
					{

	#ifdef _DEBUG				
						if( lpBuffer )
							delete [] lpBuffer;
							
						lpBuffer = new char [ str.GetLength( ) + 1 ];					
						sprintf( lpBuffer, "%s", str.GetString( ) );
						
						WriteLogFile( lpBuffer );
	#endif //#ifdef _DEBUG

						if( SetCurrentDirectory( str.GetString( ) ) )
							m_LstBxSourceFiles.AddString( str, 19 ); // 19 is arrow looking icon
						else
							m_LstBxSourceFiles.AddString( str, 13 ); // 13 is paper looking icon
					}	
					
					if( lpBuffer )
						delete [] lpBuffer;

				}
				pDC->RestoreDC(saved);
				ReleaseDC(pDC);
		}
		else
		{
			// set control to accept files   
			m_fileeditctrl.ModifyFlags(FEC_FOLDER, FEC_FILE);
			// set the MultiFileSelect switch on
			m_fileeditctrl.ModifyFlags(0, FEC_MULTIPLE);

			pOFN = m_fileeditctrl.GetOpenFileName();

			if (pOFN)
			{
				// we have to supply our own buffer to hold all the files
				// the default lpstrFile buffer is not big enough
				if (!pBuffer)
				{
						pBuffer = new TCHAR[2000];
						*pBuffer = 0;
				}

				pOFN->lpstrFile = pBuffer;
				pOFN->nMaxFile = 2000;

				pDC = m_LstBxSourceFiles.GetDC();

				saved = pDC->SaveDC();

				pDC->SelectObject(GetFont());

				pos = m_fileeditctrl.GetStartPosition();
				while (pos)
				{
					// reset the bAddString for the next item to add in the list
					bAddString = true;
					// add the file paths to the list
					str = m_fileeditctrl.GetNextPathName(pos);
					iLstBxItems = m_LstBxSourceFiles.GetCount( );
					// Find the longest string in the ListBox
					for( int i=0; i<iLstBxItems; i++ )
					{
						if( iStrLen < m_LstBxSourceFiles.GetTextLen( i ) )
						{
							iStrLen = m_LstBxSourceFiles.GetTextLen( i );
						}
					}

					lpBuffer = new char [ iStrLen + 1 ]; // Create some memory for that string which is longest
					// This is so we do not add duplicate strings
					for( int i=0; i<iLstBxItems; i++ )
					{
						m_LstBxSourceFiles.GetText( i, lpBuffer );

						if( !stricmp( lpBuffer, str.GetString( ) ) )	// upper and lower case check
						{
							bAddString = false;	// strings match do not add to listbox
							break; // No need to continue just drop out
						}
					}
					
					if( bAddString == true )
					{

	#ifdef _DEBUG
						if( lpBuffer )
							delete [] lpBuffer;
							
						lpBuffer = new char [ str.GetLength( ) + 1 ];					
						sprintf( lpBuffer, "%s", str.GetString( ) );
						
						WriteLogFile( lpBuffer );
	#endif //#ifdef _DEBUG

						if( SetCurrentDirectory( str.GetString( ) ) )
							m_LstBxSourceFiles.AddString( str, 19 ); // 19 is arrow looking icon
						else
							m_LstBxSourceFiles.AddString( str, 13 ); // 13 is paper looking icon
					}	
					
					if( lpBuffer )
						delete [] lpBuffer;
				}
				pDC->RestoreDC(saved);
				ReleaseDC(pDC);
			}
		}
	}
	// update the file enteries in the list box.
	m_LstBxSourceFiles.UpdateHzScrollBar( );

	WriteLogFile( "Add Files End..." );
}

void Cbitpusher2Dlg::OnBnClickedCancel()
{
	OnCancel();
}

void Cbitpusher2Dlg::OnBnClickedBtnAddToBatch()
{
	WriteLogFile( "Adding Files to Queue..." );

	// Add item(s) to the m_LstBxJobQueue
	// Write to the JOBQUEUE.XML file.
	m_LstBxJobQueue.UpdateHzScrollBar( );
}

void Cbitpusher2Dlg::OnBnClickedBtnProfiles()
{
	WriteLogFile( "Destination Profiles Edit Start..." );
	CDDestProfile dlgDest;
	
	INT_PTR nResponse = dlgDest.DoModal();

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
	
	// Load the Profiles from the PROFILES.XML file
	m_LstBxDestProfiles.UpdateHzScrollBar( );

	WriteLogFile( "Destination Profiles Edit End..." );
}
/*
Cbitpusher2Dlg::OnDropFiles( HDROP hDropInfo )
{

}
*/
void Cbitpusher2Dlg::OnBnClickedBtnOnlineChk()
{
	WriteLogFile( "Network Status Start..." );
	CDialogNetChk dlgNetChk;
	
	INT_PTR nResponse = dlgNetChk.DoModal();

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
	WriteLogFile( "Network Status End..." );
}

void Cbitpusher2Dlg::OnBnClickedBtnErrRpt()
{
	WriteLogFile( "Error Report Start..." );
	ErrorRptandPush dlgErrRptPush;
	
	INT_PTR nResponse = dlgErrRptPush.DoModal();

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

	WriteLogFile( "Error Report End..." );
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
}

void Cbitpusher2Dlg::OnBnClickedBtnOnlineRfsh()
{
	WriteLogFile( "Destination PC's Refresh Start..." );
//	InitDLLCommunication( );
//	CloseDLLCommunications( );
	
/*
	ULARGE_INTEGER uliFreeBytesAvail, uliTotalNumberOfBytes, uliTotalNumberOfFreeBytes;
	UINT driveType;
	driveType = GetDriveType( "\\\\relay\\c$\\" );
	GetDiskFreeSpaceEx( "\\\\relay\\c$\\", &uliFreeBytesAvail, &uliTotalNumberOfBytes, &uliTotalNumberOfFreeBytes );
	
	switch ( driveType )
	{
		case DRIVE_REMOVABLE:
			DisplayErrorMsg( "case DRIVE_REMOVABLE:" );
		break;
		case DRIVE_FIXED:
			DisplayErrorMsg( "case DRIVE_FIXED:" );
		break;
		case DRIVE_REMOTE:
			DisplayErrorMsg( "case DRIVE_REMOTE:" );
		break;
		case DRIVE_CDROM:
			DisplayErrorMsg( "case DRIVE_CDROM:" );
		break;
		case DRIVE_RAMDISK:
			DisplayErrorMsg( "case DRIVE_RAMDISK:" );
		break;
		default:
			DisplayErrorMsg( "default:" );		
		break;
	}
*/
	m_LstBxDestPCs.UpdateHzScrollBar( );
	WriteLogFile( "Destination PC's Refresh End..." );	
}

void Cbitpusher2Dlg::OnBnClickedBtnDelProfiles()
{
	int iLstCount		= m_LstBxDestProfiles.GetCount( );
	int iLstSelected	= m_LstBxDestProfiles.GetSelCount( );
	LPINT rgIndex = NULL;
	
	if( iLstSelected )
	{
		// confermation of destructive action for profiles.
		if( IDYES == MessageBox( "Do you wish to delete the selected Profiles?", "File Pusher Warning", MB_YESNO | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST ) )
		{
			WriteLogFile( "Deleting From Profiles Start..." );

			rgIndex = new int [ iLstSelected ];

			m_LstBxDestProfiles.GetSelItems( iLstCount, rgIndex);

			// This is where the enteries are being deleted.
			for( int i=iLstSelected; i>-1; i-- )
				m_LstBxDestProfiles.DeleteString( rgIndex[ i ] );
			
			delete [] rgIndex;
			m_LstBxDestProfiles.UpdateHzScrollBar( );

			WriteLogFile( "Deleting From Profiles End..." );
		}
	}
	
	// After the profiles have been removed then we need to update the full list kept on disk
}

// Delete items from the Job Queue... Note: only deleting items from the Job Queue will remove them.
void Cbitpusher2Dlg::OnBnClickedBtnDelBatch()
{
	int iLstCount		= m_LstBxJobQueue.GetCount( );
	int iLstSelected	= m_LstBxJobQueue.GetSelCount( );
	LPINT rgIndex = NULL;

	if( iLstSelected )
	{
		WriteLogFile( "Deleting From Batch Start..." );

		rgIndex = new int [ iLstSelected ];

		m_LstBxJobQueue.GetSelItems( iLstCount, rgIndex);

		// This is where the 
		for( int i=iLstSelected; i>-1; i-- )
			m_LstBxJobQueue.DeleteString( rgIndex[ i ] );
		
		delete [] rgIndex;
		m_LstBxJobQueue.UpdateHzScrollBar( );

		WriteLogFile( "Deleting From Batch End..." );
	}	
}

// This is to clear only a few of the items from the file select list
void Cbitpusher2Dlg::OnBnClickedBtnClearFiles()
{
	int iLstCount		= m_LstBxSourceFiles.GetCount( );
	int iLstSelected	= m_LstBxSourceFiles.GetSelCount( );
	LPINT rgIndex = NULL;

	if( iLstSelected )
	{
		WriteLogFile( "Clearing File Selected Start..." );

		rgIndex = new int [ iLstSelected ];

		m_LstBxSourceFiles.GetSelItems( iLstCount, rgIndex);

		for( int i=iLstSelected; i>-1; i-- )
			m_LstBxSourceFiles.DeleteString( rgIndex[ i ] );
		
		delete [] rgIndex;
		m_LstBxSourceFiles.UpdateHzScrollBar( );

		WriteLogFile( "Clearing File Selected End..." );
	}	
}

// This is to clear all the files present in the file select list
void Cbitpusher2Dlg::OnBnClickedBtnClearAllFiles()
{
	int iLstCount = m_LstBxSourceFiles.GetCount( );
		
	if( iLstCount )
	{
		if( IDYES == MessageBox( "Do you wish to Clear all the files in the list?", "File Pusher Warning", MB_YESNO | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST ) )
		{
			WriteLogFile( "Clearing all Files Start..." );
			
			for( int i=iLstCount; i>-1; i-- )
				m_LstBxSourceFiles.DeleteString( i );

			WriteLogFile( "Clearing all Files End..." );
		}
		m_LstBxSourceFiles.UpdateHzScrollBar( );
	}
}

// This is to clear the entire Job Queue
void Cbitpusher2Dlg::OnBnClickedBtnDelBatchAll()
{
	int iLstCount = m_LstBxJobQueue.GetCount( );
		
	if( iLstCount )
	{
		if( IDYES == MessageBox( "Do you wish to Clear the entire Job Queue list?", "File Pusher Warning", MB_YESNO | MB_ICONWARNING | MB_APPLMODAL | MB_TOPMOST ) )
		{
			WriteLogFile( "Clearing entire Queue Start..." );
			
			for( int i=iLstCount; i>-1; i-- )
				m_LstBxJobQueue.DeleteString( i );

			WriteLogFile( "Clearing entire Queue End..." );
		}
		m_LstBxJobQueue.UpdateHzScrollBar( );
	}
}
