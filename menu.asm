 include "settings.inc"
 include "equates.inc" 

 SEGMENT Main
 GLOBALS ON

 EXTERN PutSApp,VPutSApp,PutSAppCenter,VPutSAppCenter,DisplayImage
 EXTERN mainMenu

StartApp:
       ld a,(iy+appLwrCaseFlag)
       ld (lwrCaseFlag),a

AboutScreen:
       ;Display the About screen
       B_CALL ForceFullScreen
	B_CALL ClrLCDFull
     	ld hl,bSplashImage
	ld de,tempSwapArea
	ld bc,bSplashImageEnd-bSplashImage
       ldir
 IFDEF TI84PCSE
       ld de,1CFFh
       ld (0FE67h),de
	ld ix,tempSwapArea
       ld l,150
       ld de,100
	call DisplayImage
 ELSE
	ld hl,tempSwapArea
	ld de,42*256+33
	B_CALL DisplayImage
 ENDIF
       ld hl,1
       ld (curRow),hl
       ld hl,sAppName
       call PutSAppCenter
       ld hl,curRow
       inc (hl)
       ld hl,sAuthor
       call PutSAppCenter
 IFDEF TI84PCSE
       ld a,100
 ELSE
	ld a,27
 ENDIF
	ld (penRow),a
	ld hl,sVersion
	call VPutSAppCenter
 IFDEF TI84PCSE
       ld a,115
 ELSE
       ld a,34
 ENDIF
       ld (penRow),a
       ld hl,sBuild
       call VPutSAppCenter
 IFDEF TI84PCSE
       ld a,220
 ELSE
       ld a,57
 ENDIF
       ld (penRow),a
       ld hl,sWeb
       call VPutSAppCenter
       xor a
       ld (kbdKey),a
       ld (kbdScanCode),a
       B_CALL getkey

ShowMainMenu:
       ld hl,mainMenu

ShowMenu:
       ld (menuAddr),hl

DrawMenu:
       B_CALL CanAlphIns
       B_CALL ClrLCDFull
       B_CALL HomeUp
       ld hl,(menuAddr)
       call PutSApp
       ld de,0001h
       ld b,(hl)
       ld a,b
       ld (numChoices),a
       inc hl
$$:    push bc
       ld (curRow),de
       push de
       call PutSApp
       pop de
       inc e
       inc hl
       inc hl
       pop bc
       djnz $B
keyLoop:
       B_CALL getkey
       cp kQuit
       jr z,ExitApp
       cp kClear
	jr z,ExitApp
       cp k1
       jr c,keyLoop
       sub k1
       ld b,a
       ld a,(numChoices)
       dec a
       cp b
       jp m,keyLoop
       inc b
       push bc
       ld hl,(menuAddr)
       xor a
       ld bc,18
       cpir
       inc hl
       pop de
       dec hl
       dec hl
$$:    inc hl
       inc hl
       xor a
       ld bc,18
       cpir
       dec d
       jr nz,$B
       ld e,(hl)
       inc hl
       ld d,(hl)
       ex de,hl
       jp (hl)

ExitApp:
       ld a,(lwrCaseFlag)
       ld (iy+appLwrCaseFlag),a
	B_CALL ClrLCDFull
       res indicOnly,(iy+indicFlags)
       B_JUMP JForceCmdNoChar

sAppName:
       DB AppDescription,0
sAuthor:
       DB Author,0
sVersion:
	DB "Version ",VER_STRING,0
sBuild:
       DB "Build ",BUILD_STRING,0
sWeb:  DB WEB_STRING,0
bSplashImage:
       DB 13, 30
       DB 00000000b,00000000b,01100000b,00000000b
       DB 00000000b,00000111b,11110000b,00000000b
       DB 00000000b,00001111b,11110000b,00000000b
       DB 00000000b,00011100b,01100000b,00000000b
       DB 00011000b,00111000b,00000000b,00000000b
       DB 00111100b,01110000b,00000000b,01100000b
       DB 01111111b,11111111b,11111111b,11110000b
       DB 01111111b,11111111b,11111111b,11110000b
       DB 00111100b,00000111b,00000000b,01100000b
       DB 00011000b,00000011b,10001110b,00000000b
       DB 00000000b,00000001b,11111111b,00000000b
       DB 00000000b,00000000b,11111111b,00000000b
       DB 00000000b,00000000b,00001110b,00000000b
bSplashImageEnd:

