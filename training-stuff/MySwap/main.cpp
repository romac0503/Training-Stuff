// MySwap.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>
void mySwap(T& obj1, T& obj2) 
{ 
	T temp = T();
	temp = obj1;
	obj1 = obj2;
	obj2 = temp;
}

template <class T>
T& myMin(T& obj1, T& obj2) 
{
	return (obj1 < obj2) ? obj1 : obj2;
}

template <class T>
T& myMax(T& obj1, T& obj2)
{
	return (obj1 > obj2) ? obj1 : obj2;
}

int main(int argc, char* argv[])
{
	int a = 5; int b = -3; int c = -14;
	char c1 = 'a'; char c2 = 'z';
	float f1 = 12.34; float f2 = -5.0;

	mySwap(a, b);
	cout << a << " " << b << endl; // gibt "-3 5" aus
	string s1 = "Hallo"; string s2 = "Welt";
	mySwap(s1, s2);
	cout << s1 << " " << s2 << endl; // gibt "Welt Hallo" aus
	float x = -3.1415; float y = 2.718;
	mySwap(x, y);
	cout << x << " " << y << endl; //gibt "2.718 -3.1415" aus
	cout << myMin(a, c) << " " << myMax(a, c) << endl; //gibt "-14 5" aus
	cout << myMin(c2, c1) << " " << myMax(c2, c1) << endl; //gibt "a z" aus
	cout << myMin(f2, f1) << " " << myMax(f1, f2) << endl; //gibt "-5.0 12.34" aus

	cin.get();

	return 0;
}

