
#pragma once
#include "Zwierze.h"	
using namespace std;

class Antylopa : public Zwierze {
public:
	Antylopa(int poz_x, int poz_y, Swiat* swiat);
	Antylopa* Dziecko(int poz_x, int poz_y, Swiat* swiat);
	void Akcja();
	void Kolizja(Organizm* organizm, int x, int y);
};