// 
// 
// 

#include "Note.h"
#include "Fraction.h"
void Note::init(UniquePitch uP, int o, Fraction* t) 
{
	setUniquePitch(uP);
	setOctave(o);
	//setTiming(t); The only time we dont do this, since setTiming does a delete
	myTiming = t;
}

Note::Note(UniquePitch uP, int o, Fraction* t) 
{
	if (t == nullptr) 
	{
		t = new Fraction();
	}
	init(uP, o, t);
}
Note::Note(UniquePitch uP, int o, int tN, int tD) 
{
	init(uP, o, new Fraction(tN,tD));
}
Note::~Note() {
	delete myTiming;
}
UniquePitch Note::getUniquePitch() {
	return myUniquePitch;
}
int Note::getOctave() {
	return myOctave;
}
Fraction Note::getTiming() {
	return *myTiming;
}
double Note::getTimingValue() {
	return myTiming->getValue();
}

void Note::setUniquePitch(UniquePitch uP) {
	myUniquePitch = uP;
}
void Note::setOctave(int o) {
	myOctave = o;
}
void Note::setTiming(Fraction* f) {
	Serial.print(f->getValue());
	Serial.print(" replacing ");
	Serial.println(myTiming->getValue());
	delete myTiming;
	myTiming  = f;
}

Fraction * Note::getTimingReference()
{
	return myTiming;
}
