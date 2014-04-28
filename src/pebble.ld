
ENTRY(main)

MEMORY
{
  APP (rwx) : ORIGIN = 0, LENGTH = 24K
}

SECTIONS
{
    .header :
    {
        KEEP(*(.pbl_header))
    } > APP

    .text :
    {
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata*)
    } > APP

    .data :
    {
        KEEP(*(.data))
        *(.data.*)
    } > APP

    .bss :
    {
        *(.bss)
        *(.bss.*)
    } > APP

    PROVIDE (foo = .);
    OVERLAY : NOCROSSREFS
    {
      .foo_v0 { *(.s_foo_v0) }
      .foo_v1 { *(.s_foo_v1) }
      .foo_v2 { *(.s_foo_v2) }
    }

    DISCARD :
    {
        libc.a ( * )
        libm.a ( * )
        libgcc.a ( * )
        *(.eh_frame)
    }
}

