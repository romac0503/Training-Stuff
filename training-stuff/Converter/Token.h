#pragma once

#include <string>

struct Token
{
	std::string expression = "";

	Token(std::string expr) :expression(expr) { }
};