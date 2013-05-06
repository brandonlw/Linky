;Utility routines

 include "settings.inc"
 include "equates.inc" 
 SEGMENT Main
 GLOBALS ON

EraseFlashPage:
       ld hl,4000h
 IFDEF TI84PCSE
       cp 0FCh
       jr z,$F
       cp 0FEh
       jr z,$F
       cp 0FDh
       jr nz,efp1
$$:
 ELSE
       ld b,a
       in a,(21h)
       and 3
       ld a,3Eh
       jr z,$F
       ld a,7Eh
$$:    cp b
       ld a,b
       jr nz,efp1
 ENDIF
       push af
       call EraseFlash
       pop af
       ld hl,6000h
       jr EraseFlash
efp1:  or a
       jr nz,EraseFlash
       ld h,a
EraseFlash:
 IFDEF TI84PCSE
       cp 0ECh
       jr c,CallEraseFlash
       cp 0F0h
       jr nc,CallEraseFlash
       push ix
       push af
       ld a,3
       out (21h),a
       pop af
       call CallEraseFlash
       push af
       ld a,2
       out (21h),a
       pop af
       pop ix
       ret
 ENDIF
CallEraseFlash:
       push ix
       ld ix,EraseFlashCode
       call runRamCode
       pop ix
       ret
EraseFlashCode:
       DW EraseFlashCodeEnd-EraseFlashCodeStart
EraseFlashCodeStart:
       ld (OP1),a
       in a,(6)
       push af
       in a,(0Eh)
       push af
       ld a,(OP1)
       bit 7,a
       res 7,a
       out (6),a
       ld a,0
       jr z,$F
       inc a
$$:    out (0Eh),a
       in a,(6)
       push af
       in a,(0Eh)
       push af
       xor a
       out (0Eh),a
       ld a,2
       out (6),a
       ld a,0AAh
       ld (6AAAh),a
       ld a,1
       out (6),a
       ld a,55h
       ld (5555h),a
       ld a,2
       out (6),a
       ld a,80h
       ld (6AAAh),a
       ld a,2
       out (6),a
       ld a,0AAh
       ld (6AAAh),a
       ld a,1
       out (6),a
       ld a,55h
       ld (5555h),a
       pop af
       out (0Eh),a
       pop af
       out (6),a
       ld a,30h
       ld (hl),a
$$:    ld a,(hl)
       bit 7,a
       jr nz,$F
       bit 5,a
       jr nz,efcs1
       jr $B
$$:    pop af
       out (0Eh),a
       pop af
       out (6),a
       xor a
       ret
efcs1: ld a,0F0h
       ld (de),a
       pop af
       out (0Eh),a
       pop af
       out (6),a
       or 1
       ret
EraseFlashCodeEnd:

WriteFlash:
       cp 0ECh
       jr c,CallWriteFlash
       cp 0F0h
       jr nc,CallWriteFlash
       push ix
       push af
       ld a,3
       out (21h),a
       pop af
       call CallWriteFlash
       push af
       ld a,2
       out (21h),a
       pop af
       pop ix
       ret
CallWriteFlash:
       push af
       ld a,b
       or c
       jr z,$F
       pop af
       res 1,(iy+25h)
       push ix
       ld ix,WriteFlashCode
       call runRamCode
       pop ix
       ret
$$:    pop af
       ret
WriteFlashCode:
       DW WriteFlashCodeEnd-WriteFlashCodeStart
WriteFlashCodeStart:
       ld (OP1),a
       in a,(6)
       push af
       in a,(0Eh)
       push af
       ld a,(OP1)
WriteFlashCodeStart2:
       push af
       bit 7,a
       res 7,a
       out (6),a
       ld a,0
       jr z,$F
       inc a
$$:    out (0Eh),a
       bit 7,h
       jr nz,wfc3
       set 1,(iy+25h)
wfc3:  bit 1,(iy+25h)
       jr nz,$F
       bit 7,d
       jr z,$F
       pop af
       inc a
       ld de,4000h
       jr WriteFlashCodeStart2
$$:    in a,(6)
       push af
       in a,(0Eh)
       push af
       xor a
       out (0Eh),a
       ld a,2
       out (6),a
       ld a,0AAh
       ld (6AAAh),a
       ld a,1
       out (6),a
       ld a,55h
       ld (5555h),a
       ld a,2
       out (6),a
       ld a,0A0h
       ld (6AAAh),a
       pop af
       out (0Eh),a
       pop af
       out (6),a
       ldi
       dec de
       dec hl
$$:    ld a,(de)
       push af
       xor (hl)
       and 80h
       jr z,$F
       pop af
       bit 5,a
       jr z,$B
       ld a,(de)
       xor (hl)
       and 80h
       jr nz,wfc1
       jr wfc2
