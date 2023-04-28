#include "String.h"

String::String()
{
    CString = nullptr;
}

String::String(char* cstring)
{
    CString = Copy(cstring, CString);

    Count = Length(CString);
}

String::String(const char* cstring)
{
    CString = Copy((char*)cstring, CString);

    Count = Length(CString);
}

char String::operator[](int Index)
{
    if(Index >= Count)
    {
        Print("INDEX OUT OF RANGE");
    }

    return CString[Index];
}

void String::operator+=(String string)
{
    char* buf = new char[Count + string.Count];

    String::Copy(CString, buf);

    String::Copy(string.CString, buf, Count);

    CString = buf;

    Count = Count + string.Count;
}

void String::operator+=(char* cstring)
{
    String string = String(cstring);

    char* buf = new char[Count + string.Count];

    String::Copy(CString, buf);

    String::Copy(string.CString, buf, Count);

    CString = buf;

    Count = Count + string.Count;
}

void String::operator=(char* cstring)
{
    CString = Copy(cstring, CString);

    Count = Length(CString);
}

void String::operator=(const char* cstring)
{
    CString = Copy((char*)cstring, CString);

    Count = Length(CString);
}

void String::operator+=(const char* cstring)
{
    String string = String(cstring);

    char* buf = new char[Count + string.Count];

    String::Copy(CString, buf);

    String::Copy(string.CString, buf, Count);

    CString = buf;

    Count = Count + string.Count;
}

String String::operator+(String string)
{
    String newString = String(CString);

    newString += string;

    return newString;
}

String String::operator+(char* string)
{
    String newString = String(CString);

    newString += string;

    return newString;
}

String String::operator+(const char* string)
{
    String newString = String(CString);

    newString += string;

    return newString;
}

int String::Length(const char* str)
{
    const char* s;

	for (s = str; *s; ++s);

	return (s - str);
}

int String::Compare(const char* p1, const char* p2)
{
	const unsigned char* s1 = (const unsigned char*)p1;
	const unsigned char* s2 = (const unsigned char*)p2;

	unsigned char c1, c2;

	do
	{
		c1 = (unsigned char)*s1++;
		c2 = (unsigned char)*s2++;

		if (c1 == '\0')
			return c1 - c2;

	} while (c1 == c2);

	return c1 - c2;
}

int String::Find(char* P, char ch)
{
	int m, i;

    m = String::Length(P);

	for (i = m - 2; i >= 0; i--)
	{
		if (ch == P[i])
		{
			return  i;
		}
	}

	return -1;
}

int String::IndexOf(char* S, char* P)
{
	int n, m, i, j, lastch;

    n = String::Length(S);
    m = String::Length(P);

	i = m - 1;
    j = m - 1;

	while (i < n)
		if (P[j] == S[i])
			if (j == 0)
				return  i;
			else
			{
				j--;
                i--;
			}
		else
		{
			lastch = String::Find(P, S[i]);
			if (lastch == -1)
				i = i + m;
			else
				i = i + j - lastch;
			j = m - 1;
		}

	return  -1;
}

char* String::IntegerToANSI(long num, char* str, int radix)
{
	char sign = 0;
	char temp[65];

	long temp_loc = 0;
	long digit;
	long str_loc = 0;

	if (radix == 10 && num < 0)
	{
		sign = 1;
		num = -num;
	}

	do
	{
		digit = (unsigned long)num % radix;

		if (digit < 10)
			temp[temp_loc++] = digit + '0';
		else
			temp[temp_loc++] = digit - 10 + 'A';

		num = (((unsigned long)num) / radix);
	} while ((unsigned long)num > 0);

	if (radix == 10 && sign)
	{
		temp[temp_loc] = '-';
	}
	else
	{
		temp_loc--;
	}

	while (temp_loc >= 0)
	{
		str[str_loc++] = temp[temp_loc--];
	}

	str[str_loc] = 0;

	return str;
}

char* String::ToLowerCase(char* string)
{
    for (char* p = string; *p != '\0'; p++)
    {
        if(*p >= 'A' && *p <= 'Z')  //Only if it's an upper letter
            *p += 32;
    }

    return string;
}

char* String::ToUpperCase(char* string)
{
    for (char* p = string; *p != '\0'; p++)
    {
        if(*p >= 'a' && *p <= 'z')  //Only if it's a lower letter
            *p -= 32;
    }

    return string;
}

char* String::Copy(char* source, char* destination, int offset)
{
    char* ptr = destination + offset;

    destination += offset;

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';

    return ptr;
}