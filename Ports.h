#pragma once

class Ports
{
public:
	static unsigned char Read(unsigned short Port);
	static void Write(unsigned short Port, unsigned char Value);
	static unsigned short ReadWord(unsigned short Port);
    static unsigned int ReadInt(unsigned short Port);
    static void WriteWord(unsigned short Port, unsigned short Value);
    static void WriteInt(unsigned short Port, unsigned int Value);
	static void ReadRepeat(unsigned short Port, unsigned long Count, unsigned long Address);
	static void WriteRepeat(unsigned short Port, unsigned long Count, unsigned long Address);
	static void ReadWordRepeat(unsigned short Port, unsigned long Count, unsigned long Address);
	static void WriteWordRepeat(unsigned short Port, unsigned long Count, unsigned long Address);
};