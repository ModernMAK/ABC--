// RawToneSong.h

#ifndef _RAWTONESONG_h
#define _RAWTONESONG_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "RawTone.h"
#include "AbcFile.h"

class RawToneSong {
private:
	RawTone *
		myTones;
	unsigned int
		myToneLength;


protected:
	void init(RawTone * tones, unsigned int length){
		myTones = tones;
		myToneLength = length;
	}

public:
	RawToneSong(RawTone * tones, unsigned int length) {
		init(tones, length);
	}
	~RawToneSong() {
		delete[] myTones;
	}
	unsigned int getFrequency(int index) { return getTone(index).getFrequency(); }
	unsigned long getDuration(int index) { return getTone(index).getDuration(); }
	RawTone getTone(int index) { return myTones[index]; }
	unsigned int getLength() { return myToneLength; }
	

};

class RawToneSongExtensions {
public:
	static RawToneSong * toRawToneSong(AbcFile * file) {
		RawTone * rawTones = new RawTone[file->getLength()];
		for (int i = 0; i < file->getLength(); i++) {
			rawTones[i] = *RawToneExtensions::toRawTone(file->getNote(i));
		}
		return new RawToneSong(rawTones, file->getLength());
	}

};

#endif

