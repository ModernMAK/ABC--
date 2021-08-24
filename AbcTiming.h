// AbcTiming.h

#ifndef _ABCTIMING_h
#define _ABCTIMING_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Fraction.h"
struct AbcTiming : Fraction{
protected:
	static AbcTiming* fromAbc(String strNum, String strDenom) {
		char
			*cNumArr = new char[strNum.length() + 1],
			*cDenomArr = new char[strDenom.length() + 1];
		strNum.toCharArray(cNumArr, strNum.length() + 1);
		strDenom.toCharArray(cDenomArr, strDenom.length() + 1);
		return new AbcTiming(atoi(cNumArr), atoi(cDenomArr));
	}
public:

	AbcTiming(int nN, int nD) : Fraction(nN,nD){
	}

	static String toAbc(AbcTiming* timing) {
		String ret = "";
		if (timing->getNumerator() > 1)
		{
			ret.concat(timing->getNumerator());
		}
		
		if (timing->getDenominator() > 1)
		{
			ret.concat("/");
			ret.concat(timing->getDenominator());
		}
		return ret;
	}
	String toAbc() {
		return AbcTiming::toAbc(this);
	}
	static AbcTiming* fromAbc(String timing) 
	{
		String
			sNum = "1",
			sDenom = "1";
		int lastI = 0;
		bool flagged = false;
		for (unsigned int i = 0; i < timing.length(); i++) 
		{
			if (!isDigit(timing[i])) {
				if (i == 0) {
					flagged = true;
					break;
				}
				sNum = timing.substring(0, i);
				lastI = i;
				flagged = true;
				break;
			}
		}
		if (!flagged) {
			//We finished with no nonnumbers or / marks
			sNum = timing;
			return fromAbc(sNum, sDenom);
		}
		flagged = false;
		if (timing[lastI] == '//') {
			for (unsigned int i = lastI + 1; lastI < timing.length(); i++){
				if (!isDigit(timing[i])) {
					if (i == 0) {
						flagged = true;
						break;
					}
					sDenom = timing.substring(lastI+1, i);
					lastI = i;
					flagged = true;
					break;
				}
			}
			if (!flagged) {
				//We finished with no nonnumbers
				sDenom = timing.substring(lastI+1, timing.length()-1);
				//return fromAbc(sNum, sDenom);
			}
		}
		return fromAbc(sNum, sDenom);
		
		
		//First look for numbers until  no numbers
			//None found, assign numerator
				//Found /, skip /
					//look for numbers until no numbers
						//None found, assign denom
				//Not found /, assign denom 1
					
	}
};

#endif

