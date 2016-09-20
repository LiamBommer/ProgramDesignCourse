// StuInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "StuInfo.h"
#include "StuInfoDlg.h"
#include "StudentDlg.h"
#include "CourseDlg.h"
#include "ScoreDlg.h"
#include "AvgScoreDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg dialog

CStuInfoDlg::CStuInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStuInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStuInfoDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStuInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStuInfoDlg)
	DDX_Control(pDX, IDC_CHOOSE, m_choose);
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStuInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CStuInfoDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_CHOOSE, OnSelchangeChoose)
	ON_BN_CLICKED(IDC_ADD, OnAdd)
	ON_BN_CLICKED(IDC_MODIFY, OnModify)
	ON_BN_CLICKED(IDC_DELETE, OnDelete)
	ON_BN_CLICKED(IDC_SUMCREDIT, OnSumcredit)
	ON_BN_CLICKED(IDC_AVGSCORE, OnAvgscore)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoDlg message handlers

BOOL CStuInfoDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_list.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStuInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStuInfoDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStuInfoDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStuInfoDlg::OnSelchangeChoose() 
{
	// TODO: Add your control notification handler code here
	Display();
}

void CStuInfoDlg::Display()
{
	//初始化ListCtrl
	m_list.DeleteAllItems();
	while(m_list.DeleteColumn(0));

	CRecordset *cSet;
	if(m_choose.GetCurSel()==0||m_choose.GetCurSel()==-1)
		cSet = &m_StudentSet;
	else if(m_choose.GetCurSel()==1)
		cSet = &m_CourseSet;
	else
		cSet = &m_ScoreSet;

	cSet->Open();
	CODBCFieldInfo field;
	for( UINT i=0; i< cSet->m_nFields;i++)
	{
		cSet->GetODBCFieldInfo(i,field);
		m_list.InsertColumn(i,field.m_strName,LVCFMT_LEFT,100);
	}

	int m_nItem=0;
	CString str;
	while( ! cSet->IsEOF())
	{
		for(UINT i=0;i<cSet->m_nFields;i++)
		{
			cSet->GetFieldValue(i,str);
			if(i==0)
				m_list.InsertItem(m_nItem,str);
			else
				m_list.SetItemText(m_nItem,i,str);
		}
		m_nItem++;
		cSet->MoveNext();
	}

	cSet->Close();

}



void CStuInfoDlg::OnAdd() 
{
	// TODO: Add your control notification handler code here
	if(m_choose.GetCurSel()==0||m_choose.GetCurSel()==-1)
	{
		CStudentDlg dlg;
		dlg.m_birthday="1986-1-1";
		if(dlg.DoModal() == IDOK )
		{
			m_StudentSet.Open();
			
			int a,b,c;
			sscanf(dlg.m_birthday.GetBuffer(dlg.m_birthday.GetLength()),"%d-%d-%d",&a,&b,&c);
			CTime time(a,b,c,0,0,0);
			
			m_StudentSet.AddNew();
			m_StudentSet.m_studentname=dlg.m_studentname;
			m_StudentSet.m_studentno=dlg.m_studentno;
			m_StudentSet.m_xb=dlg.m_xb;
			m_StudentSet.m_birthday=time;
			m_StudentSet.m_special=dlg.m_special;
			m_StudentSet.m_totalcredit=dlg.m_totalcredit;

			m_StudentSet.Update();
			m_StudentSet.Requery();
			m_StudentSet.Close();			
		}
	}
	else if(m_choose.GetCurSel()==1)
	{
		CCourseDlg dlg;
		if(dlg.DoModal()==IDOK)
		{
			m_CourseSet.Open();
			m_CourseSet.AddNew();
			m_CourseSet.m_coursename=dlg.m_coursename;
			m_CourseSet.m_courseno=dlg.m_courseno;
			m_CourseSet.m_special=dlg.m_special;
			m_CourseSet.m_coursetype=dlg.m_coursetype;
			m_CourseSet.m_openterm = dlg.m_openterm;
			m_CourseSet.m_hours = dlg.m_hours;
			m_CourseSet.m_credit = dlg.m_credit;
			
			m_CourseSet.Update();
			m_CourseSet.Requery();
			m_CourseSet.Close();
		}
	}
	else if(m_choose.GetCurSel()==2)
	{
		CScoreDlg dlg;
		if(dlg.DoModal()==IDOK)
		{
			m_ScoreSet.Open();
			m_ScoreSet.AddNew();
			m_ScoreSet.m_courseno=dlg.m_courseno;
			m_ScoreSet.m_studentno=dlg.m_studentno;
			m_ScoreSet.m_score=dlg.m_score;
			m_ScoreSet.m_credit=dlg.m_credit;

			m_ScoreSet.Update();
			m_ScoreSet.Requery();
			m_ScoreSet.Close();
		}
	}
	Display();
	
}

