;Flash application header
 SEGMENT Header

;Field: Application data length
	DB 080h,0Fh
;Length is filled in at signing time
	DB 00h,00h,00h,00h
;Field: Key ID
	DB 080h,012h
 IFDEF TI84PCSE
       DB 01h,0Fh
 ELSE
	DB 01h,04h
 ENDIF
;Field: Application ID (?)
	DB 080h,021h
	DB 01h
;Field: Application build
	DB 080h,031h
	DB 0A4h ;4?
;Field: Application name
	DB 080h,048h ;always padded to 8 with spaces
	DB AppName
;Field: Expiration date (I think -- number of seconds since 1/1/1997)
;       DB 080h,056h
;       DB 003h,026h,009h,004h,004h,06fh,01bh,080h
;Field: Number of application pages
	DB 080h,081h
	DB 01h
;Presence of below field specifies NO splash screen.
 IFDEF NOSPLASH
	DB 080h,090h
 ENDIF
;Field: Default CPU speed
       DB 080h,0A1h
 IFDEF FASTSPEED
       DB 01h
 ELSE
       DB 00h
 ENDIF
;Presence of below field specifies minimum OS version supported.
 IFDEF TIOSCHECK
       DB 080h,0C2h
       DB MinOSMajorVersion,MinOSMinorVersion
 ENDIF
;Field: Date stamp (dummy stamp - 5/12/1999, I think number of seconds since 1/1/1997)
	DB 003h,026h,009h,004h,004h,06fh,01bh,080h
;Dummy encrypted TI date stamp signature
	DB 002h ,00dh ,040h                             
	DB 0a1h ,06bh ,099h ,0f6h ,059h ,0bch ,067h 
	DB 0f5h ,085h ,09ch ,009h ,06ch ,00fh ,0b4h ,003h ,09bh ,0c9h 
	DB 003h ,032h ,02ch ,0e0h ,003h ,020h ,0e3h ,02ch ,0f4h ,02dh 
	DB 073h ,0b4h ,027h ,0c4h ,0a0h ,072h ,054h ,0b9h ,0eah ,07ch 
	DB 03bh ,0aah ,016h ,0f6h ,077h ,083h ,07ah ,0eeh ,01ah ,0d4h 
	DB 042h ,04ch ,06bh ,08bh ,013h ,01fh ,0bbh ,093h ,08bh ,0fch 
	DB 019h ,01ch ,03ch ,0ech ,04dh ,0e5h ,075h 
;Field: End of application header
	DB 80h,7Fh
	DB 0,0,0,0    ;Length=0, N/A
 IFNDEF NOSPLASH
       DB 0,0
 ENDIF
 IFNDEF TIOSCHECK
       DB 0,0,0,0
 ENDIF
       DB 0,0,0,0,0,0,0,0,0
       jp AboutScreen
       DB 0,0,0,0
       DB 96h,0E2h,0,1
       DW HeaderTable
HeaderTable:
;First word is some sort of unique ID?
;Second word is the type
       DW 1, 1, RunAppLibData
;       DW 2, 2, ExecLibHook
       DW 3, 3, AutoLaunchData
       DW 0
RunAppLibData:
       DW 0000h ;number of entry points
;       DB 0,0,0,0,0,0,0,0 ;ASCII function name
;       DW 0000h ;function address
ExecLibHook:
       add a,e
       ret
AutoLaunchData:
       ;Number of entry points
       DB 00h
;       ;Unique ID for this entry?
;       DB 01h
;       ;Inclusion flags
;       DW INCLUDE_VENDOR_ID|INCLUDE_PRODUCT_ID|INCLUDE_MIN_REVISION|INCLUDE_MAX_REVISION
;       ;Values
;       DW 0000h,0000h,0000h,0000h

