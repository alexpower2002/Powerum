#include "Main.h"

extern "C" void Startup()
{
	_asm("mov rsp, 0x400000");

	Main::Start();
}