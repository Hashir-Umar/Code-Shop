#pragma once
#include <iostream>

class Complex
{
	double *realPart;
	double *imaginaryPart;
public:
	Complex();
	Complex(double r, double i);
	Complex(const Complex&);
	void setReal(double r);
	void setImaginary(double i);
	double getReal() const;
	double getImaginary() const;
	void display();
	Complex& add(const Complex&);
	Complex& subtract(const Complex&);
	Complex& multiply(const Complex&);
	Complex& increment();
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);
	Complex& operator=(const Complex&);
	~Complex();
};

