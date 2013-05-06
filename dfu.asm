;Device Firmware Upgrade (DFU) routines

 include "settings.inc"
 include "equates.inc" 
 SEGMENT Main
 GLOBALS ON

 EXTERN PutSApp,UnlockFlash,IPutC,DispHexA,DispHexHL,EraseFlashPage,WriteFlash
 EXTERN ShowMainMenu,ShowMenu,DoTools
 EXTERN DriverInit,DriverKill,EnableUSB,SetupPeripheralMode,StartControlResponse,HandleUSBActivity
 EXTERN StartControlInput

DoDFUUpload:
       ld hl,dfuUploadMenu
       jr ShowMenu

dfuUploadMenu:
       DB "DFU ROM Dump",0
       DB 3
       DB "1) With Cert",0
       DW DoDFUUploadWithCert
       DB "2) Without Cert",0
       DW DoDFUUploadWithoutCert
       DB "3) Back",0
       DW DoTools

DoDFUDownload:
       ld hl,dfuDownloadMenu
       jr ShowMenu

dfuDownloadMenu:
       DB "DFU ROM Write",0
       DB 3
       DB "1) With Cert",0
       DW DoDFUDownloadCert
       DB "2) Without Cert",0
       DW DoDFUDownloadNormal
;       DB "3) Boot",0
;       DW DoDFUDownloadBoot
;       DB "4) Boot & Cert",0
;       DW DoDFUDownloadBoth
       DB "3) Back",0
       DW DoTools

;Flags:
;0:    Temporary use
;1:    Reset means upload, set means download
;2:    Allow overwriting boot pages
;3:    Allow overwriting certificate
;4:    OS transfer has started (go OS-less from here on out)
DoDFUDownloadNormal:
       res 2,(iy+asm_Flag1)
       res 3,(iy+asm_Flag1)
       jr DoDFUDownloadStart
DoDFUDownloadBoth:
       set 2,(iy+asm_Flag1)
       set 3,(iy+asm_Flag1)
       jr DoDFUDownloadStart
DoDFUDownloadBoot:
       set 2,(iy+asm_Flag1)
       res 3,(iy+asm_Flag1)
       jr DoDFUDownloadStart
DoDFUDownloadCert:
       res 2,(iy+asm_Flag1)
       set 3,(iy+asm_Flag1)
DoDFUDownloadStart:
       call DriverInit
       res 4,(iy+asm_Flag1)
       set 1,(iy+asm_Flag1)
       ;Copy ourselves to extra RAM and transfer execution there
       di
       ld a,87h
       out (7),a
       ld hl,4000h
       ld de,8000h
       ld bc,4000h
       ldir
       ld a,81h
       out (7),a
       ld a,87h
       out (6),a
       ;Initialize the driver
       res 1,(iy+asm_Flag1)
       res 2,(iy+asm_Flag1)
       res 3,(iy+asm_Flag1)
       call DFUReset
       ld b,1 ;"no interrupt" mode
       call DriverInit
       ld hl,DFUPeripheralInfoDownload
       ld de,appData
       push de
       ld b,3
$$:    push bc
       push hl
       ld c,(hl)
       inc hl
       ld b,(hl)
       pop hl
       inc hl
       inc hl
       ld a,c
       ld (de),a
       inc de
       ld a,b
       ld (de),a
       inc de
       ld a,07h
       ld (de),a
       inc de
       pop bc
       djnz $B
       pop ix
       ld hl,DFUHandleControlRequest
       ld a,(DFUdeviceDescriptor+7)
       call SetupPeripheralMode
       ld hl,sInstructionsDownload
       call DFUDisplayInstructions
       call UnlockFlash
       ld a,02h
       ld (0FE67h),a
       call EnableUSB
       di
$$:    call HandleUSBActivity
       in a,(4)
       bit 3,a
       jr nz,$B
       call DriverKill
       bit 4,(iy+asm_Flag1)
       jr z,$F
       rst 00h
$$:    ld hl,bAppName
       rst 20h
       B_CALL FindApp
       jr nc,$F
       rst 00h
