// Flash.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Flash.h"

#include "MainFrm.h"
#include "FlashDoc.h"
#include "FlashView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashApp

BEGIN_MESSAGE_MAP(CFlashApp, CWinApp)
	//{{AFX_MSG_MAP(CFlashApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashApp construction

CFlashApp::CFlashApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFlashApp object

CFlashApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFlashApp initialization

BOOL CFlashApp::InitInstance()
{
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CFlashDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CFlashView));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// simple command line parsing
	if (m_lpCmdLine[0] == '\0')
	{
				// Open file name saved in private INI file. 
				// following 3 lines from chkbook
		CString strDocPath = GetDocPathFromIniFile();
		if (!strDocPath.IsEmpty())
			OpenDocumentFile(strDocPath);

	}
	else if ((m_lpCmdLine[0] == '-' || m_lpCmdLine[0] == '/') &&
		(m_lpCmdLine[1] == 'e' || m_lpCmdLine[1] == 'E'))
	{
		// program launched embedded - wait for DDE or OLE open
	}
	else
	{
		// open document specified as argument on command line
		OpenDocumentFile(m_lpCmdLine);
	}

	return TRUE;
}

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
		// No message handlers
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

// App command to run the dialog
void CFlashApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// INI file implementation   //this section from chkbook

static char BASED_CODE szIniFileSection[] = "Most Recent Flash Study File";
static char BASED_CODE szIniFileEntry[] = "File";

void CFlashApp::UpdateIniFileWithDocPath(const char* pszPathName)
{
	WriteProfileString(szIniFileSection, szIniFileEntry, pszPathName);
}

CString CFlashApp::GetDocPathFromIniFile()
{
	return GetProfileString(szIniFileSection, szIniFileEntry, NULL);
}

// CFlashApp commands
              
////// Overrides

CDocument* CFlashApp::OpenDocumentFile(LPCSTR lpszFileName)
{

	CFlashDoc* pDoc = (CFlashDoc*)CWinApp::OpenDocumentFile(lpszFileName);
	if (pDoc == NULL)
	{
		CString strMessage;
		AfxFormatString1(strMessage, IDS_CANNOT_OPEN_FLASHFILE, 
			lpszFileName);
		AfxMessageBox(strMessage);
		return NULL;
	}
     return pDoc;
}

void CFlashApp::OnFileNew()
{	
	// By default, the framework does not create an actual file for
	// a new document until the user does a File Save As.  But ChkBook
	// requires a file as soon as the user does a File New, because
	// ChkBook updates the file on a per transaction basis.  Upon File
	// New, we prompt the user with a File Open dialog, in which the
	// user specifies a new file (or if she changes her mind, she
	// can specify an existing check book file).  We call the same
	// CWinApp::DoPromptFileName that CWinApp::OnFileOpen calls.
	// But we replace the OFN_FILEMUSTEXIST flag with
	// OFN_CREATEPROMPT.

	CString strNewFileName;

	if (!(DoPromptFileName(strNewFileName, IDS_NEW_FLASHFILE,
			OFN_HIDEREADONLY | OFN_CREATEPROMPT, TRUE, NULL)))
		return;

	// If file doesn't already exist, then create it.
	CFile file;
	CFileStatus status;
	if (!file.GetStatus(strNewFileName, status))
	{
		CFlashDoc* pDoc=new CFlashDoc; //dont like it, but had to unprotect
	//CFlashDocs constructor to be able to use it. Got to be another way.										
	// a better better way? using friend in base class
		pDoc->NewCard();
		pDoc->DoSave(strNewFileName);             
		delete pDoc;
	}

	// Open the file now that it has been created.
	OpenDocumentFile(strNewFileName);
}
  

