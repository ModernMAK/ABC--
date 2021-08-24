//#include "RawToneSong.h"
//#include "RawTone.h"
#include "ArduinoCommands.h"
//#include "KeySignature.h"
//#include "AbcHeader.h"
//#include "KeySignatureMode.h"
//#include "AbcNote.h"
//#include "Note.h"
//#include "Fraction.h"
//#include "PitchMediator.h"
//#include "FrequencyPitch.h"
//#include "UniquePitch.h"
//
//const int length = 1;
//const AbcNote notes[length] = {
//	{ "C,,/4" },//{ "D,,/4" },{ "E,,/4" },//,{ "F,,/4" },{ "G,,/4" },{ "A,,/4" },{ "B,,/4" },
////	{ "C,/4" },{ "D,/4" },{ "E,/4" },{ "F,/4" },{ "G,/4" },{ "A,/4" },{ "B,/4" },
//	//		{ "C/4" },{ "D/4" },{ "E/4" },{ "F/4" },{ "G/4" },{ "A/4" },{ "B/4" },
//	//		{ "c/4" },{ "d/4" },{ "e/4" },{ "f/4" },{ "g/4" },{ "a/4" },{ "b/4" },
//	//		{ "c'/4" },{ "d'/4" },{ "e'/4" },{ "f'/4" },{ "g'/4" },{ "a'/4" },{ "b'/4" },
//}; 
void setup()
{
	Serial.begin(9600);
	while (!Serial) {
		delay(10);
	}
	delay(1000);
	//sendToneCommand(31, 250);
	//	String str = "^C/2";
		//Serial.println("STR : " + str);
	//play
	//	//Serial.println("ABC : " + note.toAbcString());
	//KeySignature ks = { U_A };
	//int i;
	//for (i = 0; i < length; i++) {
	//	AbcNote note = notes[i];

	//	Serial.print("ABC : ");
	//	Serial.print(i);
	//	Serial.print(" : ");
	//	Serial.print(note.toAbcString());
	//	Serial.println();

	//	Serial.print("Aa : ");
	//	Serial.print(note.getTiming().getNumerator());
	//	Serial.print(" / ");
	//	Serial.print(note.getTiming().getDenominator());
	//	Serial.println();

	//	double d = note.getTimingValue() * 1000.0;


	//	tone(8, note.getFrequency(), d);


	//	delay(d * 1.3);

	//}
	//for (i = 0; i < length; i++) {
	//	AbcNote note = notes[i];

	//	Serial.print("ABC : ");
	//	Serial.print(i);
	//	Serial.print(" : ");
	//	Serial.print(note.toAbcString());
	//	Serial.println();

	//	Serial.print("Ba : ");
	//	Serial.print(note.getTiming().getNumerator());
	//	Serial.print(" / ");
	//	Serial.print(note.getTiming().getDenominator());
	//	Serial.println();

	//	double d = note.getTimingValue() * 1000.0;

	//	tone(8, note.getFrequency(ks), d);

	//	delay(d * 1.3);

	//}

}
#define TONE_PIN 8
void playToneCommand(unsigned int frequency, unsigned long duration) {
	tone(TONE_PIN, frequency, duration);
	delay(duration * 1.3);
	//noTone(TONE_PIN);
}

void sendToneCommand(unsigned int frequency, unsigned long duration) {
	Serial.print(A_C_PlayTone);
	Serial.print(" ");
	Serial.print(frequency);
	Serial.print(" "); 
	Serial.print(duration);
	Serial.println();
}

void loop()
{
	if (Serial.available() > 0) {
		String
			str = Serial.readStringUntil('\n');
		int 
			i = str.indexOf(' '),
			tI = i;
		String
			cmd = str.substring(0,i);

		ArduinoCommands ac = (ArduinoCommands)cmd.toInt();
		switch (ac)
		{
		case A_C_PlayTone:
			tI = str.indexOf(' ', i+1 );
			int
				freq = str.substring(i + 1, tI).toInt();
			i = tI;
			tI = str.indexOf(' ', i + 1);
			if(tI == -1)
				tI = str.length();
			long
				timing = str.substring(i + 1, tI).toInt();
			playToneCommand(
					freq,
					timing
				);
      Serial.print(A_C_Completed);
      Serial.print(" : ");
      Serial.print(freq);
      Serial.print(" -> ");
      Serial.println(timing);
			break;
		}
	}
	delay(100);
  /* add main program code here */

}
