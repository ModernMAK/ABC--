// Pitch.h

#ifndef _PITCH_h
#define _PITCH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
enum Pitch {
	ERROR = -100,

	C = 0,
	Cs = 1,
	Df = 1,
	D = 2,
	Ds = 3,
	Ef = 3,
	E = 4,
	F = 5,
	Fs = 6,
	Gf = 6,
	G = 7,
	Gs = 8,
	Af = 8,
	A = 9,
	As = 10,
	Bf = 10,
	B = 11,
};
#endif

