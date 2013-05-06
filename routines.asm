;Linky entry points

 include "settings.inc"
 include "equates.inc" 
 SEGMENT Main
 GLOBALS ON

 EXTERN DispHexA,DispHexHL
 EXTERN USBactivityHook

DriverInfo:
;Returns Linky version.
;Inputs:      None
;Outputs:     HL is version (H major, L minor)
;             DE is build
;             A is flags byte (all zeroes)
       ld hl,VERSION
       ld de,BUILD
       xor a
       ret

DisableUSB:
;Disables USB communication.
;Inputs:      None
;Outputs:     None
       ;Hold the USB controller in reset and disable interrupts
       xor a
       out (5Bh),a
       out (4Ch),a
       ret

DriverInit:
;Initializes Linky driver.
;Inputs:      B is flags byte:
;             Bit 0: set for "no interrupt" mode.
;Outputs:     Returns carry set if problems
;             A is return data (all zeroes)
       push bc
       call DisableUSB
       ;Install the USB activity hook
       B_CALL getRomPage
       ld hl,USBactivityHook
       B_CALL EnableUSBHook
       ;Set everything up
       pop bc
       ld a,b
       and 1
       ld (USBFlags),a
       ret

EnableUSB:
;Enables USB communication.
;Inputs:      None
;Outputs:     None
       ;Hold the USB controller in reset
       xor a
       out (4Ch),a
       ;Enable protocol interrupts
       ld a,1
       out (5Bh),a
       ld a,0FFh
       out (87h),a
       xor a
       out (92h),a
       in a,(87h)
       ld a,0Eh
       out (89h),a
       ld a,0FFh
       out (8Bh),a
       ;Release the controller reset
       call WaitForControllerReset
       ld a,8
       out (4Ch),a
       xor a
       ret

SetupPeripheralMode:
;Sets up peripheral mode.
;Inputs:      IX: descriptor table:
;                    DW deviceDescriptorAddress
;                    DB deviceDescriptorPage
;                    DW configDescriptorAddress
;                    DB configDescriptorPage
;                    DW stringDescriptorsTableAddress
;                    DB stringDescriptorsTablePage
;             A: bMaxPacketSize0
;             HL: control request event handler
       ld (controlRequestHandler),hl
       push ix
       pop hl
       ld de,deviceDescriptor
       ld bc,3*3
       ldir
       ld (maxPacketSizes),a
       ;TODO: Set max packet sizes for each endpoint based on endpoint descriptors
       ret

DriverKill:
;Kills Linky driver.
;Inputs:      None
;Outputs:     Returns carry set if problems
       ;Disable interrupts, then our hook
       xor a
       out (5Bh),a
       res 0,(iy+3Ah)
       ;Reset the USB controller
       xor a
       out (4Ch),a
       ;Re-enable interrupts
       ld a,1
       out (5Bh),a
       ;Release controller reset
       call WaitForControllerReset
       ld a,8
       out (4Ch),a
       xor a
       ret
ResetController:
       xor a
       out (4Ch),a
WaitForControllerReset:
       in a,(4Ch)
       bit 1,a
       jr z,WaitForControllerReset
       ret

