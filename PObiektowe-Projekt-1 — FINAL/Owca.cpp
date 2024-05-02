#include "Owca.h"

Owca::Owca(int poz_x, int poz_y, Swiat* swiat) : Zwierze(poz_x, poz_y, swiat, OWCA, 4, 4, 0){
}

Owca* Owca::Dziecko(int poz_x, int poz_y, Swiat* swiat)
{
	return new Owca( poz_x, poz_y, swiat);
}
