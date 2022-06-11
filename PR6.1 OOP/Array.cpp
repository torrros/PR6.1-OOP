////////////////////Array.cpp
#include "Array.h"
#include <iostream>
#include <stdexcept>
#include <exception>
using namespace std;

Array::Array(const Array::size_type& n)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	Count = Size = n;
	elems = new value_type[Size];
	for (UINT i = 0; i < Size; i++)
		elems[i] = 0;
}

Array::Array(const iterator first, const iterator last)
throw(bad_alloc, invalid_argument)
{
	First = 0;
	if (first <= last) {
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const size_type first, const size_type last)
throw(bad_alloc, invalid_argument)
{
	if (first <= last) {
		First = first;
		Count = Size = (last - first) + 1;
		elems = new value_type[Size];
		for (UINT i = 0; i < Size; ++i)
			elems[i] = 0;
	}
	else
		throw invalid_argument("!!!");
}
Array::Array(const Array& t) throw(bad_alloc)
	: Size(t.Size), Count(t.Count), First(t.First), elems(new value_type[Size])
{
	for (UINT i = 0; i < Size; ++i)
		elems[i] = t.elems[i];
}
Array& Array::operator =(const Array& t)
{
	Array tmp(t);
	swap(tmp);
	return *this;
}
Array::~Array()
{
	delete[]elems;
	elems = 0;
}
void Array::push_back(const value_type& v)
{
	if (Count == Size) // м≥сц€ нема
		resize(Size * 2); // зб≥льшили "м≥стк≥сть"
	elems[Count++] = v; // присвоњли
}
Array::reference Array::operator [](size_type index) throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}

Array::const_reference Array::operator [](size_type index) const
throw(out_of_range)
{
	if ((First <= index) && (index < First + Size))
		return elems[index - First];
	else
		throw out_of_range("Index out of range!");
}
void Array::resize(size_type newsize) throw(bad_alloc)
{
	if (newsize > capacity())
	{
		value_type* data = new value_type[newsize];
		for (size_type i = 0; i < Count; ++i)
			data[i] = elems[i];
		delete[] elems;
		elems = data;
		Size = newsize;
	}
}
void Array::swap(Array& other)
{
	std::swap(elems, other.elems); // стандартна функц≥€ обм≥ну
	std::swap(Size, other.Size);
}

void Array::assign(const value_type& v)// заповнити масив 
{
	for (UINT i = 0; i < Size; ++i)
		elems[i] = v;
}
void Array::pop_back()
{
	// видалити останн≥й елемент
	if (Count > 0)
		--Count;
}
void Array::divide_and_add()
{
	
		value_type max = elems[0];
	value_type min = elems[0];
	for (UINT i = 0; i < Count; ++i)
	{
		if (elems[i] > max)
			max = elems[i];
		if (elems[i] < min)
			min = elems[i];
	}
	for (UINT i = 0; i < Count; ++i)
	{
		elems[i] = elems[i] / min + max;
	}
	
}
Array::size_type Array::capacity() const
{
	return Size;
}
Array::size_type Array::size() const
{
	return Count;
}
bool Array::empty() const
{
	return Count == 0;
}
ostream& operator <<(ostream& out, const Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		out << tmp[j] << " ";
	out << endl;
	return out;
}
istream& operator >>(istream& in, Array& tmp)
{
	for (size_t j = 0; j < tmp.Count; j++)
		in >> tmp[j];
	return in;
}
