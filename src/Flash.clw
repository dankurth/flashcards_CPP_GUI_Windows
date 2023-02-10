; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFlashView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "flash.h"
LastPage=0

ClassCount=6
Class1=CFlashApp
Class2=CAboutDlg
Class3=CFlashDoc
Class4=CFlashView
Class5=KDialog2
Class6=CMainFrame

ResourceCount=9
Resource1=IDD_TypeInAnswer
Resource2=IDD_ABOUTBOX
Resource3=IDR_MAINFRAME1
Resource4=IDD_DIALOG2
Resource5=IDD_MCShowCorrect
Resource6=IDD_MultipleChoice
Resource7=IDD_ShowAnswer
Resource8=IDR_MAINFRAME
Resource9=IDD_DIALOG1

[CLS:CFlashApp]
Type=0
BaseClass=CWinApp
HeaderFile=Flash.h
ImplementationFile=Flash.cpp
Filter=N
VirtualFilter=AC
LastObject=ID_FILE_NEW

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=Flash.cpp
ImplementationFile=Flash.cpp
LastObject=CAboutDlg

[CLS:CFlashDoc]
Type=0
BaseClass=CDocument
HeaderFile=FlashDoc.h
ImplementationFile=FlashDoc.cpp
Filter=N
VirtualFilter=DC
LastObject=CFlashDoc

[CLS:CFlashView]
Type=0
BaseClass=CScrollView
HeaderFile=FlashView.h
ImplementationFile=FlashView.cpp
Filter=C
LastObject=ID_HELP_FINDER
VirtualFilter=VWC

[CLS:KDialog2]
Type=0
BaseClass=CDialog
HeaderFile=Kdialog2.h
ImplementationFile=Kdialog2.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOG2]
Type=1
Class=KDialog2
ControlCount=11
Control1=IDC_EDITQuestion,edit,1352732740
Control2=IDC_EDITAnswer,edit,1352732740
Control3=IDC_EDITNEW,button,1342242817
Control4=IDC_EditDel,button,1342242816
Control5=IDC_EditPrior,button,1342242816
Control6=IDC_EditNext,button,1342242816
Control7=IDC_EditApply,button,1342242816
Control8=IDOK,button,1342242816
Control9=IDCANCEL,button,1342242816
Control10=IDC_Question,static,1342308352
Control11=IDC_Answer,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CFlashView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=IDM_EDITFILE
Command6=IDM_CLEARSTATS
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_VIEW_TOOLBAR
Command13=ID_VIEW_STATUS_BAR
Command14=IDM_MULTIPLECHOICE
Command15=IDM_SHOWANSWER
Command16=IDM_TYPEINANSWER
Command17=IDM_INTRO
Command18=ID_HELP
Command19=ID_APP_ABOUT
CommandCount=19

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
Command15=ID_CONTEXT_HELP
Command16=ID_HELP
CommandCount=16

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_CONTEXT_HELP
CommandCount=9

[DLG:IDD_DIALOG1]
Type=1
Class=?
ControlCount=10
Control1=IDC_STATIC1,static,1342308352
Control2=IDC_EDIT1,edit,1350568064
Control3=IDC_STATIC2,static,1342308352
Control4=IDC_EDIT2,edit,1350568064
Control5=IDC_STATIC3,static,1342308352
Control6=IDC_EDIT3,edit,1350568064
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDITATTEMPTS,edit,1350568064

[DLG:IDD_MCShowCorrect]
Type=1
Class=?
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_MultipleChoiceEditA,edit,1352730692
Control3=IDC_STATIC,static,1342308352
Control4=IDC_MultipleChoiceEditQ,edit,1352730692
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_MultipleChoice]
Type=1
Class=?
ControlCount=6
Control1=IDC_MultipleChoiceList,listbox,1352728835
Control2=IDC_MultipleChoiceEditA,edit,1352730692
Control3=IDC_MultipleChoiceEditQ,edit,1352730692
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDOK,button,1073741825

[DLG:IDD_ShowAnswer]
Type=1
Class=?
ControlCount=5
Control1=IDC_ShowAnswer,button,1342242817
Control2=IDC_Yes,button,1342242816
Control3=IDC_No,button,1342242816
Control4=IDC_EDIT1,edit,1352665156
Control5=IDC_STATIC,static,1342308352

[DLG:IDD_TypeInAnswer]
Type=1
Class=?
ControlCount=2
Control1=IDC_EDIT1,edit,1350631552
Control2=IDOK,button,1073741825

[MNU:IDR_MAINFRAME1]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=IDM_EDITFILE
Command6=IDM_CLEARSTATS
Command7=ID_FILE_PRINT
Command8=ID_FILE_PRINT_PREVIEW
Command9=ID_FILE_PRINT_SETUP
Command10=ID_FILE_MRU_FILE1
Command11=ID_APP_EXIT
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_EDIT_COPY
Command15=ID_EDIT_PASTE
Command16=ID_VIEW_TOOLBAR
Command17=ID_VIEW_STATUS_BAR
Command18=IDM_MULTIPLECHOICE
Command19=IDM_SHOWANSWER
Command20=IDM_TYPEINANSWER
Command21=IDM_INTRO
Command22=ID_HELP_FINDER
Command23=ID_APP_ABOUT
CommandCount=23

