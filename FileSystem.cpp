#include "FileSystem.h"

File* xRoot;
unsigned int Entries;

void FileSystem::LoadRoot()
{
	unsigned char* Root = Disk::ReadSectors(1, 1);

	Entries = *(unsigned int*)Root;

	Root += 4;

	unsigned int ExtraRootLBA = *(unsigned int*)Root;

	Root += 4;

	unsigned int ExtraRootSize = *(unsigned int*)Root;

	if (ExtraRootLBA != 0)
	{
		xRoot = new File();

		xRoot->Contents = new unsigned char[(ExtraRootSize + 1) * 512];
		xRoot->Size = (ExtraRootSize + 1) * 512;

		Disk::ReadSectors(1, 1, xRoot->Contents);
		Disk::ReadSectors(ExtraRootLBA, ExtraRootSize, xRoot->Contents + 512);
	}
}

File* FileSystem::LoadFile(char* Name)
{
	unsigned char* Root = xRoot->Contents + 12;

	int Index = 0;
	int Entry = 0;

	while (Entry < Entries)
	{
		unsigned int LBA = ((unsigned int*)(Root + Index))[0];

		unsigned int Size = ((unsigned int*)(Root + Index))[1];

		Index += 8;

		if (String::Compare((char*)(Root + Index), Name) == 0)
		{
			return new File(Size, Disk::ReadSectors(LBA, Math::ceil((double)Size / 512)));
		}
		else
		{
			Index += String::Length((char*)(Root + Index)) + 1;
		}

		Entry++;
	}

	return nullptr;
}

List<char*> FileSystem::ListFiles()
{
    unsigned char* Root = xRoot->Contents + 12;

    List<char*> result = List<char*>();

    int Index = 0;
    int Entry = 0;

    while (Entry < Entries)
    {
        Index += 8;

        char* buf = new char[String::Length((char*)(Root + Index)) + 1];

        String::Copy((char*)(Root + Index), buf);

        result.Add(buf);

        Index += String::Length((char*)(Root + Index)) + 1;

        Entry++;
    }

    return result;
}
