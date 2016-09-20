// AvgScoreDlg.cpp : implementation file
//

#include "stdafx.h"
#include "stuinfo.h"
#include "AvgScoreDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAvgScoreDlg dialog


CAvgScoreDlg::CAvgScoreDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAvgScoreDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAvgScoreDlg)
	m_avgByCourse = 0.0f;
	m_avgByNo = 0.0f;
	m_avgByXb = 0.0f;
	//}}AFX_DATA_INIT
}


void CAvgScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAvgScoreDlg)
	DDX_Control(pDX, IDC_CHOOSEXB, m_chooseXb);
	DDX_Control(pDX, IDC_CHOOSENO, m_chooseNo);
	DDX_Control(pDX, IDC_CHOOSECOURSE, m_chooseCourse);
	DDX_Text(pDX, IDC_AVGBYCOURSE, m_avgByCourse);
	DDX_Text(pDX, IDC_AVGBYNO, m_avgByNo);
	DDX_Text(pDX, IDC_AVGBYXB, m_avgByXb);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAvgScoreDlg, CDialog)
	//{{AFX_MSG_MAP(CAvgScoreDlg)
	ON_CBN_SELCHANGE(IDC_CHOOSEXB, OnSelchangeChoosexb)
	ON_CBN_SELCHANGE(IDC_CHOOSENO, OnSelchangeChooseno)
	ON_CBN_SELCHANGE(IDC_CHOOSECOURSE, OnSelchangeChoosecourse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAvgScoreDlg message handlers

BOOL CAvgScoreDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString str;

	m_CourseSet.Open();
	while(!m_CourseSet.IsEOF())
	{
		m_CourseSet.GetFieldValue(2,str);
		m_chooseCourse.AddString(str);
		m_CourseSet.MoveNext();
	}
	m_CourseSet.Close();

	m_StudentSet.Open();
	while(!m_StudentSet.IsEOF())
	{
		m_StudentSet.GetFieldValue(1,str);
		m_chooseNo.AddString(str);
		m_StudentSet.MoveNext();
	}
	m_StudentSet.Close();

	GetDlgItem(IDC_AVGBYXB)->EnableWindow(false);
	GetDlgItem(IDC_AVGBYCOURSE)->EnableWindow(false);
	GetDlgItem(IDC_AVGBYNO)->EnableWindow(false);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAvgScoreDlg::OnSelchangeChoosexb() 
{
	// TODO: Add your control notification handler code here
	CString str;
	//GetDlgItemText(IDC_CHOOSEXB,str);//也可以使用，适用于下拉式列表框
	m_chooseXb.GetWindowText(str);

	m_ScoreSet.Open();
	m_StudentSet.Open();
	int i=0,j=2,k=1,x=2;         //i为成绩表学号，j为成绩表成绩，k为学生表学号，x为学生表性别
	CString str1,str2,str3,str4;//str2成绩表学号，str1为成绩表成绩,str3为学生表学号，str4为学生表性别


	int n=0;        //人次
	float totalScore=0,  maleScore=0,  femaleScore=0;
	if(str=="男")
	{
		while(!m_ScoreSet.IsEOF())
		{
			m_ScoreSet.GetFieldValue(i,str2);     //取成绩表学号
			while(!m_StudentSet.IsEOF())
			{
				m_StudentSet.GetFieldValue(k,str3);
				if(str2==str3)						//找到与学生表相等的学号
				{
					m_StudentSet.GetFieldValue(x,str4);  //判断性别
					if(str4=="1")
					{
						m_ScoreSet.GetFieldValue(j,str1);  
						maleScore = maleScore + (float)atof(str1);
						n++;
					}
				}
				m_StudentSet.MoveNext();
			}
			m_StudentSet.MoveFirst();
			m_ScoreSet.MoveNext();
		}
		if(n==0)
			m_avgByXb=0;
		else
			m_avgByXb=maleScore/n;
		UpdateData(false);
	}
	else
	{
		while(!m_ScoreSet.IsEOF())
		{
			m_ScoreSet.GetFieldValue(i,str2);     //取成绩表学号
			while(!m_StudentSet.IsEOF())
			{
				m_StudentSet.GetFieldValue(k,str3);
				if(str2==str3)						//找到与学生表相等的学号
				{
					m_StudentSet.GetFieldValue(x,str4);  //判断性别
					if(str4=="0")
					{
						m_ScoreSet.GetFieldValue(j,str1);  
						femaleScore = femaleScore + (float)atof(str1);
						n++;
					}
				}
				m_StudentSet.MoveNext();
			}
			m_StudentSet.MoveFirst();
			m_ScoreSet.MoveNext();
		}
		if(n==0)
			m_avgByXb=0;
		else
			m_avgByXb=femaleScore/n;
		UpdateData(false);
	}
	m_ScoreSet.Close();
	m_StudentSet.Close();	
}

void CAvgScoreDlg::OnSelchangeChooseno() 
{
	// TODO: Add your control notification handler code here
	CString str;
//	m_chooseNo.GetLBText(m_chooseNo.GetCurSel(),str);
	m_chooseNo.GetWindowText(str);     //与上一个语句等效

	m_ScoreSet.Open();
	str.TrimLeft();

	CString studentno,strscore;
	float score=0;
	int n=0;//课程门数
	while(!m_ScoreSet.IsEOF())
	{
		m_ScoreSet.GetFieldValue("studentno",studentno);
		if(studentno==str)
		{
			m_ScoreSet.GetFieldValue("score",strscore);
			score=score+(float)atof(strscore);
			n++;
		}
		m_ScoreSet.MoveNext();
	}
	m_ScoreSet.Close();
	if(n==0)
		m_avgByNo = 0;
	else
		m_avgByNo = score/n;
	UpdateData(false);
}

void CAvgScoreDlg::OnSelchangeChoosecourse() 
{
	// TODO: Add your control notification handler code here
	CString str;
	m_chooseCourse.GetWindowText(str);
	str.TrimLeft();

	m_CourseSet.Open();
	CString coursename,courseno;
	while(!m_CourseSet.IsEOF())
	{
		m_CourseSet.GetFieldValue("coursename",coursename);
		if(str == coursename)
		{
			m_CourseSet.GetFieldValue("courseno",courseno);
			break;
		}
		m_CourseSet.MoveNext();
	}
	m_CourseSet.Close();

	m_ScoreSet.Open();
	float totalscore=0;
	int n=0;//人次
	CString coursenoInScore,strscore;
	while(!m_ScoreSet.IsEOF())
	{
		m_ScoreSet.GetFieldValue("courseno",coursenoInScore);
		if(courseno == coursenoInScore)
		{
			m_ScoreSet.GetFieldValue("score",strscore);
			totalscore += (float)atof(strscore);
			n++;
		}
		m_ScoreSet.MoveNext();
	}
	m_ScoreSet.Close();
	if(n==0)
		m_avgByCourse = 0;
	else
		m_avgByCourse = totalscore/n;
	UpdateData(false);
}
