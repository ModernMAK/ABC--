// ArduinoCommands.h

#ifndef _ARDUINOCOMMANDS_h
#define _ARDUINOCOMMANDS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
enum ArduinoCommands {
	A_C_Completed = 0,
	A_C_PlayTone = 1

};


#endif

