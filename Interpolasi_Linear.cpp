#include "Interpolasi_Linear.h"

Linear::Linear(Coordinate value0, Coordinate value1, float valueX) {
	zero.x = value0.x;
	zero.y = value0.y;

	one.x = value1.x;
	one.y = value1.y;

	x = valueX;
}

void Linear::SetZero(Coordinate temp) {
	zero.x = temp.x;
	zero.y = temp.y;
}
Coordinate Linear::GetZero() {
	return zero;
}

void Linear::SetOne(Coordinate temp) {
	one.x = temp.x;
	one.y = temp.y;
}
Coordinate Linear::GetOne() {
	return one;
}

void Linear::SetX(float val) {
	x = val;
}
float Linear::GetX() {
	return x;
}

void Linear::ShowResult() {
	Calculate();

	std::cout << "\n   Hasil perhitungan Interpolasi Linear ";
	std::cout << "Untuk x = " << x << " dan titik ";
	PrintCoord(zero);
	std::cout << " ";
	PrintCoord(one);
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void Linear::Calculate() {
	// y = y0 + (y1 - y0) / (x1 - x0) * (x - x0)
	result = zero.y + (one.y - zero.y) / (one.x - zero.x) * (x - zero.x);
}

void Linear::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}