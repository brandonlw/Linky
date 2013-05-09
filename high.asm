;Higher-level routines

 include "settings.inc"
 include "equates.inc" 
 SEGMENT Main
 GLOBALS ON

 EXTERN SendControlRequest_DeviceToHost,SendControlRequest_NoData
 EXTERN GetDeviceDescriptor

ClearControlBuffer:
       push hl
       ld hl,0
       ld (controlBuffer),hl
       ld (controlBuffer+2),hl
       ld (controlBuffer+4),hl
       ld (controlBuffer+6),hl
       pop hl
       ret

SetupDevice:
;Sets up a new device.
;This is either the root device (possibly a hub), or a device attached to a hub.
;If it's the root device (possibly a hub), we're already powered.
;If it's a device attached to a hub, we need to tell its parent hub to power it.
;We need to give it a unique address and add it to our device list.
;If it's a hub, we also need to attempt to set up all of its attached devices.
;Inputs:      A: device ID (or 0 for root device)
;             B: hub port number (or 0 for root device)
;Carry flag set if problems
       or a
       jr z,sdPowered
       ;This is a device attached to a hub.
       ;Tell the parent hub to power this device.
sdPowered:
       ;Get the device descriptor, so we can determine if we're dealing with a hub.
       ld de,8
       ld a,e
       ld (maxPacketSizes),a
       ld hl,appData
       ld b,1
       call GetDeviceDescriptor
       ld a,(appData+7)
       ld (maxPacketSizes),a
       ld a,(appData)
       ld d,0
       ld e,a
       ld hl,appData
       ld b,1
       call GetDeviceDescriptor
       ;Set the device address.
       call ClearControlBuffer
       ld a,05h
       ld (controlBuffer+1),a
       ld (controlBuffer+2),a
       ld de,0
       call SendControlRequest_NoData
       ld a,05h
       out (80h),a
       ;Insert device structure into our device list.
       ld a,(appData+4)
       cp 09h
       jr z,$F
       ;Device is not a hub; get out.
       xor a
       ret
$$:    ;Device is a hub, so also:
       ;      Get the configuration descriptor
       ld hl,0680h
       ld (controlBuffer),hl
       ld a,2
       ld (controlBuffer+3),a
       ld de,8
       ld (controlBuffer+6),de
       ld hl,appData
       ld b,1
       call SendControlRequest_DeviceToHost
       ld de,(appData+2)
       ld (controlBuffer+6),de
       ld hl,appData
       ld b,1
       call SendControlRequest_DeviceToHost
       ;      Configure the device
       call ClearControlBuffer
       ld a,09h
       ld (controlBuffer+1),a
       ld a,1
       ld (controlBuffer+2),a
       ld hl,appData
       ld b,1
       ld de,0
       call SendControlRequest_NoData
       ;      Claim interface
       ;      Set up interrupt endpoint
       ;      Get "device present?" status of all ports:
       ;             For each connected device, call SetupDevice.
       scf
       ret

RemoveDevice:
;Removes a device that has been disconnected.
;This is either the root device, or a device attached to a hub.
;If it's the root device, we're already no longer powered.
;If it's a device attached to a hub, we need to tell its parent hub to cut power to it.
;We need to remove it from our device list.
;If it's a hub, we also need to remove all of its attached devices.
;Inputs:      A: device ID (or 0 for root device)
;             B: hub port number (or 0 for root device)
;Carry flag set if problems
       scf
       ret

