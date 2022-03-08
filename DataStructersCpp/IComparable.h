#pragma once
template<class T> class IComparable
{
public:
	virtual const int compareTo(T* object) = 0;
};

