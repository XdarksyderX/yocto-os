org 0x7C00
bits 16

%define ENDL 0x0D, 0x0A

start:
    jmp main

puts:
    push si
    push ax
    mov bh, 0

.loop
    lodsb
    or al, al
    jz .done
    mov ah, 0x0E 
    int 10h
    jmp .loop

.done:
    pop ax
    pop si
    ret

main:
    mov ax, 0x0000
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov si, msg_hello
    call puts

    hlt

.halt:
    jmp .halt

msg_hello: db "Hello, World!", ENDL, 0

times 510-($-$$) db 0
dw 0xAA55