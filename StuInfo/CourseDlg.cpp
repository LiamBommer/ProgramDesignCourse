// CourseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "CourseDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg dialog


CCourseDlg::CCourseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCourseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCourseDlg)
	m_coursename = _T("");
	m_courseno = _T("");
	m_coursetype = _T("");
	m_credit = 0.0f;
	m_hours = 0;
	m_openterm = 0;
	m_special = _T("");
	//}}AFX_DATA_INIT
}


void CCourseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCourseDlg)
	DDX_Text(pDX, IDC_COURSENAME, m_coursename);
	DDX_Text(pDX, IDC_COURSENO, m_courseno);
	DDX_Text(pDX, IDC_COURSETYPE, m_coursetype);
	DDX_Text(pDX, IDC_CREDIT, m_credit);
	DDX_Text(pDX, IDC_HOURS, m_hours);
	DDX_Text(pDX, IDC_OPENTERM, m_openterm);
	DDX_Text(pDX, IDC_SPECIAL2, m_special);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCourseDlg, CDialog)
	//{{AFX_MSG_MAP(CCourseDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCourseDlg message handlers
