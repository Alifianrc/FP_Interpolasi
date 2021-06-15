#include "Interpolasi_Kuadratik.h"

Kuadratik::Kuadratik(Coordinate zero, Coordinate one, Coordinate two, float x) {
	result = 0;
	coord[0] = zero;
	coord[1] = one;
	coord[2] = two;

	this->x = x;
}

void Kuadratik::SetCoord(int order, Coordinate val) {
	coord[order] = val;
}
Coordinate Kuadratik::GetCoord(int order) {
	return coord[order];
}

void Kuadratik::SetX(float val) {
	x = val;
}
float Kuadratik::GetX() {
	return x;
}

void Kuadratik::ShowResult() {
	Calculate();

	std::cout << "\n   Hasil perhitungan Interpolasi Kuadratik ";
	std::cout << "untuk x = " << x << " dan titik ";
	PrintCoord(coord[0]);
	std::cout << " ";
	PrintCoord(coord[1]);
	std::cout << " ";
	PrintCoord(coord[2]);
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void Kuadratik::Calculate() {
	// b0 = y0
	float b0 = coord[0].y;

	// b1 = (y1 - y0)/(x1 - x0)
	float b1 = (coord[1].y - coord[0].y) / (coord[1].x - coord[0].x);

	// c1 = (y2 - y1)/(x2 - x1)
	float c1 = (coord[2].y - coord[1].y) / (coord[2].x - coord[1].x);

	// b2 = (c1 - b1)/(x2 - x0)
	float b2 = (c1 - b1) / (coord[2].x - coord[0].x);

	// y = b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1)
	result = b0 + b1 * (x - coord[0].x) + b2 * (x - coord[0].x) * (x - coord[1].x);
}

void Kuadratik::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}