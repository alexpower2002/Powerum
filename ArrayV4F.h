#pragma once

#include "Array.h"

class ArrayV4F
{
	Array<float> Values;

	ArrayV4F();
	ArrayV4F(int Count);

	ArrayV4F& operator*=(ArrayV4F& mul);
	ArrayV4F& operator*=(float mul);
};