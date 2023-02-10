// FlashView.h : interface of the CFlashView class
//
/////////////////////////////////////////////////////////////////////////////
class KDialog1;

class CFlashView : public CScrollView
{
KDialog1*	dlgptr1;
protected: // create from serialization only
	CFlashView();
	DECLARE_DYNCREATE(CFlashView)

// Attributes
public:
	CFlashDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlashView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlashView)
	afx_msg void OnEditFile();
	afx_msg void OnMultipleChoice();
	afx_msg void OnShowAnswer();
	afx_msg void OnTypeInAnswer();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FlashView.cpp
inline CFlashDoc* CFlashView::GetDocument()
   { return (CFlashDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////
