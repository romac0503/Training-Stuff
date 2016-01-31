#include <vld.h>
#include "MyString.h"
#include <string>
#include <stdio.h>
#include <cassert>
#include <iostream>


using namespace std;

MyString::MyString() :size(0), data(0)
{
	cerr << "Default constructor\n";
}

MyString::MyString(const char* arr) : size(0), data(0)
{
	cerr << "Zweiter constructor\n";

	size = (unsigned int)strlen(arr) + 1;
	data = new char[size];

	for (unsigned int i = 0; i < size; i++) data[i] = arr[i];
	data[size - 1] = '\0';
}

MyString::MyString(const MyString& other) :data(0)
{
	std::cerr << "copy constructor" << endl;
	*this = other;
}


MyString& MyString::operator=(const MyString& other)
{
	cerr << "assignment operator" << endl;
	if (this == &other)
		return *this;
	assert((unsigned)strlen(other.data) != 0);

	clear();		// this is maybe not neccessary, because I get some error!

	size = other.size;
	data = new char[size];

	for (unsigned int i = 0; i < size; i++)
		data[i] = other.data[i];
	data[size - 1] = '\0';

	cin.get();
	return *this;
}

MyString::~MyString()
{
	cerr << "destructor" << endl;
	clear();
}

void MyString::clear()
{
	if (data != 0){
		delete[] data;
		data = 0;
		size = 0;
	}
	else {
		cerr << "das array ist schon leer" << endl;
	}
}

char MyString::get(unsigned i) const
{
	if (check_index(i) && !check_IsEmpty())
		return data[i];
	//else cerr << "wrong index to get" << endl;
}

void MyString::set(unsigned i, char c)
{
	if (check_index(i) && !check_IsEmpty())
		data[i] = c;
	else cerr << "wrong index to set!" << endl;
}

void MyString::append(const MyString& otherStr)
{
	if (otherStr.size != 0)
	{
		int sum_length = size + otherStr.size - 1;
		
		MyString myNewString;
		myNewString.size = sum_length;
		myNewString.data = new char[sum_length];

		for (unsigned int i = 0; i < size - 1; i++)
			myNewString.data[i] = data[i];

		unsigned j = 0;
		for (int i = size - 1; j < otherStr.size - 1; i++, j++)
		{
			myNewString.data[i] = otherStr.data[j];
		}
		myNewString.data[sum_length - 1] = '\0';

		clear();

		*this = myNewString;
	}
}

void MyString::print() const
{
	int i = 0;
	while (data[i] != '\0')
	{
		cout << data[i];
		i++;
	}
	cout << endl;
}

bool MyString::check_index(unsigned int i) const
{
	if (i < (size-1)) return true;
	return false;
}

bool MyString::check_IsEmpty() const
{
	if (data != 0) return false;
	else return true;
}




