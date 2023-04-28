#pragma once

class MMU
{
public:
	MMU();
	MMU(unsigned long AddressSpace, unsigned long MapAddress, long unsigned int Bytes, bool FastAllocation = false);
	long unsigned int GetUsedAmount();
};