#include <iostream>
#include "Point.h"

int main()
{
	double x = 0, y = 0;

	std::cout << "X coordinate of P1: ";
	std::cin >> x;

	std::cout << "X coordinate of P1: ";
	std::cin >> y;

	Point obj(x, y);

	std::cout << "\nDistance Of Point from Origin: " << obj.getDistance() << std::endl;

	return 0;
}