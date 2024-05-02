#pragma once

#include "Roslina.h"
using namespace std;

class WilczeJagody : public Roslina {		// 0 - sily, 0 - inicjatywy
public:
	WilczeJagody(int poz_x, int poz_y, Swiat* swiat);
	WilczeJagody* Dziecko(int poz_x, int poz_y, Swiat* swiat);

	void Kolizja(Organizm* organizm, int x, int y);
	bool CzyOdbilAtak(Organizm* atakujacy);
};

