#pragma once
#include "Roslina.h"
using namespace std;

class Guarana : public Roslina {		// 0 - sily, 0 - inicjatywy
public:
	Guarana(int poz_x, int poz_y, Swiat* swiat);
	Guarana* Dziecko(int poz_x, int poz_y, Swiat* swiat);
	void Kolizja(Organizm* organizm, int dx, int dy);
	bool CzyOdbilAtak(Organizm* atakujacy);
};

