#include "Exceptions.h"

void Exceptions::Exc13()
{
    unsigned long l = 0;

    _asm("mov rax, qword [rsp+72]");
    _asm("mov %0, rax"::"m"(l));

    char* txt = new char[32];

	UILabel lbl = UILabel(Point{ 500,500 }, String::IntegerToANSI(l, txt, 16));

	lbl.Draw();

	_asm("hlt");
}