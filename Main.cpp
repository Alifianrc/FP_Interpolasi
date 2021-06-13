#include "Interpolasi_Linear.h"
#include "Interpolasi_Kuadratik.h"
#include "Interpolasi_Beda-Terbagi-Newton.h"
#include "Interpolasi_Lagrange.h"
#include <list>

int main() {
	// EXAMPLE MAIN

	Coordinate zero(1, 3), one(4, 5), two(7, 9), three(10, 16);

	Linear linear(zero, one, 5);
	linear.ShowResult();

	Kuadratik kuadratik(zero, one, two, 5);
	kuadratik.ShowResult();

	BedaNewton newton(zero, one, two, three, 5);
	newton.ShowResult();

	Lagrange lagrange(3, 5);
	lagrange.SetCoord(0, zero);
	lagrange.SetCoord(1, one);
	lagrange.SetCoord(2, two);
	lagrange.ShowResult();

	return 0;
}