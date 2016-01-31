#pragma once

#include "myStack.h"
#include <list>
#include "Token.h"
#include "Tokenizer.h"

class TokenConverter
{
private:
	list<Token> tokens;
	void doTokenConvert(MyStack<string>& operandStack, MyStack<string>& operatorStack, MyStack<string>& expressionStack, string sign);

public:
	TokenConverter(list<Token>  tokens);
	TokenConverter(std::string expr);
	~TokenConverter();

	std::string convertTokens();
	std::string getTokenExpr();
};