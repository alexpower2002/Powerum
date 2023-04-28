#include "Paging.h"

void Paging::MapPage(unsigned long VirtualAddress, unsigned long PhysicalAddress)
{
    unsigned short L4 = (VirtualAddress & 0xff8000000000) >> 39;
    unsigned short L3 = (VirtualAddress & 0x7fc0000000) >> 30;
    unsigned short L2 = (VirtualAddress & 0x3fe00000) >> 21;
    //unsigned short L1 = (VirtualAddress & 0x1ff000) >> 12;

    PML4 PageMap = PML4(0);

    unsigned long* Page = PageMap[L4][L3].GetPointer();

    unsigned long l = 0;

    PDEntry xPDEntry = *(PDEntry*)&l;

    xPDEntry.IsPresent = 1;
    xPDEntry.IsReadWrite = 1;
    xPDEntry.PageSize = 1;
    xPDEntry.GlobalInvalidationDisabled = 1;

    xPDEntry.Address = PhysicalAddress >> 21;

    Page[L2] = *(unsigned long*)&xPDEntry;

    //Page[L2] = PhysicalAddress | 0x183; //setting up page directory entry with is present, is rw, is 4 MB (page size)
}