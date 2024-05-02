#include <iostream>
#include "Czlowiek.h"
#include "Swiat.h"
using namespace std;

    Czlowiek::Czlowiek( int poz_x, int poz_y, Swiat* swiat)
        : Zwierze( poz_x, poz_y, swiat, CZLOWIEK, 5, 4, 0) {
    }

    Czlowiek* Czlowiek::Dziecko(int poz_x, int poz_y, Swiat* swiat){
        return nullptr;
    }

    bool Czlowiek::CzyOdbilAtak(Organizm* atakujacy){
        if (swiat->getUmiejetnosc() >0) {
            cout << "Czlowiek odbiaja atak " << atakujacy->NazwaString() << endl;
            return true;
        }
        else {
            return false;
        }
    }

    void Czlowiek::Akcja() {
        this->Ruch();
        if (dlugoscZycia == 0) {    // pocz¹tek planszy
            Zwierze::Akcja();
        }
        else {
            int dx = swiat->getCzlowiekX();
            int dy = swiat->getCzlowiekY();
            if (poz_x + dx >= 0 && poz_x + dx < swiat->getSzerokosc() && poz_y + dy >= 0 && poz_y + dy < swiat->getWysokosc() ) { //  && (dx != 0 && dy != 0)
                if (dx == 0) {
                    if (dy == 0) {
                        cout << "Czlowiek - Nie wykonuje ruchu" << endl;
                    }
                    else {
                        dx += poz_x;
                        dy += poz_y;
                        cout << "Czlowiek - Wykonuje ruch na: x = "<< dx << ", y = "<< swiat->getWysokosc()-dy << endl;

                        Organizm* Inny = swiat->getOrganizm(dx, dy);
                        if (Inny == nullptr) {
                             swiat->ZmienPole(this, dx, dy);
                            setX(dx);
                            setY(dy);
                        }
                        else {
                            Kolizja(this, dx, dy);
                        }
                    }
                }
                else {
                    dx += poz_x;
                    dy += poz_y;
                    cout << "Czlowiek - Wykonuje ruch na: x = " << dx << ", y = " << swiat->getWysokosc()-dy << endl;

                    Organizm* Inny = swiat->getOrganizm(dx, dy);
                    if (Inny == nullptr) {
                        swiat->ZmienPole(this, dx, dy);
                        setX(dx);
                        setY(dy);
                    }
                    else {
                        Kolizja(this, dx, dy);
                    }
                }
            }
            else {
                cout << "Czlowiek - Niemozliwy ruch do wykonania" << endl;
            }
        }
    }

    void Czlowiek::Kolizja(Organizm* organizm , int dx, int dy)  {

        Organizm* Inny = swiat->getOrganizm(dx, dy);
        
        if (swiat->getUmiejetnosc() < 0 && Inny->CzyOdbilAtak(this) ) { // true = odbi³
            // ewentualnie cos
        }
        else if (Inny->getSila() <= this->getSila()) {    // Wygrywa atakuj¹cy
            cout << NazwaString() << " pokonuje: " << Inny->NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
            swiat->Usun(Inny);
            swiat->ZmienPole(this, dx, dy);
        }
        else if (Inny->getSila() > this->getSila()) {    // wygrywa broni¹cy
            if (swiat->getUmiejetnosc() >0) {  // dziala umiejetnosc
                int x = dx - 1;
                for (; x <= dx + 1; x++) {
                    int y = dy - 1;
                    for (; y <= dy + 1; y++) {
                        if (x >= 0 && x < swiat->getSzerokosc() && y >= 0 && y < swiat->getWysokosc()
                            && swiat->getOrganizm(x, y) == nullptr && (x != dx && y != dy)) {
                            swiat->ZmienPole(this, x, y);
                            cout << "Czlowiek przesuwa sie na pole : x = " << x << ", y = " << swiat->getWysokosc() - y << endl;
                            x = 100;
                            y = 100;
                        }
                    }
                }
            }
            else {
                cout << Inny->NazwaString() << " pokonuje: " << NazwaString() << ", na polu : x = " << dx << ", y = " << swiat->getWysokosc() - dy << endl;
                swiat->Usun(this);
            }
        }
    }