#ifndef _korisnik_h_
#define _korisnik_h_
#include <string>
#include <iostream>
using namespace std;

class Korisnik
{
	string ime, elAdresa;
	
public:
	Korisnik(string ime, string elAdresa): ime(ime), elAdresa(elAdresa){}

	string dohIme() const { return ime; }
	string dohElAdresu() const { return elAdresa; }

	Korisnik(const Korisnik&) = delete;
	void operator=(const Korisnik&) = delete;

	friend ostream& operator<<(ostream& it, const Korisnik& k);
};

#endif