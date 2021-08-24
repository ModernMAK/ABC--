// AbcPitch.h

#ifndef _ABCPITCH_h
#define _ABCPITCH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Frequency.h"
#include"Pitch.h"

enum PitchState {
	Error = -1,
	Flat = 1,
	Natural,
	Sharp
};
class AbcPitch {
public:
	static const char
		LowerOctave = ',',
		RaiseOctave = '\'',
		SharpPitch = '^',
		NaturalPitch = '=',
		FlatPitch = '_';

	static Pitch modifyByHalfsteps(Pitch p, int halfSteps) {
		int iP = (int)p + halfSteps;
		while (iP < 0) {
			iP += 12;
		}
		while (iP > 12) {
			iP -= 12;
		}
		return (Pitch)iP;
	}
	static Pitch flatten(Pitch p, int halfSteps = 1) {

	}
	static bool isPitchSymbol(char c) {
		switch (toUpperCase(c))
		{
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
			return true;
		}
		return false;
	}
	static Pitch fromPitchSymbol(char c) {
		
		switch (toUpperCase(c))
		{
		case 'A':
			return Pitch::A;
		case 'B':
			return Pitch::B;
		case 'C':
			return Pitch::C;
		case 'D':
			return Pitch::D;
		case 'E':
			return Pitch::E;
		case 'F':
			return Pitch::F;
		case 'G':
			return Pitch::G;
		}
		return Pitch::ERROR;
	}
	static String toPitchSymbol(Pitch p, bool toUpper, Pitch key = Pitch::C) {

		String ret = "";
		switch (p)
		{
		case Cs:
			ret.concat(Sharp);
		case C:
			ret.concat(toUpper ? "C" : "c");
			break;
		case Ds:
			ret.concat(Sharp);
		case D:
			ret.concat(toUpper ? "D" : "d");
			break;
		case E:
			ret.concat(toUpper ? "E" : "e");
			break;
		case Fs:
			ret.concat(Sharp);
		case F:
			ret.concat(toUpper ? "F" : "f");
			break;
		case Gs:
			ret.concat(Sharp);
		case G:
			ret.concat(toUpper ? "G" : "g");
			break;
		case As:
			ret.concat(Sharp);
		case A:
			ret.concat(toUpper ? "A" : "a");
			break;
		case B:
			ret.concat(toUpper ? "B" : "b");
			break;
		}
		return ret;
	}
	static String toPitchSymbol(Pitch p, Pitch key = Pitch::C, bool toUpper = true) {
		return toPitchSymbol(p, toUpper, key);
	}
		static int getHalfSteps(String str, PitchState keyState = Natural) {
		int
			halfStepMod = 0;
		PitchState
			state = PitchState::Error;
		
		for (int i = 0; i < str.length(); i++) {
			if (state == PitchState::Natural || isPitchSymbol(str[i])) {
				break;
			}
			switch (state)
			{
			case PitchState::Error:
				if (NaturalPitch == str[i]) {
					state = PitchState::Natural;
				}
				else if (FlatPitch == str[i]) {
					state = PitchState::Flat;
					halfStepMod--;
				}
				else if (SharpPitch == str[i]) {
					state = PitchState::Sharp;
					halfStepMod++;
				}
				break;
			case PitchState::Flat:
				if (FlatPitch == str[i]) {
					halfStepMod--;
				}
				break;
			case PitchState::Natural:
				break;
			case PitchState::Sharp:
				if (SharpPitch == str[i]) {
					halfStepMod++;
				}
				break;
			default:
				break;
			}
		
		}
		//One final modifer where we flatten or sharpen

		if (keyState == PitchState::Flat) {
			if (state == PitchState::Natural) {
				halfStepMod++;
			}
			else {
				halfStepMod--;
			}
		}
		if (keyState == PitchState::Sharp) {
			if (state == PitchState::Natural) {
				halfStepMod--;
			}
			else {
				halfStepMod++;
			}
		}
		
		return halfStepMod;
	}
	static Pitch toPitch(String abc, Pitch key) {
		Pitch p = Pitch::ERROR;
		for (int i = 0; i < abc.length(); i++) {
			
			if (isPitchSymbol(abc[i])) {
				p = fromPitchSymbol(abc[i]);
				//TODO add thing to modify keystate \/ \/ \/
				p = modifyByHalfsteps(
						p, 
						getHalfSteps(abc.substring(0, i), PitchState::Natural)
					);
			}
		}
	}
	static Pitch toPitch(String abc) {
		return toPitch(abc, Pitch::C);//C natural, 
	}

	static int toOctave(String abc) {
		int o = 4;
		bool octaveFound = false;
		for (int i = 0; i < abc.length(); i++) {
			if (!octaveFound) {
				if (isPitchSymbol(abc[i])) {
					o += isUpperCase(abc[i]) ? 1 : 0;
					octaveFound = true;
				}
			}
			else {
				if (RaiseOctave == abc[i]) {
					o++;
				}
				else if (LowerOctave == abc[i]) {
					o--;
				}
				else {
					break;
				}
			}

		}
		return o;

	}
	static int toOctaveSymbol(int octave, int baseOctave = 0) {
		int dO = octave - baseOctave;
		String str = "";
		while (dO != 0) {
			if (dO < 0) {
				dO++;
				str.concat(RaiseOctave);
			}
			else {
				dO--;
				str.concat(LowerOctave);
			}
		}
	}

};

#endif
