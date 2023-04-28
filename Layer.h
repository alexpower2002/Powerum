#pragma once

#include "ArrayV4F.h"

class Layer
{
	ArrayV4F Biases;
	ArrayV4F BiasesDelta;
	ArrayV4F Gradients;
	ArrayV4F Values;

	ArrayV4F TempValues;
	ArrayV4F TempValues0;


};