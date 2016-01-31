#pragma once
#include "GeometryObject.h"
class Rectangle : public GeometryObject
{
public:
	Rectangle(Vector center, string color, double width, double height);
	virtual ~Rectangle();

	string draw();

protected:
	double width;
	double height;
};

