// kdialog1.cpp : implementation file
//

#include "stdafx.h"
#include "Flash.h"
#include "FlashDoc.h"
#include "kdialog1.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif
 
/////////////////////////////////////////////////////////////////////////////
// KDialog1 dialog

//KDialog1::KDialog1(	CWnd* pParent )
KDialog1::KDialog1(	CFlashDoc* docptr )
{
 	//CView* theparent = (CView*) pParent;
	//pDoc = (CFlashDoc*) theparent->GetDocument();
	pDoc=docptr;

//	Create(IDD_DIALOG1, pParent );
	Create(IDD_DIALOG1, NULL );
	
	//{{AFX_DATA_INIT(KDialog1)
	m_cardCount = 0;
	m_cardMarked = 0;
	m_cardUnmarked = 0;
	m_cardAttempts = 0;
	//}}AFX_DATA_INIT
}
   
void KDialog1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(KDialog1)
	DDX_Text(pDX, IDC_EDIT1, m_cardCount);
	DDV_MinMaxInt(pDX, m_cardCount, 0, 10000);
	DDX_Text(pDX, IDC_EDIT2, m_cardMarked);
	DDV_MinMaxInt(pDX, m_cardMarked, 0, 10000);
	DDX_Text(pDX, IDC_EDIT3, m_cardUnmarked);
	DDV_MinMaxInt(pDX, m_cardUnmarked, 0, 10000);
	DDX_Text(pDX, IDC_EDITATTEMPTS, m_cardAttempts);
	DDV_MinMaxInt(pDX, m_cardAttempts, 0, 10000);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(KDialog1, CDialog)
	//{{AFX_MSG_MAP(KDialog1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void KDialog1::PostNcDestroy()
{ // see Learn Visual C++ Now, page 292
    delete this;
}

void KDialog1::OnClose()
{  // see Learn Visual C++ Now, page 291
	DestroyWindow();
}

BOOL KDialog1::OnInitDialog()
{
	CDialog::OnInitDialog();
//also run externally by calling view to update display
	SetCount(pDoc->GetCardCount());
	SetMarked(pDoc->GetCardsMarked());
	SetAttempts(pDoc->GetCurrentCardAttempts());
	UpdateData(VAR2CTRL);
	return TRUE;
}

               
void KDialog1::SetCount(int num)
{
	m_cardCount=num;  
}  

void KDialog1::SetMarked(int num) //and unmarked 
{                                                
	m_cardMarked=num;
	m_cardUnmarked=m_cardCount-m_cardMarked;
}

void KDialog1::SetAttempts(int num)
{
	m_cardAttempts=num;
}