$$:    pop af
wfc2:  inc de
       inc hl
       ld a,b
       or c
       jr nz,wfc3
       dec de
       ld a,0F0h
       ld (de),a
       inc de
       pop af
       pop af
       out (0Eh),a
       pop af
       out (6),a
       xor a
       ret
wfc1:  pop af
       ld a,0F0h
       ld (de),a
       pop af
       out (0Eh),a
       pop af
       out (6),a
       or a
       ret
WriteFlashCodeEnd:

runRamCode:
       push bc
       push de
       push hl
       push ix
       pop hl
       ld c,(hl)
       inc hl
       ld b,(hl)
       inc hl
       ld de,ramCode
       ldir
       pop hl
       pop de
       pop bc
       jp ramCode

DisplayImage:
;Displays image in white and one other single color, scaled 4x.
;This uses the same input as BCALL _DisplayImage (this is an 84+CSE equivalent routine).
;I know this is awful, I was in a rush, bite me.
;Inputs:      IX: address of data (row, pixels per row, data)
;             L: starting row
;             DE: starting column
;             (0FE67h): color
       ld bc,(0A038h)
       push bc
       ;Reset window to fill entire screen
       xor a
       out (10h),a
       ld a,52h
       out (10h),a
       xor a
       out (11h),a
       out (11h),a
       out (10h),a
       ld a,53h
       out (10h),a
       ld a,1
       out (11h),a
       ld a,3Fh
       out (11h),a
       xor a
       out (10h),a
       ld a,50h
       out (10h),a
       xor a
       out (11h),a
       out (11h),a
       out (10h),a
       ld a,51h
       out (10h),a
       xor a
       out (11h),a
       ld a,0EFh
       out (11h),a
       ;Get number of rows and column bytes
       di
       ld c,(ix)
       inc ix
       ld h,(ix)
       ld a,4
       push iy
diRowLoop:
       push ix
       pop iy
       push af
       push bc
       push de
       push hl
       inc h
       push af
diWriteNewByte:
       pop af
       ld b,0
       inc ix
       ld a,(ix)
       push af
diWriteByteLoop:
       pop af
       dec h
       jr z,diWriteRowDone
       rlca
       push de
       ld de,(0FE67h)
       jr c,$F
       ld de,0FFFFh
$$:    ld (0A038h),de
       pop de
       push af
       call WritePixelToLCD
       inc de
       call WritePixelToLCD
       inc de
       call WritePixelToLCD
       inc de
       call WritePixelToLCD
       inc de
       inc b
       ld a,b
       cp 8
       jr nz,diWriteByteLoop
       jr diWriteNewByte
diWriteRowDone:
       pop hl
       pop de
       pop bc
       pop af
       inc l
       dec a
       jr z,$F
       push iy
       pop ix
       jr diRowLoop
$$:    ld a,4
       dec c
       jr nz,diRowLoop
       pop iy
       pop de
       ld (0A038h),de
       ret
WritePixelToLCD:
;      L: row
;      DE: column
;      (0A038h): color
;      Destroys A
       xor a
       out (10h),a
       ld a,21h
       out (10h),a
       ld a,d
       out (11h),a
       ld a,e
       out (11h),a
       xor a
       out (10h),a
       ld a,20h
       out (10h),a
       xor a
       out (11h),a
       ld a,l
       out (11h),a
       xor a
       out (10h),a
       ld a,22h
       out (10h),a
       push de
       ld de,(0A038h)
       ld a,d
       out (11h),a
       ld a,e
       out (11h),a
       pop de
       ret

UnlockFlash:
;Unlocks Flash protection.
;Destroys:
;	ramCode
;	0FFFEh
;      tempSwapArea+10
;This cannot work on the original TI-83 Plus.
	di
	ld a,1
	out (0Fh),a
	ld a,7Fh
	out (7),a
	;Find "call ix" code
	ld ix,callIXPattern
	ld de,8000h
	call FindPattern
	jr nz,unlockReturn
       ld hl,(0FFFEh)
	push hl
	;Find boot page "erase sector 0" reboot code
	ld ix,unlockPattern
	ld de,8000h
	call FindPattern
	pop de
	jr nz,unlockReturn
       ld a,81h
       out (7),a
 IFDEF TI84PCSE
	ld d,81h ;D comes from i + flags, E comes from lower byte of return address from boot code
 ELSE
	ld d,80h ;D comes from i + flags, E comes from lower byte of return address from boot code
 ENDIF
       ld hl,returnPoint
       ld bc,returnPointEnd-returnPoint
       ldir
       ld hl,unlockLoader
       ld de,tempSwapArea+10
       ld bc,unlockLoaderEnd-unlockLoader
       ldir
       jp tempSwapArea+10
