#include "SerialClass.h"
#include "ArduinoCommands.h"
#include <string>
#include "AbcFile.h"
#include "RawToneSong.h"
#include <iostream>
#pragma warning(disable: 4996)

const std::string abcFile = "C/4 D/4 E/4 F/4 G/4 A/4 B/4";

void sendToneCommand(Serial * serial, unsigned int frequency, unsigned long duration) {

	std::string
		cFinal;
		//* cCommand = new char[11],
		//* cFrequency = new char[11],
		//* cDuration = new char[11],
		//* cFinal;
	cFinal.append(std::to_string(A_C_PlayTone));
	cFinal.append(" ");
	cFinal.append(std::to_string(frequency));
	cFinal.append(" ");
	cFinal.append(std::to_string(duration));
	cFinal.append("\n");
	/*
	cCommand = itos(A_C_PlayTone,cCommand,10);
	cFrequency = itoa(frequency, cFrequency,10);
	cDuration = ltoa(frequency, cFrequency,10);
	cFinal = strcat(cCommand,strcat(" ",
		strcat(cFrequency,strcat(" ",
			strcat(cDuration,"\n")))));
	*/

	int length = cFinal.size() ;
	char* c = new char[length];
	cFinal.copy(c, length - 1);
	cFinal[length] = '\0';
	serial->WriteData(c,length-1);
	/*
	delete cCommand;
	delete cFrequency;
	delete cDuration;
	*/
}
void sendToneCommand(Serial * serial, RawTone * rt) {
	sendToneCommand(serial, rt->getFrequency(), rt->getDuration());
}

int main() {
	Serial* serial = new Serial("COM5");
	Sleep(100);

#define D5 880
#define E5 988 //987.766602512
#define F5 1047 //1046.5022612
#define A4 440
#define C4 523 //523.251130601
#define C5 784 //783.990871963
#define G5 1175 //1174.65907167
#define B4 494 //493.883301256
#define G4 784 //783.990871963
#define F4 698 //698.456462866

#define L_2 500
#define L_3 375
#define L_1 250
#define L_0 125

	const int toneLength = 55;
	RawTone * tones = new RawTone[toneLength]{
		{ D5,L_1 },	{ D5,L_1 },	{ E5,L_1 },	{ F5,L_1 },
		{ D5,L_1 },	{ F5,L_1 },	{ E5,L_1 },	{ A4,L_1 },
		{ D5,L_1 },	{ D5,L_1 },	{ E5,L_1 },	{ F5,L_1 },
		{ D5,L_2 },	{ C5,L_2 },

		{ D5,L_1 },	{ D5,L_1 },	{ E5,L_1 },	{ F5,L_1 },
		{ G5,L_1 },	{ F5,L_1 },	{ E5,L_1 },	{ D5,L_1 },
		{ C5,L_1 },	{ A4,L_1 },	{ B4,L_1 },	{ C5,L_1 },
		{ D5,L_2 },	{ D5,L_2 },

		{ B4,L_3 },{ C5,L_0 },{ B4,L_1 },{ A4,L_1 },
		{ B4,L_1 },{ C5,L_1 },{ D5,L_2 },
		{ A4,L_3 },{ B4,L_0 },{ A4,L_1 },{ G4,L_1 },
		{ F4,L_2 },{ A4,L_2 },

		{ B4,L_3 },{ C5,L_0 },{ B4,L_1 },{ A4,L_1 },
		{ B4,L_1 },{ C5,L_1 },{ D5,L_1 },{ B4,L_1 },
		{ A4,L_1 },{ D5,L_1 },{ C5,L_1 },{ E5,L_1 },
		{ D5,L_2 },{ D5,L_2 }
	};
	for (int i = 0; i < toneLength; i++) {
		sendToneCommand(serial, &tones[i]);
	}

	delete tones;
//
//	AbcFile * file = new AbcFile(abcFile);
//	RawToneSong * song = RawToneSongExtensions::toRawToneSong(file);
////	if (serial->IsConnected()) {
//	delete file;
//
//	for (int i = 0; i < song->getLength(); i++) {
//		sendToneCommand(serial, song->getFrequency(i), song->getDuration(i));
//	}
//	delete song;
//
	int length = 255;
	char buffer[256] = "";
	int readResult = 0;

	while(serial->IsConnected())
	{
		readResult = serial->ReadData(buffer, length);
		std::cout << buffer << '\n';
		Sleep(100);
	}
}