@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by FLASH.HPJ. >"hlp\Flash.hm"
echo. >>"hlp\Flash.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\Flash.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\Flash.hm"
echo. >>"hlp\Flash.hm"
echo // Prompts (IDP_*) >>"hlp\Flash.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\Flash.hm"
echo. >>"hlp\Flash.hm"
echo // Resources (IDR_*) >>"hlp\Flash.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\Flash.hm"
echo. >>"hlp\Flash.hm"
echo // Dialogs (IDD_*) >>"hlp\Flash.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\Flash.hm"
echo. >>"hlp\Flash.hm"
echo // Frame Controls (IDW_*) >>"hlp\Flash.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\Flash.hm"
REM -- Make help for Project FLASH


echo Building Win32 Help files
start /wait hcrtf -x "hlp\Flash.hpj"
echo.
if exist Debug\nul copy "hlp\Flash.hlp" Debug
if exist Debug\nul copy "hlp\Flash.cnt" Debug
if exist Release\nul copy "hlp\Flash.hlp" Release
if exist Release\nul copy "hlp\Flash.cnt" Release
echo.


