#include "MyStringPrinter.h"
#include <string>
#include <iostream>

using namespace std;

MyStringPrinter::MyStringPrinter(MyString myString)
{
	s = new MyString(myString);
}

MyStringPrinter::MyStringPrinter(const char* arr)
{
	if (arr != NULL){
		unsigned size = (unsigned int)strlen(arr) + 1;
		s = new MyString(arr);
	}
}

MyStringPrinter::MyStringPrinter(string myString)
{
	if (myString.capacity() != 0){
		str = myString;

		char* tmp = new char[myString.capacity() + 1];
		strcpy(tmp, myString.c_str());
		s = new MyString(tmp);

		delete[] tmp;
	}
}

MyStringPrinter::~MyStringPrinter()
{
	if (s != NULL)
	{
		delete s;
	}
}

std::string MyStringPrinter::returnString(MyString& s)
{
	if (!s.check_IsEmpty())
	{
		std::string tmp_string = "";

		unsigned i = 0;
		while (s.check_index(i))
		{
			char tmp_char = s.get(i);
			tmp_string += tmp_char;
			i++;
		}
		tmp_string += '\0';

		return tmp_string;
	}
	return "MyString is empty!";
}

void MyStringPrinter::print()
{
	if (!s->check_IsEmpty())
	{
		s->print();
	}
	else 
	{
		cerr << "das array ist leer!" << endl;
		cin.get();
	}
}

void MyStringPrinter::info()
{
	cerr << "MyStringPrinter gibt den String unformatiert aus." << endl;
}

const MyString& MyStringPrinter::get() const
{
	if (!s->check_IsEmpty()){
		return *s;
	}
	else return NULL;
}





