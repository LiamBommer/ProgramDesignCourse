// StuInfo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "StuInfo.h"
#include "StuInfoDlg.h"

#include <odbcinst.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStuInfoApp

BEGIN_MESSAGE_MAP(CStuInfoApp, CWinApp)
	//{{AFX_MSG_MAP(CStuInfoApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStuInfoApp construction

CStuInfoApp::CStuInfoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CStuInfoApp object

CStuInfoApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CStuInfoApp initialization

BOOL CStuInfoApp::InitInstance()
{
	CString sPath;
	GetModuleFileName(NULL,sPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);
	int nPos;
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);
	nPos = sPath.ReverseFind('\\');
	sPath = sPath.Left(nPos);

	CString lpszFile = sPath + "\\student.mdb";

	char * szDesc = new char[256];
	int len;
//	sprintf(szDesc,"DSN=%s? DESCRIPTION=TOC support source? DBQ=%s? FIL=MicrosoftAccess? DEFAULTDIR=%s?? ","student",lpszFile,sPath);
	sprintf(szDesc,"DSN=%s? DBQ=%s?? ","student",lpszFile);
	//sprintf:字串格式化命令，主要功能是把格式化的数据写入某个字符串中。

	len = strlen(szDesc);
	for(int i=0; i<len;i++)
	{
		if(szDesc[i]=='?')
			szDesc[i]='\0';
	}

	if(false==SQLConfigDataSource(NULL,ODBC_ADD_DSN,"Microsoft Access Driver (*.mdb)\0",(LPCSTR)szDesc))
		AfxMessageBox("SQLConfigDataSource Failed");


	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CStuInfoDlg dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
