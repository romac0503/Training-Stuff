/* (c) Stefan Huber, 2012.
Created for the course "Datenstrukturen and Algorithmen" in SoSe12.
Adapted by Gerhard Mitterlechner for SoSe13 with permission of S.Huber.
*/

#ifndef array_h
#define array_h

#include <cassert>
#include <ostream>
#include <iostream>

template<class T>
class Array
{
private:
	unsigned capacity;
	unsigned size;
	T* arr;

public:
	Array(unsigned capacity = 0) :
		capacity(capacity),
		size(0),
		arr(0)
	{
		if (capacity > 0)
			arr = new T[capacity];
	}

	Array(const Array<T>& copy) :
		capacity(0),
		size(0),
		arr(0)
	{
		copyFrom(copy);
	}

	Array<T>& operator=(const Array<T>& copy)
	{
		copyFrom(copy);
		return *this;
	}

	~Array()
	{
		clear();
	}

	void clear()
	{
		free();
		capacity = 0;
		size = 0;
	}

	//adds an element to the back. (Doubles the capacity if array is already full.)
	void push_back(T& elem)
	{
		if (size == capacity)
		{
			capacity *= 2;  //double the size if capacity is reached
			if (capacity == 0)
				capacity = 1;

			T* new_elems = new T[capacity];
			for (unsigned i = 0; i < size; ++i)
			{
				new_elems[i] = arr[i];
			}
				
			free();
			arr = new_elems;
		}
		assert(capacity > size);
		arr[size] = elem;
		size++;
	}

	//removes the last element. (does not shrink capacity even if many empty slots occur.)
	void pop_back()
	{
		if (size > 0)
		{
			size--;  //warning: what happens, when size == 0?
		}
		else
		{
			std::cout << "Stack is already empty!" << endl;
		}

	}

	Array<T>& operator+=(const T& elem)
	{
		push_back(elem);
		return *this;
	}

	Array<T>& operator+=(const Array<T>& arr)
	{
		for (unsigned i = 0; i<arr.getCount(); ++i)
			push_back(arr.getAt(i));
		return *this;
	}

	unsigned getCount() const
	{
		return size;
	}

	bool isEmpty() const
	{
		return size == 0;
	}

	T& getAt(unsigned idx)
	{
		assert(idx < size);
		return arr[idx];
	}

	T& operator[](unsigned idx)
	{
		return getAt(idx);
	}

	//returns element at index idx. (Assertion fails when invalid index is passed.)
	const T& getAt(unsigned idx) const
	{
		assert(idx < size);
		return arr[idx];
	}

	const T& operator[](unsigned idx) const
	{
		return getAt(idx);
	}

private:
	void free()
	{
		if (arr != 0) delete[] arr;
		arr = 0;
	}

	void copyFrom(const Array<T>& copy)
	{
		if (this == &copy)
			return;
		clear();
		size = copy.size;
		capacity = copy.capacity;
		arr = new T[capacity];
		for (unsigned i = 0; i<size; ++i)
			arr[i] = copy.getAt(i);
	}
};

template<class T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array)
{
	os << "[ ";
	for (unsigned i = 0; i<array.getCount(); ++i)
		os << array.getAt(i) << " ";
	os << "]";

	return os;
}

#endif
