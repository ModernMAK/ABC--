// Fraction.h

#ifndef _FRACTION_h
#define _FRACTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

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

