#include "PIC.h"

void PIC::Initialize()
{
	Ports::Write(0x20, 0x11);
	Ports::Write(0xA0, 0x11);
	Ports::Write(0x21, 0x20);
	Ports::Write(0xA1, 0x28);
	Ports::Write(0x21, 0x04);
	Ports::Write(0xA1, 0x02);
	Ports::Write(0x21, 0x01);
	Ports::Write(0xA1, 0x01);
	Ports::Write(0x21, 0);
	Ports::Write(0xA1, 0);
}

void PIC::MaskIRQ(unsigned char IRQ) {
	unsigned short port;
	unsigned char value;

	if (IRQ < 8) {
		port = 0x21;
	}
	else {
		port = 0xA1;
		IRQ -= 8;
	}

	value = Ports::Read(port) | (1 << IRQ);
	Ports::Write(port, value);
}

void PIC::UnmaskIRQ(unsigned char IRQ) {
	unsigned short port;
	unsigned char value;

	if (IRQ < 8) {
		port = 0x21;
	}
	else {
		port = 0xA1;
		IRQ -= 8;
	}

	value = Ports::Read(port) & ~(1 << IRQ);
	Ports::Write(port, value);
}

void PIC::EOI(bool IsSlave)
{
	if (IsSlave)
	{
		Ports::Write(0xA0, 0x20);
	}
	
	Ports::Write(0x20, 0x20);
}