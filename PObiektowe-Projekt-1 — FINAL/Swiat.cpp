
#include <iostream>
#include <fstream>
#include <string>
#include "Swiat.h"
#include "Organizm.h"
#include "Wilk.h" 
#include "Trawa.h"
#include "Owca.h"
#include "Mlecz.h"
#include "Lis.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
using namespace std;

    Swiat::Swiat(int szerokosc, int wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc) {
        setSzerokosc(szerokosc);
        setWysokosc(wysokosc);
        Plansza = new Organizm** [wysokosc];
        Kolejnosc = nullptr; // new Organizm* [wysokosc * szerokosc];
        for (int i = 0; i < wysokosc; i++) {
            Plansza[i] = new Organizm* [szerokosc];
            for (int j = 0; j < szerokosc; j++) {
                Plansza[i][j] = nullptr; // inicjalizacja wszystkich wskaŸników na nullptr
            }
        }
        iloscOrganizmow = 0;
        umiejetnosc = -5;
    }
    Swiat::~Swiat() {
        for (int i = 0; i < wysokosc; i++) {
            delete[] Plansza[i];
        }
        for (int i = 0; i < iloscOrganizmow; i++) {
            delete Kolejnosc[i];
        }
        delete[] Plansza;
        delete[] Kolejnosc;
    }

    void Swiat::Zapis(){
        ofstream plik("zapis.txt");

        if (plik.is_open()) {
            // Zapisujemy dane do pliku
            plik << szerokosc<< " " << wysokosc <<endl;	// N, M
            plik << iloscOrganizmow<<endl;
            plik << umiejetnosc << endl;
            for (int i = 0; i < wysokosc; i++) {
                for (int j = 0; j < szerokosc; j++) {
                    if (Plansza[i][j] != nullptr) {
                        plik << Plansza[i][j]->NazwaString() << endl << Plansza[i][j]->getDlugoscZycia() << endl << Plansza[i][j]->getSila() << endl << Plansza[i][j]->getX() << endl << Plansza[i][j]->getY() << endl;
                    }
                }
            }
            plik.close();
            cout << "Dane zostaly zapisane do pliku." << endl;
        }
        else {
            cout << "Nie mo¿na otworzyc pliku do zapisu!" << endl;
        }
    }
    
    void Swiat::Wczytaj(Swiat* swiat) {  
        string linia;
        ifstream plik("zapis.txt");

        if (plik.is_open()) {
            
            WyczyscKolejke();

            int norganizmow = 0;
            plik >> szerokosc >>  wysokosc;	
            plik >> norganizmow;
            plik >> umiejetnosc ;
            setSzerokosc(szerokosc);
            setWysokosc(wysokosc);
            setUmiejetnosc(umiejetnosc);

            Organizm* Nowy= nullptr;
            for (int i = 0; i < norganizmow; i++) {
                string nazwa;
                int dlugoscZycia1 = 0, sila1 = 0, x1 = 0, y1 = 0;
                plik >> nazwa;
                plik >> dlugoscZycia1;
                plik >> sila1;
                plik >> x1;
                plik >> y1;

                if (nazwa == "CZLOWIEK") {
                    Nowy = new Czlowiek(x1, y1, swiat);
                }
                else if (nazwa == "WILK")
                    Nowy = new Wilk(x1, y1, swiat);
                else if (nazwa == "OWCA")
                    Nowy = new Owca(x1, y1, swiat);
                else if (nazwa == "LIS")
                    Nowy = new Lis(x1, y1, swiat);
                else if (nazwa == "ZOLW")
                    Nowy = new Zolw(x1, y1, swiat);
                else if (nazwa == "ANTYLOPA")
                    Nowy = new Antylopa(x1, y1, swiat);
                else if (nazwa == "TRAWA")
                    Nowy = new Trawa(x1, y1, swiat);
                else if (nazwa == "MLECZ")
                    Nowy = new Mlecz(x1, y1, swiat);
                else if (nazwa == "GUARANA")
                    Nowy = new Guarana(x1, y1, swiat);
                else if (nazwa == "WILCZEJAGODY")
                    Nowy = new WilczeJagody(x1, y1, swiat);
                else if (nazwa == "BARSZCZSOSNOWSKIEGO")
                    Nowy = new BarszczSosnowskiego(x1, y1, swiat);

                Nowy->setDlugosZycia(dlugoscZycia1);
                Nowy->setSila(sila1);
            }
            plik.close();
            cout << "Dane zostaly odczytane z pliku" << endl;
        }
        else {
            cout << "Nie mo¿na otworzyæ pliku do odczytu!" << endl;
        }
    }
    
    void Swiat::wykonajTure() { // nie po kolei tylko zaczynaj¹ te które maj¹ wiêksz¹ inicjatywe 
        for (int i = 0; i < iloscOrganizmow; i++) {
            if (Kolejnosc[i] != nullptr && Kolejnosc[i]->getDlugoscZycia() >= 0 && Kolejnosc[i]->getRuch() == false) {
                //cout << Kolejnosc[i]->NazwaString()<< " " << i << " ";
                Kolejnosc[i]->Akcja();
            }
        }
        czlowiek_x = 0;
        czlowiek_y = 0;
        umiejetnosc-=1;
    }
    void Swiat::rysujSwiat() const {
        for (int i = 0; i < wysokosc; i++) {
            cout << endl;
            for (int j = 0; j < szerokosc; j++) {
                if (Plansza[i][j] != nullptr) {
                   Plansza[i][j]->Rysuj();
                }
                else { // puste pole
                    cout << ":"; 
                }
            }
        }
        cout << endl;
    }


    void Swiat::dodajOrganizm(Organizm* organizm) {
        Plansza[organizm->getY()][organizm->getX()] = organizm;
        Kolejka(organizm);
        
    }
    void Swiat::Usun(Organizm* organizm) {
        Plansza[organizm->getY()][organizm->getX()] = nullptr;
        UpdateKolejka(organizm);
    }
    void Swiat::Kolejka(Organizm* organizm) {
        iloscOrganizmow++;
        Organizm** Nowy = new Organizm * [iloscOrganizmow];

        int i = 0;
        for (; i < iloscOrganizmow - 1; i++) {
            Nowy[i] = Kolejnosc[i];
            if (Kolejnosc[i]->getInicjatywa() < organizm->getInicjatywa()) {
                break;
            }
            else if (Kolejnosc[i]->getInicjatywa() == organizm->getInicjatywa()) {
                if (Kolejnosc[i]->getDlugoscZycia() < organizm->getDlugoscZycia()) {
                    break;
                }
            }
        }

        Nowy[i] = organizm;

        for (; i < iloscOrganizmow - 1; i++) {
            Nowy[i + 1] = Kolejnosc[i];
        }
        delete[] Kolejnosc;
        Kolejnosc = Nowy;

    }

    void Swiat::UpdateKolejka(Organizm* organizm){
        if (iloscOrganizmow == 0) {
            return;
        }
        int indeks = -1;
        for (int i = 0; i < iloscOrganizmow; i++) {
            if (Kolejnosc[i] == organizm) {
                indeks = i;
                break;
            }
        }

        if (indeks == -1) {
            return;
        }

        delete Kolejnosc[indeks];

        for (int i = indeks; i < iloscOrganizmow - 1; i++) {
            Kolejnosc[i] = Kolejnosc[i + 1];
        }

        iloscOrganizmow -= 1;;

        Organizm** Nowy = new Organizm * [iloscOrganizmow];
        for (int i = 0; i < iloscOrganizmow; i++) {
            Nowy[i] = Kolejnosc[i];
        }

        delete[] Kolejnosc;
        Kolejnosc = Nowy;
    }

    void Swiat::ZmienPole(Organizm* organizm, int dX, int dY) { // POKAZUJE BLAD
        Plansza[organizm->getY()][organizm->getX()] = nullptr;  // W TYM MIEJSCU
        organizm->setX(dX);
        organizm->setY(dY);
        Plansza[dY][dX] = organizm;
    }
    Organizm* Swiat::getOrganizm(int x, int y){
        if (Plansza[y][x] != nullptr) {
            return Plansza[y][x];
        }
        else {
            return nullptr;
        }
    }
    int Swiat::getSzerokosc(){
        return szerokosc;
    }
    int Swiat::getWysokosc() { 
        return wysokosc; 
    }

    void Swiat::setSzerokosc(int szerokosc){
        this->szerokosc = szerokosc;
    }

    void Swiat::setWysokosc(int wysokosc){
        this->wysokosc = wysokosc;
    }
    
    void Swiat::changeX(int x) {
        czlowiek_x = x;
    }

    void Swiat::changeY( int y) {
        czlowiek_y = y;
    }

    int Swiat::getCzlowiekX()
    {
        return czlowiek_x;
    }
    int Swiat::getCzlowiekY()
    {
        return czlowiek_y;
    }

    void Swiat::Umiejetnosc(){
        if (umiejetnosc <= -5) {
            umiejetnosc = 6;
            cout << "Aktywowano umiejetnosc, dostepne przez ";
            cout << 5 << " tur." << endl;
        }
        else {
            cout << "Umiejetnosc jest nieaktywna" << endl;
        }
    }

    int Swiat::getUmiejetnosc(){
        return umiejetnosc;
    }
    void Swiat::setUmiejetnosc(int umiejetnosc)
    {
        this->umiejetnosc = umiejetnosc;
    }

    void Swiat::WyczyscKolejke(){
        
        for (int i = 0; i < wysokosc; i++) {
            for (int j = 0; j < szerokosc; j++) {
                if (Plansza[i][j] != nullptr) {
                    Usun(Plansza[i][j]);
                }
            }
        }
        if (Kolejnosc != nullptr) { // DZIECI - KTORYCH NIE MA NA PLANSZY
            for (int i = 0; i < iloscOrganizmow; i++) {
                delete Kolejnosc[i];
            }
            delete[] Kolejnosc;
            Kolejnosc = nullptr;
            iloscOrganizmow = 0;
        }
    }

    void Swiat::SwiatStart() {
        Swiat* swiat = this;
        int N = getSzerokosc();
        int M = getWysokosc();

        new Wilk(rand() % N, rand() % M, swiat);
        new Wilk(rand() % N, rand() % M, swiat);
     //   new Owca(rand() % N, rand() % M, swiat);
       // new Owca(rand() % N, rand() % M, swiat);
        new Trawa(rand() % N, rand() % M, swiat);
        new Trawa(rand() % N, rand() % M, swiat);
        new Lis(rand() % N, rand() % M, swiat);
        new Lis(rand() % N, rand() % M, swiat);
        new Zolw(rand() % N, rand() % M, swiat);
        new Zolw(rand() % N, rand() % M, swiat);
        new Antylopa(rand() % N, rand() % M, swiat);
        new Antylopa(rand() % N, rand() % M, swiat);
        new Guarana(rand() % N, rand() % M, swiat);
        new Guarana(rand() % N, rand() % M, swiat);
        new BarszczSosnowskiego(rand() % N, rand() % M, swiat);
        new BarszczSosnowskiego(rand() % N, rand() % M, swiat);
        new WilczeJagody(rand() % N, rand() % M, swiat);
        new WilczeJagody(rand() % N, rand() % M, swiat);
        new Mlecz(rand() % N, rand() % M, swiat);
        new Mlecz(rand() % N, rand() % M, swiat);

        new Wilk(rand() % N, rand() % M, swiat);
        new Wilk(rand() % N, rand() % M, swiat);
        new Owca(rand() % N, rand() % M, swiat);
        new Owca(rand() % N, rand() % M, swiat);
        new Trawa(rand() % N, rand() % M, swiat);
        new Trawa(rand() % N, rand() % M, swiat);
        new Lis(rand() % N, rand() % M, swiat);
        new Lis(rand() % N, rand() % M, swiat);
        new Zolw(rand() % N, rand() % M, swiat);
        new Zolw(rand() % N, rand() % M, swiat);
        new Antylopa(rand() % N, rand() % M, swiat);
        new Antylopa(rand() % N, rand() % M, swiat);
        new Guarana(rand() % N, rand() % M, swiat);
        new Guarana(rand() % N, rand() % M, swiat);
        new BarszczSosnowskiego(rand() % N, rand() % M, swiat);
        new BarszczSosnowskiego(rand() % N, rand() % M, swiat);
        new WilczeJagody(rand() % N, rand() % M, swiat);
        new WilczeJagody(rand() % N, rand() % M, swiat);
        new Mlecz(rand() % N, rand() % M, swiat);
        new Mlecz(rand() % N, rand() % M, swiat);

    }