#include "ElektronskaPoruka.h"

ostream& operator<<(ostream& it, ElektronskaPoruka& ep)
{
    ep.pisi(it);
    return it;
}

void ElektronskaPoruka::pisi(ostream& it)
{
    it << naslov << endl << *posiljalac << endl <<  *primalac;
}
