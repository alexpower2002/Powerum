#pragma once

struct IDTDescriptor
{
	unsigned short OffsetLow;
	unsigned short Selector;
	unsigned char Reserved;
	unsigned char Flags;
	unsigned short OffsetMiddle;
	unsigned int OffsetHigh;
	unsigned int Zero;
};

class IDT
{
public:
	IDTDescriptor* Interrupts;
	void SetInterruptHandler(unsigned char Interrupt, unsigned long Handler, unsigned char Flags);
};