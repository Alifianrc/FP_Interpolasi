#pragma once
#include "Coordinate.h"
#include <iostream>

class Lagrange {
private:
	Coordinate* coord;
	int coordAmount;
	float x;
	float result;
	float* L;

	void Calculate();
	float CalculateL(float xA, float xB);

	// For print coord
	void PrintCoord(Coordinate coord);

public:
	Lagrange() = default;
	Lagrange(int total, float x);

	void SetCoordAmount(int total);
	int GetCoordAmount();

	void SetX(float val);
	float GetX();

	void SetCoord(int order, Coordinate val);
	Coordinate GetCoord(int order);

	void ShowResult();
};