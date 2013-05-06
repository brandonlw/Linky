 NOLIST
 IFDEF TI84PCSE
 include "ti84pcse.inc"
 ELSE
 include "ti83plus.inc"
 ENDIF
 LIST

INCLUDE_VENDOR_ID           EQU    0001h
INCLUDE_PRODUCT_ID          EQU    0002h
INCLUDE_MIN_REVISION        EQU    0004h
INCLUDE_MAX_REVISION        EQU    0008h

;Safe RAM
 IFDEF TI84PCSE
safeRAM              EQU    tempSwapArea
 ELSE
safeRAM              EQU    appBackUpScreen
 ENDIF
lwrCaseFlag          EQU    safeRAM+0            ;1
menuAddr             EQU    lwrCaseFlag+1        ;2
numChoices           EQU    menuAddr+2           ;1
TempNum              EQU    numChoices+1         ;2
;DO NOT REORDER THESE
logPage              EQU    TempNum+2            ;1
logAddress           EQU    logPage+1            ;2
logDataPage          EQU    logAddress+2         ;1
logDataAddress       EQU    logDataPage+1        ;2
LogPage              EQU    logDataAddress+2     ;1
LogAddr              EQU    LogPage+1            ;2

;BCALL/BJUMP macros
rBR_CALL	EQU	28h
BRT_JUMP0	EQU	50h
B_CALL macro   label
	     RST     rBR_CALL
	     DW      _&label
       .endm
B_JUMP macro   label
	     CALL    BRT_JUMP0
	     DW      _&label
       .endm

;Logging action
LOG MACRO first, second
 IF LOGGING_ENABLED = 1
 IFNDEF DoLog
  EXTERN DoLog
 ENDIF
       push   bc
       ifneq "_&second", "_"
              ld     c,second
       else
              ld     c,0
       endif
       ld     b,log&first
       call   DoLog
       pop    bc
 ENDIF
 ENDMAC

 IFDEF TI84PCSE
controlBuffer               EQU    9F0Ah ;8
controlDataAddress          EQU    9F12h ;2
 ELSE
controlBuffer               EQU    9C29h ;8
controlDataAddress          EQU    9C31h ;2
 ENDIF
controlDataRemaining        EQU    controlDataAddress+2        ;2
maxPacketSizes              EQU    controlDataRemaining+2      ;16
deviceDescriptor            EQU    maxPacketSizes+16           ;2
deviceDescriptorPage        EQU    deviceDescriptor+2          ;1
configDescriptor            EQU    deviceDescriptorPage+1      ;2
configDescriptorPage        EQU    configDescriptor+2          ;1
stringDescriptor            EQU    configDescriptorPage+1      ;2
stringDescriptorPage        EQU    stringDescriptor+2          ;1
controlRequestHandler       EQU    stringDescriptorPage+1      ;2
controlDataPage             EQU    controlRequestHandler+2     ;1

 IFDEF TI84PCSE
USBaddress           EQU    9F52h ;1
USBFlags             EQU    9F56h ;1
 ELSE
USBaddress           EQU    9C71h ;1
USBFlags             EQU    9C75h ;1
 ENDIF
noInterruptMode      EQU    0
sendingControlData   EQU    1
setAddress           EQU    2
receivingControlData EQU    3

;Log types
;TODO: Come back to these
logGetMaxPacketSize EQU 1
logData EQU 2
logGetClass EQU 3
logGetIDs EQU 4
logReadDescriptor EQU 5
logQuit EQU 6
logSendData EQU 7
logSendControlData EQU 8
logAutoSetup EQU 9
logDataEnd EQU 10
logInA0Start EQU 11
logOutA0Start EQU 12
logHostInit EQU 13
logKillDevice EQU 14
logKillDriver EQU 15
logSetupLog EQU 16
logInData EQU 17
logCallBack EQU 18
logError EQU 19
logSetPortFeature EQU 20
logClearPortFeature EQU 21
logGetDeviceStatus EQU 22
logSetHubFeature EQU 23
logClearHubFeature EQU 24
logGetHubStatus EQU 25
logGetHubPortStatus EQU 26
logSetAddress EQU 27
logLogDone EQU 28
logDataStart EQU 29
logCustom EQU 30
logInterrupt EQU 31
logKBDInit EQU 32
logKBDGetKey EQU 33
logMSDInit EQU 34
logUFIInit EQU 35
logFATInit EQU 36
logPadInit EQU 37
logPadStart EQU 38
logPadSetup EQU 39
logPadCallBack EQU 40
logPumpOn EQU 41
logPumpOff EQU 42
logPump EQU 43
logCache EQU 44
logIntPort82 EQU 45
logIntPort84 EQU 46
logIntPort8F EQU 47
logIStallPipe EQU 48
logSetConfig EQU 49
logPeriphInit EQU 50
logIntPort86 EQU 51
logControlData EQU 52
logEnableOut EQU 53
logIntData EQU 54
logBulkData EQU 55
logMSDCmd EQU 56
logGotSetAddr EQU 57
logSectorRead EQU 58
logWriteError EQU 59
logSectorWrite EQU 60
logInvalidMSDCmd EQU 61
logInvalidDesc EQU 62
logStringDesc EQU 63
logCalcCmd    EQU 64
logCalcUSBErr EQU 65
logBit0Port56 EQU 66

logCacheOn           EQU 0
logCacheOff          EQU 1
logCacheIsInCache    EQU 2
logCacheReadFromCache EQU 3
logCacheResetLRU     EQU 4
logCacheSaveToCache  EQU 5

errEPIndex           EQU 1

