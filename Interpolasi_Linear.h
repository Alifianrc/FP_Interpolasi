#pragma once
#include "Coordinate.h"
#include <iostream>

class Linear {
private:
	Coordinate zero, one;
	float x;
	float result;

	void Calculate();

public:
	Linear() = default;
	Linear(Coordinate value0, Coordinate value1, float val);

	void SetZero(Coordinate temp);
	Coordinate GetZero();

	void SetOne(Coordinate temp);
	Coordinate GetOne();

	void SetX(float val);
	float GetX();

	void ShowResult();
};