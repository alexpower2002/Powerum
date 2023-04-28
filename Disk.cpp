#include "Disk.h"

unsigned char* Disk::ReadSectors(unsigned long LBA, unsigned long Count, unsigned char* Buffer)
{
	if (Buffer == 0)
	{
		Buffer = new unsigned char[512 * Count]();
	}
	
	unsigned long Index = 0;

	while (Index < Count)
	{
		Operate(LBA + Index, Buffer + Index * 512, 1);

		Index++;
	}

	return Buffer;
}

void Disk::WriteSectors(unsigned long LBA, unsigned long Count, unsigned char* Buffer)
{
	Operate(LBA, Buffer, Count, true);
}

void Disk::Operate(unsigned long LBA, unsigned char* Sectors, unsigned long Count, bool Write)
{
	Ports::Write(0x1F6, (LBA >> 24) | 0xE0);

	Ports::Write(0x1F2, Count);

	Ports::Write(0x1F3, LBA);
	Ports::Write(0x1F4, LBA >> 8);
	Ports::Write(0x1F5, LBA >> 16);

	if (Write)
	{
		Ports::Write(0x1F7, 0x30);
	}
	else
	{
		Ports::Write(0x1F7, 0x20);
	}

	while (!(Ports::Read(0x1F7) & 8));

	Ports::ReadWordRepeat(0x1F0, 256 * Count, (unsigned long)Sectors);
}