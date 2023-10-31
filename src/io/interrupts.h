#ifndef INTERRUPTS_H
# define INTERRUPTS_H

#include "idt.h"

struct interrupt_frame;
__attribute__((interrupt)) void GenericExceptionHandler(struct interrupt_frame *frame);

void	init_interrupts();

#endif