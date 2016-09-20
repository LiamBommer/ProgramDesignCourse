// ScoreSet.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "ScoreSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScoreSet

IMPLEMENT_DYNAMIC(CScoreSet, CRecordset)

CScoreSet::CScoreSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CScoreSet)
	m_studentno = _T("");
	m_score = 0.0f;
	m_credit = 0.0f;
	m_courseno = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CScoreSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CScoreSet::GetDefaultSQL()
{
	return _T("[score]");
}

void CScoreSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CScoreSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[studentno]"), m_studentno);
	RFX_Text(pFX, _T("[courseno]"), m_courseno);
	RFX_Single(pFX, _T("[score]"), m_score);
	RFX_Single(pFX, _T("[credit]"), m_credit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CScoreSet diagnostics

#ifdef _DEBUG
void CScoreSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CScoreSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
