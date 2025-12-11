#ifndef IRQ_H
#define IRQ_H

void irq_init(void);
void irq_handler(int irq, int error_code);

#endif // IRQ_H