unlockLoader:
       in a,(6)
       push af
       in a,(0Eh)
       push af
       ld a,7Fh
       out (6),a
       ld a,1
       out (0Eh),a
	ld de,unlockPatternCallStart-unlockPattern
	ld hl,(0FFFEh)
	add hl,de
       res 7,h
       set 6,h
       push hl
       pop ix
	ld a,1
	out (5),a
	ld hl,0
	add hl,sp
	ex de,hl
 IFDEF TI84PCSE
	ld sp,8282h+4000h+2+2+2+2-1 ;base comes from boot code "call IX" routine, offsets come from boot code stack trace
 ELSE
	ld sp,82A2h+4000h+2+2+2+2-1 ;base comes from boot code "call IX" routine, offsets come from boot code stack trace
 ENDIF
	ld a,80h
	ld i,a
	jp (ix)
unlockLoaderEnd:
returnPoint:
	ex de,hl
	ld sp,hl
	xor a
	out (5),a
       pop af
       out (0Eh),a
       pop af
       out (6),a
       in a,(2)
       ret
returnPointEnd:
unlockReturn:
       ld a,81h
       out (7),a
unlockRet:
	ret
callIXPattern:
	push bc
	push de
	push hl
	push ix
	pop hl
	ld c,(hl)
	inc hl
	ld b,(hl)
	inc hl
	ld de,8100h
	push de
	ldir
	pop ix
	pop hl
	pop de
	pop bc
	call 0FEFEh
	push af
	ld a,(82FEh)
	bit 2,a
	DB 0FFh
 IFDEF TI84PCSE
unlockPattern:
	call 0FEFEh
	DB 28h,0FEh ;jr z,xx
unlockPatternCallStart:
	push af
	ld a,1
	nop
	nop
	im 1
	di
	out (14h),a
	di
	DB 0FDh
	xor a
	call 0FEFEh
	push af
	xor a
	nop
	nop
	im 1
	di
	out (14h),a
	DB 0FFh
 ELSE
unlockPattern:
	ld hl,0FEFEh
	call 0FEFEh
	push af
unlockPatternCallStart:
	ld a,1
	nop
	nop
	im 1
	di
	out (14h),a
	di
	DB 0FDh
	xor a
	push af
	call 0FEFEh
	or a
	DB 28h,0FEh ;jr z,xx
	ld hl,0FEFEh
	push af
	xor a
	nop
	nop
	im 1
	di
	out (14h),a
	DB 0FFh
 ENDIF
FindPattern:
;Pattern in IX, starting address in DE
;Returns NZ if pattern not found
;(0FFFEh) contains the address of match found
;Search pattern:	terminated by 0FFh
;					0FEh is ? (one-byte wildcard)
;					0FDh is * (multi-byte wildcard)
	ld hl,unlockRet
	push hl
	dec de
searchLoopRestart:
	inc de
	ld (0FFFEh),de
	push ix
	pop hl
searchLoop:
	ld b,(hl)
	ld a,b
	inc a
	or a
	ret z
	inc de
	inc a
	jr z,matchSoFar
	dec de
	inc a
	ld c,a
	;At this point, we're either the actual byte (match or no match) (C != 0)
	;  or * wildcard (keep going until we find our pattern byte) (C == 0)
	or a
	jr nz,findByte
	inc hl
	ld b,(hl)
findByte:
	ld a,(de)
	inc de
	bit 6,d
	ret nz
	cp b
	jr z,matchSoFar
	;This isn't it; do we start over at the beginning of the pattern,
	;  or do we keep going until we find that byte?
	inc c
	dec c
	jr z,findByte
	ld de,(0FFFEh)
	jr searchLoopRestart
matchSoFar:
	inc hl
	jr searchLoop

cphlde:
       push hl
       or a
       sbc hl,de
       pop hl
       ret

WaitTimer100ms:
;Waits 100ms
       call WaitTimer20ms
       call WaitTimer20ms
       call WaitTimer20ms
WaitTimer40ms:
;Waits 40ms
       call WaitTimer20ms
WaitTimer20ms:
;Waits 20ms
       ld b,2
WaitTimerBms:
;Waits B*10 milliseconds
       ld a,42h
       out (36h),a
       xor a
       out (37h),a
       ld a,b
       out (38h),a
$$:    in a,(4)
       bit 7,a
       jr z,$B
       ret

INewLine:
       push hl
       ld hl,(curRow)
       inc l
       ld h,0
       ld (curRow),hl
       pop hl
       ret

VPutSAppCenter:
       push hl
       call SStringLen
 IFDEF TI84PCSE
       ld hl,319
 ELSE
       ld hl,95
 ENDIF
       or a
       sbc hl,bc
       srl h
       rr l
 IFDEF TI84PCSE
       ld (penCol),hl
 ELSE
       ld a,l
       ld (penCol),a
 ENDIF
       pop hl
