#pragma once

#include "Ports.h"

class Disk
{
public:
	static unsigned char* ReadSectors(unsigned long LBA, unsigned long Count, unsigned char* Buffer = 0);
	static void WriteSectors(unsigned long LBA, unsigned long Count, unsigned char* Buffer);
private:
	static void Operate(unsigned long LBA, unsigned char* Sectors, unsigned long Count, bool Write = false);
};