#ifndef ASM_H
#define ASM_H

#include "kintdefs.h"

#define asm_halt() asm volatile("hlt")

void asm_outb(u16 port, u8 value);
u8   asm_inb(u16 port);

#endif // ASM_H