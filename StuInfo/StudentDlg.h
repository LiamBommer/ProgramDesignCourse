#if !defined(AFX_STUDENTDLG_H__8F72AF0A_695E_4EC8_ABBE_0E1B65416D84__INCLUDED_)
#define AFX_STUDENTDLG_H__8F72AF0A_695E_4EC8_ABBE_0E1B65416D84__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// StudentDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog

class CStudentDlg : public CDialog
{
// Construction
public:
	CStudentDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentDlg)
	enum { IDD = IDD_STUDENT };
	CString	m_birthday;
	CString	m_special;
	CString	m_studentname;
	CString	m_studentno;
	float	m_totalcredit;
	BOOL	m_xb;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStudentDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTDLG_H__8F72AF0A_695E_4EC8_ABBE_0E1B65416D84__INCLUDED_)
