#ifndef _elektronskaporuka_h_
#define _elektronskaporuka_h_
#include "Korisnik.h"
#include <iostream>
using namespace std;

class ElektronskaPoruka
{
public:
	enum Stanje{ U_PRIPREMI, POSLATA, PRIMLJENA };

	string naslov;
	Korisnik* posiljalac, * primalac;
	Stanje stanje;
	
public:
	ElektronskaPoruka(){}
	ElektronskaPoruka(string naslov, Korisnik* posiljalac, Korisnik* primalac)
		:naslov(naslov), posiljalac(posiljalac), primalac(primalac)
	{
		stanje = U_PRIPREMI;
	}

	string dohNaslov() const { return naslov; }
	Korisnik* dohPosiljaoca() const { return posiljalac; }
	Korisnik* dohPrimaoca() const { return primalac; }
	Stanje dohStanje() const { return stanje; }

	virtual ElektronskaPoruka* kopirajPoruku() = 0;
	virtual void posaljiPoruku() = 0;

	friend ostream& operator<<(ostream& it, ElektronskaPoruka& ep);
	void pisi(ostream& it);
};

#endif