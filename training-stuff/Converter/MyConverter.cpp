#include "MyConverter.h"
#include <string>

Converter::Converter()
{
}

Converter::~Converter()
{
}

std::string Converter::convert(std::string& msg)
{
	if (msg.length() != 0)
	{
		MyStack<char> tempCharStack;
		MyStack<string> tempStringStack;
		MyStack<char> reverseStack;	   // Stack reverses all the numbers to have better excess

		for (unsigned i = 0; i < msg.length(); i++)
		{
			char t = msg.at(i);

			if (t != '+' && t != '-' && t != '*' && t != ':' && t != '/')
			{
				reverseStack.push(t);	 // here the numbers get stored in the opposite order to better make the target expression
			}
			else
			{
				postToInfix(tempStringStack, tempCharStack, reverseStack, t);
			}
		}

		if (tempStringStack.stackSize() != 0)
		{
			string stringToCheck = tempStringStack.top();
			tempStringStack.check(stringToCheck);
			return tempStringStack.top();
		}
		else
		{
			cout << "return msg" << endl;
			return msg;
		}
	}
	else
	{
		cout << "return empty string" << endl;
		return "";
	}
}

// helper function
void Converter::postToInfix(MyStack<string>& stringStack, MyStack<char>& charStack, MyStack<char>& reverseStack, char& sign)
{
	string tempString = "";

	while (reverseStack.stackSize() != 0)
	{
		charStack.push(reverseStack.top());
		reverseStack.pop();
	}
	if (stringStack.stackSize() == 1 && charStack.stackSize() == 2)
	{
		tempString = "";
		tempString += "(";
		tempString += charStack.top();
		tempString += sign;
		charStack.pop();
		tempString += charStack.top();
		tempString += ")";
		charStack.pop();
		stringStack.push(tempString);
	}
	else if (stringStack.stackSize() == 1 && charStack.stackSize() == 1)
	{
		tempString = "";
		tempString += '(';
		tempString += stringStack.top();
		stringStack.pop();
		tempString += sign;
		tempString += charStack.top();
		charStack.pop();
		tempString += ')';
		stringStack.push(tempString);
	}
	else if (stringStack.stackSize() == 2)
	{
		tempString = "";
		string secondExpr = stringStack.top();
		stringStack.pop();
		string firstExpr = stringStack.top();
		stringStack.pop();
		tempString += '(';
		tempString += firstExpr;
		tempString += sign;
		tempString += secondExpr;
		tempString += ')';
		stringStack.push(tempString);
	}
	else
	{
		tempString = "";
		tempString += "(";
		tempString += charStack.top();
		tempString += sign;
		charStack.pop();
		tempString += charStack.top();
		tempString += ")";
		charStack.pop();
		stringStack.push(tempString);
	}
}

std::string Converter::infixToPrefix(std::string msg)
{
	if (!msg.empty())
	{
		MyStack<string> finalExpr;
		finalExpr.check(msg);
		char sign = ' ';
		string expr = "";
		MyStack<char> reverseNumbers;

		for (unsigned i = 0; i < msg.length(); i++)
		{
			if (msg.at(i) == '(')
			{
				continue;
			}
			else
			{
				while (msg.at(i) != ')')
				{

					if (msg.at(i) != '+' && msg.at(i) != '-' && msg.at(i) != '*' && msg.at(i) != '/' && msg.at(i) != ':')
					{
						if (msg.at(i) != '(' && msg.at(i) != ')')
						{
							reverseNumbers.push(msg.at(i));
							i++;
						}
						else if (sign != ' ' && reverseNumbers.stackSize() == 1 && msg.at(i) == '(')
						{
							expr = "";
							expr += sign;
							string number = to_string(reverseNumbers.top());
							reverseNumbers.pop();
							int val = stoi(number);
							char newVal = val;
							expr += newVal;
							finalExpr.push(expr);
							sign = ' ';
							i++;
						}
						else
						{
							i++;
						}
					}
					else
					{
						sign = msg.at(i);

						if (finalExpr.stackSize() != 0 && sign != ' ' && reverseNumbers.stackSize() == 0)
						{
							expr = "";
							expr += sign;
							sign = ' ';
							expr += finalExpr.top();
							finalExpr.pop();
							finalExpr.push(expr);
						}
						i++;
					}
				}
				if (finalExpr.stackSize() == 1 && sign != ' ')
				{
					expr = "";
					string secongNumber = to_string(reverseNumbers.top());
					reverseNumbers.pop();
					int val2 = stoi(secongNumber);
					char newVal2 = val2;
					string firstNumber = to_string(reverseNumbers.top());
					reverseNumbers.pop();
					int val1 = stoi(firstNumber);
					char newVal1 = val1;
					expr += finalExpr.top();
					finalExpr.pop();
					expr += sign;
					sign = ' ';
					expr += newVal1;
					expr += newVal2;
					finalExpr.push(expr);
				}
				else if (finalExpr.stackSize() == 1 && reverseNumbers.stackSize() == 1)
				{
					expr = "";
					expr += finalExpr.top();
					expr += reverseNumbers.top();
					reverseNumbers.pop();
					sign = ' ';
					finalExpr.pop();
					finalExpr.push(expr);
				}
				else if (finalExpr.stackSize() == 0)
				{
					expr = "";
					string secongNumber = to_string(reverseNumbers.top());
					reverseNumbers.pop();
					int val2 = stoi(secongNumber);
					char newVal2 = val2;
					string firstNumber = to_string(reverseNumbers.top());
					reverseNumbers.pop();
					int val1 = stoi(firstNumber);
					char newVal1 = val1;
					expr += sign;
					sign = ' ';
					expr += newVal1;
					expr += newVal2;
					finalExpr.push(expr);
				}
			}
		}
		if (finalExpr.stackSize() != 0)
		{
			return finalExpr.top();
		}
	}
}

void Converter::showTree(std::string expr)
{
	int level = 0;
	int numberLevel = 0;
	int numberCount = 0;
	bool isMaxLevel = false;
	MyStack<char> stack;
	MyStack<char> reverseStack;

	for (unsigned i = 0; i < expr.length(); i++)
	{
		char c = expr.at(i);
		stack.push(c);
	}

	while (stack.stackSize() != 0)
	{
		char c = stack.top();
		reverseStack.push(c);
		stack.pop();
	}

	while (reverseStack.stackSize() != 0)
	{
		char c = reverseStack.top();

		if (c == '+' || c == '-' || c == '*' || c == '/' || c == ':')
		{
			numberCount = 0;

			if (!isMaxLevel)
			{
				for (int i = 0; i < level; i++)
				{
					cout << " ";
				}
				level++;
				cout << c << endl;
				reverseStack.pop();
			}
			else
			{	
				for (int i = 0; i < level-1; i++)
				{
					cout << " ";
				}
				cout << c << endl;
				reverseStack.pop();
			}
			
		}
		else if (c >= '0' && c <= '9')
		{

			numberCount++;

			if (reverseStack.stackSize() == 1 && numberCount == 3)
			{
				cout << " " << c;
				reverseStack.pop();
				break;
			}

			isMaxLevel = true;

			if (numberCount == 3)
			{
				level--;
				numberCount = 0;
			}

			for (int i = 0; i < level; i++)
			{
				cout << " ";
			}
			cout << c << endl;
			reverseStack.pop();
		}
	}
}