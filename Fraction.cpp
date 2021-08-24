// 
// 
// 

#include "Fraction.h"
void Fraction::init(int numerator, int denominator) {
	myNumerator = numerator;
	myDenominator = denominator;
}

Fraction::Fraction(int numerator, int denominator) {
	init(numerator, denominator);
}
int Fraction::getNumerator() { 
	return myNumerator; 
}
int Fraction::getDenominator() {
	return myDenominator; 
};
double Fraction::getValue() {
	return (double)myNumerator / (double)myDenominator;
}