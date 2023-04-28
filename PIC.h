#pragma once

#include "Ports.h"

class PIC
{
public:
	static void Initialize();
	static void EOI(bool IsSlave = false);
	static void MaskIRQ(unsigned char IRQ);
	static void UnmaskIRQ(unsigned char IRQ);
};