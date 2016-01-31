#include "stdafx.h"
#include "StringPrinter.h"
#include "LowerCaseStringPrinter.h"
#include "UpperCaseStringPrinter.h"
#include "StarFrameStringPrinter.h"
#include "MyStringPrinter.h"
#include <vld.h>

using namespace std;

int main(int argc, char* argv[])
{
	StringPrinter* stringPrinters[5];
	string a1 = "Hallo wie laufts!";
	const char a2[] = { 'D', 'a', 'n', 'k', 'e', '\0' };

	MyStringPrinter myStrPr1(a1);
	MyStringPrinter myStrPr2("Servus");
	MyStringPrinter myStrPr3(a2);

	MyString myString("MyString");

	myStrPr1.print();

	LowerCaseStringPrinter lwCaseStrPr1(myString);
	UpperCaseStringPrinter upCaseStrPr1("UpperCaseStringPrinter");
	StarFrameStringPrinter stStringPrinter("StarStringPrinter");

	stringPrinters[0] = &myStrPr1;
	stringPrinters[1] = &myStrPr2;
	stringPrinters[2] = &myStrPr3;
	stringPrinters[3] = &upCaseStrPr1;
	stringPrinters[4] = &lwCaseStrPr1;

	/*
	* printing every class derived from StringPrinter
	*/
	for (unsigned i = 0; i < 5; i++)
		stringPrinters[i]->print();

	stStringPrinter.print();

	cin.get();

	return 0;
}

