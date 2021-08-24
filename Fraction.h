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
	int n, d;
protected:
	void init(int num, int denom) {
		n = num;
		d = denom;
	}
public:
	Fraction(int nN, int nD) {
		init(nN, nD);
	}
	int getNumerator() {
		return n;
	}
	int getDenominator() {
		return d;
	}
	double getValue() {
		return getNumerator() / getDenominator();
	}


};

#endif

