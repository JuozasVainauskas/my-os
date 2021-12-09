global gdt_load_and_set

KERNEL_CODE_SEGMENT_OFFSET equ 0x08
KERNEL_DATA_SEGMENT_OFFSET equ 0x10

section .text

; load the gdt into the cpu, and enter the kernel segments
gdt_load_and_set:
    xor eax, eax                ; clear register
    mov     eax, [esp+4]        ; move the address of the GDT into the eax register
    lgdt    [eax]               ; load GDT into the processor
    jmp     KERNEL_CODE_SEGMENT_OFFSET:.reload_segments ; load cs segment

.reload_segments:
    mov     ax, KERNEL_DATA_SEGMENT_OFFSET
    mov     ds, ax
    mov     ss, ax
    mov     es, ax
    mov     gs, ax
    mov     fs, ax
    ret