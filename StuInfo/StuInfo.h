// StuInfo.h : main header file for the STUINFO application
//

#if !defined(AFX_STUINFO_H__E470E9A8_9215_4B08_9F65_21A1A44B2FE2__INCLUDED_)
#define AFX_STUINFO_H__E470E9A8_9215_4B08_9F65_21A1A44B2FE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStuInfoApp:
// See StuInfo.cpp for the implementation of this class
//

class CStuInfoApp : public CWinApp
{
public:
	CStuInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStuInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStuInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUINFO_H__E470E9A8_9215_4B08_9F65_21A1A44B2FE2__INCLUDED_)
