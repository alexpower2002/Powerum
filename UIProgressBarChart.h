#pragma once

#include "UIView.h"

class UIProgressBarChart: public UIView
{
public:
	UIProgressBarChart(List<double> fr, List<RGB> c);
	List<RGB> Colors;
	List<double> Fractions;
	void Draw() override;
};