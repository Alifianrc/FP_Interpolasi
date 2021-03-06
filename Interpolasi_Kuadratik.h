#pragma once
#include "Coordinate.h"
#include <iostream>

class Kuadratik {
private:
	Coordinate coord[3];
	float x;
	float result;

	void Calculate();

	// For print coord
	void PrintCoord(Coordinate coord);

public:
	Kuadratik() = default;
	Kuadratik(Coordinate zero, Coordinate one, Coordinate two, float x);

	void SetCoord(int order, Coordinate val);
	Coordinate GetCoord(int order);

	void SetX(float val);
	float GetX();

	void ShowResult();
};
