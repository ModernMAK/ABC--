// PitchMediator.h

#ifndef _PITCHMEDIATOR_h
#define _PITCHMEDIATOR_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "FrequencyPitch.h"
#include "UniquePitch.h"
class PitchMediator {
public:
	//PitchMediator() {}

	static const int
		FREQUENCY_OCTAVE_BASE = 4; //4
	static constexpr double
		FREQUENCY_BASE = 261.625565301, //C4
		FREQUENCY_RATE = 1.05946309; //2^(1/12)

	static UniquePitch toUniquePitch(FrequencyPitch fP);
	static FrequencyPitch toFrequencyPitch(UniquePitch uP);

	static double calculateFrequencyFromPitch(FrequencyPitch fP, int octave = FREQUENCY_OCTAVE_BASE);
	static double calculateFrequencyFromPitch(UniquePitch uP, int octave = FREQUENCY_OCTAVE_BASE);

	static FrequencyPitch modifyPitchByHalfSteps(FrequencyPitch  fP, int halfSteps = 0);
	static UniquePitch modifyPitchByHalfSteps(UniquePitch  fP, int halfSteps = 0);
};
#endif

