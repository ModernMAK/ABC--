// AbcNote.h

#ifndef _ABCNOTE_h
#define _ABCNOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Frequency.h"
#include "AbcPitch.h"
#include "AbcTiming.h"

class AbcNote {
private:
	Pitch p;
	int o;
	AbcTiming * t;
protected:
	void init(Pitch nP, int nO, AbcTiming * nT) {
		p = nP;
		o = nO;
		t = nT;
	}
	void init(String str) {
		p = AbcPitch::toPitch(str);
		o = AbcPitch::toOctave(str);
		t = AbcTiming::fromAbc(str);
	}
public:
	AbcNote(Pitch nP, AbcTiming * nT, int nO = 4) {
		init(nP, nO, nT);
	}

	AbcNote() {
	}

	AbcNote(String abc) {
		init(abc);
	}
	Pitch getPitch()
	{
		return p;
	}
	int getOctave()
	{
		return o;
	}
	AbcTiming getTiming() {
		return *t;//Return the value, since we want to 'own' the pointer.
	}
	int getFrequency()
	{
		return round(Frequency::calculateFrequency(this->getPitch(), this->getOctave()));
	}

	static String toAbc(AbcNote* abcNote) {
		String str = "";
		bool toUpper = abcNote->getOctave() < 5;
		str.concat(AbcPitch::toPitchSymbol(abcNote->getPitch(), toUpper));
		str.concat(AbcPitch::toOctaveSymbol(abcNote->getOctave(),(toUpper ? 4 : 5)));
		return str;
	}
	static AbcNote* fromAbc(String abcNote) {
		return new AbcNote(abcNote);
	}
	String toAbc() {
		return toAbc(this);
	}
};


#endif

