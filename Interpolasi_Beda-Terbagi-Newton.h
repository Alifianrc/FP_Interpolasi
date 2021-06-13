#pragma once
#include "Coordinate.h"
#include <iostream>

class BedaNewton {
private:
	Coordinate coord[4];
	float x;
	float result;

	void Calculate();

	void PrintCoord(Coordinate coord);

public:
	BedaNewton() = default;
	BedaNewton(Coordinate zero, Coordinate one, Coordinate two, Coordinate three, float x);
	
	void SetX(float val);
	float GetX();

	void SetCoord(int order, Coordinate val);
	Coordinate GetCoord(int order);

	void ShowResult();
};