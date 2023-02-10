// ShowCorrect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ShowCorrect dialog

class ShowCorrect : public CDialog
{
CFlashDoc* pDoc;

// Construction
public:
	ShowCorrect(CWnd* pParent = NULL, CView* qview = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ShowCorrect)
	enum { IDD = IDD_MCShowCorrect };
	CString	m_editBoxQ;
	CString	m_editBoxA;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShowCorrect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ShowCorrect)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
