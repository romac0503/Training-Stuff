#pragma once

#include "myStack.h"
#include <list>
#include "Token.h"

class Converter
{
private:
	void postToInfix(MyStack<string>& expressionStack, MyStack<char>& charStack, MyStack<char>& reverseStack, char& sign);

public:
	Converter();
	~Converter();

	std::string convert(std::string& expr);
	std::string infixToPrefix(std::string msg);
	void showTree(std::string expr);
};