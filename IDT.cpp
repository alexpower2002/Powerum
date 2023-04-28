#include "IDT.h"

void IDT::SetInterruptHandler(unsigned char Interrupt, unsigned long Handler, unsigned char Flags)
{
	Interrupts[Interrupt].OffsetLow = (Handler & 0xFFFF);
	Interrupts[Interrupt].OffsetMiddle = (Handler >> 16) & 0xFFFF;
	Interrupts[Interrupt].OffsetHigh = (Handler >> 32) & 0xFFFFFFFF;

	Interrupts[Interrupt].Selector = 0x8;
	Interrupts[Interrupt].Zero = 0;
	Interrupts[Interrupt].Flags = Flags;
	Interrupts[Interrupt].Reserved = 0;
}