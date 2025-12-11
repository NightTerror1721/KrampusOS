#ifndef KEYBOARD_H
#define KEYBOARD_H

void keyboard_init(void);
void keyboard_handler(void);

/**
 * Reads a character from the keyboard buffer.
 * This function blocks until a character is available.
 */
char keyboard_read_char(void);

#endif // KEYBOARD_H