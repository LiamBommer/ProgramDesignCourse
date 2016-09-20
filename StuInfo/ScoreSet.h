#if !defined(AFX_SCORESET_H__CFBFB889_733D_48FD_B0E3_B027638DFE04__INCLUDED_)
#define AFX_SCORESET_H__CFBFB889_733D_48FD_B0E3_B027638DFE04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScoreSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScoreSet recordset

class CScoreSet : public CRecordset
{
public:
	CScoreSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CScoreSet)

// Field/Param Data
	//{{AFX_FIELD(CScoreSet, CRecordset)
	CString	m_studentno;
	float	m_score;
	float	m_credit;
	CString	m_courseno;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScoreSet)
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

#endif // !defined(AFX_SCORESET_H__CFBFB889_733D_48FD_B0E3_B027638DFE04__INCLUDED_)
