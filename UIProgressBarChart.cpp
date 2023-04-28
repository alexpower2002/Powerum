#include "UIProgressBarChart.h"

UIProgressBarChart::UIProgressBarChart(List<double> fr, List<RGB> c)
{
	Fractions = fr;
	Colors = c;
}

void UIProgressBarChart::Draw()
{
	Rectangle pbc = Rectangle(Position, Point{ Position.X + Width * Fractions[0], Position.Y + Height }, Colors[0], 5);

	pbc.Draw();
	
	for (int i = 1; i < Fractions.Count - 1; i++)
	{
		pbc.LTCorner.X = pbc.RBCorner.X + 1;
		pbc.RBCorner.X++;
		pbc.Rounding = 0;
		pbc.Color = RGB{ 0xff,0xff,0xff };
		
		pbc.Draw();
		
		pbc.LTCorner.X = pbc.RBCorner.X + 1;
		pbc.RBCorner.X = pbc.LTCorner.X + Width * Fractions[i];
		pbc.Color = Colors[i];

		pbc.Draw();
	}

	pbc.LTCorner.X = pbc.RBCorner.X + 1;
	pbc.RBCorner.X++;
	pbc.Rounding = 0;
	pbc.Color = RGB{ 0xff,0xff,0xff };

	pbc.Draw();

	pbc.LTCorner.X = pbc.RBCorner.X + 1;
	pbc.RBCorner.X = pbc.LTCorner.X + Width * Fractions[Fractions.Count - 1];
	pbc.Color = Colors[Colors.Count - 1];
	pbc.Rounding = 10;

	pbc.Draw();
}