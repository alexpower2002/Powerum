#pragma once

#include "Array.h"

class DataSet
{
public:
	Array<float> Values;
	Array<float> Targets;

	DataSet(Array<float> vin, Array<float> vout);
};