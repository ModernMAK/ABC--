// KeySignatureMode.h

#ifndef _KEYSIGNATUREMODE_h
#define _KEYSIGNATUREMODE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "UniquePitch.h"
enum KeySignatureMode {
	KSM_Ionian = 0,
	KSM_Major = KSM_Ionian,

	KSM_Aeolian = 1,
	KSM_Minor = KSM_Aeolian,

	KSM_Mixolydian = 2,
	KSM_Dorian = 3,
	KSM_Phrygian = 4,
	KSM_Lydian = 5,
	KSM_Locrian = 6,
};
//enum KeySignature {
//	/*
//	KSM_7S = (1 << 0),
//	KSM_6S = (1 << 1),
//	KSM_5S = (1 << 2),
//	KSM_4S = (1 << 3),
//	KSM_3S = (1 << 4),
//	KSM_2S = (1 << 5),
//	KSM_1S = (1 << 6),
//	KSM_N = (1 << 7),
//	KSM_1S = (1 << 8),
//	KSM_2S = (1 << 9),
//	KSM_3S = (1 << 10),
//	KSM_4S = (1 << 11),
//	KSM_5S = (1 << 12),
//	KSM_6S = (1 << 13),
//	KSM_7S = (1 << 14),
//	*/
//	KSM_Cs = (1 << 0),
//	KSM_Fs = (1 << 1),
//	KSM_B = (1 << 2),
//	KSM_E = (1 << 3),
//	KSM_A = (1 << 4),
//	KSM_D = (1 << 5),
//	KSM_G = (1 << 6),
//	KSM_C = (1 << 7),
//	KSM_F = (1 << 8),
//	KSM_Bf = (1 << 9),
//	KSM_Ef = (1 << 10),
//	KSM_Af = (1 << 11),
//	KSM_Df = (1 << 12),
//	KSM_Gf = (1 << 13),
//	KSM_Cf = (1 << 14),
//
//
//};
class KeySignatureModeExtension {
public:
	static bool hasFlag(KeySignatureMode ksm, KeySignatureMode flag) {
		return (ksm & flag) == flag;
	}
	static int getModified(UniquePitch up = U_Cn, KeySignatureMode ksm = KSM_Major) {
		if (
			(hasFlag(ksm, KSM_Major)	&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) || //Ionian or Major in C#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isSharp(up)) || //Aeolian or Minor in A#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isSharp(up)) || //Mixolydian in G#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isSharp(up)) || //Dorian in D#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in E#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Lydian in F#
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isSharp(up)) //Locrian in B#
		)
		{
			return 7;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isSharp(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isSharp(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
		)
		{
			return 6;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isSharp(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
			)
		{
			return 5;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
			)
		{
			return 4;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
		)
		{
			return 3;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
		)
		{
			return 2;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isSharp(up)) //Locrian in E#
		)
		{
			return 1;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
			)
		{
			return 0;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -1;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -2;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -3;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -4;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isFlat(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -5;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isFlat(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isFlat(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isNatural(up)) //Locrian in E#
		)
		{
			return -6;
		}
		else if (
			(hasFlag(ksm, KSM_Major)		&& UniquePitchExtensions::isC(up) && UniquePitchExtensions::isFlat(up)) || //Ionian or Major in F#
			(hasFlag(ksm, KSM_Minor)		&& UniquePitchExtensions::isA(up) && UniquePitchExtensions::isFlat(up)) || //Aeolian or Minor in D#
			(hasFlag(ksm, KSM_Mixolydian)	&& UniquePitchExtensions::isG(up) && UniquePitchExtensions::isFlat(up)) || //Mixolydian in C#
			(hasFlag(ksm, KSM_Dorian)		&& UniquePitchExtensions::isD(up) && UniquePitchExtensions::isFlat(up)) || //Dorian in G#
			(hasFlag(ksm, KSM_Phrygian)		&& UniquePitchExtensions::isE(up) && UniquePitchExtensions::isFlat(up)) || //Phrygian in A#
			(hasFlag(ksm, KSM_Lydian)		&& UniquePitchExtensions::isF(up) && UniquePitchExtensions::isFlat(up)) || //Lydian in B
			(hasFlag(ksm, KSM_Locrian)		&& UniquePitchExtensions::isB(up) && UniquePitchExtensions::isFlat(up)) //Locrian in E#
		)
		{
			return -7;
		}
		return 0; //If something went wrong, asume C Major
	}
	static UniquePitch modifyPitch(UniquePitch pitch, UniquePitch ksPitch, KeySignatureMode ksm) {
		int 
			modified = getModified(ksPitch, ksm),
			outPitch = pitch;
		outPitch &= ~(U_ImplicitFlat | U_ImplicitNatural | U_ImplicitSharp);
		//F# = 7, 6, 5, 4, 3, 2, 1,
		//C# = 7, 6, 5, 4, 3, 2,
		//G# = 7, 6, 5, 4, 3,
		//D# = 7, 6, 5, 4,
		//A# = 7, 6, 5,
		//E# = 7, 6,
		//B# = 7,

		//B  = 6, 5, 4, 3, 2, 1, 0,
		//E  = 5, 4, 3, 2, 1, 0, -1
		//A  = 4, 3, 2, 1, 0, -1, -2
		//D  = 3, 2, 1, 0, -1, -2, -3
		//G  = 2, 1, 0, -1, -2, -3, -4
		//C  = 1, 0, -1, -2, -3, -4, -5
		//F  = 0, -1, -2, -3, -4, -5, -6

		//- values
		//Fb = 7,
		//Cb = 6, 7,
		//Gb = 5, 6, 7,
		//Db = 4, 5, 6, 7,
		//Ab = 3, 4, 5, 6, 7
		//Eb = 2, 3, 4, 5, 6, 7
		//Bb = 1, 2, 3, 4, 5, 6, 7,
		int hiCap = 2;
		if (UniquePitchExtensions::isA(pitch)) {
			hiCap = 5;
		}
		else if (UniquePitchExtensions::isB(pitch)) {
			hiCap = 7;
		}
		else if (UniquePitchExtensions::isC(pitch)) {
			hiCap = 2;
		}
		else if (UniquePitchExtensions::isD(pitch)) {
			hiCap = 4;
		}
		else if (UniquePitchExtensions::isE(pitch)) {
			hiCap = 6;
		}
		else if (UniquePitchExtensions::isF(pitch)) {
			hiCap = 1;
		}
		else if (UniquePitchExtensions::isG(pitch)) {
			hiCap = 3;
		}
		if (modified >= hiCap) {
			outPitch |= U_ImplicitSharp;
		}
		else if (modified <= hiCap - 8) {
			outPitch |= U_ImplicitFlat;
		}
		else outPitch |= U_ImplicitNatural;
		return (UniquePitch)outPitch;
		/*switch (modified)
		{
		case 7:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 6:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 5:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 4:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 3:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 2:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 1:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 0:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case -1:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case -2:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case -3:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case -4:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 7:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		case 7:
			pitch = (UniquePitch)(pitch | U_ImplicitSharp);
			break;
		}*/
	}
};

#endif

