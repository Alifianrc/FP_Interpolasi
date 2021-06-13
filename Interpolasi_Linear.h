#pragma once
#include "Coordinate.h"
#include <iostream>

class Linear {
private:
	Coordinate coord[2];
	float x;
	float result;

	void Calculate();

	// For print coord
	void PrintCoord(Coordinate coord);

public:
	Linear() = default;
	Linear(Coordinate zero, Coordinate one, float x);

	void SetCoord(int order, Coordinate val);
	Coordinate GetCoord(int order);

	void SetX(float val);
	float GetX();

	void ShowResult();
};