#pragma once


// CDPushProgress dialog

class CDPushProgress : public CDialog
{
	DECLARE_DYNAMIC(CDPushProgress)

public:
	CDPushProgress(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDPushProgress();

// Dialog Data
	enum { IDD = IDD_PUSHPROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
