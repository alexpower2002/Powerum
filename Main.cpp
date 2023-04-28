#include "Main.h"

const int DynamicMemory = 4 * 1024 * 1024;

MMU xMMU;

extern Random* rnd;
extern File* xRoot;
extern Dictionary<char, Character*>* CachedCharacters;

extern char* buffer;

void Main::Start()
{
	xMMU = MMU(0x200000, 0x350000, DynamicMemory, true);

	IDT xIDT;

	xIDT.Interrupts = (IDTDescriptor*)0;

	xIDT.SetInterruptHandler(13, (unsigned long)Exceptions::Exc13, 0x8E);

	rnd = new Random();

	FileSystem::LoadRoot();

	CachedCharacters = new Dictionary<char, Character*>();

	buffer = new char[32]();

	Display::ClearScreen(RGB{ 0xff, 0xff, 0xff });

    //Rectangle rect=Rectangle(Point{100,100}, Point{200,200}, RGB{0xff,0xff,0xff}, 0);


    //rect.Draw();

	//UIView v1 = UIView(RGB{ 0xff,0xff,0xff });
	//UIView v2 = UIView(RGB{ 0x0,0x0,0x0 });
	//UIView v3 = UIView(RGB{ 0xc0,0xc0,0xc0 });

	//List<int> Fractions1 = List<int>();

	//Fractions1.Add(1);
	//Fractions1.Add(1);

	//List<UIView> Views1 = List<UIView>();

	//Views1.Add(v1);
	//Views1.Add(v2);
/*
	UIGrid g1 = UIGrid(Views1, Fractions1, false);

	List<int> Fractions2 = List<int>();

	Fractions2.Add(1);
	Fractions2.Add(1);

	List<UIView> Views2 = List<UIView>();

	Views2.Add(g1);
	Views2.Add(v3);

	UIGrid g2 = UIGrid(Views2, Fractions2);

	g2.Initialize(1024, 768, Point{ 0,0 });
	g2.Draw();*/
/*
	Rectangle* rect = new Rectangle(Point{ 100, 100 }, Point{ 139, 139 }, RGB{ 0xc0, 0, 0xff }, 15);

	for (int i = 0; i < 30; i++)
	{
		//rect->Draw();

		int volatile c = 0;
		int volatile d = 0;

		//for (c = 0; c < 1200; c++)
			//for (d = 0; d < 1600; d++) {}

		int w = (0 - rect->LTCorner.X)*((double)1 / 3);
		int x = (0 - rect->LTCorner.Y)*((double)1 / 3);
		int y = (1023 - rect->RBCorner.X)*((double)1 / 3);
		int z = (767 - rect->RBCorner.Y)*((double)1 / 3);

		rect->LTCorner = Point{ rect->LTCorner.X + w, rect->LTCorner.Y + x };
		rect->RBCorner = Point{ rect->RBCorner.X + y, rect->RBCorner.Y + z };

		//Display::ClearScreen(Display::AlphaBlend(RGB{ 0,0,0xff }, { 0,0,0xff }, (double)rect->RBCorner.X / 1023));

		rect->Color = Display::AlphaBlend(RGB{ 0xc0,0,0xff }, { 0xff,0xff,0xff }, (double)rect->RBCorner.X / 1023);
	}*/

    //rect->Rounding = 0;
    //rect->LTCorner = Point{ 0,0 };
    //rect->RBCorner = Point{ 1023, 767 };

    //rect->Draw();

	//LetterOccurences();

	//NeuralNetwork();

	//BatteryUsage();

	//Files();

    //MemoryUsed();

	//Blur(Point{ 180,40 }, Point{ 240,110 }, 15);

	/*
	unsigned int len = 250*250;

	RGB* d = (RGB*)0x70000;
	RGB* s = (RGB*)0xE0027530;
	while (len--)
		*d++ = *s++;

	Blur::gaussBlur((RGB*)0x70000, (RGB*)0xE0027530, 250, 250, 10);
*/
    //DrawWuLine(300, 300, 304, 316, RGB{ 0,0,0 });

    //DrawAACircle(Point{ 400,400 }, Point{ 500,500 });

    //DrawCircle(Point{250,250},10, RGB{0xff,0,0xc0});

    //Graphics::HomeButton();

	//rect->Rounding = 15;
/*
	for (int i = 0; i < 24; i++)
	{
		//rect->Draw();

		int volatile c = 0;
		int volatile d = 0;

		//for (c = 0; c < 3200; c++)
			//for (d = 0; d < 1600; d++) {}

		int w = (100 - rect->LTCorner.X)*((double)1 / 3);
		int x = (100 - rect->LTCorner.Y)*((double)1 / 3);
		int y = (139 - rect->RBCorner.X)*((double)1 / 3);
		int z = (139 - rect->RBCorner.Y)*((double)1 / 3);

		rect->LTCorner = Point{ rect->LTCorner.X + w, rect->LTCorner.Y + x };
		rect->RBCorner = Point{ rect->RBCorner.X + y, rect->RBCorner.Y + z };

		//Display::ClearScreen(Display::AlphaBlend(RGB{ 0,0,0xff }, { 0,0,0 }, (double)(rect->RBCorner.X - 139) / (1023 - 139)));

		rect->Color = Display::AlphaBlend(RGB{ 0xc0,0,0xff }, { 0xff,0xff,0xff }, (double)(rect->RBCorner.X - 139) / (1023 - 139));
	}*/

	//rect->LTCorner = Point{ 100,100 };
	//rect->RBCorner = Point{ 139, 139 };
	//rect->Draw();

	for(;;)
        _asm("hlt");
}

