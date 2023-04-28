#pragma once

class String
{
public:
    String();
    String(char* cstring);
    String(const char* cstring);

    char* CString;

    int Count;

    char operator[](int Index);
    void operator+=(String string);
    void operator+=(char* cstring);
    void operator+=(const char* cstring);
    String operator+(String string);
    String operator+(char* string);
    String operator+(const char* string);
    void operator=(char* cstring);
    void operator=(const char* cstring);

	static char* IntegerToANSI(long num, char* str, int radix);

	static int Length(const char* str);
	static int Compare(const char* p1, const char* p2);
	static int Find(char* P, char ch);
	static int IndexOf(char* S, char* P);
    static char* ToLowerCase(char* string);
    static char* ToUpperCase(char* string);
    static char* Copy(char* source, char* destination, int offset = 0);
};