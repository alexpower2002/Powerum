char* buffer;

void Print(long num)
{
	UILabel lbl = UILabel(Point{ 500,500 }, String::IntegerToANSI(num, buffer, 16));

	lbl.Draw();
}

void Print(const char* str)
{
	UILabel lbl = UILabel(Point{ 500,500 }, (char*)str);

	lbl.Draw();
}