#ifndef ISR_H
#define ISR_H

#include "kintdefs.h"

void isr_init(void);
void isr_handle_exception(u8 int_no, u32 err_code);

#endif // ISR_H