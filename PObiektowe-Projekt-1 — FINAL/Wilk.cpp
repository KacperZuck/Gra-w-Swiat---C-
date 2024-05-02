
#include "Wilk.h"	// TEST
#include "Swiat.h"
#include "Organizm.h"
#include <iostream>
using namespace std;

Wilk::Wilk(int poz_x, int poz_y, Swiat* swiat) : Zwierze(poz_x, poz_y, swiat, WILK, 9, 4, 0){
}

Wilk* Wilk::Dziecko(int poz_x, int poz_y, Swiat* swiat){
    return new Wilk(poz_x,poz_y, swiat);
}

