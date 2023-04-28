#include "Random.h"

Random::Random()
{
	Stopwatch sw = Stopwatch();

	sw.Start();
	sw.Stop();

	Seed = sw.Elapsed;
}

Random::Random(int s)
{
	Seed = s;
}

int Random::Next(int Start, int End)
{
	Seed = (1103515245 * Seed + 12345) % 0x80000000;

	return Start + (Seed % (End - Start + 1));
}