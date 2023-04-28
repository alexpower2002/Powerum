#pragma once

struct PDEntry //2MB
{
    unsigned char IsPresent:1; //1
    unsigned char IsReadWrite:1; //1
    unsigned char IsSupervisorOnly:1; //0
    unsigned char WriteThrough:1;//0
    unsigned char IsCacheDisabled:1; //0
    unsigned char IsAccessed:1; //0
    unsigned char IsDirty:1; //0
    unsigned char PageSize:1; //1
    unsigned char GlobalInvalidationDisabled:1; //1
    unsigned char Available1:3; //000 anything can be put here
    unsigned char PageAttributionTable:1;//0
    unsigned char Reserved:8;
    unsigned int Address:24; //bits 21-45 of an address
    unsigned char Reserved2:7;
    unsigned char Available2:7;
    unsigned char ProtectionKey:4;
    unsigned char ExecuteDisabled:1;
} __attribute__((packed));

struct PageTable
{
	unsigned long* Pages; //512

    PageTable(unsigned long PTAddress)
    {
        Pages = (unsigned long*)PTAddress;
    }
};

struct PDT
{
	unsigned long* PageTables; //512

public:
    PDT(unsigned long PDTAddress)
    {
        PageTables = (unsigned long*)PDTAddress;
    }

    PageTable operator[](int Entry)
    {
        PageTable xPT = PageTable(PageTables[Entry] & 0xffffffffff000);

        return xPT;
    }

    unsigned long* GetPointer()
    {
        return (unsigned long*)this;
    }
};

struct PDPT
{
	unsigned long* DirectoryTables; //512

public:
    PDPT(unsigned long PDPTAddress)
    {
        DirectoryTables = (unsigned long*)PDPTAddress;
    }
    PDT operator[](int Entry)
    {
        PDT xPDT = PDT(DirectoryTables[Entry] & 0xffffffffff000);

        return xPDT;
    }
};

struct PML4
{
	unsigned long* PointerTables; //512

public:
    PML4(unsigned long PML4Address)
    {
        PointerTables = (unsigned long*)PML4Address;
    }
    PDPT operator[](int Entry)
    {
        PDPT xPDPT = PDPT(PointerTables[Entry] & 0xffffffffff000);

        return xPDPT;
    }
};

class Paging
{
public:
    static void MapPage(unsigned long VirtualAddress, unsigned long PhysicalAddress);
};