VPutSApp:
       ld a,(hl)
       inc hl
       or a
       ret z
       B_CALL VPutMap
       jr VPutSApp
SStringLen:
       ld bc,0
$$:    ld a,(hl)
       inc hl
       or a
       ret z
       push hl
 IFNDEF TI84PCSE
       ld h,0
       ld l,a
       add hl,hl
       add hl,hl
       add hl,hl
 ELSE
       ld de,25
       B_CALL ATimesDE
 ENDIF
       push bc
       B_CALL SFont_Len
       ld a,b
       pop bc
       pop hl
       add a,c
       ld c,a
       jr nc,$B
       inc b
       jr $B

PutSAppCenter:
       push hl
       xor a
       ld bc,0FFFFh
       cpir
       dec hl
       pop de
       or a
       sbc hl,de
       ld a,CHARS_PER_LINE
       sub l
       srl a
       ld (curCol),a
       ex de,hl

PutSApp:
       ld a,(hl)
       inc hl
       or a
       ret z
       B_CALL PutC
       jr PutSApp

IGetKey:
       push ix
       push bc
       push de
       push hl
       res onInterrupt,(iy+onFlags)
       B_CALL getkey
       pop hl
       pop de
       pop bc
       pop ix
       ret

IPutC:
       push hl ;don't think these are necessary
       push bc
       B_CALL PutC
       pop bc
       pop hl
       ret
       
GetHexA:
;lets user input an 8 bit number in hexadecimal
;prompt is at currow,curcol
;number is returned in a
       set curAble,(iy+curFlags)
       ld b,2
       ld hl,TempNum
getnumhloop:
       call IGetKey
       cp 2
       jp nz,gnhnotback
       ld a,b
       cp 2
       jp z,gnhnotback
       ld a,' '
       B_CALL PutMap
       ld hl,curCol
       dec (hl)
       jp GetHexA
gnhnotback:
       sub 142
       cp 10
       jp c,gnhnumpressed
       sub 12
       cp 6
       jp c,gnhletpressed
       jp getnumhloop
gnhnumpressed:
       ld (hl),a
       inc hl
       add a,48
       call IPutC
       djnz getnumhloop
       jp gnhdone
gnhletpressed:
       add a,10
       ld (hl),a
       inc hl
       add a,55
       call IPutC
       djnz getnumhloop
gnhdone:
       dec hl
       ld b,(hl)
       dec hl
       ld a,(hl)
       rlca
       rlca
       rlca
       rlca
       or b
       res curAble,(iy+curFlags)
       ret

DispHexHL:
       push af
       push bc
       push de
       push hl
       push ix
       ld a,h
       call DispHexA
       ld a,l
       call DispHexA
       pop ix
       pop hl
       pop de
       pop bc
       pop af
       ret

DispHexA:
       push ix
       push af
       push hl
       push bc
       push af
       rrca
       rrca
       rrca
       rrca
       call dispha
       pop af
       call dispha
       pop bc
       pop hl
       pop af
       pop ix
       ret
dispha:and 15
       cp 10
       jp nc,dhlet
       add a,48
       jp dispdh
dhlet: add a,55
dispdh:call IPutC
       ret

;DialogBox
; Input
;  (H,L) = (y,x) upper left
;  (D,E) = (y,x) lower right
;H and l must be >= 1
;D must be <= 62
;E must be <= 93
;Text inside the box must be displayed manually
DialogBox:
       push hl
       push de
       dec h
       dec l
       inc d 
       inc d
       inc e
       inc e
 IFNDEF TI84PCSE
       B_CALL EraseRectBorder
 ENDIF
       pop de
       pop hl
       push hl
       push de
 IFNDEF TI84PCSE
       B_CALL DrawRectBorderClear
 ENDIF
       pop de
	pop hl
       push hl
       push de
       inc d
       inc e
 IFNDEF TI84PCSE
       B_CALL DrawRectBorder
 ENDIF
       pop de
       pop hl
       ld a,h
       xor 63 ;Adjust for funny IPoint coordinates
       ld h,a
       ld a,d
       xor 63
       ld b,l
       ld c,h
       ld d,0
       B_CALL IPoint ;(b,c) = (x,y xor 63) - upper left
       ld b,e
       B_CALL IPoint
       inc b
       B_CALL IPoint
       dec c
       B_CALL IPoint
       ld c,a
       dec c
       B_CALL IPoint
       ld b,l
       B_CALL IPoint
       inc b
       B_CALL IPoint
       dec b
       inc c
       B_CALL IPoint
       ret