void CStuInfoDlg::OnModify() 
{
	// TODO: Add your control notification handler code here
	POSITION ps=m_list.GetFirstSelectedItemPosition();
	if(ps==NULL)
	{
		MessageBox("请选择一行！！");
		return;
	}
	int nItem = m_list.GetNextSelectedItem(ps); //获取选中的行号
	//以上适用任何数据集

	if(m_choose.GetCurSel()==0||m_choose.GetCurSel()==-1)
	{
		CStudentDlg dlg;  
		//获取选中的信息，显示在对话框中
		dlg.m_studentname=m_list.GetItemText(nItem,0);
		dlg.m_studentno=m_list.GetItemText(nItem,1);
		dlg.m_xb=m_list.GetItemText(nItem,2)=="1"?true:false;
		dlg.m_birthday=m_list.GetItemText(nItem,3);
		dlg.m_special=m_list.GetItemText(nItem,4);
		dlg.m_totalcredit=(float)atof(m_list.GetItemText(nItem,5));
		
		
		if(dlg.DoModal()==IDOK)
		{
			if(dlg.m_studentno!=m_list.GetItemText(nItem,1))
			{
				MessageBox("学号不能更改！！");
				return;
			}
			
			m_StudentSet.Open();
			
			CString str2;
			while(!m_StudentSet.IsEOF())
			{
				int i=1;
				m_StudentSet.GetFieldValue(i,str2);
				//以学号为关键字，在数据库中查找相关记录，找到后修改它
				if(dlg.m_studentno==str2)
				{
					m_StudentSet.Edit();
					m_StudentSet.m_studentname=dlg.m_studentname;
					m_StudentSet.m_studentno=dlg.m_studentno;
					m_StudentSet.m_xb=dlg.m_xb;
					
					int a,b,c;
					sscanf(dlg.m_birthday.GetBuffer(dlg.m_birthday.GetLength()),"%d-%d-%d",&a,&b,&c);
					CTime time(a,b,c,0,0,0);
					
					m_StudentSet.m_birthday=time;
					m_StudentSet.m_special=dlg.m_special;
					m_StudentSet.m_totalcredit=dlg.m_totalcredit;
					m_StudentSet.Update();
					m_StudentSet.Requery();
					break;
				}
				m_StudentSet.MoveNext();
			}
			m_StudentSet.Close();
		}
	}
	else if(m_choose.GetCurSel()==1)
	{
		CCourseDlg dlg;
		dlg.m_coursename=m_list.GetItemText(nItem,2);
		dlg.m_courseno=m_list.GetItemText(nItem,0);
		dlg.m_special=m_list.GetItemText(nItem,1);
		dlg.m_coursetype=m_list.GetItemText(nItem,3);
		dlg.m_openterm=atoi(m_list.GetItemText(nItem,4));
		dlg.m_hours=atoi(m_list.GetItemText(nItem,5));
		dlg.m_credit=(float)atof(m_list.GetItemText(nItem,6));

		if(dlg.DoModal()==IDOK)
		{
			if(dlg.m_courseno!=m_list.GetItemText(nItem,0))
			{
				MessageBox("课程号不能更改！！");
				return;
			}
			
			m_CourseSet.Open();
			
			CString str2;
			while(!m_CourseSet.IsEOF())
			{
				int i=0;
				m_CourseSet.GetFieldValue(i,str2);
				if(dlg.m_courseno==str2)
				{
					m_CourseSet.Edit();
					m_CourseSet.m_coursename=dlg.m_coursename;
					m_CourseSet.m_courseno=dlg.m_courseno;
					m_CourseSet.m_coursetype=dlg.m_coursetype;
					m_CourseSet.m_special=dlg.m_special;
					m_CourseSet.m_hours=dlg.m_hours;
					m_CourseSet.m_openterm=dlg.m_openterm;
					m_CourseSet.m_credit=dlg.m_credit;

					m_CourseSet.Update();
					m_CourseSet.Requery();
					break;
				}
				m_CourseSet.MoveNext();
			}
			m_CourseSet.Close();
		}

	}
	else if(m_choose.GetCurSel()==2)
	{
		CScoreDlg dlg;
		dlg.m_studentno=m_list.GetItemText(nItem,0);
		dlg.m_courseno=m_list.GetItemText(nItem,1);
		dlg.m_score=(float)atof(m_list.GetItemText(nItem,2));
		dlg.m_credit=(float)atof(m_list.GetItemText(nItem,3));
		
		if(dlg.DoModal()==IDOK)
		{
			if((dlg.m_studentno!=m_list.GetItemText(nItem,0))||(dlg.m_courseno!=m_list.GetItemText(nItem,1)))
			{
				MessageBox("不能改变学号和课程号！！");
				return;
			}
			m_ScoreSet.Open();
			CString str1,str2;
			while(!m_ScoreSet.IsEOF())
			{
				int i=0,j=1;
				m_ScoreSet.GetFieldValue(i,str1);
				m_ScoreSet.GetFieldValue(j,str2);
				if(dlg.m_studentno==str1 && dlg.m_courseno==str2)
				{
					m_ScoreSet.Edit();
					m_ScoreSet.m_studentno=dlg.m_studentno;
					m_ScoreSet.m_courseno=dlg.m_courseno;
					m_ScoreSet.m_score=dlg.m_score;
					m_ScoreSet.m_credit=dlg.m_credit;

					m_ScoreSet.Update();
					m_ScoreSet.Requery();
					break;
				}
				m_ScoreSet.MoveNext();
			}
			m_ScoreSet.Close();
		}

	}
	Display();   //修改完成后刷新数据
}

void CStuInfoDlg::OnDelete() 
{
	// TODO: Add your control notification handler code here
	POSITION ps=m_list.GetFirstSelectedItemPosition();
	if(ps==NULL)
	{
		MessageBox("请选择一行！！");
		return;
	}
	int nItem = m_list.GetNextSelectedItem(ps); //获取选中的行号
	//以上适用任何数据集

	CString str1,str2;
	CRecordset *cSet;//选择数据集
	
	if(m_choose.GetCurSel()==0||m_choose.GetCurSel()==-1)
	{
		cSet=&m_StudentSet;
		str1=m_list.GetItemText(nItem,1);
	}
	else if(m_choose.GetCurSel()==1)
	{
		cSet=&m_CourseSet;
		str1=m_list.GetItemText(nItem,0);
	}
	else if(m_choose.GetCurSel()==2)
	{
		cSet=&m_ScoreSet;
		str1=m_list.GetItemText(nItem,0);
		str2=m_list.GetItemText(nItem,1);
	}


	cSet->Open();
	
	CString str11,str22;
	while(!cSet->IsEOF())
	{
		if(m_choose.GetCurSel()==0||m_choose.GetCurSel()==-1)
		{
			int i=1;
			cSet->GetFieldValue(i,str11);
			if(str1==str11)
			{
				cSet->Delete();
				break;
			}

		}
		else if(m_choose.GetCurSel()==1)
		{
			int i=0;
			cSet->GetFieldValue(i,str11);
			if(str1==str11)
			{
				cSet->Delete();
				break;
			}
		}
		else if(m_choose.GetCurSel()==2)
		{
			int i=0,j=1;
			cSet->GetFieldValue(i,str11);
			cSet->GetFieldValue(j,str22);
			if((str1==str11)&&(str2==str22))
			{
				cSet->Delete();
				break;
			}
		}
		cSet->MoveNext();
	}
	cSet->Close();
	Display();

}

void CStuInfoDlg::OnSumcredit() 
{
	// TODO: Add your control notification handler code here

	m_StudentSet.Open();
	m_ScoreSet.Open();
	int i=1,j=0,k=3;
	CString str1,str2,credit,str;
	while(!m_StudentSet.IsEOF())
	{
		m_StudentSet.GetFieldValue(i,str1);
		float total = 0;;
		while(!m_ScoreSet.IsEOF())
		{
			m_ScoreSet.GetFieldValue(j,str2);
			if(str1==str2)
			{
				m_ScoreSet.GetFieldValue(k,credit);
				total = total + (float)atof(credit);
			}
			m_ScoreSet.MoveNext();
		}
		m_StudentSet.Edit();
		m_StudentSet.m_totalcredit=total;
		m_StudentSet.Update();

		m_ScoreSet.MoveFirst();	//成绩表指针复位
		total=0;				//总学分复位
		m_StudentSet.MoveNext(); //搜索学生表下一位同学
	}
	m_StudentSet.Requery();
	m_StudentSet.Close();
	m_ScoreSet.Close();
	Display();
	MessageBox("总学分更新完成！");	
}

void CStuInfoDlg::OnAvgscore() 
{
	// TODO: Add your control notification handler code here
	CAvgScoreDlg dlg;
	dlg.DoModal();	
}
