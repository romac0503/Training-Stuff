#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <GLUT/glut.h>


class Branch
{
private:
	std::vector<glm::vec2> points;

public:
	Branch();

	~Branch();

	void AddPoint(glm::vec2 point){
		points.push_back(point);
	}

	std::vector<glm::vec2> getPoints(){
		return points;
	}
};

