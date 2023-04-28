#pragma once

#include "RGB.h"
#include "Rectangle.h"
#include "List.h"

class UIView
{
public:
	UIView();
	UIView(RGB Color);
	void Initialize(int w, int h, Point start);
	virtual void Draw();
	int Width;
	int Height;
	Point Position;
	RGB BackgroundColor;
};