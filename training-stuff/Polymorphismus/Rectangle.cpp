#include "Rectangle.h"


Rectangle::Rectangle(Vector center, string color, double width, double height) : GeometryObject(center, color)
{
	this->width = width;
	this->height = height;
}


Rectangle::~Rectangle()
{
}

string Rectangle::draw()
{
	string output = "";
	output += "fill ";
	output += color;
	output += " rectangle";
	output += " " + to_string(center.x - width / 2) + "," + to_string(center.y - height / 2) + " " + to_string(width/2) + "," + to_string(height/2);

	return output;
}
