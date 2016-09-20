#if !defined(AFX_COURSEDLG_H__7D93B3F2_8CF6_480A_847F_81093CD37DEB__INCLUDED_)
#define AFX_COURSEDLG_H__7D93B3F2_8CF6_480A_847F_81093CD37DEB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog

class CCourseDlg : public CDialog
{
// Construction
public:
	CCourseDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCourseDlg)
	enum { IDD = IDD_COURSE };
	CString	m_coursename;
	CString	m_courseno;
	CString	m_coursetype;
	float	m_credit;
	BYTE	m_hours;
	BYTE	m_openterm;
	CString	m_special;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCourseDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSEDLG_H__7D93B3F2_8CF6_480A_847F_81093CD37DEB__INCLUDED_)
