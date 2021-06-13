#include "Interpolasi_Beda-Terbagi-Newton.h"

BedaNewton::BedaNewton(Coordinate zero, Coordinate one, Coordinate two, Coordinate three, float x) {
	coord[0] = zero;
	coord[1] = one;
	coord[2] = two;
	coord[3] = three;

	this->x = x;
}

void BedaNewton::SetX(float val) {
	x = val;
}
float BedaNewton::GetX() {
	return x;
}

void BedaNewton::SetCoord(int order, Coordinate val) {
	coord[order] = val;
}
Coordinate BedaNewton::GetCoord(int order) {
	return coord[order];
}

void BedaNewton::ShowResult() {
	Calculate();

	std::cout << "\n   Hasil perhitungan Interpolasi Kuadratik ";
	std::cout << "untuk x = " << x << " dan titik ";
	for (int i = 0; i < 4; i++) {
		PrintCoord(coord[i]); std::cout << " ";
	}
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void BedaNewton::Calculate() {
	// b0 = y0
	float b0 = coord[0].y;

	// b1 = (y1 - y0)/(x1 - x0)
	float b1 = (coord[1].y - coord[0].y) / (coord[1].x - coord[0].x);

	// c1 = (y2 - y1)/(x2 -x1)
	float c1 = (coord[2].y - coord[1].y) / (coord[2].x - coord[1].x);

	// d1 = (y3 - y2)/(x3 - x2)
	float d1 = (coord[3].y - coord[2].y) / (coord[3].x - coord[2].x);

	// b2 = (c1 - b1)/(x2 - x0) problem
	float b2 = (c1 - b1) / (coord[2].x - coord[0].x);

	// c2 = (d1 - c1)/(x3 - x1)
	float c2 = (d1 - c1) / (coord[3].x - coord[1].x);

	// b3 = (c2 - b2)/(x3 - x0)
	float b3 = (c2 - b2) / (coord[3].x - coord[0].x);

	// y = b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1) + b3 * (x - x0) * (x - x1) * (x - x2)
	result = b0 + (b1 * (x - coord[0].x)) + (b2 * (x - coord[0].x) * (x - coord[1].x)) + (b3 * (x - coord[0].x) * (x - coord[1].x) * (x - coord[2].x));
}

void BedaNewton::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}