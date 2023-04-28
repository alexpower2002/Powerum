#pragma once

#include "Stopwatch.h"

class Random
{
public:
	int Seed;
	Random();
	Random(int s);
	int Next(int Start, int End);
};