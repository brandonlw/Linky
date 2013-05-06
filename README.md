Linky
=====

Linky is a Flash application for the TI-84 Plus, TI-84 Plus Silver Edition, and TI-84 Plus C Silver Edition exposing an API (in multiple forms) for other programs and applications to implement USB host and peripheral functionality.

Just build (see building.txt) and transfer it to your calculator of choice. Other programs and applications will be able to see and use it as necessary.

DFU Mode
========

To use DFU (Device Firmware Upgrade) mode, follow these steps:

1. On the calculator, run Flash application LINKYDRV and select 1) Tools, then the appropriate option ("DFU ROM Dump" to upload the ROM to your computer, or "DFU ROM Write" to download the ROM from your computer into the calculator).
2. If on Windows, find zadiag and run it to install the WinUSB driver for the newly-discovered device above (vendor ID 0x0451, product ID 0xDEAD).
2. Download dfu-util for your particular platform -- use option -U for upload, -D for download, -l to list devices.

Dumping the ROM
===============
In LINKYDRV's Tools menu, select 1) DFU ROM Dump, and then choose either to include the certificate with the dump (requires Flash unlocked -- current exploit built into LINKYDRV is unpatched), or not (try this if the first option crashes for you, which would imply the exploit is patched).

Run dfu-util from the command line with: dfu-util -U dump.rom

Wait for it to finish.

Flashing the ROM
================
In LINKYDRV's Tools menu, select 2) DFU ROM Write, and then choose to either write the certificate or ignore it.
IMPORTANT! DO NOT CHOOSE TO WRITE THE CERTIFICATE UNLESS YOU *KNOW* YOUR ROM DUMP INCLUDES A VALID CERTIFICATE!
(Your ROM dump has a valid certificate if you dumped it using the "With Cert" option above, or if you can see your unique calculator ID in the About screen in an emulator.)

Run dfu-util from the command line with: dfu-util -D dump.rom

Wait for it to finish.

Contact
=======
Try brandonlw@gmail.com, brandonw.net, etc.
