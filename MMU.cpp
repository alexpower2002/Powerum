#include "MMU.h"

unsigned long Address;
unsigned long* Map;
long unsigned int PoolSize;
long signed int Used;
bool IsFastAllocationEnabled;
unsigned long FastAllocationAddress;

MMU::MMU()
{

}

MMU::MMU(unsigned long AddressSpace, unsigned long BitmapAddress, long unsigned int Bytes, bool FastAllocation)
{
	Address = AddressSpace;
	Map = (unsigned long*)BitmapAddress;
	PoolSize = Bytes / 8;
	IsFastAllocationEnabled = FastAllocation;
	FastAllocationAddress = AddressSpace;

	if (!IsFastAllocationEnabled)
	{
		for (long unsigned int i = 0; i < PoolSize; i++)
		{
			Map[i] = 0;
		}
	}

	Used = 0;
}

long unsigned int MMU::GetUsedAmount()
{
	return Used;
}

void* operator new(long unsigned int Size)
{
	if (IsFastAllocationEnabled)
	{
		unsigned long FreeSpace = FastAllocationAddress;

		FastAllocationAddress += Size;

		Used += Size;

		return (void*)(FreeSpace);
	}

	long unsigned int Length = 0;

	long unsigned int ByteIndex = 0;

	unsigned char BitIndex = 0;

	long unsigned int FreeByte = 0;
	unsigned char FreeBit = 0;

	while (ByteIndex != PoolSize)
	{
		if (!(Map[ByteIndex] & (1 << BitIndex)))
		{
			if (Length == 0)
			{
				FreeByte = ByteIndex;
				FreeBit = BitIndex;

				Length++;
			}
			else
			{
				if (Length == Size)
				{
					long unsigned int TempByte = FreeByte;
					long unsigned int TempBit = FreeBit;

					for (long unsigned int i = 0; i < Size; i++)
					{
						Map[TempByte] |= 1 << TempBit;

						if (TempBit == 63)
						{
							TempByte++;
							TempBit = 0;
						}
						else
						{
							TempBit++;
						}
					}

					Used += Size;

					return (void*)(Address + (FreeByte * 64) + FreeBit);
				}
				else
				{
					Length++;
				}
			}
		}
		else
		{
			Length = 0;
		}

		if (BitIndex == 63)
		{
			ByteIndex++;
			BitIndex = 0;
		}
		else
		{
			BitIndex++;
		}
	}

	return (void*)0;
}

void* operator new[](long unsigned int Size)
{
	long unsigned int* ArrayWithSize = (long unsigned int*)operator new(Size + 8);
	
	ArrayWithSize[0] = Size;

	return (void*)(ArrayWithSize + 1);
}

void operator delete(void* Object, long unsigned int Size)
{
	if (IsFastAllocationEnabled)
	{
		//Used -= Size;

		return;
	}

	long unsigned int ByteIndex = (((long unsigned int)Object) - Address) / 64;
	unsigned char BitIndex = (((long unsigned int)Object) - Address) % 64;

	for (long unsigned int i = 0; i < Size; i++)
	{
		Map[ByteIndex] &= ~(1 << BitIndex);

		if (BitIndex == 63)
		{
			ByteIndex++;
			BitIndex = 0;
		}
		else
		{
			BitIndex++;
		}
	}

	Used -= Size;
}

void operator delete[](void* Object)
{
	long unsigned int* ArrayWithSize = ((long unsigned int*)Object) - 1;

	operator delete((void*)ArrayWithSize, ArrayWithSize[0] + 8);
}

void operator delete[](void* Object, long unsigned int)
{
	long unsigned int* ArrayWithSize = ((long unsigned int*)Object) - 1;

	operator delete((void*)ArrayWithSize, ArrayWithSize[0] + 8);
}