#pragma once
#include "Coordinate.h"
#include "Interpolasi_Linear.h"
#include "Interpolasi_Kuadratik.h"
#include "Interpolasi_Beda-Terbagi-Newton.h"
#include "Interpolasi_Lagrange.h"

class Interpolasi {
public:
	virtual void SetCoord(int order, Coordinate val) = 0;
	virtual Coordinate GetCoord(int order) = 0;

	virtual void SetX(float val) = 0;
	virtual float GetX() = 0;

	virtual void ShowResult() = 0;
};
