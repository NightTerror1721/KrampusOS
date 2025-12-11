/* isr_stub.s */
.section .text

.global isr0
.global isr1
.global isr2
.global isr3
.global isr4
.global isr5
.global isr6
.global isr7
.global isr8
.global isr9
.global isr10
.global isr11
.global isr12
.global isr13
.global isr14
.global isr15
.global isr16
.global isr17
.global isr18
.global isr19
.global isr20
.global isr21
.global isr22
.global isr23
.global isr24
.global isr25
.global isr26
.global isr27
.global isr28
.global isr29
.global isr30
.global isr31


isr0:
    cli
    pushl $0
    pushl $0
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr1:
    cli
    pushl $0
    pushl $1
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr2:
    cli
    pushl $0
    pushl $2
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr3:
    cli
    pushl $0
    pushl $3
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr4:
    cli
    pushl $0
    pushl $4
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr5:
    cli
    pushl $0
    pushl $5
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr6:
    cli
    pushl $0
    pushl $6
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr7:
    cli
    pushl $0
    pushl $7
    call isr_handle_exception
    add $8, %esp
    sti
    iret


isr8:
    cli
    pushl $0
    pushl $8
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr9:
    cli
    pushl $0
    pushl $9
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr10:
    cli
    pushl $0
    pushl $10
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr11:
    cli
    pushl $0
    pushl $11
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr12:
    cli
    pushl $0
    pushl $12
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr13:
    cli
    pushl $0
    pushl $13
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr14:
    cli
    pushl $0
    pushl $14
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr15:
    cli
    pushl $0
    pushl $15
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr16:
    cli
    pushl $0
    pushl $16
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr17:
    cli
    pushl $0
    pushl $17
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr18:
    cli
    pushl $0
    pushl $18
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr19:
    cli
    pushl $0
    pushl $19
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr20:
    cli
    pushl $0
    pushl $20
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr21:
    cli
    pushl $0
    pushl $21
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr22:
    cli
    pushl $0
    pushl $22
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr23:
    cli
    pushl $0
    pushl $23
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr24:
    cli
    pushl $0
    pushl $24
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr25:
    cli
    pushl $0
    pushl $25
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr26:
    cli
    pushl $0
    pushl $26
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr27:
    cli
    pushl $0
    pushl $27
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr28:
    cli
    pushl $0
    pushl $28
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr29:
    cli
    pushl $0
    pushl $29
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr30:
    cli
    pushl $0
    pushl $30
    call isr_handle_exception
    add $8, %esp
    sti
    iret

isr31:
    cli
    pushl $0
    pushl $31
    call isr_handle_exception
    add $8, %esp
    sti
    iret
    