#pragma once
// bitpusher2Dlg.h : header file
//

#include "IconListBox.h"
#include "FileEditCtrl.h"

// Cbitpusher2Dlg dialog
class Cbitpusher2Dlg : public CDialog
{
// Construction
public:
	Cbitpusher2Dlg(CWnd* pParent = NULL);	// standard constructor
	~Cbitpusher2Dlg() { if (pBuffer) delete pBuffer; }
	BOOL Cbitpusher2Dlg::PreTranslateMessage(MSG* pMsg);

// Dialog Data
	enum { IDD = IDD_BITPUSHER2_DIALOG };

	CIconListBox	m_LstBxSourceFiles;
	CIconListBox	m_LstBxDestProfiles;
	CIconListBox	m_LstBxJobQueue;
	CIconListBox	m_LstBxDestPCs;
	CFileEditCtrl  m_fileeditctrl;

	int				m_Img;
	BOOL				m_Check;
	LPTSTR			pBuffer;
	
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;
	CImageList m_imgNormal;
	void InitImageLists();

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMCustomdrawPushprogress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnPush();
	afx_msg void OnBnClickedBtnPushqueue();
	afx_msg void OnBnClickedFileOpen();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnAddToBatch();
	afx_msg void OnBnClickedBtnProfiles();
	afx_msg void OnBnClickedBtnOnlineChk();
	afx_msg void OnBnClickedBtnErrRpt();
	afx_msg void OnBnClickedBtnOnlineRfsh();
	afx_msg void OnBnClickedBtnDelProfiles();
	afx_msg void OnBnClickedBtnDelBatch();
	afx_msg void OnBnClickedBtnClearFiles();
	afx_msg void OnBnClickedBtnClearAllFiles();
	afx_msg void OnBnClickedBtnDelBatchAll();
};
