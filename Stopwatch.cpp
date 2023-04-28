#include "Stopwatch.h"

Stopwatch::Stopwatch()
{

}

void Stopwatch::Start()
{
	Timestamp = GetTimestamp();
}

void Stopwatch::Stop()
{
	Elapsed = GetTimestamp() - Timestamp;
}

unsigned long Stopwatch::GetTimestamp()
{
	unsigned long lo, hi;

	_asm("rdtsc" : "=a" (lo), "=d" (hi));

	return(lo | (hi << 32));
}