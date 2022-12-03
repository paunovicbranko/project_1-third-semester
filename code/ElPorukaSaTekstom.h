#ifndef _elporukasatekstom_h_
#define _elporukasatekstom_h_
#include "ElektronskaPoruka.h"

class GPoslataPoruka {
	friend ostream& operator<<(ostream& it, const GPoslataPoruka& t) {
		it << "Poruka je vec poslata!";
		return it;
	}
};

class ElPorukaSaTekstom : public ElektronskaPoruka
{
	string tekst;

public:
	ElPorukaSaTekstom(string naslov, Korisnik* posiljalac, Korisnik* primalac)
		: ElektronskaPoruka(naslov, posiljalac, primalac) {}

	void postaviTekst(string t);
	void posaljiPoruku() override { stanje = POSLATA; }

	ElektronskaPoruka* kopirajPoruku() override { return new ElPorukaSaTekstom(*this); }
	friend ostream& operator<<(ostream& it, ElPorukaSaTekstom& ept);
};

#endif