#include "myStack.h"


template <class T>
MyStack<T>::MyStack(unsigned capacity) : arr(Array<T>(capacity)) { }

template <class T>
MyStack<T>::~MyStack()
{
	free();
}

template <class T>
void MyStack<T>::free()
{
	if (!arr.isEmpty())
	{
		arr.clear();
		arr = 0;
	}
}

template <class T>
void MyStack<T>::pop()
{
	if (!arr.isEmpty())
	{
		arr.pop_back();
	}
}

template <class T>
T& MyStack<T>::top()
{
	if (!arr.isEmpty())
	{
		return arr.getAt(arr.getCount() - 1);
	}
}

template <class T>
void MyStack<T>::push(T& value)
{
	arr.push_back(value);
}

