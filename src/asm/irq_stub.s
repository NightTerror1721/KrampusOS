/* irq_stubs.s */
.section .text
.extern irq_handler

.macro IRQ n
.global irq\n
irq\n:
    cli
    pushl $0        # Push error code (0 for IRQs)
    pushl $\n       # Push IRQ number
    call irq_handler
    add $8, %esp    # Clean up the stack
    sti
    iret
.endm

IRQ 0
IRQ 1
IRQ 2
IRQ 3
IRQ 4
IRQ 5
IRQ 6
IRQ 7
IRQ 8
IRQ 9
IRQ 10
IRQ 11
IRQ 12
IRQ 13
IRQ 14
IRQ 15
