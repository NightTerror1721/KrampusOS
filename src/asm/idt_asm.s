/* idt_asm.s */
.section .text
.global idt_load

idt_load:
    mov 4(%esp), %eax  ; # Load the address of the IDT pointer into EAX
    lidt (%eax)        ; # Load the IDT using the lidt instruction
    ret
