#pragma once
#include <iostream>
using namespace std;
class Fraction
{
	int num;
	int den;
public:
	void display();
	Fraction(int, int);
	Fraction();
	~Fraction(void);

	Fraction(const Fraction&);

	int getNum() const;
	int getDen() const;

	void setNum(int num);
	void setDen(int den);
};

