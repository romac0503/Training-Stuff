#include <iostream>
#include <stdio.h>
#include "MyStringPrinter.h"

#pragma once


class LowerCaseStringPrinter : public MyStringPrinter
{
private:
	std::string _s;


public:
	/* Constructor */
	LowerCaseStringPrinter(MyString s) : MyStringPrinter(s) { _s = returnString(s); }
	LowerCaseStringPrinter(const char* s) : MyStringPrinter(s) { _s = s; }
	LowerCaseStringPrinter(std::string s) : MyStringPrinter(s) { _s = s; }

	/* Methods */
	virtual void info();
	virtual void print();

};
