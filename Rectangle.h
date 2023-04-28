#pragma once

#include "Point.h"
#include "RGB.h"
#include "Display.h"
#include "Math.h"

struct Rectangle
{
	Point LTCorner;
	Point RBCorner;
	int Rounding;
	RGB Color;
	Rectangle(Point Corner1, Point Corner2, RGB RectColor, int Rounding = 0);
	void Draw();
};