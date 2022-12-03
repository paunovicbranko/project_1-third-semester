#include "ElPorukaSaTekstom.h"

void ElPorukaSaTekstom::postaviTekst(string t)
{
	if (stanje == POSLATA) throw GPoslataPoruka();
	tekst = t;
}

ostream& operator<<(ostream& it, ElPorukaSaTekstom& ept)
{
	ept.pisi(it);
	it << endl << ept.tekst;
	return it;
}
