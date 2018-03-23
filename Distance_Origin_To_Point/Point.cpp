#include "Point.h"
#include <cmath>

Point::Point(const double &xP1, const double &yP1) :x(xP1), y(yP1) {}

double Point::getX() const
{
	return x;
}

double Point::getY() const
{
	return y;
}

double Point::getDistance()
{
	return sqrt((x*x) + (y*y));
}
