// FlashDoc.cpp : implementation of the CFlashDoc class
//

#include "stdafx.h"
#include "Flash.h"

#include "FlashDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFlashDoc

IMPLEMENT_DYNCREATE(CFlashDoc, CDocument)

BEGIN_MESSAGE_MAP(CFlashDoc, CDocument)
	//{{AFX_MSG_MAP(CFlashDoc)
	ON_COMMAND(IDM_CLEARSTATS, OnClearStats)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFlashDoc construction/destruction

CFlashDoc::CFlashDoc()
{
	m_ncurrentCardNum=0;
	m_ncardCount=0;
}

CFlashDoc::~CFlashDoc()
{
}

BOOL CFlashDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CFlashDoc serialization

void CFlashDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	} 
	m_cardList.Serialize(ar);
	SetModifiedFlag(FALSE);
}

/////////////////////////////////////////////////////////////////////////////
// CFlashDoc diagnostics

#ifdef _DEBUG
void CFlashDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFlashDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFlashDoc commands

BOOL CFlashDoc::OnOpenDocument(const char* pszPathName)
{    
//change,	if(docptr) return FALSE; 
	// until (unless) I can make multiple docptrs I don't want 
	//to open more than one document
	
	// this section borrowed from chkbook
	// Upon opening the document, tell the application object
	// to save the path name in the private INI file.

	if (!CDocument::OnOpenDocument(pszPathName))
		return FALSE;
	UpdateIniFileWithDocPath(pszPathName);
                            
	SetCardNumRandUnMarked();
	return TRUE;
}


void CFlashDoc::UpdateIniFileWithDocPath(const char* pszPathName)
{   // from chkbook
	theApp.UpdateIniFileWithDocPath(pszPathName);
}

CCard* CFlashDoc::GetCurrentCard()
{
	POSITION pos = GetFirstCardPos();
	if(pos == NULL) return NULL; 
    
    CCard* pCard;
	for (int j=0; j<=m_ncurrentCardNum && pos!=NULL; j++) 
		pCard = GetNextCard(pos);  //current card (or last) 
   	return pCard;
}

CCard* CFlashDoc::GetRandCard()
{
/*
	The rand function returns a pseudorandom integer in the range 
	0 to RAND_MAX. Use the srand function to seed the 
	pseudorandom-number generator before calling rand.
	
	  Seed the random-number generator with current time so that
	the numbers will be different every time we run.
	
	  RAND_MAX is 32767 */
	
	CCard* pCard;

	static int p=-1;  //so don't ever repeat immediately
	//assumes FOR NOW at least two cards (dangerous, fix it)
	//char s[10]; //for debugging to display numbers
	//srand( (unsigned)time(NULL ) ); 
	//seed ONCE in entire prog, if every time repeats
	int j;
	do
	{
		j=GetCardCount()*rand()/(int)RAND_MAX;
	}
	while (j==p);
	p=j;
		
	//sprintf(s,"%d",j); //for debugging display
	//AfxMessageBox(s);
		
	POSITION pos = GetFirstCardPos();
	//if(pos == NULL) return NULL; 
	pCard = NULL; //gets NULL returned if pos==NULL
	while(pos)
	{
		pCard = GetNextCard(pos); 
		j++;
		if(j>=GetCardCount()) break;
	}

    //if(pCard) AfxMessageBox(pCard->m_question); //debugging stuff


	return pCard;
}
 
void CFlashDoc::SetCardNumRandUnMarked()
// set CurrentCardNum to random unmarked
// Note: very odd, if use the AfxMessageBox at all then errors out
// when this routine finishs!!??

