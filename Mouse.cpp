#include "Mouse.h"

unsigned char Cycle;
char Byte[3];
char X;
char Y;

extern "C" void mouse_handler()
{
	switch (Cycle)
	{
	case 0:
		Byte[0] = Ports::Read(0x60);
		Cycle++;
		break;
	case 1:
		Byte[1] = Ports::Read(0x60);
		Cycle++;
		break;
	case 2:
		Byte[2] = Ports::Read(0x60);
		X = Byte[1];
		Y = Byte[2];
		Cycle = 0;
		break;
	}

	PIC::EOI(true);
}

inline void Mouse::Wait(unsigned char a_type)
{
	unsigned int _time_out = 100000; //unsigned int
	if (a_type == 0)
	{
		while (_time_out--) //Data
		{
			if ((Ports::Read(0x64) & 1) == 1)
			{
				return;
			}
		}
		return;
	}
	else
	{
		while (_time_out--) //Signal
		{
			if ((Ports::Read(0x64) & 2) == 0)
			{
				return;
			}
		}
		return;
	}
}

inline void Mouse::Write(unsigned char a_write)
{
	//Wait to be able to send a command
	Wait(1);
	//Tell the mouse we are sending a command
	Ports::Write(0x64, 0xD4);
	//Wait for the final part
	Wait(1);
	//Finally write
	Ports::Write(0x60, a_write);
}

inline unsigned char Mouse::Read()
{
	Wait(0);

	return Ports::Read(0x60);
}

void Mouse::Initialize()
{
	unsigned char _status;

	Cycle = 0;

	Byte[0] = 0;
	Byte[1] = 0;
	Byte[2] = 0;

	X = 0;
	Y = 0;

	Wait(1);
	Ports::Write(0x64, 0xA8);

	Wait(1);
	Ports::Write(0x64, 0x20);
	Wait(0);
	_status = (Ports::Read(0x60) | 2);
	Wait(1);
	Ports::Write(0x64, 0x60);
	Wait(1);
	Ports::Write(0x60, _status);

	Write(0xF6);
	Read();

	Write(0xF4);
	Read();
}

Point Mouse::GetPosition()
{
	return Point{ X,Y };
}