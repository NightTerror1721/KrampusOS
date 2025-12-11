#ifndef CONSOLE_H
#define CONSOLE_H

#include "kintdefs.h"

typedef enum console_color_t {
    CONSOLE_COLOR_BLACK = 0x0,
    CONSOLE_COLOR_BLUE = 0x1,
    CONSOLE_COLOR_GREEN = 0x2,
    CONSOLE_COLOR_CYAN = 0x3,
    CONSOLE_COLOR_RED = 0x4,
    CONSOLE_COLOR_MAGENTA = 0x5,
    CONSOLE_COLOR_BROWN = 0x6,
    CONSOLE_COLOR_LIGHT_GREY = 0x7,
    CONSOLE_COLOR_DARK_GREY = 0x8,
    CONSOLE_COLOR_LIGHT_BLUE = 0x9,
    CONSOLE_COLOR_LIGHT_GREEN = 0xA,
    CONSOLE_COLOR_LIGHT_CYAN = 0xB,
    CONSOLE_COLOR_LIGHT_RED = 0xC,
    CONSOLE_COLOR_LIGHT_MAGENTA = 0xD,
    CONSOLE_COLOR_YELLOW = 0xE,
    CONSOLE_COLOR_WHITE = 0xF
} console_color_t;

void console_init(void);
void console_clear(void);
void console_putchar(int c);
void console_print(const char* str);
void console_newline(void);
void console_set_color(console_color_t color);
console_color_t console_get_color(void);

void console_enable_cursor(u8 start, u8 end);
void console_disable_cursor(void);
void console_update_cursor(void);

#endif // CONSOLE_H