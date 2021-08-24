// MusicalKey.h

#ifndef _MUSICALKEY_h
#define _MUSICALKEY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum MusicalKey {
	A = 0,
	B = As + 1,
	C = Bs + 1,
	D = Cs + 1,
	E = Ds + 1,
	F = Es + 1,
	G = Fs + 1,

	As = A + 1,
	Bs = B + 1,
	Cs = C + 1,
	Ds = D + 1,
	Es = E + 1,
	Fs = F + 1,
	Gs = G + 1,

	Af = Gs,
	Bf = As,
	Cf = Bs,
	Df = Cs,
	Ef = Ds,
	Ff = Es,
	Gf = Fs,
};
class MusicalKeyHelper {
public:
	static MusicalKey getKey(char s, char[] modifiers = null) {
		MusicalKey key = getKeyNatural(s);
		if (modifiers == null) {
			return key;
		}
		int size = sizeof(modifiers) / sizeof(modifiers[0]);
		int index = 0;
		while (index < size && index < 2) {
			switch (modifiers[index]) {
				case '^':
					key = sharpen(key);
					break;
				case '=':
					return key;
				case '_':
					key = flatten(key);
					break;
				default:
					return key;
			}
		}
		return key;
		
	}
	static MusicalKey getKeyNatural(char c) {
		switch (c) {
		case 'A':
		case 'a':
			return MusicalKey.A;
		case 'B':
		case 'b':
			return MusicalKey.B;
		case 'C':
		case 'c':
			return MusicalKey.C;
		case 'D':
		case 'd':
			return MusicalKey.D;
		case 'E':
		case 'e':
			return MusicalKey.E;
		case 'F':
		case 'f':
			return MusicalKey.F;
		case 'G':
		case 'g':
			return MusicalKey.G;
		}
		return MusicalKey.C;
	}
	static MusicalKey sharpen(MusicalKey key) {
		int key = (int)(object)key;
		key += 1;
		key %= 14;

		return (MusicalKey)(object)key;
	}
	static MusicalKey flatten(MusicalKey key) {
		int key = (int)(object)key;
		key -= 1;
		while (key < 0) {
			key += 14;
		}
		return (MusicalKey)(object)key;
	}
};


#endif

