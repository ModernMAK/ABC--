// RawTone.h

#ifndef _RAWTONE_h
#define _RAWTONE_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "AbcNote.h"
class RawTone {
private:
	unsigned int
		myFrequency;
	unsigned long
		myDuration;

protected:
	void init(unsigned int freq, unsigned long dur) {
		myFrequency = freq;
		myDuration = dur;
	}

public:
	unsigned int getFrequency() {
		return myFrequency;
	}
	unsigned long getDuration() {
		return myDuration;
	}
	RawTone(unsigned int freq = 0, unsigned long dur = 0) {
		init(freq, dur);
	}

};

class RawToneExtensions {
public:
	static RawTone * toRawTone(AbcNote note) {
		return toRawTone(&note);
	}
	static RawTone * toRawTone(AbcNote * note) {
		return new RawTone(note->getFrequency(), note->getTimingValue() * 1000);
	}

};

#endif

