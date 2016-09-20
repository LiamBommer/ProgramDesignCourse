// StudentSet.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "StudentSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentSet

IMPLEMENT_DYNAMIC(CStudentSet, CRecordset)

CStudentSet::CStudentSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CStudentSet)
	m_studentname = _T("");
	m_studentno = _T("");
	m_xb = FALSE;
	m_special = _T("");
	m_totalcredit = 0.0f;
	m_nFields = 6;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CStudentSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CStudentSet::GetDefaultSQL()
{
	return _T("[student]");
}

void CStudentSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CStudentSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentname]"), m_studentname);
	RFX_Text(pFX, _T("[studentno]"), m_studentno);
	RFX_Bool(pFX, _T("[xb]"), m_xb);
	RFX_Date(pFX, _T("[birthday]"), m_birthday);
	RFX_Text(pFX, _T("[special]"), m_special);
	RFX_Single(pFX, _T("[totalcredit]"), m_totalcredit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CStudentSet diagnostics

#ifdef _DEBUG
void CStudentSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudentSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
