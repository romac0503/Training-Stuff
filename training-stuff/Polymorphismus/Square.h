#pragma once
#include "Rectangle.h"
class Square : public Rectangle
{
public:
	Square(Vector center, string color, double length);
	virtual ~Square();
};

