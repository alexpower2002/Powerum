#pragma once

template<typename T>
class Nullable
{
public:
	Nullable<T>();
	Nullable<T>(T value);
	bool HasValue;
	T Value;
};

template<typename T>
inline Nullable<T>::Nullable()
{
	HasValue = false;
}

template<typename T>
inline Nullable<T>::Nullable(T value)
{
	HasValue = true;
	Value = value;
}