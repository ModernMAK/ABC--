// Fraction.h

#ifndef _FRACTION_h
#define _FRACTION_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <stdexcept>
struct Fraction {
private:
	int
		myNumerator,
		myDenominator;
public:
	float getDecimal() {
		
		return ((float)myNumerator) / ((float)myDenominator);
	}
	void setFraction(int num, int denom) {
		myNumerator = num;
		myDenominator = denom;
		if (myDenominator == 0.0f) {
			throw std::invalid_argument("Denominator cannot be 0!");
		}
	}
	//operator float() const { return (this->getDecimal()); }

};

#endif

