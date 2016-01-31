#include "MyString.h"
#include "StringPrinter.h"
#include <string>

#pragma once

class MyStringPrinter : public StringPrinter
{

public:
	/* Constructors */
	MyStringPrinter(const char*);
	MyStringPrinter(MyString);
	MyStringPrinter(std::string);

	/* Destructor */
	~MyStringPrinter();

	/* Methods */
	void print();
	void info();
	const MyString& get()const;

protected:
	/* Composition */
	MyString* s;
	std::string str;

	/* Helper function */
	std::string returnString(MyString& s);

	
};