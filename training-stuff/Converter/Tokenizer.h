#pragma once

#include "myStack.h"
#include <list>
#include "Token.h"
#include <string>
#include <iostream>

class Tokenizer
{
private: 
	std::string postFixExpr;

public:
	Tokenizer();
	~Tokenizer();

	list<Token> tokenize(std::string postFixExpr);
};