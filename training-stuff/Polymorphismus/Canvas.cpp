#include "Canvas.h"
#include <algorithm>


Canvas::Canvas(Vector center, string color, double width, double height) : Rectangle(center, color, width, height)
{
	objects = 0;
	size = 0;
	objects = new GeometryObject*[size];
}


Canvas::~Canvas()
{
	delete[] objects;
	size = 0;
}

void Canvas::addGeometryObject(GeometryObject* obj)
{
	int newSize = size + 1;
	GeometryObject** tempArr = new GeometryObject*[newSize];

	if (size == 0)
	{
		tempArr[0] = obj;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			tempArr[i] = objects[i];
		}
		tempArr[newSize - 1] = obj;
	}

	clear();

	size = newSize;
	objects = tempArr;

	tempArr = 0;
	delete[] tempArr;
}

void Canvas::clear()
{
	if (objects != NULL)
	{
		delete[] objects;
	}
	size = 0;
	objects = 0;
}

string Canvas::output()
{
	string output = "";
	output += "convert -size " + to_string(width) + "x" + to_string(height) + " xc:transparent -draw \"fill " + color + " rectangle " + to_string(center.x) + "," + to_string(center.y) + " " + to_string(width) + "," + to_string(height);

	if (objects != NULL)
	{
		for (int i = 0; i < size; i++)
		{
			output += " ";
			output += objects[i]->draw();
		}
		output += "\"";
		output += " output.gif";
	}

	return output;

}
