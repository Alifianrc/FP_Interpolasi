#include "Interpolasi_Kuadratik.h"

Kuadratik::Kuadratik(Coordinate value0, Coordinate value1, Coordinate value2, float valueX) {
	zero.x = value0.x;
	zero.y = value0.y;

	one.x = value1.x;
	one.y = value1.y;

	two.x = value2.x;
	two.y = value2.y;

	x = valueX;
}

void Kuadratik::SetZero(Coordinate temp) {
	zero.x = temp.x;
	zero.y = temp.y;
}
Coordinate Kuadratik::GetZero() {
	return zero;
}

void Kuadratik::SetOne(Coordinate temp) {
	one.x = temp.x;
	one.y = temp.y;
}
Coordinate Kuadratik::GetOne() {
	return one;
}

void Kuadratik::SetTwo(Coordinate temp) {
	two.x = temp.x;
	two.y = temp.y;
}
Coordinate Kuadratik::GetTwo() {
	return two;
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
	PrintCoord(zero);
	std::cout << " ";
	PrintCoord(one);
	std::cout << " ";
	PrintCoord(two);
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void Kuadratik::Calculate() {
	// b0 = y0
	float b0 = zero.y;

	// b1 = (y1 - y0)/(x1 - x0)
	float b1 = (one.y - zero.y) / (one.x - zero.x);

	// c1 = (y2 - y1)/(x2 - x1)
	float c1 = (two.y - one.y) / (two.x - one.x);

	// b2 = (c1 - b1)/(x2 - x0)
	float b2 = (c1 - b1) / (two.x - zero.x);

	// y = b0 + b1 * (x - x0) + b2 * (x - x0) * (x - x1)
	result = b0 + b1 * (x - zero.x) + b2 * (x - zero.x) * (x - one.x);
}

void Kuadratik::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}