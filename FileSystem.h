#pragma once

#include "MMU.h"
#include "Disk.h"
#include "Math.h"
#include "File.h"
#include "String.h"
#include "List.h"

class FileSystem
{
public:
	static void LoadRoot();
	static File* LoadFile(char* Name);
    static List<char*> ListFiles();
};