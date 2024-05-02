
#include <iostream>
#include "BarszczSosnowskiego.h"
#include "Roslina.h"
#include "Swiat.h"
#include "Czlowiek.h"

BarszczSosnowskiego::BarszczSosnowskiego(int poz_x, int poz_y, Swiat* swiat) : Roslina( poz_x, poz_y, swiat, BARSZCZ, 10, 0, 0){
}

BarszczSosnowskiego* BarszczSosnowskiego::Dziecko(int poz_x, int poz_y, Swiat* swiat){
	return new BarszczSosnowskiego(poz_x, poz_y, swiat);
}

void BarszczSosnowskiego::Akcja() {
    int x = poz_x - 1;
    for (; x <= poz_x + 1; x++) {
        int y = poz_y - 1;
        for (; y <= poz_y + 1; y++) {
            if (x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc() && ( x!=poz_x && y!=poz_y)) {
                Organizm* Stary = swiat->getOrganizm(x, y);
                if (Stary != nullptr && Stary->CzyZwierze(Stary->getRasa())==true) {
                    Kolizja(this, x, y);
                }
            }
        }
    }
    Roslina::Akcja();
}
void BarszczSosnowskiego::Kolizja(Organizm* organizm, int dx, int dy){

    Organizm* Stary = swiat->getOrganizm(dx, dy);
    if (Stary->CzyOdbilAtak(this)) { // true = odbi³    
        // ewentualnie cos
    }
    else if(CzyZwierze(Stary->getRasa())) {
        cout << Stary->NazwaString() << " zostal zabity przez Barszcz Sosnowskiego w jego poblizu" << endl; 
        swiat->Usun(Stary);
    }
    else {
        Roslina::Kolizja(this, dx, dy);
    }

}

bool BarszczSosnowskiego::CzyOdbilAtak(Organizm* atakujacy) {
    if (atakujacy->CzyOdbilAtak(this)) { // true = odbi³
        // ewentualnie cos
    }
    else if (CzyZwierze(atakujacy->getRasa())) {
        cout << atakujacy->NazwaString() << " zostal zabity przez Barszcz Sosnowskiego" << endl;
        swiat->Usun(atakujacy);
        return true;
    }
    else {
        return false;
    }
}



/*

bool BarszczSosnowskiego::CzyOdbilAtak(Organizm* atakujacy){
    if (atakujacy->CzyOdbilAtak(this)) { // true = odbi³
        // ewentualnie cos
    }
    else if (CzyZwierze(atakujacy->getRasa())) {
        cout << atakujacy->NazwaString() << " zostal zabity przez Barszcz Sosnowskiego" << endl;
        swiat->Usun(atakujacy);
        return true;
    }
    else {
        return false;
    }
}
*/