#pragma once
class Point
{
	const double x;
	const double y;

public:
	Point(const double&, const double&);

	double getX() const;
	double getY() const;
	double getDistance();
};

