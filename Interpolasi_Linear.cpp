#include "Interpolasi_Linear.h"

Linear::Linear(Coordinate zero, Coordinate one, float x) {
	result = 0;
	coord[0] = zero;
	coord[1] = one;

	this->x = x;
}

void Linear::SetCoord(int order, Coordinate val) {
	coord[order] = val;
}
Coordinate Linear::GetCoord(int order) {
	return coord[order];
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
	PrintCoord(coord[0]);
	std::cout << " ";
	PrintCoord(coord[1]);
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void Linear::Calculate() {
	// y = y0 + (y1 - y0) / (x1 - x0) * (x - x0)
	result = coord[0].y + (coord[1].y - coord[0].y) / (coord[1].x - coord[0].x) * (x - coord[0].x);
}

void Linear::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}