// UniquePitch.h

#ifndef _UNIQUEPITCH_h
#define _UNIQUEPITCH_h

enum UniquePitch {
	U_Rest = (1 << 13),

	U_A = (1 << 0),
	U_B = (1 << 1),
	U_C = (1 << 2),
	U_D = (1 << 3),
	U_E = (1 << 4),
	U_F = (1 << 5),
	U_G = (1 << 6),

	U_ImplicitFlat = (1 << 7),
	U_ImplicitNatural = (1 << 8),
	U_ImplicitSharp = (1 << 9),

	U_ExplicitFlat = (1 << 10),
	U_ExplicitNatural = (1 << 11),
	U_ExplicitSharp = (1 << 12),

	U_An = U_A | U_ImplicitNatural,
	U_Bn = U_B | U_ImplicitNatural,
	U_Cn = U_C | U_ImplicitNatural,
	U_Dn = U_D | U_ImplicitNatural,
	U_En = U_E | U_ImplicitNatural,
	U_Fn = U_F | U_ImplicitNatural,
	U_Gn = U_G | U_ImplicitNatural,

	U_Af = (U_A | U_ImplicitFlat),
	U_Bf = (U_B | U_ImplicitFlat),
	U_Cf = (U_C | U_ImplicitFlat),
	U_Df = (U_D | U_ImplicitFlat),
	U_Ef = (U_E | U_ImplicitFlat),
	U_Ff = (U_F | U_ImplicitFlat),
	U_Gf = (U_G | U_ImplicitFlat),

	U_As = (U_A | U_ImplicitSharp),
	U_Bs = (U_B | U_ImplicitSharp),
	U_Cs = (U_C | U_ImplicitSharp),
	U_Ds = (U_D | U_ImplicitSharp),
	U_Es = (U_E | U_ImplicitSharp),
	U_Fs = (U_F | U_ImplicitSharp),
	U_Gs = (U_G | U_ImplicitSharp),
};

class UniquePitchExtensions {
protected:
	static bool hasFlag(UniquePitch uP, UniquePitch flag);
public:
	static bool isFlat(UniquePitch uP);
	static bool isSharp(UniquePitch uP);
	static bool isNatural(UniquePitch uP);


	static bool isImplicitFlat(UniquePitch uP);
	static bool isImplicitNatural(UniquePitch uP);
	static bool isImplicitSharp(UniquePitch uP);

	static bool isExplicit(UniquePitch uP);
	static bool isExplicitFlat(UniquePitch uP);
	static bool isExplicitNatural(UniquePitch uP);
	static bool isExplicitSharp(UniquePitch uP);

	static bool isRest(UniquePitch uP);

	static bool isA(UniquePitch uP);
	static bool isB(UniquePitch uP);
	static bool isC(UniquePitch uP);
	static bool isD(UniquePitch uP);
	static bool isE(UniquePitch uP);
	static bool isF(UniquePitch uP);
	static bool isG(UniquePitch uP);
};

#endif

