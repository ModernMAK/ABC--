// Fraction.h

#ifndef _FRACTION_h
#define _FRACTION_h

struct Fraction {
private:
	int myNumerator,
		myDenominator;

protected:
	void init(int numerator, int denominator);

public:
	Fraction(int numerator = 1, int denominator = 1);
	int getNumerator();
	int getDenominator();
	double getValue();
};

#endif

