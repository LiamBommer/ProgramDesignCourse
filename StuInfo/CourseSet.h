#if !defined(AFX_COURSESET_H__D09EC40C_8D3A_4FAB_A6A8_36BBDE4122E3__INCLUDED_)
#define AFX_COURSESET_H__D09EC40C_8D3A_4FAB_A6A8_36BBDE4122E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CourseSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCourseSet recordset

class CCourseSet : public CRecordset
{
public:
	CCourseSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCourseSet)

// Field/Param Data
	//{{AFX_FIELD(CCourseSet, CRecordset)
	CString	m_courseno;
	CString	m_special;
	CString	m_coursename;
	CString	m_coursetype;
	BYTE	m_openterm;
	BYTE	m_hours;
	float	m_credit;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCourseSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COURSESET_H__D09EC40C_8D3A_4FAB_A6A8_36BBDE4122E3__INCLUDED_)
