#include "pic.h"
#include "asm.h"

#define PIC1 0x20               // IO base address for master PIC
#define PIC2 0xA0               // IO base address for slave PIC

#define PIC1_COMMAND PIC1       // Command port for master PIC
#define PIC1_DATA    (PIC1 + 1) // Data port for master PIC
#define PIC2_COMMAND PIC2       // Command port for slave PIC
#define PIC2_DATA    (PIC2 + 1) // Data port for slave PIC

#define PIC_EOI 0x20              // End-of-interrupt command code

void pic_remap(u8 offset1, u8 offset2)
{
    u8 a1, a2;

    a1 = asm_inb(PIC1_DATA); // Save masks
    a2 = asm_inb(PIC2_DATA);

    asm_outb(PIC1_COMMAND, 0x11); // Start initialization
    asm_outb(PIC2_COMMAND, 0x11);

    asm_outb(PIC1_DATA, offset1); // Set vector offset for master PIC
    asm_outb(PIC2_DATA, offset2); // Set vector offset for slave PIC

    asm_outb(PIC1_DATA, 0x04); // Tell master PIC about slave at IRQ2
    asm_outb(PIC2_DATA, 0x02); // Tell slave PIC its cascade identity

    asm_outb(PIC1_DATA, 0x01); // Set 8086/88 mode
    asm_outb(PIC2_DATA, 0x01); // Set 8086/88 mode

    asm_outb(PIC1_DATA, a1); // Restore saved masks
    asm_outb(PIC2_DATA, a2);
}

void pic_send_eoi(u8 irq)
{
    if (irq >= 8)
        asm_outb(PIC2_COMMAND, PIC_EOI); // Send EOI to slave PIC
    asm_outb(PIC1_COMMAND, PIC_EOI);     // Send EOI to master PIC
}
