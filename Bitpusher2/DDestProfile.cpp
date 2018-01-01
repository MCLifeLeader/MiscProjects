// DDestProfile.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "DDestProfile.h"


// CDDestProfile dialog

IMPLEMENT_DYNAMIC(CDDestProfile, CDialog)
CDDestProfile::CDDestProfile(CWnd* pParent /*=NULL*/)
	: CDialog(CDDestProfile::IDD, pParent)
{
	m_Img = 0;
	m_Check = TRUE;
}

CDDestProfile::~CDDestProfile()
{
}

void CDDestProfile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, DEST_LST_DLG_PROFILE_LST, m_LstBxDestProfile);
	DDX_Control(pDX, DEST_LST_DLG_IN_PROF, m_LstBxDestinProfile);	
	DDV_MinMaxInt(pDX, m_Img, 0, 19);
}


BEGIN_MESSAGE_MAP(CDDestProfile, CDialog)
	ON_BN_CLICKED(DEST_BTN_DLG_NEWPROFILE, OnBnClickedBtnDlgNewprofile)
	ON_BN_CLICKED(DEST_BTN_DLG_DELETEPROFILE, OnBnClickedBtnDlgDeleteprofile)
	ON_BN_CLICKED(DEST_BTN_DLG_GETDESTS, OnBnClickedBtnDlgGetdests)
	ON_BN_CLICKED(DEST_BTN_DLG_ALIAS_ADD, OnBnClickedBtnDlgAliasAdd)
	ON_BN_CLICKED(DEST_BTN_DLG_PROAPPLY, OnBnClickedBtnDlgProapply)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

BOOL CDDestProfile::OnInitDialog()
{
	// subclass the control
	CDialog::OnInitDialog();
	InitImageLists();

	m_LstBxDestProfile.SetImageList(&m_imgNormal);
	m_LstBxDestinProfile.SetImageList(&m_imgNormal);

	m_LstBxDestProfile.AddString( "This is a Test", 10 );
	m_LstBxDestinProfile.AddString( "This is a Test", 11 );

	m_LstBxDestProfile.UpdateHzScrollBar( );
	m_LstBxDestinProfile.UpdateHzScrollBar( );	
	return TRUE;
}

void CDDestProfile::InitImageLists()
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

void CDDestProfile::OnBnClickedBtnDlgNewprofile()
{
	// TODO: Add your control notification handler code here
}

void CDDestProfile::OnBnClickedBtnDlgDeleteprofile()
{
	// TODO: Add your control notification handler code here
}

void CDDestProfile::OnBnClickedBtnDlgGetdests()
{
	// TODO: Add your control notification handler code here
}

void CDDestProfile::OnBnClickedBtnDlgAliasAdd()
{
	// TODO: Add your control notification handler code here
}

void CDDestProfile::OnBnClickedBtnDlgProapply()
{
	// TODO: Add your control notification handler code here
}

void CDDestProfile::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
