#pragma once

#include "List.h"
#include "Nullable.h"

template<typename K, typename I>
class Dictionary
{
public:
	Dictionary();
	List<K> Keys;
	List<I> Items;
	void Add(K Key, I Item);
	Nullable<I> operator[](K Key);
};

template<typename K, typename I>
Dictionary<K, I>::Dictionary()
{
	Keys = List<K>();
	Items = List<I>();
}

template<typename K, typename I>
void Dictionary<K, I>::Add(K Key, I Item)
{
	Keys.Add(Key);
	Items.Add(Item);
}

template<typename K, typename I>
Nullable<I> Dictionary<K, I>::operator[](K Key)
{
	int Index = Keys.IndexOf(Key);

	Nullable<I> Result;

	if (Index != -1)
	{
		Result.Value = Items[Index];
		Result.HasValue = true;
	}
	else
	{
		Result.HasValue = false;
	}

	return Result;
}