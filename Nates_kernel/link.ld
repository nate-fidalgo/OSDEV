OUTPUT_FORMAT("binary")
ENTRY(start)
phys = 0x00001000;
SECTIONS
{
  .text phys : AT(phys) {
    code = .;
	startitup.o (.text);
    sound.o (.text);
    . = ALIGN(4096);
  }
  .data : AT(phys + (data - code))
  {
    data = .;
    *(.data)
    . = ALIGN(4096);
  }
  .bss : AT(phys + (bss - code))
  {
    bss = .;
    *(.bss)
    . = ALIGN(4096);
  }
  end = .;
}