{
	static int p=-1;
	int cardsUnmarked=GetCardCount()-GetCardsMarked();
	
	time_t ltime;
	time(&ltime); //get secs since UCT midnight 1/1/1970
	int randnum;
	
	if(!cardsUnmarked)
	{
		AfxMessageBox("All cards have now been answered correctly!\nWe'll now study only the difficult ones (the ones\nthat required more than one attempt to get them right)");
		{
			OnClearStatsPartial();
			cardsUnmarked=GetCardCount()-GetCardsMarked();
				if(!cardsUnmarked)
				{
					AfxMessageBox("You didn't miss ANY!! Clearing ALL cards for restudy");
					OnClearStats();
					cardsUnmarked=GetCardCount()-GetCardsMarked();
				}
		}
	}
	randnum=(int)ltime; //convert from long to short
	randnum=abs(randnum);	// if conversion made it negative, make positive 
	randnum=randnum % 10;	 //cut down to last digit (0 to 9) 
	randnum=m_ncardCount * randnum / 10; //get int part of % of cardCount 
 
// since int only keeps whole number discards the fraction part
// I could have multiplied by 10 then divided by 100 to get percent,
//but afterall in the end that's the same as just dividing by 10  
//next on list, if randnum==currentcard and cards-not-marked > 1 then when
//user hits yes or no make sure it quizzes on a different card, not the same	


  //this should be a simple algorithm, to go down a list
  //looking for the nth element selected at random, all the while keeping
  //track of the number of the last passed unmarked card. At the nth element
  //if an unmarked card has been found then quit and return it, else continue
  //until find the very next unmarked card
	
	POSITION pos = GetFirstCardPos();
	if(pos == NULL) return; 
	CCard* pCard;
	int j=0, k=-1; //j is nth position, k is last passed unmarked card
	while(pos)
	{
		pCard = GetNextCard(pos); 
		if(!pCard->m_bmarked)
		{
			if(cardsUnmarked==1) k=j;
			else if (j!=p) k=j;
		}

		if((j>=randnum)&&(k>-1)) break;
		j++;
	}
	p=k; //remember what last random card was so don't reuse immediately
	m_ncurrentCardNum=k;
}

CString CFlashDoc::GetCurrentQuestion()
{
	CString s="no question";
    CCard* pCard=GetCurrentCard();
    if(pCard) s=pCard->m_question;
    return s;
}

CString CFlashDoc::GetCurrentAnswer()
{
	CString s="no answer";
    CCard* pCard=GetCurrentCard();
    if(pCard) s=pCard->m_answer;
    return s;
}

void CFlashDoc::SetCurrentCardMarked()
{
    CCard* pCard=GetCurrentCard();
    if(pCard) pCard->m_bmarked=TRUE;
	SetModifiedFlag(TRUE);
}

void CFlashDoc::SetCurrentCardAttempts()
{
	CCard* pCard=GetCurrentCard();
	if(pCard) pCard->m_nattempts++;
	SetModifiedFlag(TRUE);
}

int CFlashDoc::GetCurrentCardAttempts()
{
	int num=0;
	CCard* pCard=GetCurrentCard();
	if(pCard) num=pCard->m_nattempts;
	return num;
}

void CFlashDoc::SetCurrentCardUnMarked()
{
    CCard* pCard=GetCurrentCard();
    if(pCard) pCard->m_bmarked=FALSE;
	SetModifiedFlag(TRUE);
}                                        

int CFlashDoc::GetCardsMarked()
{
	int cardsmarked=0;
	POSITION pos = GetFirstCardPos();
    
    CCard* pCard;
	while(pos)
		{ 
		pCard = GetNextCard(pos);
		if(pCard->m_bmarked) cardsmarked++;
		} 
   	return cardsmarked;
}

void CFlashDoc::SetCardsMarkedNone()
{
	POSITION pos = GetFirstCardPos();
    
    CCard* pCard;
	while(pos!=NULL)
	{ 
		pCard = GetNextCard(pos);
		if(pCard)
		{
			pCard->m_bmarked=FALSE;
			pCard->m_nattempts=0;
		}
	}
	SetModifiedFlag(TRUE);
}


void CFlashDoc::SetCurrentQuestion(CString s)
{
    CCard* pCard=GetCurrentCard();
    if(pCard) pCard->m_question=s;
	SetModifiedFlag(TRUE);
}

void CFlashDoc::SetCurrentAnswer(CString s)
{
    CCard* pCard=GetCurrentCard();
    if(pCard) pCard->m_answer=s;
}

CCard* CFlashDoc::NewCard()
{
	CCard* pCardItem = new CCard();
	m_cardList.AddTail(pCardItem);
	return pCardItem;
}	
  
void CFlashDoc::DelCard(POSITION& pos)
{   
	CCard* pCard = (CCard*)m_cardList.GetAt(pos);
	m_cardList.RemoveAt(pos);
	delete pCard; //RemoveAt example said do this to avoid memory leaks
}	


POSITION CFlashDoc::GetFirstCardPos()
{
	return m_cardList.GetHeadPosition();
}

CCard* CFlashDoc::GetNextCard(POSITION& pos)
{       
	return (CCard*)m_cardList.GetNext(pos);
}                 

                 
int CFlashDoc::GetCardCount()
{
	m_ncardCount=m_cardList.GetCount();
	return m_ncardCount;
}                                                                     
                 

//////////////////////////////////////////////////////////////////////
// CCard commands
IMPLEMENT_SERIAL(CCard, CObject, 1)


