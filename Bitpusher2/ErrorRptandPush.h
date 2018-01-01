#pragma once
#include "IconListBox.h"

// ErrorRptandPush dialog

class ErrorRptandPush : public CDialog
{
	DECLARE_DYNAMIC(ErrorRptandPush)

public:
	ErrorRptandPush(CWnd* pParent = NULL);   // standard constructor
	virtual ~ErrorRptandPush();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_ERROR_RPT };

	CIconListBox	m_LstBxDestProfile;
	CIconListBox	m_LstBxPushLog;
	CIconListBox	m_LstBxDestErrors;
		
	int				m_Img;
	BOOL				m_Check;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	HICON m_hIcon;
	CImageList m_imgNormal;
	void InitImageLists();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDlgRepush();
	afx_msg void OnBnClickedCancel();
};
