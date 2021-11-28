global outb

outb:
    mov al, [esp + 8]    ; type of byte command
    mov dx, [esp + 4]    ; cursor address
    out dx, al           ; send the cursor address to the I/O port
    ret
