// TypeInAnswer.cpp : implementation file
//

#include "stdafx.h"
#include "flash.h"
#include "flashdoc.h"
#include "ShowCorrect.h"
#include "TypeInAnswer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TypeInAnswer dialog


TypeInAnswer::TypeInAnswer(CWnd* pParent /*=NULL*/)
	: CDialog(TypeInAnswer::IDD, pParent)
{
	theparent = (CView*) pParent; //so can use/pass parent for child dialog
	pDoc = (CFlashDoc*) theparent->GetDocument();

	//{{AFX_DATA_INIT(TypeInAnswer)
	m_editBox = _T("");
	//}}AFX_DATA_INIT
}

void TypeInAnswer::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TypeInAnswer)
	DDX_Text(pDX, IDC_EDIT1, m_editBox);
	DDV_MaxChars(pDX, m_editBox, 40);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TypeInAnswer, CDialog)
	//{{AFX_MSG_MAP(TypeInAnswer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// TypeInAnswer message handlers

//have this button invisible, but having it
//allows me to just hit enter to select w/o
//closing the window cuz comment out at bottom
void TypeInAnswer::OnOK() 
{
	UpdateData(CTRL2VAR);
	if(m_editBox==pDoc->GetCurrentAnswer()) pDoc->GotItRight();
	else //m_editBox="you blew it";
	{
		ShowCorrect pShowCorrect(NULL, theparent );
		pShowCorrect.DoModal();
		pDoc->GotItWrong();
	}
	m_editBox="";
	UpdateData(VAR2CTRL);
	
//	CDialog::OnOK();
}
