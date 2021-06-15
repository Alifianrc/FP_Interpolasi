#include "Interpolasi.h"
#include <vector>

void InputProcess(std::vector<Coordinate*>& vect, short c_amount)
{
	for (short i = 0; i < c_amount; i++)
	{
		std::cout << "Input koordinat " << i + 1 << ":\n";
		std::cout << "x: ";
		float x = 0;
		std::cin >> x;
		std::cout << "y: ";
		float y = 0;
		std::cin >> y;
		vect.push_back(new Coordinate(x, y));
	}
}

int main() {
	/* Initialization */
	std::cout << "Initializing...\n";
	bool running = true;
	std::vector<Coordinate*> coordinates;

	/* Running loop */
	while (running)
	{
		system("cls");
		std::cout << "Pilih aksi:\n1. Interpolasi Linear\n2. Interpolasi Kuadratik\n3. Interpolasi Beda Newton\n4. Interpolasi Lagrange\nMasukkan karakter selain 1..4 untuk keluar dari program\nPilihan: ";
		char input;
		std::cin >> input;
		if (input > 48 && input < 53)
		{
			float x = 0;
			switch (input)
			{
				/* Interp Linear */
			case 49:
				system("cls");
				std::cout << "=== Interpolasi Linear ===\n";
				InputProcess(coordinates, 2);
				std::cout << "Masukkan nilai x yang ingin dicari: ";
				std::cin >> x;
				Linear lin(*coordinates[0], *coordinates[1], x);
				lin.ShowResult();
				for (short i = 0; i < coordinates.size(); i++)
				{
					delete coordinates[i];
				}
				coordinates.clear();
				system("pause");
				break;

				/* Interp Kuadratik */
			case 50:
				system("cls");
				std::cout << "=== Interpolasi Kuadratik ===\n";
				InputProcess(coordinates, 3);
				std::cout << "Masukkan nilai x yang ingin dicari: ";
				std::cin >> x;
				Kuadratik kuad(*coordinates[0], *coordinates[1], *coordinates[2], x);
				kuad.ShowResult();
				for (short i = 0; i < coordinates.size(); i++)
				{
					delete coordinates[i];
				}
				coordinates.clear();
				system("pause");
				break;

				/* Interp BedaNewton*/
			case 51:
				system("cls");
				std::cout << "=== Interpolasi Kuadratik ===\n";
				InputProcess(coordinates, 4);
				std::cout << "Masukkan nilai x yang ingin dicari: ";
				std::cin >> x;
				BedaNewton bd(*coordinates[0], *coordinates[1], *coordinates[2], *coordinates[3], x);
				bd.ShowResult();
				for (short i = 0; i < coordinates.size(); i++)
				{
					delete coordinates[i];
				}
				coordinates.clear();
				system("pause");
				break;

				/* Interp Lagrange */
			case 52:
				system("cls");
				std::cout << "=== Interpolasi Lagrange ===\n";
				short amount;
				std::cout << "Masukkan jumlah titik: ";
				std::cin >> amount;
				InputProcess(coordinates, amount);
				std::cout << "Masukkan nilai x yang ingin dicari: ";
				std::cin >> x;
				Lagrange lag(amount, x);
				for (short i = 0; i < amount; i++)
				{
					lag.SetCoord(i, *coordinates[i]);
					delete coordinates[i];
				}
				lag.ShowResult();
				coordinates.clear();
				system("pause");
				break;
			}
		}
		else running = false;
	}
	return 0;
}