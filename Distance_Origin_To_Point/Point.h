#pragma once
class Point
{
	const double x;
	const double y;

public:
	Point(const double&, const double&);

	double getX();
	double getY();
	double getDistance();
};

