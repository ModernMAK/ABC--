// AbcNote.h
#include "MusicalKey.h"
#ifndef _ABCNOTE_h
#define _ABCNOTE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class AbcNote {
private:
	MusicalKey myKey;
	Fraction myTimingMultiplier;
	MusicalOctave myOctave;
public:
	AbcNote(string abc) {
		//' = +
		//, = -

		foreach(char c in abc) {
		
		}
	}
	AbcNote(MusicalKey, Fraction timing, MusiaclOctave octave) {
		
	}
	MusicalKey getKey();
	float getTimingMultiplier();
	MusicalOctave getOctave();
};

#endif

