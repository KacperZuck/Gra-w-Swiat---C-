#pragma once

#include "Zwierze.h"
using namespace std;

class Czlowiek : public Zwierze {
public:
    Czlowiek(int poz_x, int poz_y, Swiat* swiat);
	Czlowiek* Dziecko(int poz_x, int poz_y, Swiat* swiat);
    bool CzyOdbilAtak(Organizm* atakujacy);

    void Akcja();
    void Kolizja(Organizm* organizm, int x, int y) ;
};
