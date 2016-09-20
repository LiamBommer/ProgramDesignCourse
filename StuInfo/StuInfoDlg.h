// StuInfoDlg.h : header file
//

#if !defined(AFX_STUINFODLG_H__2A207038_5845_446B_BF3F_C6C6240A3146__INCLUDED_)
#define AFX_STUINFODLG_H__2A207038_5845_446B_BF3F_C6C6240A3146__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include"StudentSet.h"
#include"CourseSet.h"
#include"ScoreSet.h"

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

class CStuInfoDlg : public CDialog
{
// Construction
public:
	CStuInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStuInfoDlg)
	enum { IDD = IDD_STUINFO_DIALOG };
	CComboBox	m_choose;
	CListCtrl	m_list;
	CStudentSet m_StudentSet;
	CCourseSet m_CourseSet;
	CScoreSet m_ScoreSet;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStuInfoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSelchangeChoose();
	afx_msg void Display();
	afx_msg void OnAdd();
	afx_msg void OnModify();
	afx_msg void OnDelete();
	afx_msg void OnSumcredit();
	afx_msg void OnAvgscore();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFODLG_H__2A207038_5845_446B_BF3F_C6C6240A3146__INCLUDED_)
