#include "Interpolasi_Lagrange.h"

Lagrange::Lagrange(int total, float x) {
	result = 0;
	coord = new Coordinate[total];
	coordAmount = total;
	L = new float[total];

	this->x = x;
}
Lagrange::~Lagrange() {
	delete coord;
	delete L;
}

void Lagrange::SetCoordAmount(int total) {
	free(coord);
	free(L);
	
	coord = new Coordinate[total];
	coordAmount = total;
	L = new float[total];
}
int Lagrange::GetCoordAmount() {
	return coordAmount;
}

void Lagrange::SetX(float val) {
	x = val;
}
float Lagrange::GetX() {
	return x;
}

void Lagrange::SetCoord(int order, Coordinate val) {
	coord[order] = val;
}
Coordinate Lagrange::GetCoord(int order) {
	return coord[order];
}

void Lagrange::ShowResult() {
	Calculate();

	std::cout << "\n   Hasil perhitungan Interpolasi Kuadratik ";
	std::cout << "untuk x = " << x << " dan titik ";
	for (int i = 0; i < coordAmount; i++) {
		PrintCoord(coord[i]); std::cout << " ";
	}
	std::cout << "  :\n";
	std::cout << "   y = " << result << "\n";
}

void Lagrange::Calculate() {
	// Calculate L
	for (int i = 0; i < coordAmount; i++) {
		// karena jika L = 0 maka perkalian hasilnya 0
		L[i] = 1;

		for (int j = 0; j < coordAmount; j++) {
			if (i != j) {
				L[i] *= CalculateL(coord[i].x, coord[j].x);
			}
		}
	}

	// Calculate y
	for (int i = 0; i < coordAmount; i++) {
		result += (L[i] * coord[i].y);
	}
}
float Lagrange::CalculateL(float xA, float xB) {
	// return (Li) = (x - xj) / (xi - xj)
	float temp = (x - xB) / (xA - xB);

	return temp;
}

void Lagrange::PrintCoord(Coordinate coord) {
	std::cout << "(" << coord.x << "," << coord.y << ")";
}