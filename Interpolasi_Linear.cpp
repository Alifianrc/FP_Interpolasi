#include "Interpolasi_Linear.h"

Linear::Linear(Coordinate value0, Coordinate value1, float val) {
	zero.x = value0.x;
	zero.y = value0.y;

	one.x = value1.x;
	one.y = value1.y;

	x = val;
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

	std::cout << "Untuk x = " << x << " dan titik " << "(" << zero.x << "," << zero.y << ")   (" << one.x << "," << one.y << ") :\n";
	std::cout << "y = " << result << "\n\n";
}

void Linear::Calculate() {
	// y = y0 + (y1 - y0) / (x1 - x0) * (x - x0)

	result = zero.y + (one.y - zero.y) / (one.x - zero.x) * (x - zero.x);
}