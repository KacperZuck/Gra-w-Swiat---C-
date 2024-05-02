#pragma once

#include "Organizm.h"
using namespace std;

class Swiat {
protected:
    int szerokosc, wysokosc;	// N, M
    int iloscOrganizmow;
    int czlowiek_x, czlowiek_y, umiejetnosc;
    Organizm*** Plansza; // Tablica 2 wymiarowa
    Organizm** Kolejnosc;   // 0 - najwy¿sza inicjatywa
public:
    Swiat(int szerokosc, int wysokosc);
    ~Swiat();
    void SwiatStart();
    void Zapis();
    void Wczytaj(Swiat* swiat);

    void wykonajTure(); // wywo³uje u wszystkich akcja i kolizja
    void rysujSwiat() const;
    void dodajOrganizm(Organizm* organizm);
    Organizm* getOrganizm(int x, int y);

    int getSzerokosc();
    int getWysokosc();
    void setSzerokosc(int szerokosc);
    void setWysokosc(int wysokosc);

    void Usun(Organizm* organizm);
    void ZmienPole(Organizm* organizm, int dX, int dY);
    void Kolejka(Organizm* organizm);
    void UpdateKolejka(Organizm* organizm);

    void changeX( int x);
    void changeY( int y);
    int getCzlowiekX();
    int getCzlowiekY();
    void Umiejetnosc();
    int getUmiejetnosc();
    void setUmiejetnosc(int umiejetnosc);
    void WyczyscKolejke();
};