$$:    ;Swap page A into here
       ld hl,AppReloaderStart
       ld de,ramCode
       ld bc,AppReloaderEnd-AppReloaderStart
       ldir
       jp ramCode
AppReloaderStart:
       bit 7,a
       res 7,a
       out (6),a
       ld a,0
       jr z,$F
       inc a
$$:    out (0Eh),a
       jp DoTools
AppReloaderEnd:
bAppName:
       DB AppObj,AppName,0
DFUReceiveData:
       ld a,05h
       ld (0FE67h),a
       bit 4,(iy+asm_Flag1)
       set 4,(iy+asm_Flag1) ;we're receiving large chunks of data into RAM, time to consider RAM and the OS screwed
       jr nz,$F
       ;Set initial values
       call DFUDownloadSetup
$$:    ;Receive control data to RAM (wait for it to finish)
       ld de,(controlBuffer+6)
       ld b,81h
       ld hl,userMem
       call StartControlInput
       ld de,0FFFFh
$$:    push de
       call HandleUSBActivity
       pop de
       dec de
       ld a,d
       or e
       scf
       ret z
       ld hl,USBFlags
       bit receivingControlData,(hl)
       jr nz,$B
       ld bc,(controlBuffer+6)
       ld a,b
       or c
       jr nz,$F
       ;We're done
DFUDownloadSetup:
       ;Set initial values
       ld hl,4000h
       ld (0FE68h),hl
       ld (0FE69h),hl
       ld a,0FFh
       ld (appSearchPage),a
       or a
       ret
$$:    ;Prepare to write the data
       ld a,(0FE68h)
       ld b,a
 IFDEF TI84PCSE
       bit 3,(iy+asm_Flag1)
       jr z,$F
       cp 0FEh
       jr z,DFUWriteDoErase ;we're supporting this and it has its own sector(s), so erase it
$$:    cp 0FDh
       jr z,DFUWriteDone ;skipping this whole page for now
       cp 0FFh
       jr z,DFUWriteDone ;skipping this whole page for now
       cp 0FEh
       jr z,DFUWriteDone ;skipping this whole page since we made it here
 ELSE
       in a,(21h)
       and 3
       ld a,b
       jr z,is84P
       cp 6Ch
       jr c,DFUWriteDo
       cp 70h
       jr c,DFUWriteDone
       cp 7Fh
       jr z,DFUWriteDone
       bit 3,(iy+asm_Flag1)
       jr z,$F
       cp 7Eh
       jr z,DFUWriteDoErase ;we're supporting this and it has its own sector(s), so erase it
$$:    cp 7Eh
       jr z,DFUWriteDone ;skipping this whole page since we made it here
       jr DFUWriteDo
is84P: cp 2Ch
       jr c,DFUWriteDo
       cp 30h
       jr c,DFUWriteDone
       cp 3Fh
       jr z,DFUWriteDone
       bit 3,(iy+asm_Flag1)
       jr z,$F
       cp 3Eh
       jr z,DFUWriteDoErase ;we're supporting this and it has its own sector(s), so erase it
$$:    cp 3Eh
       jr z,DFUWriteDone ;skipping this whole page since we made it here
DFUWriteDo:
 ENDIF
       ld b,a
       and 3
       jr nz,$F
DFUWriteDoErase:
       ld a,(appSearchPage)
       cp b
       jr z,$F
       ld a,b
       ld (appSearchPage),a
       ;New sector, erase it
       call EraseFlashPage
$$:    ;Write the data
       ld a,(0FE68h)
       ld hl,userMem
       ld de,(0FE69h)
       ld bc,(controlBuffer+6)
       call WriteFlash
DFUWriteDone:
       ;Update pointers
       ld bc,(controlBuffer+6)
       ld hl,(0FE69h)
       add hl,bc
       bit 7,h
       jr z,$F
       res 7,h
       set 6,h
       ld a,(0FE68h)
       inc a
       ld (0FE68h),a
$$:    ld (0FE69h),hl
       or a
       ret

DoDFUUploadWithCert:
       call UnlockFlash
