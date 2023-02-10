// kdialog2.cpp : implementation file
//

#include "stdafx.h"
#include "Flash.h"
#include "FlashDoc.h"
#include "kdialog2.h" 

                           
#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// KDialog2 dialog

KDialog2::KDialog2(CWnd* pParent /*=NULL*/)
	: CDialog(KDialog2::IDD, pParent)
{
	CView* theparent = (CView*) pParent;
	pDoc = (CFlashDoc*) theparent->GetDocument();

	//{{AFX_DATA_INIT(KDialog2)
	m_editQuestion = pDoc->GetCurrentQuestion();
	m_editAnswer = pDoc->GetCurrentAnswer();
	//}}AFX_DATA_INIT
}

void KDialog2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(KDialog2)
	DDX_Text(pDX, IDC_EDITQuestion, m_editQuestion);
	DDV_MaxChars(pDX, m_editQuestion, 2000);
	DDX_Text(pDX, IDC_EDITAnswer, m_editAnswer);
	DDV_MaxChars(pDX, m_editAnswer, 2000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(KDialog2, CDialog)
	//{{AFX_MSG_MAP(KDialog2)
	ON_BN_CLICKED(IDC_EDITNEW, OnClickedEditNew)
	ON_BN_CLICKED(IDC_EditPrior, OnClickedEditPrior)
	ON_BN_CLICKED(IDC_EditNext, OnClickedEditNext)
	ON_BN_CLICKED(IDC_EditApply, OnClickedEditApply)
	ON_BN_CLICKED(IDC_EditDel, OnClickedEditDel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

                                 
/////////////////////////////////////////////////////////////////////////////
// KDialog2 message handlers

void KDialog2::OnOK()
{
	UpdateData(TRUE); //move from dialog to class variable
	pDoc->SetCurrentQuestion(m_editQuestion);	
	pDoc->SetCurrentAnswer(m_editAnswer);	
	pDoc->UpdateAllViews(NULL);
	CDialog::OnOK();
}

void KDialog2::OnClickedEditNew()
{	
	UpdateData(TRUE); //move from dialog to class variable
	pDoc->SetCurrentQuestion(m_editQuestion);	
	pDoc->SetCurrentAnswer(m_editAnswer);	

	pDoc->NewCard();
	pDoc->SetCurrentCardNum(pDoc->GetCardCount());
	pDoc->UpdateAllViews(NULL);
	m_editQuestion=pDoc->GetCurrentQuestion();
	m_editAnswer=pDoc->GetCurrentAnswer();
	UpdateData(FALSE); //move from class variable to dialog
	
	SetFocus(); //moves it back to question box for next entry
}
    
void KDialog2::OnClickedEditPrior()
{
	pDoc->SetCurrentCardNumLess();
	pDoc->UpdateAllViews(NULL);
	m_editQuestion=pDoc->GetCurrentQuestion();
	m_editAnswer=pDoc->GetCurrentAnswer();
	UpdateData(FALSE); //move from class variable to dialog
}

void KDialog2::OnClickedEditNext()
{
	pDoc->SetCurrentCardNumMore();
	pDoc->UpdateAllViews(NULL);
	m_editQuestion=pDoc->GetCurrentQuestion();
	m_editAnswer=pDoc->GetCurrentAnswer();
	UpdateData(FALSE); //move from class variable to dialog
}


void KDialog2::OnClickedEditApply()
{
	UpdateData(TRUE); //move from dialog to class variable
	pDoc->SetCurrentQuestion(m_editQuestion);	
	pDoc->SetCurrentAnswer(m_editAnswer);	
	pDoc->UpdateAllViews(NULL);
}

void KDialog2::OnClickedEditDel()
{          
	/* I don't know really why I can delete the first and last cards with the
	settings I have here but it works beautifully so guess I'll leave it alone
	for now */
	int j = 0;
	int cardNumber = pDoc->GetCurrentCardNum();
	
	POSITION pos = pDoc->GetFirstCardPos();
	if(pos == NULL) return;
    
    for (j=1; j<=cardNumber; j++)
    	{
    		pDoc->GetNextCard(pos); 
    		if(pos==NULL) return; 
    	}
	pDoc->DelCard(pos);
                                                           
    // we're at the same CardNum, but it is now for next one in list
	pDoc->UpdateAllViews(NULL);
	m_editQuestion=pDoc->GetCurrentQuestion();
	m_editAnswer=pDoc->GetCurrentAnswer();
	UpdateData(FALSE); //move from class variable to dialog
}
