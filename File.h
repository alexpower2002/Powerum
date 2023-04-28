#pragma once

class File
{
public:
	File();
	File(unsigned int s, unsigned char* c);

	unsigned short Size;
	unsigned char* Contents;
};