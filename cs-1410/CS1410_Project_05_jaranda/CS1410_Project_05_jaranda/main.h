#pragma once

class Fraction
{
	friend Fraction operator *(const Fraction&, const Fraction&);
	friend Fraction operator /(const Fraction&, const Fraction&);
	friend Fraction operator +(const Fraction&, const Fraction&);
	friend Fraction operator -(const Fraction&, const Fraction&);
	friend bool operator ==(const Fraction&, const Fraction&);
	friend ostream& operator <<(ostream& os, const Fraction& frac);

private:
	int numerator, denominator;

public:
	// Function Name: Fraction::Fraction
	// Purpose: Fraction constructor
	// Parameters: int numerator, int denominator
	// Returns: Fraction
	// Pre-conditions: 
	// Post-conditions: 
	Fraction(int num, int den);
	// Function Name: Fraction::simplify
	// Purpose: Simplify a fraction
	// Parameters: Fraction reduce
	// Returns: Fraction reduced
	// Pre-conditions: none
	// Post-conditions: none
	static Fraction Fraction::simplify(Fraction reduce);
};