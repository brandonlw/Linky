;Linky - USB Library
; (C) 2013 by Brandon Wilson. All rights reserved. 

 include "settings.inc"
 include "equates.inc" ;Equates and macros to be used
 include "header.asm"
 GLOBALS ON

 SEGMENT MAIN

 EXTERN ShowMainMenu,ShowMenu,AboutScreen,ExitApp
 EXTERN DispLog,PutSApp,DispHexA,DispHexHL,UnlockFlash
 EXTERN DriverInit,DriverKill,SetupPeripheralMode,EnableUSB,StartControlResponse,FinishControlRequest
 EXTERN DoDFUUpload,DoDFUDownload

mainMenu:
       DB AppDescription," ",VER_STRING,0
       DB 5
       DB "1) Tools",0
       DW DoTools
       DB "2) Demos",0
       DW DoDemos
       DB "3) View Log",0
       ;TODO: Make this work correctly on all models...and then actually use it
       DW ShowMainMenu ;DispLog
       DB "4) About",0
       DW AboutScreen
       DB "5) Quit",0
       DW ExitApp

DoTools:
       ld hl,toolsMenu
       jr ShowMenu

toolsMenu:
       DB "Tools",0
       DB 3
       DB "1) DFU ROM Dump",0
       DW DoDFUUpload
       DB "2) DFU ROM Write",0
       DW DoDFUDownload
       DB "3) Back",0
       DW ShowMainMenu

DoDemos:
       ld hl,demoMenu
       jr ShowMenu

demoMenu:
       DB "Demos",0
       DB 2
       DB "1) Host Init",0
       DW HostInit
       DB "2) Back",0
       DW ShowMainMenu

HostInit:
       ld b,0
       call DriverInit
       call EnableUSB
       B_CALL getkey
       call DriverKill
       jr DoDemos

SendMissileCommand:
       ld hl,0921h
       ld (controlBuffer),hl
       ld hl,0200h
       ld (controlBuffer+2),hl
       ld hl,0
       ld (controlBuffer+4),hl
       ld de,1
       ld (controlBuffer+6),de
       ld hl,appData
       ld (hl),b
       ld b,1
;       jr SendControlRequest
DoMissileStuff:
       ld a,01h
       out (8Eh),a
       ld a,31h
       out (9Ah),a
       ld a,1
       out (93h),a
       ld a,90h
       out (94h),a
       xor a
       out (95h),a
       ld a,20
       out (9Bh),a
       ld a,0Eh
       out (89h),a
       ld b,40h
       call SendMissileCommand
       ld a,1
       out (8Eh),a
       ld a,20h
       out (94h),a
       ld b,40h
       call SendMissileCommand
       ld a,1
       out (8Eh),a
       ld a,20h
       out (94h),a
       ld b,10h
       call SendMissileCommand
       ld b,40h
       call SendMissileCommand
       ld a,1
       out (8Eh),a
       ld a,20h
       out (94h),a
       ld b,40h
       call SendMissileCommand
       ld a,1
       out (8Eh),a
       ld a,20h
       out (94h),a
       ret

