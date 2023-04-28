#include "UILabel.h"

Dictionary<char, Character*>* CachedCharacters;

UILabel::UILabel(Point p, char* t, int s)
{
	Position = p;
	Text = t;
	Spacing = s;
}

void UILabel::Draw()
{
	char* Filename = new char[7]();

	Filename[0] = '0';
	Filename[1] = '.';
	Filename[2] = 'c';
	Filename[3] = 'h';
	Filename[4] = 'a';
	Filename[5] = 'r';
	Filename[6] = '\0';

	int CurrentXOffset = 0;

	while (*Text)
	{
		if (*Text == ' ')
		{
			CurrentXOffset += 3;

			Text++;

			continue;
		}

		Character* chr;

		auto result = (*CachedCharacters)[*Text];

		bool exists = true;

		if (!result.HasValue)
		{
			Filename[0] = *Text;

			File* f = FileSystem::LoadFile(Filename);

			if (f == nullptr)
			{
				exists = false;
			}
			else
			{
				int xWidth = ((int*)f->Contents)[0];
				int xHeight = ((int*)f->Contents)[1];

				unsigned char* AlphaImage = f->Contents + 8;

				RGB* Image = new RGB[xWidth * xHeight];

				for (int i = 0; i < xHeight; i++)
				{
					for (int j = 0; j < xWidth; j++)
					{
						Image[j + i * xWidth] = RGB{ (0xff * ((double)(255 - AlphaImage[j + i * xWidth]) / 255)),(0xff * ((double)(255 - AlphaImage[j + i * xWidth]) / 255)),(0xff * ((double)(255 - AlphaImage[j + i * xWidth]) / 255)) };
					}
				}

				chr = new Character();

				chr->Width = xWidth;
				chr->Height = xHeight;

				chr->Image = Image;

				CachedCharacters->Add(*Text, chr);
			}
		}
		else
		{
			chr = result.Value;
		}

		if (exists)
		{
			for (int i = 0; i < chr->Height; i++)
			{
				for (int j = 0; j < chr->Width; j++)
				{
					Display::SetPixel(Point{ Position.X + CurrentXOffset + j, Position.Y + i }, chr->Image[j + i * chr->Width]);
				}
			}

			CurrentXOffset += chr->Width + Spacing;
		}

		Text++;
	}

	delete[] Filename;
}