// MusicalNoteLength.h

#ifndef _MUSICALNOTELENGTH_h
#define _MUSICALNOTELENGTH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
enum MusicalNoteLength {
	Whole = 1,
	Half = Whole * 2,
	Quarter = Half * 2,
	Eighth = Quarter * 2,
	Sixteenth = Eighth * 2,
	Thirtyseconth = Sixteenth * 2,
};
class MusicalNoteLengthHelper {
public:
	static float getDecimal(MusicalNoteLength mnl) {
		return 1.0f / ((float)((int)mnl));
	}
};

#endif

