#include "Interpolasi_Linear.h"
#include "Interpolasi_Kuadratik.h"

int main() {
	Coordinate zero(4, 5), one(7, 9), two(10, 16);

	Linear linear(zero, one, 5);
	linear.ShowResult();

	Kuadratik kuadratik(zero, one, two, 5);
	kuadratik.ShowResult();

	return 0;
}