#include "TokenConverter.h"

TokenConverter::TokenConverter(list<Token>  tokens) : tokens(tokens)
{
}

TokenConverter::TokenConverter(std::string expr)
{
	Tokenizer tokenizer;
	tokens = tokenizer.tokenize(expr);
}

TokenConverter::~TokenConverter()
{
	if (!tokens.empty())
	{
		tokens.clear();
	}
}

std::string TokenConverter::convertTokens()
{
	if (!tokens.empty())
	{
		MyStack<string> operatorStack;	  // + , -, *, etc.
		MyStack<string> operandStack;    // 1, 2, etc.	-> will give the full parenthised expression back
		MyStack<string> expressionStack;

		for (list<Token>::iterator it = tokens.begin(); it != tokens.end(); it++)
		{
			Token t = *it;
			string expr = t.expression;

			if (expr != "+" && expr != "-" && expr != "*" && expr != ":" && expr != "/")
			{
				expressionStack.push(expr);
			}
			else
			{
				doTokenConvert(operandStack, operatorStack, expressionStack, expr);		 // hier ist noch ein Fehler drin!!!
			}
		}

		if (operandStack.stackSize() != 0)
		{
			string stringToCheck = operandStack.top();
			operandStack.check(stringToCheck);
			return operandStack.top();
		}
		else
		{
			cout << "return msg" << endl;
			return getTokenExpr();
		}
	}
	else
	{
		return "";
	}
}

// helper function for Tokens
void TokenConverter::doTokenConvert(MyStack<string>& operandStack, MyStack<string>& operatorStack, MyStack<string>& expressionStack, string sign)
{
	string tempString = "";

	while (expressionStack.stackSize() != 0)
	{
		operandStack.push(expressionStack.top());   // operandStack stores all the numbers
		expressionStack.pop();
	}
	if (operandStack.stackSize() == 1 && operatorStack.stackSize() == 2)
	{
		tempString = "";
		tempString += "(";
		tempString += operandStack.top();
		tempString += sign;
		operandStack.pop();
		tempString += operandStack.top();
		tempString += ")";
		operandStack.pop();
		operandStack.push(tempString);
	}
	else if (operandStack.stackSize() == 1 && operatorStack.stackSize() == 1)
	{
		tempString = "";
		tempString += '(';
		tempString += operandStack.top();
		operandStack.pop();
		tempString += sign;
		tempString += operandStack.top();
		operandStack.pop();
		tempString += ')';
		operandStack.push(tempString);
	}
	else if (operandStack.stackSize() == 2)
	{
		tempString = "";
		string secondExpr = operandStack.top();
		operandStack.pop();
		string firstExpr = operandStack.top();
		operandStack.pop();
		tempString += '(';
		tempString += firstExpr;
		tempString += sign;
		tempString += secondExpr;
		tempString += ')';
		operandStack.push(tempString);
	}
	else
	{
		tempString = "";
		tempString += "(";
		tempString += operandStack.top();
		tempString += sign;
		operandStack.pop();
		tempString += operandStack.top();
		tempString += ")";
		operandStack.pop();
		operandStack.push(tempString);
	}
}

std::string TokenConverter::getTokenExpr()
{
	if (!tokens.empty())
	{
		string returnMsg = "";

		for (list<Token>::iterator it = tokens.begin(); it != tokens.end(); it++)
		{
			Token t = *it;
			returnMsg += t.expression;
		}
		return returnMsg;
	}
	return "";
}