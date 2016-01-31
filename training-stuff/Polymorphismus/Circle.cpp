#include "Circle.h"


Circle::Circle(Vector center, string color, double radius) : GeometryObject(center, color)
{
	this->radius = radius;
}


Circle::~Circle()
{
}

string Circle::draw()
{
	string output = "";
	output += "fill ";
	output += color;
	output += " circle";
	output += " " + to_string(center.x) + "," + to_string(center.y) + " " + to_string(center.x + radius) + "," + to_string(radius);

	return output;
}
