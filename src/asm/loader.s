global loader
global outb

extern kmain

MAGIC_NUMBER equ 0x1BADB002     ; ensures GRUB that it is jumping into an OS
FLAGS        equ 0x0            ; multiboot flags
CHECKSUM     equ -MAGIC_NUMBER  ; magic number + flags + checksum should equal 0
                                ; Value standards: https://www.gnu.org/software/grub/manual/multiboot/multiboot.html
KERNEL_STACK_SIZE equ 4096

section .bss
align 4
kernel_stack:
    resb KERNEL_STACK_SIZE

section .text:
align 4
    dd MAGIC_NUMBER
    dd FLAGS
    dd CHECKSUM

loader:
    mov esp, kernel_stack + KERNEL_STACK_SIZE
    call kmain

.loop:
    jmp .loop
