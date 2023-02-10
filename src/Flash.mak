# Microsoft Developer Studio Generated NMAKE File, Format Version 4.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Flash - Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Flash - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Flash - Win32 Release" && "$(CFG)" != "Flash - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "Flash.mak" CFG="Flash - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Flash - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Flash - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 
################################################################################
# Begin Project
# PROP Target_Last_Scanned "Flash - Win32 Debug"
MTL=mktyplib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Flash - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
OUTDIR=.\Release
INTDIR=.\Release

ALL : "$(OUTDIR)\Flash.exe" "$(OUTDIR)\Flash.hlp"

CLEAN : 
	-@erase ".\Release\Flash.exe"
	-@erase ".\Release\Kdialog2.obj"
	-@erase ".\Release\Flash.pch"
	-@erase ".\Release\MainFrm.obj"
	-@erase ".\Release\TypeInAnswer.obj"
	-@erase ".\Release\kdialog1.obj"
	-@erase ".\Release\Flash.obj"
	-@erase ".\Release\MultipleChoice.obj"
	-@erase ".\Release\ShowAnswer.obj"
	-@erase ".\Release\FlashDoc.obj"
	-@erase ".\Release\ShowCorrect.obj"
	-@erase ".\Release\FlashView.obj"
	-@erase ".\Release\StdAfx.obj"
	-@erase ".\Release\Flash.res"
	-@erase ".\Release\Flash.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/Flash.pch" /Yu"stdafx.h" /Fo"$(INTDIR)/" /c 
CPP_OBJS=.\Release/
CPP_SBRS=
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Flash.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Flash.bsc" 
BSC32_SBRS=
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:no\
 /pdb:"$(OUTDIR)/Flash.pdb" /machine:I386 /out:"$(OUTDIR)/Flash.exe" 
LINK32_OBJS= \
	"$(INTDIR)/Kdialog2.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/TypeInAnswer.obj" \
	"$(INTDIR)/kdialog1.obj" \
	"$(INTDIR)/Flash.obj" \
	"$(INTDIR)/MultipleChoice.obj" \
	"$(INTDIR)/ShowAnswer.obj" \
	"$(INTDIR)/FlashDoc.obj" \
	"$(INTDIR)/ShowCorrect.obj" \
	"$(INTDIR)/FlashView.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/Flash.res"

"$(OUTDIR)\Flash.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
OUTDIR=.\Debug
INTDIR=.\Debug

ALL : "$(OUTDIR)\Flash.exe" "$(OUTDIR)\Flash.bsc" "$(OUTDIR)\Flash.hlp"

CLEAN : 
	-@erase ".\Debug\vc40.pdb"
	-@erase ".\Debug\Flash.pch"
	-@erase ".\Debug\vc40.idb"
	-@erase ".\Debug\Flash.bsc"
	-@erase ".\Debug\kdialog1.sbr"
	-@erase ".\Debug\FlashView.sbr"
	-@erase ".\Debug\MainFrm.sbr"
	-@erase ".\Debug\FlashDoc.sbr"
	-@erase ".\Debug\Flash.sbr"
	-@erase ".\Debug\MultipleChoice.sbr"
	-@erase ".\Debug\StdAfx.sbr"
	-@erase ".\Debug\ShowAnswer.sbr"
	-@erase ".\Debug\TypeInAnswer.sbr"
	-@erase ".\Debug\ShowCorrect.sbr"
	-@erase ".\Debug\Kdialog2.sbr"
	-@erase ".\Debug\Flash.exe"
	-@erase ".\Debug\ShowCorrect.obj"
	-@erase ".\Debug\Kdialog2.obj"
	-@erase ".\Debug\kdialog1.obj"
	-@erase ".\Debug\FlashView.obj"
	-@erase ".\Debug\MainFrm.obj"
	-@erase ".\Debug\FlashDoc.obj"
	-@erase ".\Debug\Flash.obj"
	-@erase ".\Debug\MultipleChoice.obj"
	-@erase ".\Debug\StdAfx.obj"
	-@erase ".\Debug\ShowAnswer.obj"
	-@erase ".\Debug\TypeInAnswer.obj"
	-@erase ".\Debug\Flash.res"
	-@erase ".\Debug\Flash.ilk"
	-@erase ".\Debug\Flash.pdb"
	-@erase ".\Debug\Flash.hlp"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Flash.pch" /Yu"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c 
