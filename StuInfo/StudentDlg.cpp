// StudentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "StudentDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg dialog


CStudentDlg::CStudentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentDlg)
	m_birthday = _T("");
	m_special = _T("");
	m_studentname = _T("");
	m_studentno = _T("");
	m_totalcredit = 0.0f;
	m_xb = FALSE;
	//}}AFX_DATA_INIT
}


void CStudentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentDlg)
	DDX_Text(pDX, IDC_BIRTHDAY, m_birthday);
	DDX_Text(pDX, IDC_SPECIAL, m_special);
	DDX_Text(pDX, IDC_STUDENTNAME, m_studentname);
	DDX_Text(pDX, IDC_STUDENTNO, m_studentno);
	DDX_Text(pDX, IDC_TOTALCREDIT, m_totalcredit);
	DDX_Text(pDX, IDC_XB, m_xb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStudentDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentDlg message handlers

void CStudentDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	m_studentname.TrimLeft();
	m_studentno.TrimLeft();
	if(m_studentname.IsEmpty()||m_studentno.IsEmpty())
	{
		MessageBox("学号和姓名不能为空！！");
		return;
	}
	else
		CDialog::OnOK();
}
