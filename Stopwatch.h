#pragma once

class Stopwatch
{
public:
	Stopwatch();
	unsigned long Timestamp;
	unsigned long Elapsed;
	void Start();
	void Stop();
	unsigned long GetTimestamp();
};
