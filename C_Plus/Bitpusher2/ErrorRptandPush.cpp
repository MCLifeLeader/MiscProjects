// ErrorRptandPush.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "ErrorRptandPush.h"


// ErrorRptandPush dialog

IMPLEMENT_DYNAMIC(ErrorRptandPush, CDialog)
ErrorRptandPush::ErrorRptandPush(CWnd* pParent /*=NULL*/)
	: CDialog(ErrorRptandPush::IDD, pParent)
{
	m_Img = 0;
	m_Check = TRUE;
}

ErrorRptandPush::~ErrorRptandPush()
{
}

void ErrorRptandPush::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	
	DDX_Control(pDX, ERR_LST_DLG_DEST_PROF, m_LstBxDestProfile);
	DDX_Control(pDX, ERR_LST_DLG_ERRLOG, m_LstBxPushLog);
	DDX_Control(pDX, ERR_LST_DLG_ERRDESTS, m_LstBxDestErrors);

	DDV_MinMaxInt(pDX, m_Img, 0, 19);	
}


BEGIN_MESSAGE_MAP(ErrorRptandPush, CDialog)
	ON_BN_CLICKED(ERR_BTN_DLG_REPUSH, OnBnClickedBtnDlgRepush)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

// ErrorRptandPush message handlers

BOOL ErrorRptandPush::OnInitDialog()
{
	// subclass the control

	CDialog::OnInitDialog();
	InitImageLists();

	m_LstBxDestProfile.SetImageList(&m_imgNormal);
	m_LstBxPushLog.SetImageList(&m_imgNormal);
	m_LstBxDestErrors.SetImageList(&m_imgNormal);

	m_LstBxDestProfile.AddString( "This is a Test", 2 );
	m_LstBxPushLog.AddString( "This is a Test", 4 );
	m_LstBxDestErrors.AddString( "This is a Test", 6 );

	m_LstBxDestProfile.UpdateHzScrollBar( );
	m_LstBxPushLog.UpdateHzScrollBar( );
	m_LstBxDestErrors.UpdateHzScrollBar( );
	
	return TRUE;
}

void ErrorRptandPush::InitImageLists()
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

void ErrorRptandPush::OnBnClickedBtnDlgRepush()
{
	// TODO: Add your control notification handler code here
}

void ErrorRptandPush::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
