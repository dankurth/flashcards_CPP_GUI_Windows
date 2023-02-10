// FlashDoc.h : interface of the CFlashDoc class
//
/////////////////////////////////////////////////////////////////////////////
class CCard;

class CFlashDoc : public CDocument
{
protected: // create from serialization only
	CFlashDoc();
	DECLARE_DYNCREATE(CFlashDoc)

// Attributes
protected:
	CObList		m_cardList;
	int			m_ncurrentCardNum;
	int			m_ncardCount;
public:

// Operations
public: 
	friend void CFlashApp::OnFileNew(); //only way, for now, to access 
	                                   //constructor to save to new file
    void CardEditDialog();
// for dialog 2
	CCard* GetCurrentCard();
    CString GetCurrentQuestion();
    void SetCurrentQuestion(CString s);
    CString GetCurrentAnswer();
    void SetCurrentAnswer(CString s);

	CCard* NewCard();
	POSITION GetFirstCardPos();
	CCard* GetNextCard(POSITION& pos);
	int GetCardCount();          
	void SetCurrentCardNumMore() 
		{ if(m_ncurrentCardNum<m_ncardCount-1)m_ncurrentCardNum++; }
	void SetCurrentCardNumLess() 
		{if(m_ncurrentCardNum>0)m_ncurrentCardNum--;}
    void SetCurrentCardNum(int num) { m_ncurrentCardNum=num; }
    int GetCurrentCardNum() { return m_ncurrentCardNum; }
    void SetCardsMarkedNone();
	void DelCard(POSITION& pos);    
	
	void SetCurrentCardMarked();
	void SetCurrentCardUnMarked();
	void SetCurrentCardAttempts();
	int GetCardsMarked(); 
	int GetCurrentCardAttempts();
	void SetCardNumRandUnMarked();
	void GotItRight();
	void GotItWrong();
	CCard* GetRandCard();
	void OnClearStatsPartial();

    
// Overrides
	BOOL OnOpenDocument(const char* pszPathName);
	void DeleteContents();
	
// Implementation
	void UpdateIniFileWithDocPath(const char* pszPathName);


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFlashDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFlashDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFlashDoc)
	afx_msg void OnClearStats();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
// class CCard

// A card is a question and an answer
class CCard : public CObject
{  
public:
	CCard();
protected:
    //CCard();
	DECLARE_SERIAL(CCard)
	
// Attributes
	CString		m_question;
	CString		m_answer;
	int			m_nattempts;
	BOOL		m_bmarked; 

public:
	virtual void Serialize(CArchive& ar);
	BOOL DrawCard(CDC* pDC, CRect rect);
	BOOL DrawCardQ(CDC* pDC, CRect rect);
	BOOL DrawCardA(CDC* pDC, CRect rect);

};
