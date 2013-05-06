; DEFINE TI84PCSE
 DEFINE NOSPLASH
 DEFINE FASTSPEED
 DEFINE TIOSCHECK

 DEFINE Header, Space=ROM
 DEFINE Main, Space=ROM
 DEFINE MemVars, Space=ROM

MinOSMajorVersion    EQU 2
MinOSMinorVersion    EQU 30
 IFDEF TI84PCSE
CHARS_PER_LINE       EQU 26
 ELSE
CHARS_PER_LINE       EQU 16
 ENDIF

AppName              EQU "LINKYDRV"
AppDescription       EQU "Linky"
Author               EQU "Brandon Wilson"

VERSION              EQU 0001h
VER_STRING           EQU "0.01" ;must be 4 characters
BUILD                EQU 0001
BUILD_STRING         EQU "0001"
WEB_STRING           EQU "brandonw.net"

LOGGING_ENABLED      EQU 0

