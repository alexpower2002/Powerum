#pragma once

template<typename T>
class Array
{
public:
	Array();
	Array(int N);
	int IndexOf(T Item);
	void Clear();
	int Count;
	T* Elements;
	T& operator [](int Index);
};

template<typename T>
inline Array<T>::Array()
{
	Count = 0;
}

template<typename T>
inline Array<T>::Array(int N)
{
	Count = N;

	if (Count > 0)
	{
		Elements = new T[Count];
	}
}

template<typename T>
inline int Array<T>::IndexOf(T Item)
{
	int Index = -1;

	for (int i = 0; i < Count; i++)
	{
		if (Elements[i] == Item)
		{
			Index = i;
			break;
		}
	}

	return Index;
}

template<typename T>
inline void Array<T>::Clear()
{
	delete[] Elements;
}

template<typename T>
inline T& Array<T>::operator [](int Index)
{
	if (Index > Count)
	{
        Print("INDEX OUT OF RANGE");
        _asm("hlt");
	}

	return Elements[Index];
}
