#include "Display.h"

void Display::SetPixel(Point Location, RGB Color)
{
	unsigned long Index = Location.X + Location.Y * 1024;
	unsigned char* VideoMemory = (unsigned char*)0xE0000000;

	VideoMemory[Index * 3] = Color.Blue;
	VideoMemory[Index * 3 + 1] = Color.Green;
	VideoMemory[Index * 3 + 2] = Color.Red;
}

RGB Display::GetPixel(Point Location)
{
	unsigned long Index = Location.X + Location.Y * 1024;
	unsigned char* VideoMemory = (unsigned char*)0xE0000000;
	RGB Color;
	
	Color.Blue = VideoMemory[Index * 3];
	Color.Green = VideoMemory[Index * 3 + 1];
	Color.Red = VideoMemory[Index * 3 + 2];

	return Color;
}

void Display::ClearScreen(RGB Color)
{
	unsigned long Red = Color.Red;
	unsigned long Green = Color.Green;
	unsigned long Blue = Color.Blue;

	unsigned long Low;
	unsigned long Medium;
	unsigned long High;

	Low = Blue | Green << 8 | Red << 16 | Blue << 24 | Green << 32 | Red << 40 | Blue << 48 | Green << 56;
	Medium = Red | Blue << 8 | Green << 16 | Red << 24 | Blue << 32 | Green << 40 | Red << 48 | Blue << 56;
	High = Green | Red << 8 | Blue << 16 | Green << 24 | Red << 32 | Blue << 40 | Green << 48 | Red << 56;

	_asm("movq xmm0, %0":: "r"(Low));
	_asm("movq xmm1, %0":: "r"(High));
	_asm("movq xmm2, %0":: "r"(Medium));

	_asm("pinsrq xmm0, %0, 1":: "r"(Medium));
	_asm("pinsrq xmm1, %0, 1":: "r"(Low));
	_asm("pinsrq xmm2, %0, 1":: "r"(High));

	for (unsigned long Index = 0xE0000000; Index <= 0xE0240000; Index += 48)
	{
		_asm("movdqa xmmword ptr [%0], xmm0":: "r"(Index));
	}

	for (unsigned long Index = 0xE0000010; Index <= 0xE0240010; Index += 48)
	{
		_asm("movdqa xmmword ptr [%0], xmm1":: "r"(Index));
	}

	for (unsigned long Index = 0xE0000020; Index <= 0xE0240020; Index += 48)
	{
		_asm("movdqa xmmword ptr [%0], xmm2":: "r"(Index));
	}
}

RGB Display::AlphaBlend(RGB Color1, RGB Color2, double Coefficient)
{
	unsigned int Red;
	unsigned int Green;
	unsigned int Blue;

	Red = Color1.Red + (Color2.Red - Color1.Red) * Coefficient;
	Green = Color1.Green + (Color2.Green - Color1.Green) * Coefficient;
	Blue = Color1.Blue + (Color2.Blue - Color1.Blue) * Coefficient;

	return RGB{ Red, Green, Blue };
}