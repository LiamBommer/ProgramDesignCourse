#if !defined(AFX_AVGSCOREDLG_H__59C247E8_1208_4F57_BC51_0B796C0958F9__INCLUDED_)
#define AFX_AVGSCOREDLG_H__59C247E8_1208_4F57_BC51_0B796C0958F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AvgScoreDlg.h : header file
//
#include"StudentSet.h"
#include"CourseSet.h"
#include"ScoreSet.h"

/////////////////////////////////////////////////////////////////////////////
// CAvgScoreDlg dialog

class CAvgScoreDlg : public CDialog
{
// Construction
public:
	CAvgScoreDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAvgScoreDlg)
	enum { IDD = IDD_AVGSCORE };
	CComboBox	m_chooseXb;
	CComboBox	m_chooseNo;
	CComboBox	m_chooseCourse;
	float	m_avgByCourse;
	float	m_avgByNo;
	float	m_avgByXb;
	CStudentSet m_StudentSet;
	CCourseSet m_CourseSet;
	CScoreSet m_ScoreSet;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAvgScoreDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAvgScoreDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeChoosexb();
	afx_msg void OnSelchangeChooseno();
	afx_msg void OnSelchangeChoosecourse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AVGSCOREDLG_H__59C247E8_1208_4F57_BC51_0B796C0958F9__INCLUDED_)
