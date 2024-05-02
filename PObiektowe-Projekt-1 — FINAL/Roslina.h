#pragma once
#include "Organizm.h"
using namespace std;

class Roslina : public Organizm {  
public:
	Roslina( int poz_x, int poz_y, Swiat* swiat, Rasa rasa, int sila, int inicjatywa, int dlugoscZycia);    // inicjatywa = 0
    virtual void Akcja();
    virtual void Kolizja(Organizm* organizm, int dx, int dy);
};