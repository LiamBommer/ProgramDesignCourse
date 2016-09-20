// CourseSet.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "CourseSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseSet

IMPLEMENT_DYNAMIC(CCourseSet, CRecordset)

CCourseSet::CCourseSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCourseSet)
	m_courseno = _T("");
	m_special = _T("");
	m_coursename = _T("");
	m_coursetype = _T("");
	m_openterm = 0;
	m_hours = 0;
	m_credit = 0.0f;
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCourseSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=student");
}

CString CCourseSet::GetDefaultSQL()
{
	return _T("[course]");
}

void CCourseSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCourseSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[courseno]"), m_courseno);
	RFX_Text(pFX, _T("[special]"), m_special);
	RFX_Text(pFX, _T("[coursename]"), m_coursename);
	RFX_Text(pFX, _T("[coursetype]"), m_coursetype);
	RFX_Byte(pFX, _T("[openterm]"), m_openterm);
	RFX_Byte(pFX, _T("[hours]"), m_hours);
	RFX_Single(pFX, _T("[credit]"), m_credit);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCourseSet diagnostics

#ifdef _DEBUG
void CCourseSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCourseSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