void Main::NeuralNetwork()
{
    RNN* rnn = new RNN("ABCDEFGHIJKLMNOPQRSTUVWXYZ ", "JESUS CHRIST IS A SUPER STAR");

    rnn->Run();
}

void Main::LetterOccurences()
{
	auto Fractions = List<double>();

	Fractions.Add(0.1);
	Fractions.Add(0.05);
	Fractions.Add(0.03);
	Fractions.Add(0.03);
	Fractions.Add(0.02);
	Fractions.Add(0.04);
	Fractions.Add(0.03);
	Fractions.Add(0.04);
	Fractions.Add(0.09);
	Fractions.Add(0.03);
	Fractions.Add(0.03);
	Fractions.Add(0.03);
	Fractions.Add(0.04);
	Fractions.Add(0.03);
	Fractions.Add(0.02);
	Fractions.Add(0.07);
	Fractions.Add(0.14);
	Fractions.Add(0.01);
	Fractions.Add(0.08);
	Fractions.Add(0.02);
	Fractions.Add(0.03);

	Random rnd = Random();

	List<RGB> Colors = List<RGB>();

	for (int i = 0; i < 21; i++)
	{
		Colors.Add(RGB{ rnd.Next(0, 255),rnd.Next(0, 255),rnd.Next(0, 255) });
	}

	UIProgressBarChart* pbc = new UIProgressBarChart(Fractions, Colors);

	pbc->Initialize(824, 20, Point{ 100,100 });
	pbc->Draw();
}

void Main::MemoryUsed()
{
	int Used = xMMU.GetUsedAmount();

	auto Fractions = List<double>();

	Fractions.Add((double)Used / DynamicMemory);
	Fractions.Add(1 - ((double)Used / DynamicMemory));

	auto UsedColor = RGB();

	if (Used > 0.75 * DynamicMemory)
	{
		UsedColor = RGB{ 255, 69, 58 };
	}
	else
	{
		if (Used > 0.5 * DynamicMemory)
		{
			UsedColor = RGB{ 255, 149, 0 };
		}
		else
		{
			if (Used > 0.25 * DynamicMemory)
			{
				UsedColor = RGB{ 255, 214, 10 };
			}
			else
			{
				UsedColor = RGB{ 48, 209, 58 };
			}
		}
	}

	auto Colors = List<RGB>();

	Colors.Add(UsedColor);
	Colors.Add(RGB{ 0xe0,0xe0,0xe0 });

	UIProgressBarChart* pbc = new UIProgressBarChart(Fractions, Colors);

	pbc->Initialize(824, 20, Point{ 100,70 });
	pbc->Draw();
}

