#include "DataSet.h"

DataSet::DataSet(Array<float> vin, Array<float> vout)
{
	Values = vin;
	Targets = vout;
}