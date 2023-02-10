// ShowAnswer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ShowAnswer dialog

class ShowAnswer : public CDialog
{
CFlashDoc* pDoc;

// Construction
public:
	ShowAnswer(CWnd* pParent /* = NULL*/);   // standard constructor

	BOOL m_showAnswerFlag;
// Dialog Data
	//{{AFX_DATA(ShowAnswer)
	enum { IDD = IDD_ShowAnswer };
	CString	m_editBox;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ShowAnswer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ShowAnswer)
	afx_msg void OnYes();
	afx_msg void OnNo();
	afx_msg void OnShowAnswer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
