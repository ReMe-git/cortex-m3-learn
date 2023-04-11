ENTRY(Reset_Handler)

_Heap_Size = 0x2800;
_Stack_Size = 0x800;

MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 64K
  SRAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 20K
}

SECTIONS
{
  .text :
  {
    . = ALIGN(4);
    *(.text*)          
    *(.text)           
    *(.rodata)         
    *(.rodata*)        
    . = ALIGN(4);
    _etext = .; 
  } >FLASH

  .ARM.attributes : 
  {
    *(.ARM.attributes) 
  } >FLASH
  
  _sidata = .;
  .data : AT (_sidata)
  {
    . = ALIGN(4);
    _sdata = .;        
    *(.data)           
    *(.data*)         
    . = ALIGN(4);
    _edata = .; 
  } >SRAM

  . = ALIGN(4);
  .bss :
  {
    _sbss = .;
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _ebss = .; 
    __bss_end__ = _ebss;
  } >SRAM
  
  . = ALIGN(4);
  .heap_stack :
  {
    . = ALIGN(4);
    _Heap_Base = .;
    . = . +_Heap_Size;
    _Heap_Limit = .;
    . = . +_Stack_Size;
    _Stack_Top = .;
    . = ALIGN(4);
  } >SRAM
}
