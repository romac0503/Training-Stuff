#pragma once	 

#include <string>
#include <iostream>
#include "Vector.h"
#include <math.h>

using namespace std;

class GeometryObject
{
public:
	GeometryObject(Vector center, string color);
	~GeometryObject();

	virtual string draw() = 0;

protected:
	string color;
	Vector center;
};

