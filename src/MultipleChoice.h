// MultipleChoice.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MultipleChoice dialog

class MultipleChoice : public CDialog
{
CFlashDoc* pDoc;
CView* theparent;
	// Construction
public:
//	MultipleChoice(CWnd* pParent = NULL);   // standard constructor
	MultipleChoice(CWnd* pParent/* = NULL*/);   // need a pointer to pDoc

// Dialog Data
	//{{AFX_DATA(MultipleChoice)
	enum { IDD = IDD_MultipleChoice };
	CString	m_listBox;
	CString	m_editBoxA;
	CString	m_editBoxQ;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MultipleChoice)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	CListBox& ListBox()
	{ return *(CListBox*) GetDlgItem(IDC_MultipleChoiceList); }
	
	virtual BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(MultipleChoice)
	afx_msg void OnDblclkMultipleChoiceList();
	afx_msg void OnSelchangeMultipleChoiceList();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
		
	
};
