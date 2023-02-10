// kdialog1.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// KDialog1 dialog

class KDialog1 : public CDialog
{
CFlashDoc* pDoc;

// Construction
public: 	
//	KDialog1(CWnd* pParent);	
	KDialog1(CFlashDoc* docptr);	
	//overrides
	void PostNcDestroy();
	void OnClose();

	void SetCount(int num);
	void SetMarked(int num);
	void SetAttempts(int num);
	virtual BOOL OnInitDialog();

// Dialog Data
	//{{AFX_DATA(KDialog1)
	enum { IDD = IDD_DIALOG1 };
	int		m_cardCount;
	int		m_cardMarked;
	int		m_cardUnmarked;
	int		m_cardAttempts;
	//}}AFX_DATA

// Implementation
protected:                 
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

	// Generated message map functions
	//{{AFX_MSG(KDialog1)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

