#pragma once

#include "array.h"
#include <stdexcept>
#include <string>

using namespace std;

template <class T>
class MyStack
{
private:
	Array<T> arr;
	void free()
	{
		if (!arr.isEmpty())
		{
			arr.clear();
			arr = 0;
		}
	}

public:
	MyStack(unsigned capacity = 0) : arr(Array<T>(capacity))
	{
	}

	~MyStack()
	{
		free();
	}

	void pop()
	{
		if (!arr.isEmpty())
		{
			arr.pop_back();
		}
	}

	void push(T value)
	{
		arr.push_back(value);
	}

	T& top()
	{
		if (!arr.isEmpty())
		{
			return arr.getAt(arr.getCount() - 1);
		}
		else
		{
			throw out_of_range("Stack<>::top: empty stack");
		}
	}

	unsigned stackSize()
	{
		return arr.getCount();
	}

	void check(std::string& expression)
	{
		const char* c = expression.c_str();
		string msg = expression;

		/*
		** I needed somehow to convert the value from my array to the sign
		** was a bit of an pain in the ass.
		** didn*t found a better solution for now, but this works for now ;)
		*/
		int val;
		char newVal;

		for (unsigned i = 0; i < expression.length(); i++)
		{
			switch (c[i])
			{
			case '{':
				arr.push_back(to_string(c[i]));
				break;
			case '[':
				arr.push_back(to_string(c[i]));
				break;
			case '(':
				arr.push_back(to_string(c[i]));
				break;
			case '<':
				arr.push_back(to_string(c[i]));
				break;
			case '}':
				if (!arr.isEmpty())
				{
					val = stoi(arr.getAt(arr.getCount() - 1));	  // with stoi i am converting the value to an int 
					newVal = val;								  // to convert it back to an char

					if (newVal == '{')
					{
						arr.pop_back();
					}
					else
					{
						msg += " is not correct parenthesised! Found: ";
						msg += c[i];
						msg += "\nExpected: ";
						if (newVal == '(')
						{
							msg += ")";
						}
						else if (newVal == '<')
						{
							msg += ">";
						}
						else
						{
							msg += "]";
						}
						msg += "at position ";
						msg += to_string(i);
						throw out_of_range(msg);
					}
				}
				else
				{
					throw out_of_range("Stack<>::top: empty stack in check function");
				}
				break;
			case ']':
				if (!arr.isEmpty())
				{
					val = stoi(arr.getAt(arr.getCount() - 1));
					newVal = val;

					if (newVal == '[')
					{
						arr.pop_back();
					}
					else
					{
						msg += " is not correct parenthesised! Found: ";
						msg += c[i];
						msg += "\nExpected: ";
						if (newVal == '{')
						{
							msg += "}";
						}
						else if (newVal == '<')
						{
							msg += ">";
						}
						else
						{
							msg += ")";
						}
						msg += " at position ";
						msg += to_string(i);
						throw out_of_range(msg);
					}
				}
				else
				{
					throw out_of_range("Stack<>::top: empty stack in check function");
				}
				break;
			case ')':
				if (!arr.isEmpty())
				{
					val = stoi(arr.getAt(arr.getCount() - 1));
					newVal = val;

					if (newVal == '(')
					{
						arr.pop_back();
					}
					else
					{
						msg += " is not correct parenthesised! Found: ";
						msg += c[i];
						msg += "\nExpected: ";
						if (newVal == '{')
						{
							msg += "}";
						}
						else if (newVal == '<')
						{
							msg += ">";
						}
						else
						{
							msg += "]";
						}
						msg += " at position ";
						msg += to_string(i);
						throw out_of_range(msg);
					}
				}
				else
				{
					throw out_of_range("Stack<>::top: empty stack in check function");
				}
				break;
			case '>':
				if (!arr.isEmpty())
				{
					val = stoi(arr.getAt(arr.getCount() - 1));
					newVal = val;

					if (newVal == '<')
					{
						arr.pop_back();
					}
					else
					{
						msg += " is not correct parenthesised! Found: ";
						msg += c[i];
						msg += "\nExpected ";
						if (newVal == '{')
						{
							msg += "}";
						}
						else if (newVal == '(')
						{
							msg += ")";
						}
						else
						{
							msg += "]";
						}
						msg += " at position ";
						msg += to_string(i);
						throw out_of_range(msg);
					}
				}
				else
				{
					throw out_of_range("Stack<>::top: empty stack in check function");
				}
				break;
			}
			if (arr.isEmpty() && i == expression.length() - 1)
			{
				cout << expression << " is correct parenthesised" << endl;
			}

		}
	}
};

