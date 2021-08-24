
#ifndef _ABCFILE_h
#define _ABCFILE_h

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "AbcNote.h"

class AbcFile
{
private:
	AbcNote *
		myNotes;
	int
		myLength;
protected:
	void init(std::string str) {
		std::vector<AbcNote*>
			tempNotes;
		bool isDone = false;
		unsigned int lastI = 0;
		while (!isDone) {
			int tempI = str.find(' ', lastI);
			if (tempI == -1) {
				tempI = str.length() - lastI;
				isDone = true;
			}
			std::string tempStr = str.substr(lastI,tempI);
			lastI = tempI + 1;
			isDone |= (lastI >= str.length());
			AbcNote * abc = new AbcNote(tempStr);

			tempNotes.push_back(abc);
		}
		myLength = tempNotes.size();
		myNotes = new AbcNote[myLength];
		for (int i = 0; i < myLength; i++) {
			myNotes[i] = *tempNotes.at(i);
		}
	}
public:
	AbcFile(std::string strData) { init(strData); }
	~AbcFile() { delete[] myNotes; }

	int getLength() { return myLength; }
	AbcNote * getNotes() {
		return myNotes;
	}
	AbcNote getNote(unsigned int index) {
		return *(myNotes + index);
	}
};
#endif
