#include "Rectangle.h"

Rectangle::Rectangle(Point Corner1, Point Corner2, RGB RectColor, int CornerRounding)
{
	LTCorner = Corner1;
	RBCorner = Corner2;
	Color = RectColor;
	Rounding = CornerRounding;
}

void Rectangle::Draw()
{
	RGB TempStore[40];

	if (Rounding & (1 << 4))
	{
		if (Rounding & (1 << 0))
		{
			TempStore[0] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y });
			TempStore[1] = Display::GetPixel(Point{ LTCorner.X + 1, LTCorner.Y });
			TempStore[2] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y + 1 });
		}

		if (Rounding & (1 << 1))
		{
			TempStore[3] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y });
			TempStore[4] = Display::GetPixel(Point{ RBCorner.X - 1, LTCorner.Y });
			TempStore[5] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y + 1 });
		}

		if (Rounding & (1 << 2))
		{
			TempStore[6] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y });
			TempStore[7] = Display::GetPixel(Point{ LTCorner.X + 1, RBCorner.Y });
			TempStore[8] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y - 1 });
		}

		if (Rounding & (1 << 3))
		{
			TempStore[9] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y });
			TempStore[10] = Display::GetPixel(Point{ RBCorner.X - 1, RBCorner.Y });
			TempStore[11] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y - 1 });
		}
	}
	else
	{
		if (Rounding & (1 << 0))
		{
			TempStore[0] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y });
			TempStore[1] = Display::GetPixel(Point{ LTCorner.X + 1, LTCorner.Y });
			TempStore[2] = Display::GetPixel(Point{ LTCorner.X + 2, LTCorner.Y });
			TempStore[3] = Display::GetPixel(Point{ LTCorner.X + 3, LTCorner.Y });
			TempStore[4] = Display::GetPixel(Point{ LTCorner.X + 4, LTCorner.Y });
			TempStore[5] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y + 1 });
			TempStore[6] = Display::GetPixel(Point{ LTCorner.X + 1, LTCorner.Y + 1 });
			TempStore[7] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y + 2 });
			TempStore[8] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y + 3 });
			TempStore[9] = Display::GetPixel(Point{ LTCorner.X, LTCorner.Y + 4 });
		}

		if (Rounding & (1 << 1))
		{
			TempStore[10] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y });
			TempStore[11] = Display::GetPixel(Point{ RBCorner.X - 1, LTCorner.Y });
			TempStore[12] = Display::GetPixel(Point{ RBCorner.X - 2, LTCorner.Y });
			TempStore[13] = Display::GetPixel(Point{ RBCorner.X - 3, LTCorner.Y });
			TempStore[14] = Display::GetPixel(Point{ RBCorner.X - 4, LTCorner.Y });
			TempStore[15] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y + 1 });
			TempStore[16] = Display::GetPixel(Point{ RBCorner.X - 1, LTCorner.Y + 1 });
			TempStore[17] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y + 2 });
			TempStore[18] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y + 3 });
			TempStore[19] = Display::GetPixel(Point{ RBCorner.X, LTCorner.Y + 4 });
		}

		if (Rounding & (1 << 2))
		{
			TempStore[20] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y });
			TempStore[21] = Display::GetPixel(Point{ LTCorner.X + 1, RBCorner.Y });
			TempStore[22] = Display::GetPixel(Point{ LTCorner.X + 2, RBCorner.Y });
			TempStore[23] = Display::GetPixel(Point{ LTCorner.X + 3, RBCorner.Y });
			TempStore[24] = Display::GetPixel(Point{ LTCorner.X + 4, RBCorner.Y });
			TempStore[25] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y - 1 });
			TempStore[26] = Display::GetPixel(Point{ LTCorner.X + 1, RBCorner.Y - 1 });
			TempStore[27] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y - 2 });
			TempStore[28] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y - 3 });
			TempStore[29] = Display::GetPixel(Point{ LTCorner.X, RBCorner.Y - 4 });
		}

		if (Rounding & (1 << 3))
		{
			TempStore[30] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y });
			TempStore[31] = Display::GetPixel(Point{ RBCorner.X - 1, RBCorner.Y });
			TempStore[32] = Display::GetPixel(Point{ RBCorner.X - 2, RBCorner.Y });
			TempStore[33] = Display::GetPixel(Point{ RBCorner.X - 3, RBCorner.Y });
			TempStore[34] = Display::GetPixel(Point{ RBCorner.X - 4, RBCorner.Y });
			TempStore[35] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y - 1 });
			TempStore[36] = Display::GetPixel(Point{ RBCorner.X - 1, RBCorner.Y - 1 });
			TempStore[37] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y - 2 });
			TempStore[38] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y - 3 });
			TempStore[39] = Display::GetPixel(Point{ RBCorner.X, RBCorner.Y - 4 });
		}
	}

	unsigned long Red = Color.Red;
	unsigned long Green = Color.Green;
	unsigned long Blue = Color.Blue;

	unsigned long Low;
	unsigned long Medium;
	unsigned long High;

	Low = Blue | Green << 8 | Red << 16 | Blue << 24 | Green << 32 | Red << 40 | Blue << 48 | Green << 56;
	Medium = Red | Blue << 8 | Green << 16 | Red << 24 | Blue << 32 | Green << 40 | Red << 48 | Blue << 56;
	High = Green | Red << 8 | Blue << 16 | Green << 24 | Red << 32 | Blue << 40 | Green << 48 | Red << 56;

	Point NewRBCorner = Point{ RBCorner.X - ((RBCorner.X - LTCorner.X + 1) % 16) + 1, RBCorner.Y };

	if (NewRBCorner.X < 0)
	{
		NewRBCorner.X = 0;
	}

	_asm("movq xmm0, %0":: "r"(Low));
	_asm("movq xmm1, %0":: "r"(High));
	_asm("movq xmm2, %0":: "r"(Medium));

	_asm("pinsrq xmm0, %0, 1":: "r"(Medium));
	_asm("pinsrq xmm1, %0, 1":: "r"(Low));
	_asm("pinsrq xmm2, %0, 1":: "r"(High));

	for (unsigned long i = 0xE0000000 + LTCorner.Y * 1024 * 3; i <= 0xE0000000 + RBCorner.Y * 1024 * 3; i += 1024 * 3)
	{
		for (unsigned long j = i + LTCorner.X * 3; j < i + NewRBCorner.X * 3; j += 48)
		{
			_asm("movdqu xmmword ptr [%0], xmm0":: "r"(j));
		}

		for (unsigned long j = i + LTCorner.X * 3 + 16; j < i + NewRBCorner.X * 3 + 16; j += 48)
		{
			_asm("movdqu xmmword ptr [%0], xmm1":: "r"(j));
		}

		for (unsigned long j = i + LTCorner.X * 3 + 32; j < i + NewRBCorner.X * 3 + 32; j += 48)
		{
			_asm("movdqu xmmword ptr [%0], xmm2":: "r"(j));
		}
	}

	int Alignment = (RBCorner.X - LTCorner.X + 1) % 16;

	if (Alignment != 0)
	{
		for (int i = LTCorner.Y; i <= RBCorner.Y; i++)
		{
			for (int j = NewRBCorner.X; j < NewRBCorner.X + Alignment; j++)
			{
				int Index = j + i * 1024;
				unsigned char* VideoMemory = (unsigned char*)0xE0000000;
				VideoMemory[Index * 3] = Color.Blue;
			}

			for (int j = NewRBCorner.X; j < NewRBCorner.X + Alignment; j++)
			{
				int Index = j + i * 1024;
				unsigned char* VideoMemory = (unsigned char*)0xE0000000;
				VideoMemory[Index * 3 + 1] = Color.Green;
			}

			for (int j = NewRBCorner.X; j < NewRBCorner.X + Alignment; j++)
			{
				int Index = j + i * 1024;
				unsigned char* VideoMemory = (unsigned char*)0xE0000000;
				VideoMemory[Index * 3 + 2] = Color.Red;
			}
		}
	}

	if (Rounding & (1 << 4))
	{
		if (Rounding & (1 << 0))
		{
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y }, Display::AlphaBlend(TempStore[0], Color, (double)30 / 255));
			Display::SetPixel(Point{ LTCorner.X + 1, LTCorner.Y }, Display::AlphaBlend(TempStore[1], Color, (double)187 / 255));
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y + 1 }, Display::AlphaBlend(TempStore[2], Color, (double)187 / 255));
		}

		if (Rounding & (1 << 1))
		{
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y }, Display::AlphaBlend(TempStore[3], Color, (double)30 / 255));
			Display::SetPixel(Point{ RBCorner.X - 1, LTCorner.Y }, Display::AlphaBlend(TempStore[4], Color, (double)187 / 255));
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y + 1 }, Display::AlphaBlend(TempStore[5], Color, (double)187 / 255));
		}

		if (Rounding & (1 << 2))
		{
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y }, Display::AlphaBlend(TempStore[6], Color, (double)30 / 255));
			Display::SetPixel(Point{ LTCorner.X + 1, RBCorner.Y }, Display::AlphaBlend(TempStore[7], Color, (double)187 / 255));
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y - 1 }, Display::AlphaBlend(TempStore[8], Color, (double)187 / 255));
		}

		if (Rounding & (1 << 3))
		{
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y }, Display::AlphaBlend(TempStore[9], Color, (double)30 / 255));
			Display::SetPixel(Point{ RBCorner.X - 1, RBCorner.Y }, Display::AlphaBlend(TempStore[10], Color, (double)187 / 255));
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y - 1 }, Display::AlphaBlend(TempStore[11], Color, (double)187 / 255));
		}
	}
	else
	{
		if (Rounding & (1 << 0))
		{
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y }, TempStore[0]);
			Display::SetPixel(Point{ LTCorner.X + 1, LTCorner.Y }, TempStore[1]);
			Display::SetPixel(Point{ LTCorner.X + 2, LTCorner.Y }, Display::AlphaBlend(TempStore[2], Color, (double)69 / 255));
			Display::SetPixel(Point{ LTCorner.X + 3, LTCorner.Y }, Display::AlphaBlend(TempStore[3], Color, (double)171 / 255));
			Display::SetPixel(Point{ LTCorner.X + 4, LTCorner.Y }, Display::AlphaBlend(TempStore[4], Color, (double)219 / 255));
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y + 1 }, TempStore[5]);
			Display::SetPixel(Point{ LTCorner.X + 1, LTCorner.Y + 1 }, Display::AlphaBlend(TempStore[6], Color, (double)119 / 255));
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y + 2 }, Display::AlphaBlend(TempStore[7], Color, (double)69 / 255));
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y + 3 }, Display::AlphaBlend(TempStore[8], Color, (double)171 / 255));
			Display::SetPixel(Point{ LTCorner.X, LTCorner.Y + 4 }, Display::AlphaBlend(TempStore[9], Color, (double)219 / 255));
		}

		if (Rounding & (1 << 1))
		{
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y }, TempStore[10]);
			Display::SetPixel(Point{ RBCorner.X - 1, LTCorner.Y }, TempStore[11]);
			Display::SetPixel(Point{ RBCorner.X - 2, LTCorner.Y }, Display::AlphaBlend(TempStore[12], Color, (double)69 / 255));
			Display::SetPixel(Point{ RBCorner.X - 3, LTCorner.Y }, Display::AlphaBlend(TempStore[13], Color, (double)171 / 255));
			Display::SetPixel(Point{ RBCorner.X - 4, LTCorner.Y }, Display::AlphaBlend(TempStore[14], Color, (double)219 / 255));
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y + 1 }, TempStore[15]);
			Display::SetPixel(Point{ RBCorner.X - 1, LTCorner.Y + 1 }, Display::AlphaBlend(TempStore[16], Color, (double)119 / 255));
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y + 2 }, Display::AlphaBlend(TempStore[17], Color, (double)69 / 255));
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y + 3 }, Display::AlphaBlend(TempStore[18], Color, (double)171 / 255));
			Display::SetPixel(Point{ RBCorner.X, LTCorner.Y + 4 }, Display::AlphaBlend(TempStore[19], Color, (double)219 / 255));
		}

		if (Rounding & (1 << 2))
		{
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y }, TempStore[20]);
			Display::SetPixel(Point{ LTCorner.X + 1, RBCorner.Y }, TempStore[21]);
			Display::SetPixel(Point{ LTCorner.X + 2, RBCorner.Y }, Display::AlphaBlend(TempStore[22], Color, (double)69 / 255));
			Display::SetPixel(Point{ LTCorner.X + 3, RBCorner.Y }, Display::AlphaBlend(TempStore[23], Color, (double)171 / 255));
			Display::SetPixel(Point{ LTCorner.X + 4, RBCorner.Y }, Display::AlphaBlend(TempStore[24], Color, (double)219 / 255));
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y - 1 }, TempStore[25]);
			Display::SetPixel(Point{ LTCorner.X + 1, RBCorner.Y - 1 }, Display::AlphaBlend(TempStore[26], Color, (double)119 / 255));
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y - 2 }, Display::AlphaBlend(TempStore[27], Color, (double)69 / 255));
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y - 3 }, Display::AlphaBlend(TempStore[28], Color, (double)171 / 255));
			Display::SetPixel(Point{ LTCorner.X, RBCorner.Y - 4 }, Display::AlphaBlend(TempStore[29], Color, (double)219 / 255));
		}

		if (Rounding & (1 << 3))
		{
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y }, TempStore[30]);
			Display::SetPixel(Point{ RBCorner.X - 1, RBCorner.Y }, TempStore[31]);
			Display::SetPixel(Point{ RBCorner.X - 2, RBCorner.Y }, Display::AlphaBlend(TempStore[32], Color, (double)69 / 255));
			Display::SetPixel(Point{ RBCorner.X - 3, RBCorner.Y }, Display::AlphaBlend(TempStore[33], Color, (double)171 / 255));
			Display::SetPixel(Point{ RBCorner.X - 4, RBCorner.Y }, Display::AlphaBlend(TempStore[34], Color, (double)219 / 255));
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y - 1 }, TempStore[35]);
			Display::SetPixel(Point{ RBCorner.X - 1, RBCorner.Y - 1 }, Display::AlphaBlend(TempStore[36], Color, (double)119 / 255));
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y - 2 }, Display::AlphaBlend(TempStore[37], Color, (double)69 / 255));
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y - 3 }, Display::AlphaBlend(TempStore[38], Color, (double)171 / 255));
			Display::SetPixel(Point{ RBCorner.X, RBCorner.Y - 4 }, Display::AlphaBlend(TempStore[39], Color, (double)219 / 255));
		}
	}
}