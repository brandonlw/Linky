;Linky log viewer
;Mostly (completely :/) written by Dan Englender
;TODO: Re-do this

 include "settings.inc"
 include "equates.inc"
 SEGMENT Main
 GLOBALS ON

 EXTERN PutSApp,DispHexA,IGetKey,INewLine,Start,ILdHLInd,USBErrorFeatureDisabled,DispHexHL,GetHexA,INewLine,Init
 EXTERN ShowMainMenu

DispLog:
       ld a,87h                                         ;*** HACK: using page 87h for logging
       ld (LogPage),a
       ld hl,8000h
       ld (LogAddr),hl
       res    appAutoScroll,(iy+appFlags)
       call   GetLogVal
       ld     a,logSetupLog
       cp     b
       ;jr     nz,NoLogData
DispLogLoop:
       call   DispLogScreen
$$:
       call   IGetKey
       cp     kClear
       jr     z,DispLogDone
       cp     kQuit
       jr     z,DispLogDone
       cp     kEnter
       jr     z,LogEnter
       cp     kUp
       jr     z,LogUp
       cp     kAdd
       jr     z,LogWayDown
       cp     kSub
       jr     z,LogWayUp
       cp     kDown
       jr     nz,$b
LogDown:
       call   GetLogVal
       ld     a,b
       cp     logLogDone
       jr     z,$b
       cp     logQuit
       jr     z,$b
       call   IncLogAddr
       jr     DispLogLoop
LogUp:
       call   GetLogVal
       ld     a,b
       cp     logSetupLog
       jr     z,$b
       call   DecLogAddr
       jr     DispLogLoop
LogWayDown:
       ld     b,8
LogWayDownLoop:
       push   bc
       call   GetLogVal
       ld     a,b
       pop    bc
       cp     logLogDone
       jr     z,DispLogLoop
       cp     logQuit
       jr     z,DispLogLoop
       push   bc
       call   IncLogAddr
       pop    bc
       djnz   LogWayDownLoop
       jr     DispLogLoop
LogWayUp:
       ld     b,8
LogWayUpLoop:
       push   bc
       call   GetLogVal
       ld     a,b
       pop    bc
       cp     logSetupLog
       jr     z,DispLogLoop
       push   bc
       call   DecLogAddr
       pop    bc
       djnz   LogWayUpLoop
       jr     DispLogLoop

LogEnter:
       call   GetLogVal
       ld     a,logDataStart
       cp     b
       jr     nz,$b
       B_CALL ClrLCDFull
       B_CALL HomeUp
       ld     hl,(LogAddr)
       push   hl
       inc    hl
       inc    hl
       ld     (LogAddr),hl
       call   GetLogVal
       ld     e,b
       ld     d,c
       dec    de
       dec    de
       dec    de
       dec    de                   ;Place to end loop
       inc    hl
       inc    hl
       ld     (LogAddr),hl
LogEnterLoop:
       call   GetLogVal
       ld     a,b
       call   DispHexA
       ld     a,c
       call   DispHexA
       inc    hl
       inc    hl
       ld     (LogAddr),hl
       B_CALL CpHLDE
       jr     nz,LogEnterLoop
       call   IGetKey
       pop    hl
       ld     (LogAddr),hl
       jp     DispLogLoop
DispLogDone:
       set    appAutoScroll,(iy+appFlags)
       jr ShowMainMenu

DecLogAddr:

       ld     hl,(LogAddr)
       jr     z,DecLogData
       dec    hl
       dec    hl
       dec    hl
       dec    hl
       ld     (LogAddr),hl
       call   GetLogVal
       ld     a,logDataEnd
       cp     b
       ret    nz


DecLogData:
IncLogData:
       inc    hl
       inc    hl
       ld     (LogAddr),hl
       call   GetLogVal
       ld     h,c
       ld     l,b
       ld     (LogAddr),hl
       ret


IncLogAddr:
       call   GetLogVal
       ld     a,logDataStart
       cp     b
       ld     hl,(LogAddr)
       jr     z,IncLogData
       inc    hl
       inc    hl
       inc    hl
       inc    hl
       ld     (LogAddr),hl
       ret

DispLogScreen:
       B_CALL ClrLCDFull
       B_CALL HomeUp
       ld     hl,(LogAddr)
       push   hl
       ld     b,8
$$:
       push   bc
       call   GetLogVal
       ld     a,NumLogVals
       cp     b
       ld     hl,lsLogError
       jr     c,BadLogVal
       ld     l,b
       ld     h,0
       add    hl,hl
       ld     de,LogStringTable
       add    hl,de
       B_CALL ldHLind
BadLogVal:
       call   PutSApp
       ld     a,14
       ld     (curCol),a
       ld     a,c
       call   DispHexA
       ld     a,b
       cp     logLogDone
       jr     z,$f
       cp     logQuit
       jr     z,$f
       call   IncLogAddr
       pop    bc
       djnz   $b
       push   bc
$$:
       pop    bc
       pop    hl
       ld     (LogAddr),hl
       ret


GetLogVal:
;Output
; B = Log Type
; C = Log data1
; HL -> current LogAddr
       push   de
       in     a,(7)
       ld     d,a
       ld     hl,(LogAddr)
       ld     a,(LogPage)
       di
       out    (7),a
       ld     b,(hl)
       inc    hl
       ld     c,(hl)
       ld     a,d
       out    (7),a
       ei
       dec    hl
       pop    de
       ret

NoLogData:
       B_CALL ClrLCDFull
       B_CALL HomeUp
       ld     hl,NoLogDataTXT
       call   PutSApp
       call   IGetKey
       jr ShowMainMenu
NoLogDataTXT:
       db     "No Log Data",0

