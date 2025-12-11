#ifndef IDT_H
#define IDT_H

#include "kintdefs.h"

void idt_init(void);
void idt_set_gate(u8 num, u32 base, u16 sel, u8 flags);

#endif // IDT_H