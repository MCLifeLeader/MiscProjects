#pragma once
#include "IconListBox.h"

// CDialogNetChk dialog

class CDialogNetChk : public CDialog
{
	DECLARE_DYNAMIC(CDialogNetChk)

public:
	CDialogNetChk(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialogNetChk();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_ONLINE_CHECK };

	CIconListBox	m_LstBxDestProfile;
	CIconListBox	m_LstBxDriveSpace;
	CIconListBox	m_LstBxOnlineStatus;
	
	int				m_Img;
	BOOL				m_Check;	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	HICON m_hIcon;
	CImageList m_imgNormal;
	void InitImageLists();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnStatus();
	afx_msg void OnBnClickedBtnNetsendv();
	afx_msg void OnBnClickedCancel();
};