CCard::CCard()
{
m_question="";
m_answer=""; 
m_nattempts=0;
m_bmarked=FALSE;
}

void CCard::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_question;
		ar << m_answer;
		ar << m_nattempts;
		ar << m_bmarked;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_question;
		ar >> m_answer;
		ar >> m_nattempts;
		ar >> m_bmarked;
	}
}

BOOL CCard::DrawCard(CDC* pDC, CRect rect)
{
    CString s = m_question + "\n" + m_answer;
	pDC->DrawText(s, s.GetLength(), rect, DT_WORDBREAK);
		
	return TRUE;
}

BOOL CCard::DrawCardQ(CDC* pDC, CRect rect)
{
    CString s = m_question;
	pDC->DrawText(s, s.GetLength(), rect, DT_WORDBREAK | DT_NOCLIP);
		
	return TRUE;
}

BOOL CCard::DrawCardA(CDC* pDC, CRect rect)
{    
    CString s = m_answer;
	pDC->DrawText(s, s.GetLength(), rect, DT_WORDBREAK | DT_NOCLIP);
		
	return TRUE;
}

// DeleteContents is override
// It is called by base OnCloseDocument
// typhically by OnFileClose
void CFlashDoc::DeleteContents()
{
	POSITION pos;
	while( ( pos = m_cardList.GetTailPosition() ) != NULL )
		DelCard(pos);
}

void CFlashDoc::GotItRight()
{
	SetCurrentCardMarked(); 
	SetCardNumRandUnMarked(); // set CurrentCardNum to random unmarked
	UpdateAllViews(NULL);
}

void CFlashDoc::GotItWrong()
{
	SetCurrentCardAttempts(); // set m_nattempts in current card to ++
	SetCardNumRandUnMarked(); // set CurrentCardNum to random unmarked
	UpdateAllViews(NULL);
}

void CFlashDoc::OnClearStats() 
{
	SetCurrentCardNum(0);
    SetCardsMarkedNone(); //and set Attempts 0 too
	UpdateAllViews(NULL);
}

void CFlashDoc::OnClearStatsPartial() 
{
	POSITION pos = GetFirstCardPos();
    
    CCard* pCard;
	while(pos!=NULL)
	{ 
		pCard = GetNextCard(pos);
		if(pCard->m_nattempts) // if attempts greater than 0
		{
			pCard->m_bmarked=FALSE;
			pCard->m_nattempts=0;
		}
	}
	SetModifiedFlag(TRUE);	
	UpdateAllViews(NULL);

}
/*
//make it part of this for now so can use class stuff
but remember to get rid of it cuz it SCREWS UP testing royally
#define Q_SIZE 480
#define A_SIZE 480
	CString qs; CString as;
	FILE *fptr; int j=0; char ch; int hexbuffer;
	char qbuffer[500]; char abuffer[500];
	char* pqbuffer=qbuffer; char* pabuffer=abuffer; int rfile=1;
	
	if( (fptr=fopen("temp.rec","r"))==NULL ) return;//return(1);
	
	while( (fscanf(fptr,"%x ",&hexbuffer)) != EOF)
	{
		NewCard();
		SetCurrentCardNum(GetCardCount());
		j=0;
	while(((ch=getc(fptr))!='=') && j<Q_SIZE) // cut off if too long 
	{ 
		qbuffer[j]=ch; 
		j++;
	}
	qbuffer[j]='\0'; // printw("qbuffer %s\n",qbuffer); 

	qs=pqbuffer; 
	SetCurrentQuestion(qs);
	
	if(ch!='=')while((ch=getc(fptr))!='=');  // if cut off move past excess to the start of next read 
	while(TRUE) // skip spaces and newlines preceding start of answer
	{ ch=getc(fptr); if((ch!='\n') && (ch!=' ')) break; } // if newline or space loop again 
    ungetc(ch,fptr);
    j=0;
    while(((ch=getc(fptr))!='}') && j<A_SIZE)
	{
		if (ch==EOF) { fclose(fptr); return; }//return(2);}
		abuffer[j]=ch; j++;
	}
	abuffer[j-1]='\0'; // printw("abuffer %s\n",abuffer); refresh();
	// for this program cut off whatever that little box thing is

	as=pabuffer; 
	SetCurrentAnswer(as);

	if(ch!='}')while((ch=getc(fptr))!='}')
	{
		if (ch==EOF) { fclose(fptr); return; }//return(3); } // File read error at line %d",Ncount+Ycount+1);
	}
    while((ch=getc(fptr)) != '}' );
    }
	fclose(fptr);
	//return(0);
}

*/

