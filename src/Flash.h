// Flash.h : main header file for the FLASH application
//
#define VAR2CTRL FALSE
#define CTRL2VAR TRUE

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

static int cardNumber=1;
/////////////////////////////////////////////////////////////////////////////
// CFlashApp:
// See Flash.cpp for the implementation of this class
//

class CFlashApp : public CWinApp
{
public:
	CFlashApp();

	// Operations
	void UpdateIniFileWithDocPath(const char* pszPathName); //from chkbook
	CString GetDocPathFromIniFile(); //from chkbook

// Overrides
    virtual CDocument* OpenDocumentFile(LPCSTR lpszFileName);

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFlashApp)
	afx_msg void OnAppAbout();
	afx_msg void OnFileNew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CFlashApp theApp; //external so doc can use it for GetDocPa..

