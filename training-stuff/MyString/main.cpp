// MyString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>
#include <vld.h>

using namespace std;

int main(int argc, char* argv[])
{
	cerr << "***** 1.Step ******" << endl;
	MyString leer;
	leer.set(0, 'A');
	
	cerr << "****** 2.Step ******" << endl;
	MyString hallo("Hallo");
	hallo.set(0, 'h');
	hallo.print();
	hallo.append(" du!");
	hallo.print();
	
	cerr << "****** 3.Step ******" << endl;
	std::cout << hallo.get(9) << std::endl;

	cerr << "****** 4.Step ******" << endl;
	MyString cpy = hallo;
	cpy.set(1, 'o');

	cerr << "****** 5.Step ******" << endl;
	hallo.print();
	cpy.print();
	leer = hallo;
	hallo.set(8, '?');
	leer.print();
	cpy.print();

	cerr << "***** 6.Step ******" << endl;
	MyString cpy2(cpy);
	cin.get();

	return 0;
}

