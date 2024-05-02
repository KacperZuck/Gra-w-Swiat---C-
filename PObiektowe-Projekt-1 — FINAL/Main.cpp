#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Czlowiek.h"
#include <conio.h>
using namespace std;	// ew. DODAc ZAKONCZENIE JAK NIEZYJE CZLOWIEK

#define N 40	// X
#define M 15	// Y
#define DOL 80	
#define GORA 72
#define PRAWO 77
#define LEWO 75
#define NOWATURA 'r'
#define UMIEJETNOSC 'q'
#define ZAPIS 'z'
#define WCZYTAJ 'b'


int main() {

	SetConsoleTitle(L"Kacper Zuchowski [194660]");
	Swiat* swiat = new Swiat(N, M);
	Organizm* czlowiek = new Czlowiek(rand() % N, rand() % M, swiat);
	int stop=1;
	swiat->SwiatStart();
	swiat->wykonajTure();
	swiat->rysujSwiat();
	while (stop) {
		cout << "Wybierz Opcje: 'R' - nowa tura, '0' - STOP, 'Q' - umiejetniosc, 'Z' - zapisz, 'B' - wczytaj, Sterowanie - strzalki" << endl;
		char znak;

		znak = _getch();

		system("cls");
		switch (znak) {
		case DOL:
			swiat->changeY(1);
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case GORA:
			swiat->changeY(-1);
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case LEWO:
			swiat->changeX(-1);
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case PRAWO:
			swiat->changeX(1);
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case UMIEJETNOSC:
			swiat->Umiejetnosc();
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case NOWATURA:
			swiat->wykonajTure();
			swiat->rysujSwiat();
			break;
		case WCZYTAJ:
			swiat->rysujSwiat();
			system("cls");
			swiat->Wczytaj(swiat);
			swiat->rysujSwiat();
			break;
		case ZAPIS:
			swiat->Zapis();
			swiat->rysujSwiat();
			break;
		case '0':
			stop = 0;
			break;
		}
		if (swiat->getUmiejetnosc() > 0) {
			cout << endl << "Umiejetnosc jest jeszcze czynna przez:" << swiat->getUmiejetnosc() << " tur." << endl;
		}
	}

	return 0;
}