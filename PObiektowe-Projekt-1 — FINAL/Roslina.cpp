
#include <iostream>
#include "Swiat.h"
#include "Roslina.h"
using namespace std;

Roslina::Roslina( int poz_x, int poz_y, Swiat* swiat, Rasa rasa, int sila, int inicjatywa, int dlugoscZycia)
	 : Organizm( poz_x, poz_y, swiat, rasa, sila , 0 , dlugoscZycia) {}

void Roslina::Akcja() {
    this->Ruch();
    
    bool zasieje = (rand() % 100 ) >= 98;
    if (zasieje) {
        int sprawdzenie = 0;
        int dx = rand() % 3 - 1; // -1, 0, 1
        int dy = rand() % 3 - 1; // -1, 0, 1
        while (sprawdzenie != 9) {   // wszystkie 9 pol
            if (poz_x + dx >= 0 && poz_x + dx < swiat->getSzerokosc() && poz_y + dy >= 0 && poz_y + dy < swiat->getWysokosc() ) {
                if (swiat->getOrganizm(dx + poz_x, dy + poz_y) == nullptr) {
                    Organizm* dziecko = this->Dziecko(dx+poz_x, dy+poz_y, swiat);
                    dziecko->setDlugosZycia(-1);
                    cout << "Nowy " << NazwaString() << " na polu : x = " << dx +poz_x<< ", y = " << swiat->getWysokosc() - dy - poz_y << endl;
                    break;
                }
                else if(swiat->getOrganizm(dx + poz_x, dy+poz_y)->getRasa() != this->getRasa() ) {
                    Kolizja(this, dx+poz_x, dy+poz_y);
                    break;
                }
            }
            dx = rand() % 3 - 1; // -1, 0, 1
            dy = rand() % 3 - 1; // -1, 0, 1
            sprawdzenie++;
        }
        if (sprawdzenie == 9) { cout << "Brak miejsca na nowe " << NazwaString() << " na polu : x = " << dx + poz_x << ", y = " << swiat->getWysokosc() - dy - poz_y << endl;
        }
    }
}

void Roslina::Kolizja(Organizm* organizm, int dx, int dy) {

    Organizm* Stary = swiat->getOrganizm(dx, dy);
    if (Stary->CzyOdbilAtak(this)) { // true = odbi³
        // ewentualnie cos
    }
    else if (Stary->getRasa() != this->getRasa()) {
        if (Stary->getSila() <= this->getSila()) {    // Wygrywa roslina
            cout << NazwaString() << " zatrula " << Stary->NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(Stary);
            Organizm* dziecko = this->Dziecko(dx, dy, swiat);
            dziecko->setDlugosZycia(-1);
            cout << "Nowy " << NazwaString() << " na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;

        }
        else if (Stary->getSila() > this->getSila()) {    // wygrywa organizm
            cout << Stary->NazwaString() << " pokonuje " << NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
        }
    }
    

}

/*
if ( Stary->CzyRoslina(Stary->getRasa()) == false  && Stary->CzyOdbilAtak(this)) { // true = odbi³
        // ewentualnie cos
    }


    

    Organizm* Stary = swiat->getOrganizm(dx, dy);
    if (Stary->CzyZwierze(Stary->getRasa()) == true) {
        if (Stary->CzyOdbilAtak(this)) { // true = odbi³
            // ewentualnie cos
        }
        else if (Stary->getSila() <= this->getSila()) {    // Wygrywa roslina
            cout << NazwaString() << " zatrula " << Stary->NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(Stary);
            Organizm* dziecko = this->Dziecko(dx, dy, swiat);
            dziecko->setDlugosZycia(-1);
            cout << "Nowy " << NazwaString() << " na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;

        }
        else if (Stary->getSila() > this->getSila()) {    // wygrywa organizm
            cout << Stary->NazwaString() << " pokonuje " << NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
        }
    }
    else if (Stary->CzyRoslina(Stary->getRasa()) == true) {
        if (Stary->getSila() <= this->getSila()) {    // wygrywa nowa roslina
            cout << NazwaString() << " pokonala " << Stary->NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(Stary);
            Organizm* dziecko = this->Dziecko(dx, dy, swiat);
            dziecko->setDlugosZycia(-1);
            cout << "Nowy " << NazwaString() << " na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;

        }
        else if (Stary->getSila() > this->getSila()) {    // wygrywa stara rozlina
            cout << Stary->NazwaString() << " pokonuje " << NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
        }
    }

   


*/