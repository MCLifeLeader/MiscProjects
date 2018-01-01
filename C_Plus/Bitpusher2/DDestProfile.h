#pragma once
#include "IconListBox.h"

// CDDestProfile dialog

class CDDestProfile : public CDialog
{
	DECLARE_DYNAMIC(CDDestProfile)

public:
	CDDestProfile(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDDestProfile();
	BOOL OnInitDialog();

// Dialog Data
	enum { IDD = IDD_DESTPROFILE };

	CIconListBox	m_LstBxDestProfile;
	CIconListBox	m_LstBxDestinProfile;	

	int				m_Img;
	BOOL				m_Check;	

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	HICON m_hIcon;
	CImageList m_imgNormal;
	void InitImageLists();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnDlgNewprofile();
	afx_msg void OnBnClickedBtnDlgDeleteprofile();
	afx_msg void OnBnClickedBtnDlgGetdests();
	afx_msg void OnBnClickedBtnDlgAliasAdd();
	afx_msg void OnBnClickedBtnDlgProapply();
	afx_msg void OnBnClickedCancel();
};
