#include "VremenskaOznaka.h"

ostream& operator<<(ostream& it, const VremenskaOznaka& vo)
{
	return it << vo.dan << "." << vo.mesec << "." << vo.godina << "-" << vo.sati << ":" << vo.minuti;
}