CPP_OBJS=.\Debug/
CPP_SBRS=.\Debug/
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo"$(INTDIR)/Flash.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o"$(OUTDIR)/Flash.bsc" 
BSC32_SBRS= \
	"$(INTDIR)/kdialog1.sbr" \
	"$(INTDIR)/FlashView.sbr" \
	"$(INTDIR)/MainFrm.sbr" \
	"$(INTDIR)/FlashDoc.sbr" \
	"$(INTDIR)/Flash.sbr" \
	"$(INTDIR)/MultipleChoice.sbr" \
	"$(INTDIR)/StdAfx.sbr" \
	"$(INTDIR)/ShowAnswer.sbr" \
	"$(INTDIR)/TypeInAnswer.sbr" \
	"$(INTDIR)/ShowCorrect.sbr" \
	"$(INTDIR)/Kdialog2.sbr"

"$(OUTDIR)\Flash.bsc" : "$(OUTDIR)" $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386
LINK32_FLAGS=/nologo /subsystem:windows /incremental:yes\
 /pdb:"$(OUTDIR)/Flash.pdb" /debug /machine:I386 /out:"$(OUTDIR)/Flash.exe" 
LINK32_OBJS= \
	"$(INTDIR)/ShowCorrect.obj" \
	"$(INTDIR)/Kdialog2.obj" \
	"$(INTDIR)/kdialog1.obj" \
	"$(INTDIR)/FlashView.obj" \
	"$(INTDIR)/MainFrm.obj" \
	"$(INTDIR)/FlashDoc.obj" \
	"$(INTDIR)/Flash.obj" \
	"$(INTDIR)/MultipleChoice.obj" \
	"$(INTDIR)/StdAfx.obj" \
	"$(INTDIR)/ShowAnswer.obj" \
	"$(INTDIR)/TypeInAnswer.obj" \
	"$(INTDIR)/Flash.res"

"$(OUTDIR)\Flash.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.c{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_SBRS)}.sbr:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Target

# Name "Flash - Win32 Release"
# Name "Flash - Win32 Debug"

!IF  "$(CFG)" == "Flash - Win32 Release"

!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

!ENDIF 

################################################################################
# Begin Source File

SOURCE=.\ReadMe.txt

!IF  "$(CFG)" == "Flash - Win32 Release"

!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Flash.cpp
DEP_CPP_FLASH=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\MainFrm.h"\
	".\FlashDoc.h"\
	".\FlashView.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\Flash.obj" : $(SOURCE) $(DEP_CPP_FLASH) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\Flash.obj" : $(SOURCE) $(DEP_CPP_FLASH) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\Flash.sbr" : $(SOURCE) $(DEP_CPP_FLASH) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\StdAfx.cpp
DEP_CPP_STDAF=\
	".\StdAfx.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MD /W3 /GX /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL"\
 /D "_MBCS" /Fp"$(INTDIR)/Flash.pch" /Yc"stdafx.h" /Fo"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Flash.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

# ADD CPP /Yc"stdafx.h"

BuildCmds= \
	$(CPP) /nologo /MDd /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS"\
 /D "_AFXDLL" /D "_MBCS" /FR"$(INTDIR)/" /Fp"$(INTDIR)/Flash.pch" /Yc"stdafx.h"\
 /Fo"$(INTDIR)/" /Fd"$(INTDIR)/" /c $(SOURCE) \
	

"$(INTDIR)\StdAfx.obj" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\StdAfx.sbr" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

"$(INTDIR)\Flash.pch" : $(SOURCE) $(DEP_CPP_STDAF) "$(INTDIR)"
   $(BuildCmds)

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MainFrm.cpp
DEP_CPP_MAINF=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\MainFrm.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\MainFrm.obj" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\MainFrm.sbr" : $(SOURCE) $(DEP_CPP_MAINF) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\FlashDoc.cpp

!IF  "$(CFG)" == "Flash - Win32 Release"

DEP_CPP_FLASHD=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	
NODEP_CPP_FLASHD=\
	".\}"\
	

"$(INTDIR)\FlashDoc.obj" : $(SOURCE) $(DEP_CPP_FLASHD) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

DEP_CPP_FLASHD=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	

"$(INTDIR)\FlashDoc.obj" : $(SOURCE) $(DEP_CPP_FLASHD) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\FlashDoc.sbr" : $(SOURCE) $(DEP_CPP_FLASHD) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\FlashView.cpp

!IF  "$(CFG)" == "Flash - Win32 Release"

DEP_CPP_FLASHV=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\FlashView.h"\
	".\kdialog1.h"\
	".\Kdialog2.h"\
	".\MultipleChoice.h"\
	".\ShowAnswer.h"\
	".\ShowCorrect.h"\
	".\TypeInAnswer.h"\
	
NODEP_CPP_FLASHV=\
	".\}"\
	

"$(INTDIR)\FlashView.obj" : $(SOURCE) $(DEP_CPP_FLASHV) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

