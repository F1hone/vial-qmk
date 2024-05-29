# This file intentionally left blank
DFU_SUFFIX_ARGS = -p FFFF -v FFFF
BOOTLOADER=stm32duino
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE 
NO_USB_STARTUP_CHECK = yes  
WAIT_FOR_USB = yes 