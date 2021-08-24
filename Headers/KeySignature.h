// KeySignature.h

#ifndef _KEYSIGNATURE_h
#define _KEYSIGNATURE_h
#include "KeySignatureMode.h"
#include "UniquePitch.h"
struct KeySignature {
private:
	UniquePitch
		myPitch;
	KeySignatureMode
		myMode;
protected:
	void init(UniquePitch uP, KeySignatureMode ksm) {
		myPitch = uP;
		myMode = ksm;
	}
public:
	KeySignature(UniquePitch up = U_Cn, KeySignatureMode ksm = KSM_Major) {
		init(up, ksm);
	}
	UniquePitch getUniquePitch() {
		return myPitch;
	}
	KeySignatureMode getKeySignatureMode() {
		return myMode;
	}
	UniquePitch getModifiedPitch(UniquePitch uP) {
		return KeySignatureModeExtension::modifyPitch(uP, getUniquePitch(), getKeySignatureMode());
	}
};

#endif

