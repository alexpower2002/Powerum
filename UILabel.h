#pragma once

#include "Display.h"
#include "RGB.h"
#include "Point.h"
#include "UIView.h"
#include "FileSystem.h"
#include "Dictionary.h"
#include "Character.h"

class UILabel: public UIView
{
public:
	UILabel(Point p, char* t, int s = 0);
	char* Text;
	int Spacing;
	void Draw() override;
};