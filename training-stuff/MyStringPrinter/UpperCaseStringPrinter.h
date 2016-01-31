#include "MyStringPrinter.h"

#pragma once

class UpperCaseStringPrinter : public MyStringPrinter
{
private:
	std::string _s;

public:
	UpperCaseStringPrinter(MyString s) : MyStringPrinter(s) { _s = returnString(s); }
	UpperCaseStringPrinter(const char* s) : MyStringPrinter(s) { _s = s; }
	UpperCaseStringPrinter(std::string s) : MyStringPrinter(s) { _s = s; }

	void print();
	void info();

};
