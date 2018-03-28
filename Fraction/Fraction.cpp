#include "Fraction.h"

Fraction::Fraction(int n, int d)
{
	if (d==0)
		d=1;

	num = n;
	den = d;
}

Fraction::Fraction(const Fraction &obj)
{
	num = obj.num;
	den = obj.den;
}

Fraction::Fraction()
{
	num = 0;
	den = 1;
}

Fraction::~Fraction()
{
	num = 0;
	den = 1;
}

int Fraction::getNum() const
{
	return num;
}
int Fraction::getDen() const
{
	return den;
}

void Fraction::setNum(int n)
{
	num = n;
}
void Fraction::setDen(int d)
{
	den = d;
}

void Fraction::display()
{
	std::cout << num << "/" << den << std::endl;
}
