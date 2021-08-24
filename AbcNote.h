// AbcNote.h

#ifndef _ABCNOTE_h
#define _ABCNOTE_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "KeySignature.h"
#include "Note.h"
#include "UniquePitch.h"
#include "Fraction.h"
#include "PitchMediator.h"
#include "FrequencyPitch.h"
#include "KeySignature.h"

class AbcNote : public Note {

protected:
	void init(std::string abc);

public:
	AbcNote(std::string abc);
	AbcNote() { }

	double getFrequency(UniquePitch kp = U_Cn, KeySignatureMode ksm = KSM_Major);
	double getFrequency(KeySignature ks);
	std::string toAbcString();

	static const char
		ABC_RAISE_OCTAVE = '\'',
		ABC_LOWER_OCTAVE = ',',
		ABC_NATURAL_MODIFIER = '=',
		ABC_SHARP_MODIFIER = '^',
		ABC_FLAT_MODIFIER = '_';


	static bool isPitchCharacter(char abc);
	static UniquePitch getPitchFromAbcCharacter(char abc);
	static std::string getAbcStringFromPitch(UniquePitch uP, bool isMiddlePitch = true);
	static UniquePitch getUniquePitchFromAbc(std::string abc);
	static int getOctaveFromAbc(std::string abc);
	static std::string getAbcFromOctave(int abc);
	static Fraction* getTimingFromAbc(std::string abc);
	static std::string getAbcFromTiming(Fraction* abc);
};

#endif