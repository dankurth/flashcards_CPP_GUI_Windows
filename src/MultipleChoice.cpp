// MultipleChoice.cpp : implementation file
//

#include "stdafx.h"
#include "Flash.h"
#include "FlashDoc.h"
#include "MultipleChoice.h"
#include "ShowCorrect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MultipleChoice dialog


MultipleChoice::MultipleChoice(CWnd* pParent /*=NULL*/)
	: CDialog(MultipleChoice::IDD, pParent)
{
	theparent = (CView*) pParent; //so can use/pass parent for child dialog
	pDoc = (CFlashDoc*) theparent->GetDocument();
	
	//{{AFX_DATA_INIT(MultipleChoice)
	m_listBox = _T("");
	m_editBoxA = _T("");
	m_editBoxQ = _T("");
	//}}AFX_DATA_INIT
}


void MultipleChoice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(MultipleChoice)
	DDX_LBString(pDX, IDC_MultipleChoiceList, m_listBox);
	DDX_Text(pDX, IDC_MultipleChoiceEditA, m_editBoxA);
	DDV_MaxChars(pDX, m_editBoxA, 10000);
	DDX_Text(pDX, IDC_MultipleChoiceEditQ, m_editBoxQ);
	DDV_MaxChars(pDX, m_editBoxQ, 10000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MultipleChoice, CDialog)
	//{{AFX_MSG_MAP(MultipleChoice)
	ON_LBN_DBLCLK(IDC_MultipleChoiceList, OnDblclkMultipleChoiceList)
	ON_LBN_SELCHANGE(IDC_MultipleChoiceList, OnSelchangeMultipleChoiceList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL MultipleChoice::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_editBoxQ=pDoc->GetCurrentQuestion();
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetRandCard()->m_answer);
	ListBox().AddString(pDoc->GetCurrentAnswer());
	UpdateData(VAR2CTRL);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// MultipleChoice message handlers


void MultipleChoice::OnDblclkMultipleChoiceList() 
{
	CString cs;
	ListBox().GetText(ListBox().GetCurSel(),cs);

	if(cs==pDoc->GetCurrentAnswer()) //m_editBoxA="match";
	{
		pDoc->GotItRight();   // set m_bmarked in current card itself
	}

	else //m_editBox="you blew it";
	{
		ShowCorrect pShowCorrect(NULL, theparent );
		pShowCorrect.DoModal();
		pDoc->GotItWrong();
	}
	
	ListBox().ResetContent();
	OnInitDialog();
	m_editBoxA="";
	//ListBox().GetText(ListBox().GetCurSel(),cs);
	//m_editBox=cs;
	
	UpdateData(VAR2CTRL);
	SetFocus();
}


void MultipleChoice::OnSelchangeMultipleChoiceList() 
{
	CString cs;
	ListBox().GetText(ListBox().GetCurSel(),cs);
	m_editBoxA=cs;
	UpdateData(VAR2CTRL);
}

void MultipleChoice::OnOK() 
{
	if(m_editBoxA=="") return;
	OnDblclkMultipleChoiceList();
	
//	CDialog::OnOK();
}
