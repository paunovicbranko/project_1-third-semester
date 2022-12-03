#ifndef _vremenskaoznaka_h_
#define _vremenskaoznaka_h_
#include <iostream>
using namespace std;

class VremenskaOznaka
{
	int godina, mesec, dan, sati, minuti;

public:
	VremenskaOznaka(int godina, int mesec, int dan, int sati, int minuti)
		:godina(godina), mesec(mesec), dan(dan), sati(sati), minuti(minuti){}

	friend ostream& operator<<(ostream& it, const VremenskaOznaka& vo);
};

#endif