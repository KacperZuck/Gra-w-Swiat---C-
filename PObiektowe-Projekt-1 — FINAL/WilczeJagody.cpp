
#include <iostream>
#include "WilczeJagody.h"
#include "Swiat.h"
using namespace std;

WilczeJagody::WilczeJagody(int poz_x, int poz_y, Swiat* swiat) : Roslina(poz_x, poz_y, swiat, JAGODY, 99, 0 , 0){
}

WilczeJagody* WilczeJagody::Dziecko(int poz_x, int poz_y, Swiat* swiat){
	return new WilczeJagody(poz_x, poz_y, swiat);
}

void WilczeJagody::Kolizja(Organizm* organizm, int x, int y){

	if (organizm->CzyZwierze(organizm->getRasa()) == true) {
		cout << "Wilcze Jagody pokonuja " << organizm->NazwaString() << endl;
		swiat->Usun(organizm);
	}
	else {
		Roslina::Kolizja(this, x,y);
	}
}

bool WilczeJagody::CzyOdbilAtak(Organizm* atakujacy){

	if (CzyZwierze(atakujacy->getRasa())) {
		cout << atakujacy->NazwaString() << " zostal zabity przez Wilcze Jagody" << endl;
		swiat->Usun(atakujacy);
		return true;
	}
	else {
		return false;
	}
}

/*
if (atakujacy->CzyOdbilAtak(this)) { // true = odbi³
		return false;
	}
	else
*/