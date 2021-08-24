// AbcNote.h

#ifndef _ABCNOTE_h
#define _ABCNOTE_h
#include "KeySignature.h"
#include "Note.h"
#include "UniquePitch.h"
#include "Fraction.h"
#include "PitchMediator.h"
#include "FrequencyPitch.h"
#include "KeySignature.h"
#include "RawTone.h"
class AbcNote : public Note {

protected:
	void init(String abc);

public:
	AbcNote(String abc);

	double getFrequency(UniquePitch kp = U_Cn, KeySignatureMode ksm = KSM_Major);
	double getFrequency(KeySignature ks);
	String toAbcString();

	static const char
		ABC_RAISE_OCTAVE = '\'',
		ABC_LOWER_OCTAVE = ',',
		ABC_NATURAL_MODIFIER = '=',
		ABC_SHARP_MODIFIER = '^',
		ABC_FLAT_MODIFIER = '_';


	static bool isPitchCharacter(char abc);
	static UniquePitch getPitchFromAbcCharacter(char abc);
	static String getAbcStringFromPitch(UniquePitch uP, bool isMiddlePitch = true);
	static UniquePitch getUniquePitchFromAbc(String abc);
	static int getOctaveFromAbc(String abc);
	static String getAbcFromOctave(int abc);
	static Fraction* getTimingFromAbc(String abc);
	static String getAbcFromTiming(Fraction* abc);
};

#endif