DoDFUUploadWithoutCert:
       ld b,0
       call DriverInit
       res 1,(iy+asm_Flag1)
       res 2,(iy+asm_Flag1)
       res 3,(iy+asm_Flag1)
       call DFUReset
       B_CALL getRomPage
       ld hl,DFUPeripheralInfo
       ld de,appData
       push de
       ld b,3
$$:    push bc
       ldi
       ldi
       ld (de),a
       inc de
       pop bc
       djnz $B
       pop ix
       ld hl,DFUHandleControlRequest
       ld a,(DFUdeviceDescriptor+7)
       call SetupPeripheralMode
       ld hl,sInstructions
       call DFUDisplayInstructions
       ld a,02h
       ld (0FE67h),a
       call EnableUSB
$$:    B_CALL getkey
       cp kClear
       jr nz,$B
       call DriverKill
       jr DoTools
DFUHandleControlRequest:
       ld a,(controlBuffer)
       cp 21h
       jr nz,$F
       ld a,(controlBuffer+1)
       cp 01h ;DFU_DNLOAD
       jr z,DFUReceiveData
       scf
       ret
$$:    cp 0A1h
       scf
       ret nz
       ld a,(controlBuffer+1)
       cp 02h ;DFU_UPLOAD
       jr z,DFUSendData
       cp 03h ;DFU_GETSTATUS
       scf
       ret nz
       ;Prepare 6 bytes of data to return
       ld ix,appData
       ld (ix+0),0 ;OK
       ld (ix+1),0 ;bwPollTimeout
       ld (ix+2),0
       ld (ix+3),0
       ld a,(0FE67h)
       ld (ix+4),a
       ld (ix+5),0 ;iString
       ld hl,appData
       ld de,6
       ld b,1
       call StartControlResponse
       xor a
       ret
DFUReset:
       res 0,(iy+asm_Flag1)
       ld hl,4000h
       ld (tempSwapArea),hl
       xor a
       ld (tempSwapArea+2),a
       ret
DFUDisplayInstructions:
       push hl
       B_CALL ClrLCDFull
       B_CALL HomeUp
       pop hl
       jr PutSApp
DFUSendData:
       bit 0,(iy+asm_Flag1)
       jr z,$F
       ld de,0
       call StartControlResponse
       xor a
       ret
$$:    ld bc,(tempSwapArea+2-1)
       ld ix,(tempSwapArea)
       ld hl,(tempSwapArea)
       ld de,(controlBuffer+6)
       add hl,de
       bit 7,h
       jr z,dfusdGo
       res 7,h
       set 6,h
       ld a,(tempSwapArea+2)
       inc a
       ld (tempSwapArea+2),a
 IFDEF TI84PCSE
       or a
       jr nz,dfusdGo
 ELSE
       in a,(21h)
       and 3
       ld c,40h
       jr z,$F
       ld c,80h
$$:    ld a,(tempSwapArea+2)
       cp c
       jr nz,dfusdGo
 ENDIF
       push bc
       push ix
       call DFUReset
       ld hl,sInstructions
       call DFUDisplayInstructions
       pop ix
       pop bc
       push ix
       pop de
       ld hl,8000h
       or a
       sbc hl,de
       ex de,hl
       set 0,(iy+asm_Flag1)
dfusdGo:
       ld (tempSwapArea),hl
       push ix
       pop hl
       call StartControlResponse
       xor a
       ret
sInstructions:
       DB "Press ",LlBrack,"CLEAR] to"
       DB " quit.",0
sInstructionsDownload:
 IFNDEF TI84PCSE
       DB "Press ",LlBrack,"ON] to   "
       DB " quit.",0
 ELSE
       DB "Press ",LlBrack,"ON] to quit.",0
 ENDIF
DFUPeripheralInfo:
       DW DFUdeviceDescriptor
       DW DFUconfigDescriptor
       DW DFUstringDescriptors
DFUPeripheralInfoDownload:
       DW DFUdeviceDescriptor+4000h
       DW DFUconfigDescriptorDownload+4000h
       DW DFUstringDescriptors+4000h
