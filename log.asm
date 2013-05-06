;Linky USB communication logging
;Mostly (completely :/) written by Dan Englender
;TODO: Re-do this

 include "settings.inc"
 include "equates.inc"
 SEGMENT Main
 GLOBALS ON
 EXTERN IPutS,DispHexA,IGetKey,INewLine,Start,ILdHLInd,USBErrorFeatureDisabled,DispHexHL

DoLog:
       push   ix
       push   hl
       push   de
       push   af
       push   bc
;       ld a,b
;       cp logSectorRead
;       jr z,$F
;       cp logSectorWrite
;       jr nz,logDone
$$:    call   DoLogDo
logDone:
       pop    bc
       pop    af
       pop    de
       pop    hl
       pop    ix
       ret

DoLogDo:
       ld     hl,logPage
       ld     a,(hl)
       or     a
       ret    z
       inc    hl
       ld     e,(hl)
       inc    hl
       ld     d,(hl)
;       bit 6,d
;       ret nz
       ex     de,hl                ;HL = logptr
       out    (7),a                ;set log RAM page
       ld     a,b
       cp     logData
       jr     z,DoLogData
       cp     logDataEnd
       jr     z,DoLogDataEnd
       cp     logDataStart
       jr     nz,$f
       in     a,(7)
       push   af
       ld     a,81h
       out    (7),a
       ld     ix,logDataAddress
       ld     (ix+0),l
       ld     (ix+1),h
       pop    af
       out    (7),a
$$:
       ld     (hl),b
       inc    hl
       ld     (hl),c
       inc    hl
       ld     (hl),0
       inc    hl
       ld     (hl),0
       inc    hl
DoLogCont:
       ld     a,81h
       out    (7),a
       ex     de,hl
       ld     (hl),d
       dec    hl
       ld     (hl),e
       ret
DoLogData:
;If we've already stored 32 bytes of data, time to start a new data log entry

       jr     LogDataOK

       push   bc
       push   hl

       in     a,(7)
       push   af
       ld     a,81h
       out    (7),a
       ld     ix,logDataAddress
       ld     c,(ix+0)          
       ld     b,(ix+1)            ;BC -> data start address
       pop    af
       out    (7),a
       
       or     a
       sbc    hl,bc                              ;How much data has been stored so far?
       ld     bc,68
       or     a
       sbc    hl,bc                              ;If it's 32 bytes, split up into two log entries
       pop    hl
       pop    bc
       jr     nz,LogDataOK
       push   bc                                 ;Start new entry
       ld     a,81h
       out    (7),a
       ex     de,hl
       ld     (hl),d
       dec    hl
       ld     (hl),e

       ld     b,logDataEnd
       ld     c,0
       call   DoLogDo                     ;End the current data entry
       ld     b,logDataStart
       ld     c,0
       call   DoLogDo                     ;And start the new one
       pop    bc
       jp     DoLogDo                     ;Restore the data


LogDataOK:
       ld     (hl),c
       inc    hl
       jr     DoLogCont

DoLogDataEnd:
       ld     a,l
       and    3
       jr     z,$f
       ld     (hl),0
       inc    hl
       jr     DoLogDataEnd
$$:                                       ;Update DataEnd and DataStart with each other's addresses
       ld     (hl),b                      ;DataEnd
       inc    hl
       inc    hl
       in     a,(7)
       push   af
       ld     a,81h
       out    (7),a
       ld     ix,logDataAddress
       ld     c,(ix+0)          ;DataStart Address
       ld     b,(ix+1)
       pop    af
       out    (7),a

       ld     (hl),c
       inc    hl
       ld     (hl),b
       inc    hl                          ;HL -> next log address
       inc    bc
       inc    bc                          ;BC -> DataStart's data2
       ld     a,l
       ld     (bc),a
       inc    bc
       ld     a,h
       ld     (bc),a
       jr     DoLogCont


LogCustom:
       LOG    Custom,b
       ret

SetupLog:
;B = page
;hl = addr
       ld     ix,logPage
       ld     (ix+0),b
       ld     (ix+1),l
       ld     (ix+2),h
       di
       ld a,b
       out (7),a
       ld hl,8000h
       ld (hl),0
       ld de,8001h
       ld bc,4000h-1
       ldir
       ld a,81h
       out (7),a
       LOG    SetupLog
       or     a
       ret

StopLog:
       LOG    LogDone
       ld     ix,logPage
       ld     (ix+0),0
       ld     (ix+1),0
       ld     (ix+2),0
       ret

