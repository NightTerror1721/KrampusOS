#include "console.h"
#include "asm.h"

#define VGA_MEMORY 0xB8000
#define VGA_WIDTH 80
#define VGA_HEIGHT 25

#define vga_entry(c, color) ((u16)(c) | ((u16)(color) << 8))

static u16* vga_buffer = (u16*)VGA_MEMORY;

static u8 console_color = 0x07; // Light grey on black
static u16 cursor_row = 0;
static u16 cursor_column = 0;


static void console_clear_without_update_cursor(void)
{
    for (u16 y = 0; y < VGA_HEIGHT; y++)
        for (u16 x = 0; x < VGA_WIDTH; x++)
            vga_buffer[y * VGA_WIDTH + x] = vga_entry(' ', console_color);

    cursor_row = 0;
    cursor_column = 0;
}

void console_init(void)
{
    console_clear_without_update_cursor();
    console_enable_cursor(0, 15);
    console_update_cursor();
}

void console_clear(void)
{
    console_clear_without_update_cursor();
    console_update_cursor();
}

void console_putchar(int c)
{
    if (c == '\n')
    {
        console_newline();
        console_update_cursor();
        return;
    }

    if (c == '\b')
    {
        if (cursor_column > 0)
            cursor_column--;
        else if (cursor_row > 0)
        {
            cursor_row--;
            cursor_column = VGA_WIDTH - 1;
        }

        vga_buffer[cursor_row * VGA_WIDTH + cursor_column] = vga_entry(' ', console_color);
        console_update_cursor();
        return;
    }

    vga_buffer[cursor_row * VGA_WIDTH + cursor_column] = vga_entry(c, console_color);
    cursor_column++;

    if (cursor_column >= VGA_WIDTH)
        console_newline();

    console_update_cursor();
}

void console_print(const char* str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
        console_putchar(str[i]);
}

void console_newline(void)
{
    cursor_column = 0;

    if (cursor_row + 1 < VGA_HEIGHT)
        cursor_row++;
    else
    {
        // Scroll up
        for (u16 y = 1; y < VGA_HEIGHT; y++)
            for (u16 x = 0; x < VGA_WIDTH; x++)
                vga_buffer[(y - 1) * VGA_WIDTH + x] = vga_buffer[y * VGA_WIDTH + x];

        // Clear the last line
        for (u16 x = 0; x < VGA_WIDTH; x++)
            vga_buffer[(VGA_HEIGHT - 1) * VGA_WIDTH + x] = vga_entry(' ', console_color);
    }
}

void console_set_color(console_color_t color)
{
    console_color = (u8)color;
}

console_color_t console_get_color(void)
{
    return (console_color_t)console_color;
}


void console_enable_cursor(u8 start, u8 end)
{
    asm_outb(0x3D4, 0x0A);
    asm_outb(0x3D5, (asm_inb(0x3D5) & 0xC0) | start);
    asm_outb(0x3D4, 0x0B);
    asm_outb(0x3D5, (asm_inb(0x3D5) & 0xE0) | end);
}

void console_disable_cursor(void)
{
    asm_outb(0x3D4, 0x0A);
    asm_outb(0x3D5, asm_inb(0x3D5) | 0x20);
}

void console_update_cursor(void)
{
    u16 pos = cursor_row * VGA_WIDTH + cursor_column;

    asm_outb(0x3D4, 0x0F);
    asm_outb(0x3D5, (u8)(pos & 0xFF));
    asm_outb(0x3D4, 0x0E);
    asm_outb(0x3D5, (u8)((pos >> 8) & 0xFF));
}
