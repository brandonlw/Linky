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
       DB 1
       DB "1) Back",0
       DW ShowMainMenu

