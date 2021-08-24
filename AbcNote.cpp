// 
// 
// 

#include "AbcNote.h"

MusicalKey AbcNote::getKey() {
	return myKey;
}

float AbcNote::getTimingMultiplier() {
	return myTimingMultiplier->getDeimal();
}

MusicalOctave AbcNote::getOctave()
{
	return myOctave;
}
