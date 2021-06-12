#pragma once
#include "Coordinate.h"
#include <iostream>

class Kuadratik {
private:
	Coordinate zero, one, two;
	float x;
	float result;

	void Calculate();

	// For print coord
	void PrintCoord(Coordinate coord);

public:
	Kuadratik() = default;
	Kuadratik(Coordinate value0, Coordinate value1, Coordinate value2, float valueX);

	void SetZero(Coordinate temp);
	Coordinate GetZero();

	void SetOne(Coordinate temp);
	Coordinate GetOne();

	void SetTwo(Coordinate temp);
	Coordinate GetTwo();

	void SetX(float val);
	float GetX();

	void ShowResult();
};
