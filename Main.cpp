#include "Interpolasi_Linear.h"

int main() {
	Coordinate zero(4, 5), one(7, 6);
	Linear linear(zero, one, 5);

	linear.ShowResult();

	return 0;
}