#pragma once
#include "GeometryObject.h"
class Circle : public GeometryObject
{
public:
	Circle(Vector center, string color, double radius);
	virtual ~Circle();

	string draw();

protected:
	double radius;
};

