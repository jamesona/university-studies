// Author: Jameson Aranda
// Assignment: CS1410_Project_05_jaranda
// Instructor: Craig Sharp
// Class: CS 1410 -- 002
// Date Written: 3/27/2017 7:02:01 PM
// Description: implementation of a fraction class with operator overloads

// I declare that the following code was written by me or provided
// by the instructor for this project. I understand that copying source
// code from any other source constitutes cheating, and that I will receive 
// a zero on this project if I am found in violation of this policy.

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

class Fraction 
{
friend Fraction operator *(const Fraction&, const Fraction&);
friend Fraction operator /(const Fraction&, const Fraction&);
friend Fraction operator +(const Fraction&, const Fraction&);
friend Fraction operator ++(const Fraction&);
friend Fraction operator -(const Fraction&, const Fraction&);
friend Fraction operator --(const Fraction&);
friend bool operator ==(const Fraction&, const Fraction&);
friend ostream& operator <<(ostream& os, const Fraction& frac);

private:
	int numerator, denominator;

public:
	Fraction(int num, int den);
	static Fraction Fraction::simplify(Fraction reduce);
};

Fraction::Fraction(int num, int den)
{
	numerator = num;
	denominator = den;
}

Fraction Fraction::simplify(Fraction reduce)
{
	int gcd = 1;

	while (reduce.numerator % gcd == 0 && reduce.denominator % gcd == 0)
	{
		gcd++;
	}

	gcd--;

	reduce.numerator /= gcd;
	reduce.denominator /= gcd;

	return reduce;
};

Fraction operator *(const Fraction& left, const Fraction& right)
{
	int rn = left.numerator * right.numerator, 
		rd = left.denominator * right.denominator;
	Fraction result(rn, rd);

	return Fraction::simplify(result);
};

Fraction operator /(const Fraction& left, const Fraction& right)
{
	int rn = left.numerator * right.denominator,
		rd = left.denominator * right.numerator;
	Fraction result(rn, rd);

	return Fraction::simplify(result);
};

Fraction operator +(const Fraction& left, const Fraction& right)
{
	int ld = left.denominator, rd = right.denominator,
		resN = (left.numerator * rd) + (right.numerator * ld),
		resD = ld * rd;
	Fraction result(resN, resD);

	return Fraction::simplify(result);
};

Fraction operator ++(const Fraction& frac)
{
	Fraction result(frac.numerator+1, frac.denominator);

	return Fraction::simplify(result);
};

Fraction operator -(const Fraction& left, const Fraction& right)
{
	int ld = left.denominator, rd = right.denominator,
		resN = (left.numerator * rd) - (right.numerator * ld),
		resD = ld * rd;
	Fraction result(resN, resD);

	return Fraction::simplify(result);
};

Fraction operator --(const Fraction& frac)
{
	Fraction result(frac.numerator-1, frac.denominator);

	return Fraction::simplify(result);
};

bool operator ==(const Fraction& left, const Fraction& right)
{
	Fraction::simplify(left);
	Fraction::simplify(right);
	return left.numerator == right.numerator && left.denominator == right.denominator;
};

ostream& operator <<(ostream& os, const Fraction& frac)
{
	Fraction reduced(frac.numerator, frac.denominator);
	if (frac.denominator == 1)
	{
		os << reduced.numerator;
	}
	else
	{
		os << reduced.numerator << " / " << reduced.denominator;
	}
	return os;
};

int main() {
	Fraction x(1, 2), y(3, 4);
	cout << x + y << endl;
	cout << x - y << endl;
	cout << x * y << endl;
	cout << x / y << endl;
}