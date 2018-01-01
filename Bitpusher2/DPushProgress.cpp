// DPushProgress.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "DPushProgress.h"
#include "logging.h"

// CDPushProgress dialog

IMPLEMENT_DYNAMIC(CDPushProgress, CDialog)
CDPushProgress::CDPushProgress(CWnd* pParent /*=NULL*/)
	: CDialog(CDPushProgress::IDD, pParent)
{
}

CDPushProgress::~CDPushProgress()
{
}

void CDPushProgress::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDPushProgress, CDialog)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// CDPushProgress message handlers

void CDPushProgress::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	WriteLogFile( "Push Canceled by User" );
	OnCancel();
}
