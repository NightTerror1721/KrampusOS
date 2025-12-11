#include "keyboard.h"
#include "kio.h"
#include "irq.h"
#include "asm.h"

#define KBD_BUFFER_SIZE 256

static char kbd_buffer[KBD_BUFFER_SIZE];
static int kbd_buffer_head = 0;
static int kbd_buffer_tail = 0;

static bool shift_pressed = false;

// Simple US QWERTY scancode to ASCII mapping
static const char scancode_to_ascii[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', // 0-9
   '9', '0', '-', '=', '\b', '\t', 'q', 'w', 'e', 'r', // 10-19
   't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n', 0, // 20-29
   'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', // 30-39
  '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', // 40-49
   'm', ',', '.', '/', 0, '*', 0, ' ', 0, 0, // 50-59

    // Remaining scancodes are not mapped
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 60-69
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 70-79
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 80-89
    0, 0, 0, 0, 0, 0, 0, 0 // 90-97
};

// Shifted characters mapping
static const char scancode_shift_to_ascii[128] = {
    0,  27, '!', '@', '#', '$', '%', '^', '&', '*', // 0-9
   '(', ')', '_', '+', '\b', '\t', 'Q', 'W', 'E', 'R', // 10-19
   'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '\n', 0, // 20-29
   'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', // 30-39
   '"', '~', 0, '|', 'Z', 'X', 'C', 'V', 'B', 'N', // 40-49
   'M', '<', '>', '?', 0, '*', 0, ' ', 0, 0, // 50-59

    // Remaining scancodes are not mapped
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 60-69
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 70-79
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, // 80-89
    0, 0, 0, 0, 0, 0, 0, 0 // 90-97
};

static void buffer_push(char c)
{
    int next = (kbd_buffer_head + 1) % KBD_BUFFER_SIZE;
    if (next != kbd_buffer_tail) // Check for buffer overflow
    {
        kbd_buffer[kbd_buffer_head] = c;
        kbd_buffer_head = next;
    }
}


void keyboard_init(void)
{
    // Nothing needed for basic keyboard initialization in this simple OS
}

void keyboard_handler(void)
{
    u8 scancode = asm_inb(0x60); // Read from keyboard data port

    // Key release event
    if (scancode & 0x80)
    {
        scancode &= 0x7F; // Get original scancode
        if (scancode == 42 || scancode == 54) // Shift keys
            shift_pressed = false;
    }

    // Key press event
    else
    {
        if (scancode == 42 || scancode == 54) // Shift keys
        {
            shift_pressed = true;
            return;
        }

        char c = shift_pressed
                ? scancode_shift_to_ascii[scancode]
                : scancode_to_ascii[scancode];

        /*if (c == '\b') // Backspace
        {
            if (kbd_buffer_head != kbd_buffer_tail)
                buffer_push('\b');
        }*/
        if (c != 0) // Valid character
        {
            buffer_push(c);
        }
    }
}

char keyboard_read_char(void)
{
    while (kbd_buffer_head == kbd_buffer_tail)
    {
        // Wait for a character to be available
        asm_halt();
    }

    char c = kbd_buffer[kbd_buffer_tail];
    kbd_buffer_tail = (kbd_buffer_tail + 1) % KBD_BUFFER_SIZE;

    return c;
}
