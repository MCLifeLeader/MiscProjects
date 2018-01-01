#pragma once


// CDQueuePush dialog

class CDQueuePush : public CDialog
{
	DECLARE_DYNAMIC(CDQueuePush)

public:
	CDQueuePush(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDQueuePush();

// Dialog Data
	enum { IDD = IDD_PUSHPROGRESS_Q };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
