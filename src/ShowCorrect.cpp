// ShowCorrect.cpp : implementation file
//

#include "stdafx.h"
#include "Flash.h"
#include "FlashDoc.h"
#include "ShowCorrect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ShowCorrect dialog


ShowCorrect::ShowCorrect(CWnd* pParent /*= NULL*/, CView* qview)
	: CDialog(ShowCorrect::IDD, pParent)
{
	pDoc = (CFlashDoc*) qview->GetDocument();
	
	//{{AFX_DATA_INIT(ShowCorrect)
	m_editBoxQ = pDoc->GetCurrentQuestion();
	m_editBoxA = pDoc->GetCurrentAnswer();
	//}}AFX_DATA_INIT
}


void ShowCorrect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ShowCorrect)
	DDX_Text(pDX, IDC_MultipleChoiceEditQ, m_editBoxQ);
	DDV_MaxChars(pDX, m_editBoxQ, 10000);
	DDX_Text(pDX, IDC_MultipleChoiceEditA, m_editBoxA);
	DDV_MaxChars(pDX, m_editBoxA, 10000);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ShowCorrect, CDialog)
	//{{AFX_MSG_MAP(ShowCorrect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ShowCorrect message handlers
