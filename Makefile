all:
	cd /Users/alexdol/CLionProjects/Main/Main
	x86_64-elf-g++ *.cpp -c -masm=intel -include "Helper.h" -Wno-packed-bitfield-compat -Wno-narrowing -O3 -msse2 -mno-red-zone -ffreestanding -fno-exceptions -fno-rtti -fno-optimize-sibling-calls
	x86_64-elf-ld *.o -T Link.ld -o Boot/Main.app
	/Users/alexdol/CLionProjects/Boot/Boot/Run.sh
	rm *.o
