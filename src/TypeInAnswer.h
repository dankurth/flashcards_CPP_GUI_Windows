// TypeInAnswer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TypeInAnswer dialog

class TypeInAnswer : public CDialog
{
CFlashDoc* pDoc;
CView* theparent;

// Construction
public:
	TypeInAnswer(CWnd* pParent /*= NULL*/);   // standard constructor

// Dialog Data
	//{{AFX_DATA(TypeInAnswer)
	enum { IDD = IDD_TypeInAnswer };
	CString	m_editBox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TypeInAnswer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TypeInAnswer)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
