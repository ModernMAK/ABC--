// 
// 
// 

#include "PitchMediator.h"
double PitchMediator::calculateFrequencyFromPitch(FrequencyPitch fP, int octave) {
	return FREQUENCY_BASE * pow(FREQUENCY_RATE, (int)fP + ((octave - FREQUENCY_OCTAVE_BASE) * 12));
}
double PitchMediator::calculateFrequencyFromPitch(UniquePitch uP, int octave) {
	return calculateFrequencyFromPitch(toFrequencyPitch(uP), octave);
}

FrequencyPitch PitchMediator::toFrequencyPitch(UniquePitch uP) {
	if (UniquePitchExtensions::isRest(uP)) {
		return F_Rest;
	} 
	else if (UniquePitchExtensions::isA(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Af;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_As;
		}
		else return F_A;
	}
	else if (UniquePitchExtensions::isB(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Bf;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Bs;
		}
		else return F_B;
	}
	else if (UniquePitchExtensions::isC(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Cf;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Cs;
		}
		else return F_C;
	}
	else if (UniquePitchExtensions::isD(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Df;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Ds;
		}
		else return F_D;
	}
	else if (UniquePitchExtensions::isE(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Ef;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Es;
		}
		else return F_E;
	}
	else if (UniquePitchExtensions::isF(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Ff;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Fs;
		}
		else return F_F;
	}
	else if (UniquePitchExtensions::isG(uP)) {
		if (UniquePitchExtensions::isFlat(uP)) {
			return F_Gf;
		}
		else if (UniquePitchExtensions::isSharp(uP)) {
			return F_Gs;
		}
		else return F_G;
	}

	//switch (uP) {
	//	case U_Rest:
	//		return F_Rest;
	//	case U_An:
	//		return F_An;
	//	case U_Bn:
	//	case U_Cf:
	//		return F_Bn;
	//	case U_Cn:
	//	case U_Bs:
	//		return F_C;
	//	case U_Dn:
	//		return F_D;
	//	case U_E:
	//	case U_Ff:
	//		return F_E;
	//	case U_F:
	//		return F_F;
	//	case U_G:
	//		return F_G;
	//	case U_As:
	//	case U_Bf:
	//		return F_As;
	//	case U_Cs:
	//	case U_Df:
	//		return F_Cs;
	//	case U_Ds:
	//	case U_Ef:
	//		return F_Ds;
	//	case U_Fs:
	//	case U_Gf:
	//		return F_Fs;
	//	case U_Gs:
	//	case U_Af:
	//		return F_Gs;
	//}
	//return F_C;//If something goes wrong, assume C
	return F_Rest;
}
UniquePitch PitchMediator::toUniquePitch(FrequencyPitch fP) {
	switch (fP) {
		case F_Rest:
			return U_Rest;
		case F_A:
			return U_An;
		case F_B:
		//case F_Cf:
			return U_Bn;
		case F_C:
		//	case F_Bs:
			return U_Cn;
		case F_D:
			return U_Dn;
		case F_E:
		;//	case F_Ff:
			return U_E;
		case F_F:
			return U_F;
		case F_G:
			return U_G;

		case F_As:
		//	case F_Bf:
			return U_As;
		case F_Cs:
		//	case F_Df:
			return U_Cs;
		case F_Ds:
		//	case F_Ef:
			return U_Ds;
		case F_Fs:
		//	case F_Gf:
			return U_Fs;
		case F_Gs:
		//	case F_Af:
			return U_Gs;
	}
	return U_Cn;
}

UniquePitch PitchMediator::modifyPitchByHalfSteps(UniquePitch uP, int halfSteps) {
	//Serial.print("mpbhs -> ");

	/*Serial.print("uP1 ");
	Serial.print(uP);
	Serial.print(" -> ");*/
	FrequencyPitch fP = toFrequencyPitch(uP);

	/*Serial.print("fP1 ");
	Serial.print(fP);
	Serial.print(" -> ");*/

	fP = modifyPitchByHalfSteps(fP, halfSteps);

	/*Serial.print("fP2 ");
	Serial.print(fP);
	Serial.print(" -> ");*/

	uP = toUniquePitch(fP);
/*
	Serial.print("uP2 ");
	Serial.print(uP);
	Serial.println();*/

	return uP;
}
FrequencyPitch PitchMediator::modifyPitchByHalfSteps(FrequencyPitch fP, int halfSteps) {
	int iP = fP + halfSteps;
	while (iP < 0) {
		iP += 12;
	}
	while (iP >= 12) {
		iP -= 12;
	}
	return (FrequencyPitch)iP;
}