DEP_CPP_FLASHV=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\FlashView.h"\
	".\kdialog1.h"\
	".\Kdialog2.h"\
	".\MultipleChoice.h"\
	".\ShowAnswer.h"\
	".\ShowCorrect.h"\
	".\TypeInAnswer.h"\
	

"$(INTDIR)\FlashView.obj" : $(SOURCE) $(DEP_CPP_FLASHV) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\FlashView.sbr" : $(SOURCE) $(DEP_CPP_FLASHV) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Flash.rc
DEP_RSC_FLASH_=\
	".\res\Flash.ico"\
	".\res\Toolbar.bmp"\
	".\res\Flash.rc2"\
	

"$(INTDIR)\Flash.res" : $(SOURCE) $(DEP_RSC_FLASH_) "$(INTDIR)"
   $(RSC) $(RSC_PROJ) $(SOURCE)


# End Source File
################################################################################
# Begin Source File

SOURCE=.\hlp\Flash.hpj

!IF  "$(CFG)" == "Flash - Win32 Release"

# Begin Custom Build - Making help file...
OutDir=.\Release
ProjDir=.
TargetName=Flash
InputPath=.\hlp\Flash.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   "$(ProjDir)\makehelp.bat"

# End Custom Build

!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

# Begin Custom Build - Making help file...
OutDir=.\Debug
ProjDir=.
TargetName=Flash
InputPath=.\hlp\Flash.hpj

"$(OutDir)\$(TargetName).hlp" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
   "$(ProjDir)\makehelp.bat"

# End Custom Build

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\Kdialog2.cpp

!IF  "$(CFG)" == "Flash - Win32 Release"

DEP_CPP_KDIAL=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\Kdialog2.h"\
	
NODEP_CPP_KDIAL=\
	".\KDialog2"\
	

"$(INTDIR)\Kdialog2.obj" : $(SOURCE) $(DEP_CPP_KDIAL) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"

DEP_CPP_KDIAL=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\Kdialog2.h"\
	

"$(INTDIR)\Kdialog2.obj" : $(SOURCE) $(DEP_CPP_KDIAL) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\Kdialog2.sbr" : $(SOURCE) $(DEP_CPP_KDIAL) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\TypeInAnswer.cpp
DEP_CPP_TYPEI=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\ShowCorrect.h"\
	".\TypeInAnswer.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\TypeInAnswer.obj" : $(SOURCE) $(DEP_CPP_TYPEI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\TypeInAnswer.obj" : $(SOURCE) $(DEP_CPP_TYPEI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\TypeInAnswer.sbr" : $(SOURCE) $(DEP_CPP_TYPEI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\MultipleChoice.cpp
DEP_CPP_MULTI=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\MultipleChoice.h"\
	".\ShowCorrect.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\MultipleChoice.obj" : $(SOURCE) $(DEP_CPP_MULTI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\MultipleChoice.obj" : $(SOURCE) $(DEP_CPP_MULTI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\MultipleChoice.sbr" : $(SOURCE) $(DEP_CPP_MULTI) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ShowAnswer.cpp
DEP_CPP_SHOWA=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\ShowAnswer.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\ShowAnswer.obj" : $(SOURCE) $(DEP_CPP_SHOWA) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\ShowAnswer.obj" : $(SOURCE) $(DEP_CPP_SHOWA) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\ShowAnswer.sbr" : $(SOURCE) $(DEP_CPP_SHOWA) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\ShowCorrect.cpp
DEP_CPP_SHOWC=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\ShowCorrect.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\ShowCorrect.obj" : $(SOURCE) $(DEP_CPP_SHOWC) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\ShowCorrect.obj" : $(SOURCE) $(DEP_CPP_SHOWC) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\ShowCorrect.sbr" : $(SOURCE) $(DEP_CPP_SHOWC) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\kdialog1.cpp
DEP_CPP_KDIALO=\
	".\StdAfx.h"\
	".\Flash.h"\
	".\FlashDoc.h"\
	".\kdialog1.h"\
	

!IF  "$(CFG)" == "Flash - Win32 Release"


"$(INTDIR)\kdialog1.obj" : $(SOURCE) $(DEP_CPP_KDIALO) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ELSEIF  "$(CFG)" == "Flash - Win32 Debug"


"$(INTDIR)\kdialog1.obj" : $(SOURCE) $(DEP_CPP_KDIALO) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"

"$(INTDIR)\kdialog1.sbr" : $(SOURCE) $(DEP_CPP_KDIALO) "$(INTDIR)"\
 "$(INTDIR)\Flash.pch"


!ENDIF 

# End Source File
# End Target
# End Project
################################################################################
