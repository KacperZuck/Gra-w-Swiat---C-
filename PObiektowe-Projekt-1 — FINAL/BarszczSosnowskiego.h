#pragma once

#include "Roslina.h"
using namespace std;

class BarszczSosnowskiego : public Roslina {		
public:
	BarszczSosnowskiego(int poz_x, int poz_y, Swiat* swiat);
	BarszczSosnowskiego* Dziecko(int poz_x, int poz_y, Swiat* swiat);
	
	void Akcja();
	void Kolizja(Organizm* organizm, int dx, int dy);
	bool CzyOdbilAtak(Organizm* atakujacy);
};


