// 
// 
// 

#include "AbcNote.h"

void AbcNote::init(String abc) {
	//Serial.print("ABC : ");
	//Serial.print(abc);
	//Serial.print(" -> ");
	setUniquePitch(getUniquePitchFromAbc(abc));
	setOctave(getOctaveFromAbc(abc));
	setTiming(getTimingFromAbc(abc));
}

AbcNote::AbcNote(String abc) {
	init(abc);
}

double AbcNote::getFrequency(UniquePitch kp, KeySignatureMode ksm) {
	//TODO -> Later, use ks to modify this value

	return PitchMediator::calculateFrequencyFromPitch(
		KeySignatureModeExtension::modifyPitch(getUniquePitch(), kp, ksm),
		getOctave()
	);
}
double AbcNote::getFrequency(KeySignature ks) {
	//TODO -> Later, use ks to modify this value

	return PitchMediator::calculateFrequencyFromPitch(
		ks.getModifiedPitch(getUniquePitch())
	);
}

String AbcNote::toAbcString()
{
	int octave = getOctave();
	bool isMiddle = octave <= 4;
	if (!isMiddle) {
		octave--;
	}
	String str = "";
	str += getAbcStringFromPitch(getUniquePitch(), isMiddle);
	str += getAbcFromOctave(octave);
	str += getAbcFromTiming(getTimingReference());
	return str;
}

bool AbcNote::isPitchCharacter(char abc)
{
	return (
		('a' <= abc && abc <= 'g') ||
		('A' <= abc && abc <= 'G') ||
		('z' == abc) ||
		('Z' == abc) ||
		('x' == abc) ||
		('X' == abc)
	);
}

UniquePitch AbcNote::getPitchFromAbcCharacter(char abc)
{
	//Serial.print("getAbcChar -> ");
	//Serial.print(abc);
	//Serial.print(" -> ");
	switch (abc)
	{
		case 'A':
		case 'a':
			//Serial.println("A");
			return UniquePitch::U_An;
		case 'B':
		case 'b':
			//Serial.println("B");
			return UniquePitch::U_Bn;
		case 'C':
		case 'c':
		//	Serial.println("C");
			return UniquePitch::U_Cn;
		case 'D':
		case 'd':
		//	Serial.println("D");
			return UniquePitch::U_Dn;
		case 'E':
		case 'e':
		//	Serial.println("E");
			return UniquePitch::U_En;
		case 'F':
		case 'f':
		//	Serial.println("F");
			return UniquePitch::U_Fn;
		case 'G':
		case 'g':
		//	Serial.println("G");
			return UniquePitch::U_Gn;
		case 'Z':
		case 'z':
		case 'X':
		case 'x':
		//	Serial.println("Z");
			return UniquePitch::U_Rest;
	}
	//Serial.println("Ended");
	return UniquePitch::U_Rest;
}

String AbcNote::getAbcStringFromPitch(UniquePitch uP, bool isMiddlePitch)
{
		String temp = "";

		if (UniquePitchExtensions::isA(uP)) {
			temp += (isMiddlePitch ? 'A' : 'a');
		}
		else if (UniquePitchExtensions::isB(uP)) {
			temp += (isMiddlePitch ? 'B' : 'B');
		}
		else if (UniquePitchExtensions::isC(uP)) {
			temp += (isMiddlePitch ? 'C' : 'c');
		}
		else if (UniquePitchExtensions::isD(uP)) {
			temp += (isMiddlePitch ? 'D' : 'd');
		}
		else if (UniquePitchExtensions::isE(uP)) {
			temp += (isMiddlePitch ? 'E' : 'e');
		}
		else if (UniquePitchExtensions::isF(uP)) {
			temp += (isMiddlePitch ? 'F' : 'f');
		}
		else if (UniquePitchExtensions::isG(uP)) {
			temp += (isMiddlePitch ? 'G' : 'g');
		}
		else if (UniquePitchExtensions::isRest(uP)) {
			temp += 'z';
		}

		if (UniquePitchExtensions::isExplicitNatural(uP)) {
			temp = ABC_NATURAL_MODIFIER + temp;
		}
		else if (UniquePitchExtensions::isFlat(uP)) {
			temp = ABC_FLAT_MODIFIER + temp;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			temp = ABC_SHARP_MODIFIER + temp;
		}
		return temp;
}

