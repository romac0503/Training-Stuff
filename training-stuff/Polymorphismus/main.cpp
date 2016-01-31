// Polymorphismus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "GeometryObject.h"
#include "Canvas.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Vector.h"
#include "vld.h"

#include <Magick++.h>
#include <Magick++\Image.h>

using namespace Magick;

int main(int argc, char* argv[])
{

	Canvas image(Vector(300, 100), "yellow", 600, 200);
	Rectangle rectangle(Vector(100, 100), "blue", 80, 40);
	Square square(Vector(300, 100), "green", 100);
	Circle circle(Vector(500, 100), "red", 60);

	image.addGeometryObject(&rectangle);
	image.addGeometryObject(&square);
	image.addGeometryObject(&circle);

	string output = image.output();
	const char* path = output.c_str();

	cout << path << endl;
	cin.get();

	/*InitializeMagick(path);*/

	return 0;

}
