#include "Ports.h"

unsigned char Ports::Read(unsigned short Port)
{
	unsigned char Result;

	_asm("in %0, %1":: "a" (Result), "d" (Port));

	return Result;
}

void Ports::Write(unsigned short Port, unsigned char Value)
{
	_asm("out %1, %0":: "a" (Value), "d" (Port));
}

unsigned short Ports::ReadWord(unsigned short Port)
{
	unsigned short Result;

	_asm("in %0, %1":: "a" (Result), "d" (Port));

	return Result;
}

unsigned int Ports::ReadInt(unsigned short Port)
{
    unsigned int Result;

    _asm("in %0, %1":: "a" (Result), "d" (Port));

    return Result;
}

void Ports::WriteWord(unsigned short Port, unsigned short Value)
{
	_asm("out %1, %0":: "a" (Value), "d" (Port));
}

void Ports::WriteInt(unsigned short Port, unsigned int Value)
{
    _asm("out %1, %0":: "a" (Value), "d" (Port));
}

void Ports::ReadRepeat(unsigned short Port, unsigned long Count, unsigned long Address)
{
	_asm("rep insb": "+c" (Count) : "d" (Port), "D" (Address));
}

void Ports::WriteRepeat(unsigned short Port, unsigned long Count, unsigned long Address)
{
	_asm("rep outsb": "+c" (Count) : "d" (Port), "D" (Address));
}

void Ports::ReadWordRepeat(unsigned short Port, unsigned long Count, unsigned long Address)
{
	_asm("rep insw": "+c" (Count): "d" (Port), "D" (Address));
}

void Ports::WriteWordRepeat(unsigned short Port, unsigned long Count, unsigned long Address)
{
	_asm("rep outsw": "+c" (Count) : "d" (Port), "D" (Address));
}