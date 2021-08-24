// Frequency.h

#ifndef _FREQUENCY_h
#define _FREQUENCY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Pitch.h"
class Frequency {
public:
	static constexpr double
		PIANO_RATE = 1.0594630943592952645618252949463,
		PIANO_BASE = 32.703195662574829334731249190413;
	static const int
		HALFSTEPS_PER_RATE = 12;//12 Halfsteps, Pitch labels thsse for us.
	static double calculateFrequency(int d) {
		return PIANO_BASE * pow(PIANO_RATE, d);
	}
	static double calculateFrequency(Pitch p, int o) {
		return calculateFrequency(((int)p) + (o * HALFSTEPS_PER_RATE));
	};

};

#endif

