// kdialog2.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// KDialog2 dialog

class KDialog2 : public CDialog
{
CFlashDoc* pDoc;

// Construction
public:
	KDialog2(CWnd* pParent /*= NULL*/);	// standard constructor


// Dialog Data
	//{{AFX_DATA(KDialog2)
	enum { IDD = IDD_DIALOG2 };
	CString	m_editQuestion;
	CString	m_editAnswer;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(KDialog2)
	virtual void OnOK();
	afx_msg void OnClickedEditNew();
	afx_msg void OnClickedEditPrior();
	afx_msg void OnClickedEditNext();
	afx_msg void OnClickedEditApply();
	afx_msg void OnClickedEditDel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
