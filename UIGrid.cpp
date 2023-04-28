#include "UIGrid.h"

UIGrid::UIGrid(List<UIView> v, List<int> fr, bool ishoriz)
{
	Views = v;
	Fractions = fr;
	IsHorizontal = ishoriz;
}

void UIGrid::Draw()
{
	double sum = 0;
	Point Offset = Point{ 0,0 };

	for (int i = 0; i < Fractions.Count; i++)
	{
		sum += Fractions[i];
	}

	for (int i = 0; i < Fractions.Count; i++)
	{
		if (IsHorizontal)
		{
			int new_offset = Width * Fractions[i] / sum;

			Views[i].Initialize(new_offset, Height, Offset);

			Offset.X += new_offset;
		}
		else
		{
			int new_offset = Height * Fractions[i] / sum;

			Views[i].Initialize(Width, new_offset, Offset);

			Offset.Y += new_offset;
		}

		Views[i].Draw();
	}
}