UniquePitch AbcNote::getUniquePitchFromAbc(String abc) {
	char cPitch = 'C';
	byte state = 0; //0 = Looking, 1 = Nat, 2 = Sharp, 3 = Flat
	int halfStepMod = 0;
/*
	Serial.print("gupAbc -> ");
	Serial.print(cPitch);
	Serial.print(" , ");
	Serial.print(state);
	Serial.print(" , ");
	Serial.print(halfStepMod);
	Serial.print(" -> ");
*/
	for (size_t i = 0; i < abc.length(); i++)
	{
		if (state == 0 && abc[i] == ABC_NATURAL_MODIFIER) {
			state = 1;
			/*Serial.print(" state ");
			Serial.print(state);
			Serial.print(" -> ");*/
		}
		else if ((state == 0 || state == 2) && abc[i] == ABC_SHARP_MODIFIER) {
			halfStepMod++;
			state = 2;
			/*Serial.print(" hs++ ");
			Serial.print(halfStepMod);
			Serial.print(" -> ");*/
		}
		else if ((state == 0 || state == 3) && abc[i] == ABC_FLAT_MODIFIER) {
			halfStepMod--;
			state = 3;
			/*Serial.print(" h-- ");
			Serial.print(halfStepMod);
			Serial.print(" -> ");*/
		}
		else if (isPitchCharacter(abc[i])) {
			cPitch = abc[i];
			/*Serial.print(" cPitch ");
			Serial.print(cPitch);
			Serial.print(" -> ");*/
			break;
		}
		else {
			break;
		}
	}

	UniquePitch uP =
		getPitchFromAbcCharacter(cPitch);
/*
	Serial.print(" uP1 ");
	Serial.print(uP);
	Serial.print(" -> ")*/;
	uP = PitchMediator::modifyPitchByHalfSteps(
			uP,
			halfStepMod
		);
/*
	Serial.print(" uP2 ");
	Serial.print(uP);
	Serial.print(" -> ");
	Serial.print("b e -> ");
	Serial.print(getAbcStringFromPitch(uP));
	Serial.print(" -> ");*/
	if (state == 1) {
		uP = (UniquePitch)(uP | UniquePitch::U_ExplicitNatural);
	}
	/*Serial.print("e gupfAbcS -> ");
	Serial.print(getAbcStringFromPitch(uP));
	Serial.println(" -> ");*/
	return uP;
}

int AbcNote::getOctaveFromAbc(String abc) {
	int o = 4;
	byte state = 0;
	for (size_t i = 0; i < abc.length(); i++)
	{
		if ((state == 0 || state == 1 || state == 2) && abc[i] == ABC_RAISE_OCTAVE)
		{
			o++;
			state = 2;
		}
		else if ((state == 0 || state == 1 || state == 3) && abc[i] == ABC_LOWER_OCTAVE)
		{
			o--;
			state = 3;
		}
		else if ((state == 0) && isPitchCharacter(abc[i]))
		{
			o += isUpperCase(abc[i]) ? 0 : 1;
			state = 1;
		//	break;
		}
		/*else 
		{
			break;
		}*/
	}
	return o;
}

String AbcNote::getAbcFromOctave(int i)
{
	i -= 4;//Shift to C
	String str = "";
	while (i < 0) {
		i++;
		str += ABC_LOWER_OCTAVE;
	}
	while (i > 0) {
		i--;
		str += ABC_RAISE_OCTAVE;
	}
	return str;
}


Fraction* AbcNote::getTimingFromAbc(String abc) {
	String
		myNum = "1",
		myDenom = "1";
	byte state = 0; //0 = Looking, 1 = Nat, 2 = Sharp, 3 = Flat
	int lI = 0;

	for (size_t i = 0; i < abc.length(); i++)
	{
		if (isDigit(abc[i])) 
		{
			if (state == 0)
			{
				state = 1;
			}
			else if (state == 3) 
			{
				state = 4;
			}
		}
		else 
		{
			if (abc[i] == '/') 
			{
				state = 3;
				lI = i + 1;
			}
			else if (state == 1) 
			{
				myNum = abc.substring(lI, i);
				lI = i;
				state = 2;
			}
			else if (state == 4) 
			{
				myDenom = abc.substring(lI, i);
				state = 5;
			}
		}
	}
	if (state == 4)
	{
		myDenom = abc.substring(lI, abc.length());
	}
	
	return new Fraction(myNum.toInt(), myDenom.toInt());
}

String AbcNote::getAbcFromTiming(Fraction * abc)
{
	String str = "";
	if (abc->getNumerator() > 1) {
		str += abc->getNumerator();
	}
	if (abc->getDenominator() > 1) {
		str += '/';
		str += abc->getDenominator();
	}
	return str;
}