DFUdeviceDescriptor:
	DB 12h		;size of descriptor
	DB 01h		;device descriptor type
	DW 0110h	;USB version
	DB 0FFh       ;bDeviceClass
	DB 00h		;bDeviceSubClass
	DB 00h		;bDeviceProtocol
	DB 40h		;bMaxPacketSize0
	DW 0451h	;wVendorID
	DW 0DEADh	;wProductID
	DW 0100h	;device release number
	DB 01h		;manufacturer string index
	DB 02h		;product string index
	DB 03h		;serial number string index
	DB 01h		;bNumConfigurations
DFUconfigDescriptor:
	DB 09h		;size of descriptor
	DB 02h		;config descriptor type
	DW DFUconfigDescriptorEnd-DFUconfigDescriptor
	DB 01h		;number of interfaces
	DB 01h		;configuration number
	DB 04h		;configuration string index
	DB 0A0h	;bmAttributes
	DB 00h        ;bMaxPower
;Interface descriptor
       DB 09h        ;size of descriptor
       DB 04h        ;interface descriptor type
       DB 00h        ;interface number
       DB 00h        ;bAlternateSetting
       DB 00h        ;bNumEndpoints
       DB 0FEh       ;bInterfaceClass
       DB 01h        ;bInterfaceSubClass
       DB 02h        ;bInterfaceProtocol
       DB 05h        ;interface string index
;Functional descriptor
       DB 09h        ;size of descriptor
       DB 21h        ;functional descriptor type
       DB 06h        ;bus reset not required, upload (calc->PC) capable
       DW 100        ;wait 100ms after DFU_DETACH (irrelevant)
       DW 4096       ;number of bytes per request
       DW 0100h      ;DFU version (1.00)
DFUconfigDescriptorEnd:
DFUconfigDescriptorDownload:
	DB 09h		;size of descriptor
	DB 02h		;config descriptor type
	DW DFUconfigDescriptorDownloadEnd-DFUconfigDescriptorDownload
	DB 01h		;number of interfaces
	DB 01h		;configuration number
	DB 04h		;configuration string index
	DB 0A0h	;bmAttributes
	DB 00h        ;bMaxPower
;Interface descriptor
       DB 09h        ;size of descriptor
       DB 04h        ;interface descriptor type
       DB 00h        ;interface number
       DB 00h        ;bAlternateSetting
       DB 00h        ;bNumEndpoints
       DB 0FEh       ;bInterfaceClass
       DB 01h        ;bInterfaceSubClass
       DB 02h        ;bInterfaceProtocol
       DB 05h        ;interface string index
;Functional descriptor
       DB 09h        ;size of descriptor
       DB 21h        ;functional descriptor type
       DB 05h        ;bus reset not required, download (PC->calc) capable
       DW 100        ;wait 100ms after DFU_DETACH (irrelevant)
       DW 4096       ;number of bytes per request (TODO: Make this larger once we figure out control pipe issue)
       DW 0100h      ;DFU version (1.00)
DFUconfigDescriptorDownloadEnd:
DFUstringDescriptors:
       DB 6          ;Number of descriptors in table
       DB 00h        ;String descriptor index
DFUString0Start:
       DB DFUString0End-DFUString0Start
       DB 03h
       DW 0409h
DFUString0End:

       DB 01h        ;String descriptor index
DFUString1Start:
       DB DFUString1End-DFUString1Start
       DB 03h
       DW "Texas Instruments"
DFUString1End:

       DB 02h        ;String descriptor index
DFUString2Start:
       DB DFUString2End-DFUString2Start
       DB 03h
       DW "TI Device - DFU Mode"
DFUString2End:

       DB 03h        ;String descriptor index
DFUString3Start:
       DB DFUString3End-DFUString3Start
       DB 03h
       DW "12345"
DFUString3End:

       DB 04h        ;String descriptor index
DFUString4Start:
       DB DFUString4End-DFUString4Start
       DB 03h
       DW "TI Device - DFU Mode"
DFUString4End:

       DB 05h        ;String descriptor index
DFUString5Start:
       DB DFUString5End-DFUString5Start
       DB 03h
       DW "TI Device - DFU Mode"
DFUString5End:

