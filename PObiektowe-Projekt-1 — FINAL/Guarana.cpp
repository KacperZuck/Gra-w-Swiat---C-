
#include <iostream>
#include "Guarana.h"
#include "Swiat.h"

Guarana::Guarana(int poz_x, int poz_y, Swiat* swiat) : Roslina(poz_x, poz_y, swiat, GUARANA, 0, 0, 0){
}

Guarana* Guarana::Dziecko(int poz_x, int poz_y, Swiat* swiat){
	return new Guarana(poz_x, poz_y, swiat);
}

void Guarana::Kolizja(Organizm* organizm, int dx, int dy){
	int sila = organizm->getSila();
	organizm->setSila(sila + 3);
	cout << organizm->NazwaString() << " zostal wzmocniony o 3, jego sila wynosi teraz: "<< organizm->getSila() << endl;
	Roslina::Kolizja(organizm, dx, dy);
}

bool Guarana::CzyOdbilAtak(Organizm* atakujacy){
	
	if (CzyZwierze(atakujacy->getRasa())) {
		int sila = atakujacy->getSila();
		atakujacy->setSila(sila + 3);
		cout << atakujacy->NazwaString() << " zostal wzmocniony o 3, jego sila wynosi teraz: " << atakujacy->getSila() << endl;
	}
	return false;
}
