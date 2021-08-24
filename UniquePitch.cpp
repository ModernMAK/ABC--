// 
// 
// 

#include "UniquePitch.h"
bool UniquePitchExtensions::hasFlag(UniquePitch uP, UniquePitch flag)
{
	return (uP & flag) == flag;
}

bool UniquePitchExtensions::isFlat(UniquePitch uP)
{
	return (
		(!isExplicit(uP) && isImplicitFlat(uP)) ||
		(isExplicitFlat(uP))
	);
}

bool UniquePitchExtensions::isSharp(UniquePitch uP)
{
	return (
		(!isExplicit(uP) && isImplicitSharp(uP)) ||
		(isExplicitSharp(uP))
	);
}

bool UniquePitchExtensions::isNatural(UniquePitch uP)
{
	return (
		(!isExplicit(uP) && isImplicitNatural(uP)) ||
		(isExplicitNatural(uP))
	);
}


bool UniquePitchExtensions::isImplicitFlat(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ImplicitFlat);
}

bool UniquePitchExtensions::isImplicitNatural(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ImplicitNatural);
}

bool UniquePitchExtensions::isImplicitSharp(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ImplicitSharp);
}


bool UniquePitchExtensions::isExplicit(UniquePitch uP)
{
	return isExplicitFlat(uP) || isExplicitNatural(uP) || isExplicitSharp(uP);
}

bool UniquePitchExtensions::isExplicitFlat(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ExplicitFlat);
}

bool UniquePitchExtensions::isExplicitNatural(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ExplicitNatural);
}

bool UniquePitchExtensions::isExplicitSharp(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_ExplicitSharp);
}


bool UniquePitchExtensions::isRest(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_Rest);
}


bool UniquePitchExtensions::isA(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_A);
}

bool UniquePitchExtensions::isB(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_B);
}

bool UniquePitchExtensions::isC(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_C);
}

bool UniquePitchExtensions::isD(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_D);
}

bool UniquePitchExtensions::isE(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_E);
}

bool UniquePitchExtensions::isF(UniquePitch uP)
{
	return hasFlag(uP, UniquePitch::U_F);
}

bool UniquePitchExtensions::isG(UniquePitch uP)
{
	return hasFlag(uP,UniquePitch::U_G);
}
