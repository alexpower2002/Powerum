#include "Sigmoid.h"

double Sigmoid::Output(double x)
{
	return x < -45.0 ? 0.0 : x > 45.0 ? 1.0 : 1.0 / (1.0 + Math::exp(-x));
}

double Sigmoid::Derivative(double x)
{
	return x * (1 - x);
}