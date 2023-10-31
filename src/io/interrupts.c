#include "interrupts.h"
#include "../printer/kernel_printer.h"
#include "../memory/memory.h"

struct idtr idtr;

__attribute__((interrupt)) void GenericException_Handler(struct interrupt_frame* frame) {
    (void)frame;
    printf("GenericException_Handler\n");
    while(1);
}

__attribute__((interrupt)) void PageFaultException_Handler(struct interrupt_frame* frame)
{
	(void)frame;
	printf("PageFaultException_Handler\n");
	while(1);

}
__attribute__((interrupt)) void DoubleFault_Handler(struct interrupt_frame* frame)
{
	(void)frame;
	printf("DoubleFault_Handler\n");
	while(1);
}



void	set_idt_gate(uint64_t handler, uint8_t entry_offset, uint8_t type_attr, uint8_t selector)
{
	struct idt_descriptor_entry *interrupt = (struct idt_descriptor_entry *) (idtr.offset + entry_offset * sizeof(struct idt_descriptor_entry));
	memset(interrupt, 0, sizeof(struct idt_descriptor_entry));
	set_offset(interrupt, handler);
	interrupt->type_attributes = type_attr;
	interrupt->selector = selector;
}


void	init_interrupts()
{
	__asm__("cli");

	idtr.limit = 256 * sizeof(struct idt_descriptor_entry) - 1;
	idtr.offset = (uint64_t) request_page();
	memset((void *) idtr.offset, 0, 256 * sizeof(struct idt_descriptor_entry));
	for (uint16_t i = 0; i < 256; i++)
		set_idt_gate((uint64_t) GenericException_Handler, i, IDT_TA_InterruptGate, 0x28);
	set_idt_gate((uint64_t) PageFaultException_Handler, 0x0E, IDT_TA_InterruptGate, 0x28);
	set_idt_gate((uint64_t) DoubleFault_Handler, 0x08, IDT_TA_InterruptGate, 0x28);
	__asm__ volatile ("lidt %0" : : "m" (idtr));

	__asm__("sti");
}