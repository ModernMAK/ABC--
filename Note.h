// Note.h

#ifndef _NOTE_h
#define _NOTE_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "UniquePitch.h"
#include "Fraction.h"
#include "PitchMediator.h"
class Note {
private:
	UniquePitch
		myUniquePitch;
	int
		myOctave;
	Fraction*
		myTiming;
protected:
	void init(UniquePitch pitch, int octave, Fraction* timing);
	void setUniquePitch(UniquePitch uP);
	void setOctave(int o);
	void setTiming(Fraction* f);
	Fraction* getTimingReference();
public:
	Note(UniquePitch pitch, int octave, Fraction* timing);
	Note(UniquePitch pitch = UniquePitch::U_Cn, int octave = PitchMediator::FREQUENCY_OCTAVE_BASE, int timingNum = 1, int timingDenom = 1);
	~Note();
	UniquePitch getUniquePitch();
	int getOctave();
	Fraction getTiming();
	double getTimingValue();
};



#endif

