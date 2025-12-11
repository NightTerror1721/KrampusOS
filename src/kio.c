#include "kio.h"
#include <stdarg.h>

static void print_decimal(int value)
{
    if (value == 0)
    {
        console_putchar('0');
        return;
    }

    if (value < 0)
    {
        console_putchar('-');
        value = -value;
    }

    char buffer[10];
    int i = 0;

    while (value > 0)
    {
        buffer[i++] = (value % 10) + '0';
        value /= 10;
    }

    while (i--)
        console_putchar(buffer[i]);
}

static void print_unsigned_decimal(unsigned int value)
{
    if (value == 0)
    {
        console_putchar('0');
        return;
    }

    char buffer[10];
    int i = 0;

    while (value > 0)
    {
        buffer[i++] = (value % 10) + '0';
        value /= 10;
    }

    while (i--)
        console_putchar(buffer[i]);
}

static void print_hex(unsigned int value)
{
    static const char hex_chars[] = "0123456789abcdef";
    char buffer[8];
    int i = 0;

    if (value == 0)
    {
        console_putchar('0');
        return;
    }

    while (value > 0)
    {
        buffer[i++] = hex_chars[value & 0xF];
        value >>= 4;
    }

    while (i--)
        console_putchar(buffer[i]);
}


void printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    for (int i = 0; fmt[i] != '\0'; i++)
    {
        if (fmt[i] != '%')
            console_putchar(fmt[i]);
        else
        {
            char f = fmt[++i];
            switch (f)
            {
                case 'c':
                    console_putchar((char)va_arg(args, int));
                    break;

                case 's':
                    console_print(va_arg(args, const char*));
                    break;
                
                case 'd':
                    print_decimal(va_arg(args, int));
                    break;

                case 'u':
                    print_unsigned_decimal(va_arg(args, unsigned int));
                    break;
                
                case 'x':
                    print_hex(va_arg(args, unsigned int));
                    break;

                case '%':
                    console_putchar('%');
                    break;

                default:
                    console_putchar('%');
                    console_putchar(f);
                    break;
            }
        }
    }

    va_end(args);
}
