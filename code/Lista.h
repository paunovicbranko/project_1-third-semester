#ifndef _lista_h_
#define _lista_h_
#include <iostream>
using namespace std;

class GNemaTekuceg {
	friend ostream& operator<<(ostream& it, const GNemaTekuceg& t) {
		it << "Ne postoji tekuci element!";
		return it;
	}
};


template <typename T>
class Lista
{
	struct Elem {
		T podatak; Elem* sled;
		Elem(const T& podatak, Elem* sled = nullptr): podatak(podatak), sled(sled) {}
	};
	Elem* prvi, * posl;
	int broj;
	mutable Elem* tek;

	void kopiraj(const Lista& l);
	void brisi();

	void premesti(Lista& l) {
		prvi = l.prvi;
		posl = l.posl;
		tek = l.tek;
		l.prvi = l.posl = l.tek = nullptr;
	}

	void zameni(Lista& l1, Lista& l2) {
		std::swap(l1.prvi, l2.prvi);
		std::swap(l1.posl, l2.posl);
		std::swap(l1.broj, l2.broj);
		std::swap(l1.tek, l2.tek);
	}

public:
	Lista() {
		prvi = posl = tek = pret = nullptr;
	}

	Lista(const Lista& l) {
		kopiraj(l);
	}

	Lista(Lista&& l) {
		premesti(l);
	}

	~Lista() {
		brisi();
	}

	Lista operator=(Lista l) {
		swap(*this, l);
		return *this;
	}

	// Dodavanje jednog elementa u listu:
	Lista& dodaj(const T& t) {
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		broj++;
		return *this;
	}

	int dohBroj() const { return broj; }
	void naPrvi() const { tek = prvi; }
	void naSled() const {
		if (tek) tek = tek->sled;
	}
	bool imaTek() const {
		return tek != nullptr;
	}
	T& dohTek() const {
		if (!tek) throw GNemaTekuceg();
		return tek->pod;
	}

};

template<typename T>
inline void Lista<T>::kopiraj(const Lista& l)
{
	prvi = posl = tek = pret = nullptr;

	for (Elem* pok = l.prvi; pok; pok = pok->sled) {
		Elem* novi = new Elem(pok->pod);
		posl = (!prvi ? prvi : posl->sled) = novi;

		if (pok == l.tek) tek = novi;
		if (pok == l.pret) pret = novi;
	}
}

template<typename T>
inline void Lista<T>::brisi()
{
	while (prvi) {
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
}

#endif


