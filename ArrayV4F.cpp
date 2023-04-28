#include "ArrayV4F.h"

ArrayV4F::ArrayV4F()
{
	Values = Array<float>();
}

ArrayV4F::ArrayV4F(int Count)
{
	Values = Array<float>(Count);
}

ArrayV4F& ArrayV4F::operator*=(ArrayV4F& mul)
{
	_asm("");
	
	return *this;
}

ArrayV4F& ArrayV4F::operator*=(float mul)
{
	_asm("");

	return *this;
}