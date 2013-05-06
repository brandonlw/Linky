;BASIC/Assembly interfaces
;TODO: Re-do this

 include "settings.inc"
 include "equates.inc" 
 SEGMENT Main
 GLOBALS ON

InterfaceTable:
       DW (InterfaceTableEnd-InterfaceTable-1)/4
       DW 0001h, RunAppLibData ;Type 0001h, RunAppLib data
       DW 0002h, ExecLibHook   ;Type 0002h, ExecLib hook
InterfaceTableEnd:

;RunAppLib Assembly Interface
;-----------------------------------------------------------------------------
RunAppLibData:
       DW (RunAppLibEntryPointsEnd - RunAppLibEntryPoints)/10
RunAppLibEntryPoints:
       COMMENT ~
       DB "Version",0
       DW DriverVersion
       DB "Flush",0,0,0
       DW DriverInit
       DB "Kill",0,0,0,0
       DW DriverKill
       DB "CalcInit"
       DW CalculatorInit
       DB "MInit",0,0,0
       DW MouseInit
       DB "GInit",0,0,0
       DW GamepadInit
       DB "KInit",0,0,0
       DW KeyboardInit
       DB "MSInit",0,0
       DW MassStorageInit
       DB "SendKey",0
       DW SendKeypress
       ~
RunAppLibEntryPointsEnd:

;-----------------------------------------------------------------------------

;OpenLib(/ExecLib BASIC Interface
;-----------------------------------------------------------------------------
ExecLibHook:
       add a,e
       ld hl,6*7
       B_CALL EnoughMem
       jr nc,$F
       B_JUMP ErrMemory
$$:    B_CALL RclAns
       ld a,(hl)
       cp ListObj
       jr z,$F
       B_JUMP ErrDataType
$$:    push de
       ld hl,tempSwapArea
       ld bc,7*9
       B_CALL MemClear             ;Clear RAM so ConvOP1 won't fail
       pop de                      ;DE -> size bytes
       ld a,(de)
       cp 8
       jr c,$F
       ld a,7
$$:    ld b,a
       add a,a                     ;*2
       add a,a                     ;*4
       add a,a                     ;*8
       add a,b                     ;*9
       ld c,a
       ld b,0
       inc de
       inc de
       ex de,hl
       ld de,tempSwapArea
       push de
       ldir                        ;Copy from list to tempSwapArea
       pop hl                      ;HL -> list data
       call ListToRegVals
       cp NumBASICEntryPoints
       jr c,$F
       ld a,errEPIndex
       jr BasicReturn
$$:    push hl
       push de
       ld l,a
       ld h,0
       add hl,hl
       ld de,BASICEntryPointTable
       add hl,de
       ld e,(hl)
       inc hl
       ld d,(hl)
       push de
       pop ix
       pop de
       pop hl
       di
       ld iy,BasicReturn
       push iy
       ld iy,flags
       ei
       jp (ix)
BASICEntryPointTable:
NumBASICEntryPoints         EQU ($-BASICEntryPointTable)/2

BasicReturn:
       res 4,(iy+9)
;RegValsToList:
       push hl
       push de
       push bc
       push af
       B_CALL RclAns
       B_CALL DelVar
       B_CALL AnsName
       ld hl,7
       B_CALL CreateRList
       inc de
       inc de
       pop af
       call ToListSaveDE           ;A value
       pop bc
       ld a,b
       push bc
       call ToListSaveDE           ;B value
       pop bc
       ld a,c
       call ToListSaveDE           ;C value
       pop bc
       ld a,b
       push bc
       call ToListSaveDE           ;D value
       pop bc
       ld a,c
       call ToListSaveDE           ;E value
       pop bc
       ld a,b
       push bc
       call ToListSaveDE           ;H value
       pop bc
       ld a,c                      ;L value
ToListSaveDE:
       push de
       ld l,a
       ld h,0
       B_CALL SetXXXXOP2
       ld hl,OP2
       pop de
       B_CALL Mov9B
       ret

ListToRegVals:
;HL points to list data
       rst 20h
       call ConvOP1SaveHL
       push af                     ;A on stack
       rst 20h
       call ConvOP1SaveHL
       push af                     ;B on stack
       rst 20h
       call ConvOP1SaveHL
       pop bc
       ld c,a
       push bc                     ;BC on stack
       rst 20h
       call ConvOP1SaveHL
       push af                     ;D on stack
       rst 20h
       call ConvOP1SaveHL
       pop de
       ld e,a
       push de                     ;DE on stack
       rst 20h
       call ConvOP1SaveHL
       push af                     ;H on stack
       rst 20h
       B_CALL ConvOP1
       pop hl
       ld l,a
       pop de
       pop bc
       pop af
       ret

ConvOP1SaveHL:
       push hl
       B_CALL ConvOP1
       pop hl
       ret
;-----------------------------------------------------------------------------

