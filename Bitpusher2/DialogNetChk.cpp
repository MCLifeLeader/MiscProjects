// DialogNetChk.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "DialogNetChk.h"


// CDialogNetChk dialog

IMPLEMENT_DYNAMIC(CDialogNetChk, CDialog)
CDialogNetChk::CDialogNetChk(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogNetChk::IDD, pParent)
{
	m_Img = 0;
	m_Check = TRUE;
}

CDialogNetChk::~CDialogNetChk()
{
}

void CDialogNetChk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, NETCHK_LST_PROF_NETSTAT, m_LstBxDestProfile);
	DDX_Control(pDX, NETCHK_LST_DRIVE_SPACE, m_LstBxDriveSpace);
	DDX_Control(pDX, NETCHK_LST_PC_ONLINE_STAT, m_LstBxOnlineStatus);
			
	DDV_MinMaxInt(pDX, m_Img, 0, 19);
}


BEGIN_MESSAGE_MAP(CDialogNetChk, CDialog)
	ON_BN_CLICKED(NETCHK_BTN_STATUS, OnBnClickedBtnStatus)
	ON_BN_CLICKED(NETCHK_BTN_NETSENDV, OnBnClickedBtnNetsendv)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CDialogNetChk::OnInitDialog()
{
	// subclass the control
	CDialog::OnInitDialog();
	InitImageLists();

	m_LstBxDestProfile.SetImageList(&m_imgNormal);
	m_LstBxDriveSpace.SetImageList(&m_imgNormal);
	m_LstBxOnlineStatus.SetImageList(&m_imgNormal);

	m_LstBxDestProfile.AddString( "This is a Test", 15 );
	m_LstBxDriveSpace.AddString( "This is a Test", 16 );
	m_LstBxOnlineStatus.AddString( "This is a Test", 17 );

	m_LstBxDestProfile.UpdateHzScrollBar( );
	m_LstBxDriveSpace.UpdateHzScrollBar( );
	m_LstBxOnlineStatus.UpdateHzScrollBar( );
		
	return TRUE;
}

void CDialogNetChk::InitImageLists()
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

// CDialogNetChk message handlers
void CDialogNetChk::OnBnClickedBtnStatus()
{
	// TODO: Add your control notification handler code here
}

void CDialogNetChk::OnBnClickedBtnNetsendv()
{
	// TODO: Add your control notification handler code here
}

void CDialogNetChk::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