void Main::BatteryUsage()
{
	Rectangle topline = Rectangle(Point{ 12,12 }, Point{ 1012,12 }, RGB{ 0xd0,0xd0,0xd0 });

	Rectangle bottomline = Rectangle(Point{ 12,417 }, Point{ 1012,417 }, RGB{ 0xd0,0xd0,0xd0 });

	Graphics::PunctLineV(Point{ 12,12 }, Point{ 12,417 }, RGB{ 0xd0,0xd0,0xd0 }, RGB{ 0xff,0xff,0xff }, 5);
	Graphics::PunctLineV(Point{ 262,12 }, Point{ 262,417 }, RGB{ 0xd0,0xd0,0xd0 }, RGB{ 0xff,0xff,0xff }, 5);
	Graphics::PunctLineV(Point{ 512,12 }, Point{ 512,417 }, RGB{ 0xd0,0xd0,0xd0 }, RGB{ 0xff,0xff,0xff }, 5);
	Graphics::PunctLineV(Point{ 762,12 }, Point{ 762,417 }, RGB{ 0xd0,0xd0,0xd0 }, RGB{ 0xff,0xff,0xff }, 5);
	Graphics::PunctLineV(Point{ 1012,12 }, Point{ 1012,417 }, RGB{ 0xd0,0xd0,0xd0 }, RGB{ 0xff,0xff,0xff }, 5);

	Rectangle iline1 = Rectangle(Point{ 12,112 }, Point{ 1012,112 }, RGB{ 0xd0,0xd0,0xd0 });
	Rectangle iline2 = Rectangle(Point{ 12,212 }, Point{ 1012,212 }, RGB{ 0xd0,0xd0,0xd0 });
	Rectangle iline3 = Rectangle(Point{ 12,312 }, Point{ 1012,312 }, RGB{ 0xd0,0xd0,0xd0 });

	iline1.Draw();
	iline2.Draw();
	iline3.Draw();

	topline.Draw();

	Rectangle column = Rectangle(Point{ 14,217 }, Point{ 18,417 }, RGB{ 52,199,89 }, 19);

	for (int i = 0; i <= 9; i++)
	{
		column.Draw();

		column.LTCorner.X += 6;
		column.LTCorner.Y += 1;
		column.RBCorner.X += 6;
	}

	column.Color = RGB{ 255,204,0 };

	for (int i = 0; i <= 69; i++)
	{
		column.Draw();

		column.LTCorner.X += 6;
		column.RBCorner.X += 6;
	}

	Rectangle charging = Rectangle(Point{ column.LTCorner.X,12 }, Point{ column.LTCorner.X + 35,417 }, RGB{ 194,232,191 });

	charging.Draw();

	for (int i = 0; i <= 39; i++)
	{
		Graphics::DrawWuLine(charging.LTCorner.X, charging.LTCorner.Y + 10 * i, charging.RBCorner.X, charging.LTCorner.Y + 35 + 10 * i, RGB{ 0xff,0xff,0xff });
		Graphics::DrawWuLine(charging.LTCorner.X, charging.LTCorner.Y + 10 * i + 1, charging.RBCorner.X, charging.LTCorner.Y + 36 + 10 * i, RGB{ 0xff,0xff,0xff });
		Graphics::DrawWuLine(charging.LTCorner.X, charging.LTCorner.Y + 10 * i + 2, charging.RBCorner.X, charging.LTCorner.Y + 37 + 10 * i, RGB{ 0xff,0xff,0xff });
		Graphics::DrawWuLine(charging.LTCorner.X, charging.LTCorner.Y + 10 * i + 3, charging.RBCorner.X, charging.LTCorner.Y + 38 + 10 * i, RGB{ 0xff,0xff,0xff });
		Graphics::DrawWuLine(charging.LTCorner.X, charging.LTCorner.Y + 10 * i + 4, charging.RBCorner.X, charging.LTCorner.Y + 39 + 10 * i, RGB{ 0xff,0xff,0xff });
	}

	column.Color = RGB{ 52,199,89 };

	for (int i = 0; i <= 5; i++)
	{
		column.Draw();

		column.LTCorner.X += 6;
		column.LTCorner.Y -= 7;
		column.RBCorner.X += 6;
	}

	bottomline.Draw();
}

void Main::Files()
{
    List<char*> files = FileSystem::ListFiles();

    for (int i = 0; i < files.Count; i++)
    {
        auto file = new UIImage();

        file->Initialize(0,0,Point{110+ (i%10)*80,100+(i/10)*140});
        file->LoadImage((char*)"f.image");
        file->Draw();

        auto lbl = new UILabel(Point{120+(i%10)*80, 210+(i/10)*140}, String::ToUpperCase(files[i]));

        lbl->Draw();
    }

    String str1 = "1";
    String str2="2";
    String str3="3";

    Print((str1).CString);
}