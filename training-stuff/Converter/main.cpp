
// Converter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "MyConverter.h"
#include "TokenConverter.h"
#include "Token.h"
#include "vld.h"

using namespace std;

void TestPostToInfix()
{
	string postStr = "34+5*62:-";
	Converter conv;

	try
	{
		string infStr = conv.convert(postStr);
		cout << "############# String Stack Test #############" << endl;
		cout << "Postfix Expression: \t" << postStr << endl;
		cout << "Infix Expression: \t" << infStr << endl;
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}
	cout << endl;
	cin.get();
}

void TestPostToInfixTokens()
{
	Token t1("15");
	Token t2("105");
	Token op1("+");
	Token t3("42");
	Token t4("7");
	Token op2("/");
	Token op3("*");

	list<Token> tokens;
	tokens.push_back(t1);
	tokens.push_back(t2);
	tokens.push_back(op1);
	tokens.push_back(t3);
	tokens.push_back(t4);
	tokens.push_back(op2);
	tokens.push_back(op3);

	TokenConverter conv(tokens);

	try
	{
		string infStr = conv.convertTokens();
		cout << "############# Token Stack Test #############" << endl;
		cout << "Postfix Expression: \t" << conv.getTokenExpr() << endl;
		cout << "Infix Expression: \t" << infStr << endl;
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}
	cout << endl;
	cin.get();
}

void TestTokenizer()
{
	string postStr = "34+5*62:-";
	string postStrWithSpace = "3 4 + 5*6 2 : -";

	TokenConverter conv(postStrWithSpace);
	string postStrConverted = conv.getTokenExpr();

	cout << "############# Tokenizer Test #############" << endl;
	assert(postStr == postStrConverted);
	cout << "Postfixstring with space \t" << postStrWithSpace << endl;
	cout << "Postfixstring tokenized \t" << postStrConverted << endl;
	cout << "Tokenizer Test completed!" << endl << endl;
	cin.get();
}

void TestInfixToPrefix()
{
	string infixStr = "(((3+4)*5)-(6:2))";
	string infixStr2 = "(((3+4)*(5+6))+8)";
	Converter conv;

	try
	{
		cout << "############# Infix to Prefix Test #############" << endl;
		string prefixStr = conv.infixToPrefix(infixStr);
		cout << "Infixstring 1 \t" << infixStr << endl;
		cout << "Prefixstring 1 \t" << prefixStr << endl << endl;
		cout << "Prefixstring: " << prefixStr << " as a tree" << endl << endl;
		conv.showTree(prefixStr);
		cout << endl;

		string prefixStr2 = conv.infixToPrefix(infixStr2);
		cout << "Infixstring 2 \t" << infixStr2 << endl;
		cout << "Prefixstring 2 \t" << prefixStr2 << endl << endl;
		cout << "Prefixstring: "<< prefixStr2 << " as a tree" << endl << endl;
		conv.showTree(prefixStr2);
		cout << endl << endl;
		cout << "############# Infix to Prefix Test completed! #############" << endl;
	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
	}
	cout << endl;
	cin.get();
}

int main(int argc, char* argv[])
{													 
	TestPostToInfix();
	TestPostToInfixTokens();
	TestTokenizer();
	TestInfixToPrefix();
	cin.get();
	return 0;
}

