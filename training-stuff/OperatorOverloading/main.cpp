// OperatorOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Array.h"
#include <vld.h>
#include <iostream>
#include <string>

using namespace std;

// global variables
int intElements1[] = { 5, 42, 8, 16, 24, 5, 8 };
string strElements1[] = { "Hallo", "wie", "geht", "es", "dir?" };
Array<string> stringArr1(strElements1, 5);
Array<int> intArr1(intElements1, 7);

void TestAssignmentOperator()
{
	// Testing the assignment operator
	Array<int> intArr2 = intArr1;
	Array<string> stringArr2 = stringArr1;

	for (int i = 0; i < 5; i++)
	{
		if (stringArr1[i] != stringArr2[i])
		{
			throw "the elements of the string Arrays are not equal!";
		}
	}

	for (int i = 0; i < 7; i++)
	{
		if (intArr1[i] != intArr2[i])
		{
			throw "the elements of the int Arrays are not equal!";
		}
	}
}

void TestUnevenOperator()
{
	// Initialize Array	with C-Style Array
	string strElements2[] = { "hallo", "wie", "geht", "es", "dir?" };
	int intElements2[] = { 5, 42, 8, 16, 24, 5, 9 };

	Array<int> intArr2(intElements2, 7);
	Array<string> stringArr2(strElements2, 5);

	if (intArr1 == intArr2)
	{
		throw "the elements of the int Arrays are not equal!";
	}

	if (stringArr1 == stringArr2)
	{
		throw "the elements of the string Arrays are not equal!";
	}

	intArr1 = intArr2;
	stringArr1 = stringArr2;

	if (intArr1 != intArr2)
	{
		throw "the elements of the int Arrays are equal!";
	}

	if (stringArr1 != stringArr2)
	{
		throw "the elements of the string Arrays are equal!";
	}
}

void TestCountElement()
{
	assert(stringArr1.count_elem("es") == 1);
	assert(intArr1.count_elem(5) == 2);
}

void TestReverse()
{
	string strElements2[] = { "dir?", "es", "geht", "wie", "hallo" };
	int intElements2[] = { 9, 5, 24, 16, 8, 42, 5 };

	Array<string> stringArr2(strElements2, 5);
	Array<int> intArr2(intElements2, 7);

	stringArr1.reverse();
	intArr1.reverse();
	assert(stringArr1 == stringArr2);
	assert(intArr1 == intArr2);
	
	stringArr1.reverse();
	intArr1.reverse();
}

void TestFindSubArray()
{
	string strElements2[] = { "wie" , "geht", "es"};
	int intElements2[] = { 8, 16 };

	Array<string> stringArr2(strElements2, 3);
	Array<int> intArr2(intElements2, 2);

	assert(stringArr1.findSubArr(stringArr2) == 1);
	assert(intArr1.findSubArr(intArr2) == 2);
}

void TestGetSubArray()
{
	string strElements2[] = { "wie", "geht", "es" };
	int intElements2[] = { 8, 16 };

	Array<string> stringArr2(strElements2, 3);
	Array<int> intArr2(intElements2, 2);

	Array<string> stringArr3 = stringArr1.getSubArr(1, 3);
	Array<int> intArr3 = intArr1.getSubArr(2, 2);

	stringArr3.get_elements();
	intArr3.get_elements();

	assert(stringArr2 == stringArr3);
	assert(intArr2 == intArr2);
}

void TestRemoveElement()
{
	string strElements2[] = { "wie", "geht", "es" };
	int intElements2[] = { 5, 42, 16, 5, 9 };

	Array<string> stringArr2(strElements2, 3);
	Array<int> intArr2(intElements2, 5);

	stringArr1.remove(0);
	intArr1.remove(4);

	stringArr1.removeElement("dir?");
	intArr1.removeElement(8);

	stringArr1.get_elements();
	intArr1.get_elements();

	assert(stringArr1 == stringArr2);
	assert(intArr1 == intArr2);
}

void TestAllUnique()
{
	assert(stringArr1.allUnique());
	assert(!intArr1.allUnique());
}

void TestAllEqual()
{
	string strElements2[] = { "wie", "Wie", "wie" };
	int intElements2[] = { 5, 5, 5, 5, 5 };

	Array<string> stringArr2(strElements2, 3);
	Array<int> intArr2(intElements2, 5);

	assert(!stringArr2.allEqual());
	assert(intArr2.allEqual());

}

void TestGetEveryNthElement()
{
	string strElements2[] = { "dir?", "es", "geht", "wie", "hallo" };
	string strElements3[] = { "es", "wie" };
	int intElements2[] = { 9, 5, 24, 16, 8, 42, 5 };
	int intElements3[] = { 24, 42 };

	Array<string> stringArr2(strElements2, 5);
	Array<string> stringArr3(strElements3, 2);
	Array<int> intArr2(intElements2, 7);
	Array<int> intArr3(intElements3, 2);

	Array<string> stringArr4 = stringArr2.getEveryNthElement(2);
	Array<int> intArr4 = intArr2.getEveryNthElement(3);

	stringArr4.get_elements();
	intArr4.get_elements();

	assert(stringArr3 == stringArr4);
	assert(intArr3 == intArr4);
}

void TestCountDistinctElements()
{
	int numberDistinctElements = stringArr1.countDistinctElements();
	stringArr1.get_elements();
	assert(numberDistinctElements == 3);

	numberDistinctElements = intArr1.countDistinctElements();
	intArr1.get_elements();
	assert(numberDistinctElements == 4);
}

void TestGetDistinctElements()
{
	string strElements2[] = { "es", "geht", "wie" };
	int intElements2[] = { 5, 9, 16, 42 };

	Array<string> stringArr2(strElements2, 3);
	Array<int> intArr2(intElements2, 4);

	Array<string> stringArr3 = stringArr1.getDistinctElements();
	Array<int> intArr3 = intArr1.getDistinctElements();

	assert(stringArr2 == stringArr3);
	assert(intArr2 == intArr3);
}

int main(int argc, char* argv[])
{
	try
	{
		TestAssignmentOperator();
	}
	catch (string& e)
	{
		cout << "Assignment Operator Exception: " << e << endl;
	}
	cout << "Assigment operator Test completed" << endl;

	try
	{
		TestUnevenOperator();
	}
	catch (string& e)
	{
		cout << "Uneven Operator Exception: " << e << endl;
	}
	cout << "Uneven and Even Operator Test completed" << endl;

	TestCountElement();
	cout << "Count element Test completed" << endl;

	TestReverse();
	cout << "Reverse Test completed" << endl;

	TestFindSubArray();
	cout << "Find Sub array Test completed" << endl;

	TestGetSubArray();
	cout << "Get Sub array Test completed" << endl;

	TestRemoveElement();
	cout << "Remove Element Test completed" << endl;

	TestAllUnique();
	cout << "All Unique Test completed" << endl;

	TestAllEqual();
	cout << "All Equal Test completed" << endl;

	TestGetEveryNthElement();
	cout << "Get every Nth Element Test completed" << endl;

	TestCountDistinctElements();
	cout << "Count distinct Elements Test completed" << endl;

	TestGetDistinctElements();
	cout << "Get distinct Elements Test completed" << endl;

	cin.get();
	return 0;
}


	







