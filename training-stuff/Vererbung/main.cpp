// Vererbung.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <stdio.h>
#include <iostream> 
#include <vld.h>

#include "A.h"
#include "B.h"
#include "C.h"

void test(B &b);
void testMemLeak();

using namespace std;

int main()
{
	A a(1);
	B b(1, 2);
	C c(1, 2, 3);

	testMemLeak();

	cout << "Adresse von A " << &a.x << endl;
	cout << "Adresse von B " << &b.x << " " << &b.y << endl;
	cout << "Adresse von C " << &c.z << endl;

	test(c);

	cin.get();
	return 0;
}

void test(B &b)
{
	cout << "Membervariable von A: " << &b.A::x << endl;		// Adresse von der Variable x der Klasse A wird ausgegeben
	cout << "Membervariable von B: " << &b.x << endl;
	cout << "Membervariable von B: " << &b.y << endl;
}

void testMemLeak()
{
	A* a = new A(1);
}

