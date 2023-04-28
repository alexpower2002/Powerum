#pragma once

#include "Ports.h"
#include "PIC.h"
#include "Point.h"

class Mouse
{
public:
	static void Initialize();
	static void Wait(unsigned char a_type);
	static void Write(unsigned char a_write);
	static unsigned char Read();
	static Point GetPosition();
};