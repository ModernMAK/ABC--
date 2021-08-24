// MusicalOctave.h

#ifndef _MUSICALOCTAVE_h
#define _MUSICALOCTAVE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
enum MusicalOctave {
	Zero = 0,
	One,
	Two,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight
};
#endif

