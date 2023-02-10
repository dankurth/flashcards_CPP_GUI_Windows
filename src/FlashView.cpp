// FlashView.cpp : implementation of the CFlashView class
//

#include "stdafx.h"
#include "Flash.h"

#include "FlashDoc.h"
#include "FlashView.h"
#include "kdialog1.h"   //modeless stats dialog
#include "kdialog2.h"   //modal edit dialog
#include "MultipleChoice.h"
#include "ShowAnswer.h"
#include "ShowCorrect.h"
#include "TypeInAnswer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashView

IMPLEMENT_DYNCREATE(CFlashView, CScrollView)

BEGIN_MESSAGE_MAP(CFlashView, CScrollView)
	//{{AFX_MSG_MAP(CFlashView)
	ON_COMMAND(IDM_EDITFILE, OnEditFile)
	ON_COMMAND(IDM_MULTIPLECHOICE, OnMultipleChoice)
	ON_COMMAND(IDM_SHOWANSWER, OnShowAnswer)
	ON_COMMAND(IDM_TYPEINANSWER, OnTypeInAnswer)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashView construction/destruction

CFlashView::CFlashView()
{
	dlgptr1=NULL;
}

CFlashView::~CFlashView()
{
}

BOOL CFlashView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFlashView drawing

void CFlashView::OnDraw(CDC* pDC)
{
	if(dlgptr1) dlgptr1->OnInitDialog(); 
	/* do dlgptr1 here because that way I can put clearstats in the 
	flashdoc.cpp and when I select it from the menu (which I can then do
	without having to be in one view or the other since I've moved it from
	them to the doc file) it will generate the UpdateAllViews (the last 
	line in the clearstats) which will cause the views to redraw, which
	will then update the dialog1 stats!!! So, can put it in menu and make
	it available regardless of which view selected AND don't have to make
	another pointer to dialog1 for the doc to get to it. */
	

	CFlashDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
    CCard* pCard = pDoc->GetCurrentCard();
    if(pCard==NULL) return;
	CRect rect;
	GetClientRect( rect );
	pCard->DrawCardQ(pDC, rect);
}

void CFlashView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();
	CSize sizeTotal;
	// TODO: calculate the total size of this view
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);

	if (dlgptr1) delete dlgptr1;     //delete this pointer & the dialog box it points to
	dlgptr1=NULL;    //set class var NULL so OnDraw knows not to use it
	KDialog1* dlgptr = new KDialog1(GetDocument());//(this); //allocate new pointer, init it
	dlgptr1=dlgptr; //put addr in class var so OnDraw can use it
}

/////////////////////////////////////////////////////////////////////////////
// CFlashView printing

BOOL CFlashView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFlashView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFlashView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFlashView diagnostics

#ifdef _DEBUG
void CFlashView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CFlashView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CFlashDoc* CFlashView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFlashDoc)));
	return (CFlashDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlashView message handlers


void CFlashView::OnEditFile() 
{
	KDialog2 dlgptr2(this);  //Honor System dialog
	dlgptr2.DoModal();
}

void CFlashView::OnMultipleChoice() 
{
	MultipleChoice mcptr(this);
	mcptr.DoModal();  
}

void CFlashView::OnShowAnswer() 
{
//	KDialog1* dlgptr = new KDialog1(GetDocument());//(this); //allocate new pointer, init it
//	dlgptr1=dlgptr; //put addr in class var so OnDraw can use it
	ShowAnswer pShowAnswer(this);
	pShowAnswer.DoModal();
//	delete dlgptr;     //delete this pointer & the dialog box it points to
//	dlgptr1=NULL;    //set class var NULL so OnDraw knows not to use it
}

void CFlashView::OnTypeInAnswer() 
{
	TypeInAnswer pTypeInAnswer(this);
	pTypeInAnswer.DoModal();
}
