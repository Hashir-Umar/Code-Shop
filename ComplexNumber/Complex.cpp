#include "Complex.h"

Complex::Complex()
{
	realPart = new double(0);
	imaginaryPart = new double(0);
}

Complex::Complex(double r, double i)
{
	realPart = new double(r);
	imaginaryPart = new double(i);
}

Complex::Complex(const Complex& obj)
{
	realPart = new double(*obj.realPart);
	imaginaryPart = new double(*obj.imaginaryPart);
}

void Complex::display()
{
	if (*imaginaryPart >= 0)
		std::cout << *realPart << " + " << *imaginaryPart << "i"<< std::endl;
	else
		std::cout << *realPart << " " << *imaginaryPart << "i" << std::endl;
}

void Complex::setReal(double r)
{
	delete realPart;
	realPart = new double(r);
}

void Complex::setImaginary(double i)
{
	delete imaginaryPart;
	imaginaryPart = new double(i);
}

double Complex::getReal() const
{
	return *realPart;
}

double Complex::getImaginary() const
{
	return *imaginaryPart;
}

//+=
Complex& Complex::add(const Complex&obj)
{
	*realPart += *obj.realPart;
	*imaginaryPart += *obj.imaginaryPart;

	return (*this);
}

//-=
Complex& Complex::subtract(const Complex&obj)
{
	*realPart -= *obj.realPart;
	*imaginaryPart -= *obj.imaginaryPart;

	return (*this);
}

//*=
Complex& Complex::multiply(const Complex&obj)
{
	double realRes = *obj.realPart * (*realPart);
	double imaginaryRes = *obj.realPart * (*imaginaryPart);
	imaginaryRes += *obj.imaginaryPart * (*realPart);
	realRes += *obj.imaginaryPart * *imaginaryPart * -1;

	*realPart = realRes;
	*imaginaryPart = imaginaryRes;
	return (*this);
}

Complex& Complex::increment()
{
	*realPart += 1;
	*imaginaryPart += 1;
	return (*this);
}

Complex Complex::operator+(const Complex& obj)
{
	Complex c(*obj.realPart + *realPart, *obj.imaginaryPart + *imaginaryPart);
	return c;
}

Complex Complex::operator-(const Complex& obj)
{
	Complex c(*realPart - *obj.realPart, *imaginaryPart - *obj.imaginaryPart);
	return c;
}

Complex Complex::operator*(const Complex&obj)
{
	double realRes = *obj.realPart * (*realPart);
	double imaginaryRes = *obj.realPart * (*imaginaryPart);
	imaginaryRes += *obj.imaginaryPart * (*realPart);
	realRes += *obj.imaginaryPart * *imaginaryPart * -1;
	
	Complex c(realRes, imaginaryRes);
	return c;
}

Complex& Complex::operator=(const Complex& obj)
{
	delete realPart;
	delete imaginaryPart;
	realPart = new double(*obj.realPart);
	imaginaryPart = new double(*obj.imaginaryPart);
	return (*this);
}

Complex::~Complex()
{
	delete realPart;
	delete imaginaryPart;
}

