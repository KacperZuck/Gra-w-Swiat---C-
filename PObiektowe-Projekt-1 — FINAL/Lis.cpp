
#include <iostream>
#include "Lis.h"
#include "Swiat.h"

Lis::Lis(int poz_x, int poz_y, Swiat* swiat) : Zwierze( poz_x, poz_y, swiat, LIS, 3, 7, 0){
}

Lis* Lis::Dziecko(int poz_x, int poz_y, Swiat* swiat)
{
	return new Lis(poz_x, poz_y, swiat);
}

void Lis::Akcja(){
    int dx = rand() % 3 - 1; // -1, 0, 1
    int dy = rand() % 3 - 1; // -1, 0, 1
    while (true) {
        if (poz_x + dx >= 0 && poz_x + dx < swiat->getSzerokosc() && poz_y + dy >= 0 && poz_y + dy < swiat->getWysokosc() && ( dx!=0 && dy!=0)) {
            dx += poz_x;
            dy += poz_y;
            break;
        }
        dx = rand() % 3 - 1; // -1, 0, 1
        dy = rand() % 3 - 1; // -1, 0, 1
    }

    Organizm* Stary = swiat->getOrganizm(dx, dy);
    if (Stary == nullptr) {
        swiat->ZmienPole(this, dx, dy);
        setX(dx);
        setY(dy);
    }
    else if(Stary->getSila() < sila ){    // Jesli jest slabszy nie podejmuje walki
        Zwierze::Kolizja(this, dx, dy);  
    }
    else {
        cout << "Lis nie porusza sie na pole: x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
    }
}

