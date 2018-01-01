// DQueuePush.cpp : implementation file
//

#include "stdafx.h"
#include "bitpusher2.h"
#include "DQueuePush.h"
#include "logging.h"


// CDQueuePush dialog

IMPLEMENT_DYNAMIC(CDQueuePush, CDialog)
CDQueuePush::CDQueuePush(CWnd* pParent /*=NULL*/)
	: CDialog(CDQueuePush::IDD, pParent)
{
}

CDQueuePush::~CDQueuePush()
{
}

void CDQueuePush::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDQueuePush, CDialog)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// CDQueuePush message handlers

void CDQueuePush::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	WriteLogFile( "Push Queue Canceled by User" );
	OnCancel();
}
