#pragma once
#include "Rectangle.h"
class Canvas :
	public Rectangle
{
public:
	Canvas(Vector center, string color, double width, double height);
	virtual ~Canvas();

	void addGeometryObject(GeometryObject* object);
	string output();

private:
	GeometryObject** objects;
	double size;
	void clear();
};

