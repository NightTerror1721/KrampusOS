#include "console.h"
#include "kio.h"
#include "asm.h"
#include "isr.h"
#include "idt.h"
#include "irq.h"
#include "pic.h"
#include "keyboard.h"

void kmain(void)
{
    console_init();

    printf("Welcome to KrampusOS!\n");

    printf("Initializing IDT...\n");
    idt_init();

    printf("Initializing ISRs...\n");
    isr_init();

    printf("Remapping PIC...\n");
    pic_remap(0x20, 0x28);

    printf("Initializing IRQs...\n");
    irq_init();
    keyboard_init();

    printf("System initialization complete.\n");

    printf("Activating interrupts...\n");
    __asm__ __volatile__("sti");

    printf("You can start typing on the keyboard:\n");
    while (1)
    {
        char c = keyboard_read_char();
        console_putchar(c);
    }
}