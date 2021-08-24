#include "AbcNote.h"
#include "Frequency.h"
#include "Fraction.h"
#include "AbcTiming.h"
#include "Pitch.h"
#include "AbcPitch.h"
//#include <vector>

String strAbc = "ddefdfeAddefd2c2ddefgfedcABc";

int recursiveBuilder(String str, int lastI, int depth, AbcNote * noteArr) {
	bool flagged = false;

	Serial.print("Str : ");
	Serial.print(str);
	Serial.print(" -> I : ");
	Serial.print(lastI);
	Serial.print(" -> D : ");
	Serial.print(depth);
	for (int i = lastI; i < str.length(); i++) {
		if (AbcPitch::isPitchSymbol(str[i])) {
			String sub = str.substring(lastI,i+1);
			Serial.print(" -> S : ");
			Serial.print(sub);
			Serial.println();
			recursiveBuilder(str, i+1, depth + 1, noteArr);
			flagged = true;
			*(noteArr + depth) = *AbcNote::fromAbc(sub);
		}
	}
	if (flagged == false) {
		noteArr = new AbcNote[depth + 1];
		*(noteArr + depth) = *AbcNote::fromAbc(str.substring(lastI));
	}
}

int recursiveBuilder(String str, AbcNote * noteArr) {
	recursiveBuilder(str, 0, 0, noteArr);
}

void setup()
{
	Serial.begin(9600);
	while (!Serial) {
		delay(100);
	}
	delay(100);

	Serial.println("A");
	AbcNote* abcTune;
	int size = recursiveBuilder(strAbc, abcTune);
	AbcTiming* timing = new AbcTiming(1, 4);

	Serial.println("B");
	for (int i = 0; i < size; i++) {
		Serial.print("C");
		Serial.println(i);
		double dur = timing->getValue() * (abcTune + i)->getTiming().getValue();
		tone(8, (abcTune + i)->getFrequency(), dur * 1000.0);
		delay(dur * 1300.0);
	}

	delete timing;
	delete[] abcTune;
	//vector<AbcNote> abcTune;


  /* add setup code here */

}

void loop()
{

  /* add main program code here */

}