LogStringTable:
       dw     lsLogError
       dw     lsGetMaxPacketSize
       dw     lsData
       dw     lsGetClass
       dw     lsGetIDs
       dw     lsReadDescriptor
       dw     lsQuit
       dw     lsSendData
       dw     lsSendControlData
       dw     lsAutoSetup
       dw     lsDataEnd
       dw     lsInA0Start
       dw     lsOutA0Start
       dw     lsHostInit
       dw     lsKillDevice
       dw     lsKillDriver
       dw     lsSetupLog
       dw     lsInData
       dw     lsCallBack
       dw     lsError
       dw     lsSetPortFeature
       dw     lsClearPortFeature
       dw     lsGetDeviceStatus
       dw     lsSetHubFeature
       dw     lsClearHubFeature
       dw     lsGetHubStatus
       dw     lsGetHubPortStatus
       dw     lsSetAddress
       dw     lsLogDone
       dw     lsLogDataStart
       dw     lsLogCustom
       dw     lsLogInterrupt
       dw     lsLogKBDInit
       dw     lsLogKBDGetKey
       dw     lsLogMSDInit
       dw     lsLogUFIInit
       dw     lsLogFATInit
       dw     lsLogPadInit
       dw     lsLogPadStart
       dw     lsLogPadSetup
       dw     lsLogPadCallBack
       dw     isLogPumpOn
       dw     isLogPumpOff
       dw     isLogPump
       dw     isLogCache
       dw     isLogIntPort82
       dw     isLogIntPort84
       dw     lsLogIntPort8F
       dw     lsLogIStallPipe
       dw     lsLogSetConfig
       dw     lsLogPeriphInit
       dw     lsLogIntPort86
       dw     lsLogControlData
       dw     lsLogEnableOut
       dw     lsLogIntData
       dw     lsLogBulkData
       dw     lsLogMSDCmd
       dw     lsLogGotSetAddr
       dw     lsLogSectorRead
       dw     lsLogWriteError
       dw     lsLogSectorWrite
       dw     lsLogInvalidMSDCmd
       dw     lsLogInvalidDesc
       dw     lsLogStringDesc
       dw     lsLogCalcCmd
       dw     lsLogCalcUSBErr
       dw     lsLogBit0Port56
NumLogVals EQU ($-LogStringTable)/2
lsGetMaxPacketSize:  db     "GetMaxPack",0
lsData:              db     "Data",0
lsGetClass:          db     "GetClass",0
lsGetIDs:            db     "GetIDs",0
lsReadDescriptor     db     "ReadDesc",0
lsQuit:              db     "Quit",0
lsSendData:          db     "SendData",0
lsSendControlData    db     "SndConData",0
lsAutoSetup          db     "AutoSetup",0
lsDataEnd            db     "DataEnd",0
lsInA0Start          db     "InA0Start",0
lsOutA0Start         db     "OutA0Start",0
lsHostInit           db     "HostInit",0
lsKillDevice         db     "KillDevice",0
lsKillDriver         db     "KillDriver",0
lsSetupLog           db     "SetupLog",0
lsInData             db     "InData",0
lsCallBack           db     "CallBack",0
lsError              db     "Error",0
lsSetPortFeature     db     "SetPrtFeat",0
lsClearPortFeature   db     "ClrPrtFeat",0
lsGetDeviceStatus    db     "GetDevStat",0
lsSetHubFeature      db     "SetHubFeat",0
lsClearHubFeature    db     "ClrHubFeat",0
lsGetHubStatus       db     "GetHubStat",0
lsGetHubPortStatus   db     "GetPrtStat",0
lsSetAddress         db     "SetAddress",0
lsLogDone            db     "LogDone",0
lsLogDataStart       db     "Data",0
lsLogCustom          db     "Custom",0
lsLogInterrupt       db     "Interrupt",0
lsLogKBDInit         db     "KBDInit",0
lsLogKBDGetKey       db     "KBDGetKey",0
lsLogMSDInit         db     "MSDInit",0
lsLogUFIInit         db     "UFIInit",0
lsLogFATInit         db     "FATInit",0
lsLogPadInit         db     "PadInit",0
lsLogPadStart        db     "PadStart",0
lsLogPadSetup        db     "PadSetup",0
lsLogPadCallBack     db     "PadCB",0
isLogPumpOn          db     "PumpOn",0
isLogPumpOff         db     "PumpOff",0
isLogPump            db     "Pump",0
isLogCache           db     "Cache",0
isLogIntPort82       db     "IntPort82",0
isLogIntPort84       db     "IntPort84",0
lsLogIntPort8F       db     "IntPort8F",0
lsLogIStallPipe      db     "IStallPipe",0
lsLogSetConfig       db     "SetConfig",0
lsLogPeriphInit      db     "PeriphInit",0
lsLogIntPort86       db     "IntPort86",0
lsLogControlData     db     "ControlData",0
lsLogEnableOut       db     "EnableOut",0
lsLogIntData         db     "IntData",0
lsLogBulkData        db     "BulkData",0
lsLogMSDCmd          db     "MSDCmd",0
lsLogGotSetAddr      db     "GotSetAddr",0
lsLogSectorRead      db     "SectorRead",0
lsLogWriteError      db     "WriteError",0
lsLogSectorWrite     db     "SectorWrite",0
lsLogInvalidMSDCmd   db     "InvalidMSDCmd",0
lsLogInvalidDesc     db     "InvalidDesc",0
lsLogStringDesc      db     "StringDesc",0
lsLogCalcCmd         db     "CalcCmd",0
lsLogCalcUSBErr      db     "CalcUSBErr",0
lsLogBit0Port56      db     "Bit0Port56",0

lsLogError           db     "LOG ERROR",0

LogPageTXT:
       db     "Log Page:",0
LogAddrTXT:
       db     "Log Addr:",0

