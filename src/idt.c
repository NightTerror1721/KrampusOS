#include "idt.h"

#define IDT_SIZE 256

struct idt_entry {
    u16 base_low;
    u16 sel;
    u8 always0;
    u8 flags;
    u16 base_high;
} __attribute__((packed));

struct idt_ptr {
    u16 limit;
    u32 base;
} __attribute__((packed));

extern void idt_load(u32);

static struct idt_entry idt[IDT_SIZE];
static struct idt_ptr idtp;

static void idt_memset(void* dest, u8 val, u32 len)
{
    u8* ptr = (u8*)dest;
    for (u32 i = 0; i < len; i++)
        ptr[i] = val;
}

void idt_set_gate(u8 num, u32 base, u16 sel, u8 flags)
{
    idt[num].base_low = (u16)(base & 0xFFFF);
    idt[num].sel = sel;
    idt[num].always0 = 0;
    idt[num].flags = flags;
    idt[num].base_high = (u16)((base >> 16) & 0xFFFF);
}

void idt_init(void)
{
    idtp.limit = (sizeof(struct idt_entry) * IDT_SIZE) - 1;
    idtp.base = (u32)&idt;

    idt_memset(&idt, 0, sizeof(struct idt_entry) * IDT_SIZE);

    idt_load((u32)&idtp);
}
