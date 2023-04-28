#include "UIView.h"

UIView::UIView()
{

}

UIView::UIView(RGB Color)
{
	BackgroundColor = Color;
}

void UIView::Initialize(int w, int h, Point start)
{
	Width = w;
	Height = h;
	Position = start;
}

void UIView::Draw()
{
	Rectangle rect = Rectangle(Position, Point{ Position.X + Width, Position.Y + Height }, BackgroundColor);

	rect.Draw();
}