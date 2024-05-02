
#include <iostream>
#include "Antylopa.h"
#include "Swiat.h"
Antylopa::Antylopa(int poz_x, int poz_y, Swiat* swiat) : Zwierze(poz_x, poz_y, swiat, ANTYLOPA, 4, 4, 0){
}

Antylopa* Antylopa::Dziecko(int poz_x, int poz_y, Swiat* swiat)
{
	return new Antylopa(poz_x, poz_y, swiat);
}

void Antylopa::Akcja(){
    int dx = rand() % 5 - 2; 
    int dy = rand() % 5 - 2; 
    while (true) {
        if (poz_x + dx >= 0 && poz_x + dx < swiat->getSzerokosc() && poz_y + dy >= 0 && poz_y + dy < swiat->getWysokosc() && (dx!=0 && dy!=0)) {
            dx += poz_x;
            dy += poz_y;
            break;
        }
        dx = rand() % 5 - 2; 
        dy = rand() % 5 - 2; 
    }

    Organizm* Stary = swiat->getOrganizm(dx, dy);
    if (Stary == nullptr) {
        swiat->ZmienPole(this, dx, dy);
        setX(dx);
        setY(dy);
    }
    else {
        Kolizja(this, dx, dy);          
    }
}

void Antylopa::Kolizja(Organizm* organizm, int dx, int dy){
    
    Organizm* Stary = swiat->getOrganizm(dx, dy);
    bool czyUciekla = rand() % 2;

    if (Stary->getRasa() == this->getRasa()) {
        if (Stary->getDlugoscZycia() < 0) {  
            int x = dx - 1;
            for (; x <= dx + 1; x++) {
                int y = dy - 1;
                for (; y <= dy + 1; y++) {
                    if (x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc() 
                            && swiat->getOrganizm(x, y) == nullptr && (x!=dx && y!=dy)) {
                        Organizm* dziecko = this->Dziecko(x, y, swiat);
                        dziecko->setDlugosZycia(-1);
                        cout << "Nowy " << NazwaString() << " na polu : x = " << x << ", y = " << swiat->getWysokosc() - y << endl;
                        x = 100;
                        y = 100;
                    }
                }
                if (x == dx + 1) {
                    cout << "Brak miejsca na nowe " << NazwaString() << " na polu : x = " << x << ", y = " << swiat->getWysokosc() - y << endl;
                }
            }
        }
    }
    else if (Stary->CzyOdbilAtak(this)) { // true = odbi³
        // ewentualnie cos
    }
    else if (!czyUciekla) { // jesli nie
        if (Stary->getSila() <= this->getSila()) {    // Wygrywa atakuj¹cy
            cout << NazwaString() << " pokonuje: " << Stary->NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(Stary);
            swiat->ZmienPole(this, dx, dy);
        }
        else if (Stary->getSila() > this->getSila()) {    // wygrywa broni¹cy
            cout << Stary->NazwaString() << " pokonuje: " << NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(this);
        }
    }
    else { // uciek³a
        int x = dx - 1;
            for (; x <= dx + 1; x++) {
                int y = dy - 1;
                for (; y <= dy + 1; y++) {
                    if (x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc() && swiat->getOrganizm(x, y) == nullptr) {
                        swiat->ZmienPole(this, x,y);
                        cout << "Udana ucieczka " << NazwaString() << " na polu : x = " << x << ", y = " << swiat->getWysokosc() - y << endl;
                        x = 100;
                    }
                }
                if (x == dx + 1) {
                    cout << "Brak miejsca na ucieczke" << NazwaString() << " na polu : x = " << x << ", y = " << swiat->getWysokosc() - y << endl;
                    Zwierze::Kolizja(this, dx, dy);
                }
            }
    }
    
}
