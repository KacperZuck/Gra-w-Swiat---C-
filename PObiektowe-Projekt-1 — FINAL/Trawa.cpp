
#include "Trawa.h"	// TEST
#include "Swiat.h"
using namespace std;

Trawa::Trawa(int poz_x, int poz_y, Swiat* swiat) : Roslina(poz_x, poz_y, swiat, TRAWA, 0, 0, 0) {
}

Trawa* Trawa::Dziecko(int poz_x, int poz_y, Swiat* swiat){
	return new Trawa(poz_x, poz_y, swiat);
}
