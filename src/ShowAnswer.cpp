// ShowAnswer.cpp : implementation file
//

#include "stdafx.h"
#include "Flash.h"
#include "FlashDoc.h"
#include "ShowAnswer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ShowAnswer dialog


ShowAnswer::ShowAnswer(CWnd* pParent /*=NULL*/)
	: CDialog(ShowAnswer::IDD, pParent)
{

	CView* theparent = (CView*) pParent;
	pDoc = (CFlashDoc*) theparent->GetDocument();

	m_showAnswerFlag = FALSE;

	//{{AFX_DATA_INIT(ShowAnswer)
	m_editBox = _T("");
	//}}AFX_DATA_INIT
}


void ShowAnswer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShowAnswer)
	DDX_Text(pDX, IDC_EDIT1, m_editBox);
	DDV_MaxChars(pDX, m_editBox, 10000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ShowAnswer, CDialog)
	//{{AFX_MSG_MAP(ShowAnswer)
	ON_BN_CLICKED(IDC_Yes, OnYes)
	ON_BN_CLICKED(IDC_No, OnNo)
	ON_BN_CLICKED(IDC_ShowAnswer, OnShowAnswer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// ShowAnswer message handlers

void ShowAnswer::OnYes() 
{
	if(!m_showAnswerFlag) return;
	m_showAnswerFlag = FALSE;

	pDoc->GotItRight();   // set m_bmarked in current card itself
	m_editBox = "";
	UpdateData(VAR2CTRL);
	SetFocus();
}

void ShowAnswer::OnNo() 
{
	if(!m_showAnswerFlag) return;
	m_showAnswerFlag = FALSE;

	pDoc->GotItWrong();  
	m_editBox = "";
	UpdateData(VAR2CTRL);
	SetFocus(); //so tab goes to tab order 1

}

void ShowAnswer::OnShowAnswer() 
{
 
	if(m_showAnswerFlag) return;
	m_showAnswerFlag = TRUE;
	pDoc->UpdateAllViews(NULL);
	m_editBox = pDoc->GetCurrentAnswer();
	UpdateData(VAR2CTRL);
}

/*
void ShowAnswer::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	m_editBox = "key pressed";
	UpdateData(VAR2CTRL);
	
	if(nChar=='4')
	{
		if(!m_showAnswerFlag)
		{
			OnShowAnswer();
		}
		else
		{
			OnYes();
		}
	}
	else if(nChar=='6')
	{
		if(!m_showAnswerFlag)
		{
			OnShowAnswer();
		}
		else
		{
			OnNo();
		}
	}
	
	CDialog::OnChar(nChar, nRepCnt, nFlags);
}
*/
  /*

void ShowAnswer::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnChar(nChar, nRepCnt, nFlags);
}
*/
