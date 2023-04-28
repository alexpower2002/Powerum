#pragma once

#include "UIView.h"

class UIGrid: public UIView
{
public:
	UIGrid(List<UIView> v, List<int> fr, bool ishoriz = true);
	List<UIView> Views;
	List<int> Fractions;
	bool IsHorizontal;
	void Draw() override;
};