// Stack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "myStack.h"
#include <iostream>

using namespace std;

void TestEmptyStack()
{
	MyStack<unsigned> stack;
	stack.pop();
	try
	{
		stack.top();
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}

	cout << "Test empty stack completed!" << endl;
	cin.get();
}

void TestFullStack()
{
	MyStack<unsigned> stack(1);
	stack.push(42);
	stack.push(69);

	assert(stack.stackSize() == 2);
	cout << "Test full stack completed!" << endl;
	cin.get();
}

void TestExpression()
{
	MyStack<string> stack;
	string expr1 = "{xyz}abc+-x[[[a[cb]k-lm]v](a<s<df>>)]";
	string expr2 = "(([(x+(x-({x+y)}))]oo)poi)";
	string expr3 = "<)";
	
	try
	{
		stack.check(expr1);
	}
	catch (exception const& ex)
	{
		cerr << endl << "Exception: " << ex.what() << endl;
	}

	try
	{
		stack.check(expr2);
	}
	catch (exception const& ex)
	{
		cerr << endl << "Exception: " << ex.what() << endl;
	}

	try
	{
		stack.check(expr3);
	}
	catch (exception const& ex)
	{
		cerr << endl << "Exception: " << ex.what() << endl;
	}

	cout << endl << "Test expression check completed!" << endl;
	cin.get();
}

int main(int argc, char* argv[])
{
	TestEmptyStack();
	TestFullStack();
	TestExpression();

	return 0;
}

