#include "Korisnik.h"

ostream& operator<<(ostream& it, const Korisnik& k)
{
    return it << "(" << k.ime << ")" << k.elAdresa;
}
