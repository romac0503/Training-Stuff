#include "Tokenizer.h"

Tokenizer::Tokenizer()
{
}

Tokenizer::~Tokenizer()
{
}

list<Token> Tokenizer::tokenize(std::string postFixExpr)
{
	if (postFixExpr.length() != 0)
	{
		const char* c = postFixExpr.c_str();

		list<Token> tokens;
		std::string toTokenNumber = "";
		std::string toTokenOperator = "";


		for (unsigned i = 0; i < postFixExpr.length(); i++)
		{
			// Oh nein! Schon wieder diese Umwandlungen!!! :(

			if (c[i] != ' ')
			{
				// creating the operator for a Token
				if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == ':' || c[i] == '/')
				{
					toTokenOperator = c[i];
					Token token(toTokenOperator);
					tokens.push_back(token);
					toTokenOperator = "";
				}  // creating the number for a Token
				else
				{
					for (; c[i] != ' '; i++)
					{
						toTokenNumber += c[i];
					}
					Token token(toTokenNumber);
					tokens.push_back(token);
					toTokenNumber = "";
				}
			}
		}
		return tokens;
	}
}