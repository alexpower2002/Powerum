#pragma once

template<typename T>
struct Node
{
	T Item;
	Node<T>* Next;
};

template<typename T>
class List
{
public:
	List();
	int Count;
	Node<T>* First;
	Node<T>* Last;
	void Add(T Item);
	void Clear();
	Node<T>* NodeAt(int Index);
	T operator[](int Index);
	int IndexOf(T Item);
};

template<typename T>
List<T>::List()
{
	Count = 0;
}

template<typename T>
void List<T>::Add(T Item)
{
    Node<T>* Next = new Node<T>();

    Next->Item = Item;
    Next->Next = 0;

    if(Count==0){
        First = Next;
    }else{
        Last->Next = Next;
    }

    Last = Next;

    Count++;
}

template<typename T>
Node<T>* List<T>::NodeAt(int Index)
{
	Node<T>* Element;

	for (int i = 0; i <= Index; i++)
	{
		if (i == 0)
		{
			Element = First;
		}
		else
		{
			Element = Element->Next;
		}
	}

	return Element;
}

template<typename T>
void List<T>::Clear()
{
	Count = 0;
	/*
	if (Count > 0)
	{
		auto Present = First;
		auto Next = Present->Next;

		//delete Present;

		if (Count > 1)
		{
			for (int i = 1; i < Count; i++)
			{
				Present = Next;
				Next = Present->Next;

				//delete Present;
			}
		}
	}*/
}

template<typename T>
T List<T>::operator[](int Index)
{
	return NodeAt(Index)->Item;
}

template<typename T>
int List<T>::IndexOf(T Item)
{
	int Index = -1;

	for (int i = 0; i < Count; i++)
	{
		if (NodeAt(i)->Item == Item)
		{
			Index = i;
			break;
		}
	}

	return Index;
}