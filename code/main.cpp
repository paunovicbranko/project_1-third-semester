#include <iostream>
#include "Korisnik.h"
#include "ElPorukaSaTekstom.h"
using namespace std;

int main() {
	try {
		Korisnik k1("Branko", "paunovic.b01@gmail.com");
		Korisnik k2("Petar", "petrovicpetar@gmail.com");

		ElPorukaSaTekstom ept1("Naslov 1", &k1, &k2);
		ept1.postaviTekst("Ovo je tekst poruke i on ce se nalaziti na kraju.");
		ept1.posaljiPoruku();
		//ept1.postaviTekst("Ovo je promena teksta");
		cout << ept1 << endl;
	}
	catch (GPoslataPoruka pp) {
		cout << pp << endl;
	}
}