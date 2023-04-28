#pragma once

#include "String.h"
#include "RGB.h"
#include "Point.h"

class Display
{
public:
	static void SetPixel(Point Location, RGB Color);
	static RGB GetPixel(Point Location);
	static void ClearScreen(RGB Color);
	static RGB AlphaBlend(RGB c1, RGB c2, double a);
};