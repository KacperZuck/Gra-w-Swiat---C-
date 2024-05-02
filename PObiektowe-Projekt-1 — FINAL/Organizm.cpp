
#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
using namespace std;

Organizm::Organizm(int poz_x, int poz_y, Swiat* swiat, Rasa rasa, int sila, int inicjatywa, int dlugoscZycia)
	: poz_x(poz_x), poz_y(poz_y), swiat(swiat), sila(sila), inicjatywa(inicjatywa), dlugoscZycia(dlugoscZycia), rasa(rasa), ruch(false) {
	swiat->dodajOrganizm(this);
}

void Organizm::Rysuj() {
	Postarz();
	switch (rasa){
	case CZLOWIEK:
		cout << "@";
		break;
	case WILK:
		cout << "W";
		break;
	case OWCA:
		cout << "O";
		break;
	case LIS:
		cout << "L";
		break;
	case ZOLW:
		cout << "Z";
		break;
	case ANTYLOPA:
		cout << "A";
		break;
	case TRAWA:
		cout << "T";
		break;
	case MLECZ:
		cout << "M";
		break;
	case GUARANA:
		cout << "G";
		break;
	case JAGODY:
		cout << "J";
		break;
	case BARSZCZ:
		cout << "B";
		break;
	default:
		cout << "x";
		break;
	}
	
}

bool Organizm::CzyOdbilAtak(Organizm* atakujacy) {
    /// if(atakujacy.getSila() < 5 ) dla zolwia
    return false;
}

bool Organizm::CzyZwierze(Rasa rasa){

	switch (rasa){
	case CZLOWIEK:
		return true;
		break;
	case WILK:
		return true;
		break;
	case OWCA:
		return true;
		break;
	case LIS:
		return true;
		break;
	case ZOLW:
		return true;
		break;
	case ANTYLOPA:
		return true;
		break;
	default:
		return false;
		break;
	}
}

bool Organizm::CzyRoslina(Rasa rasa){

	switch (rasa){
	case TRAWA:
		return true;
		break;
	case MLECZ:
		return true;
		break;
	case GUARANA:
		return true;
		break;
	case JAGODY:
		return true;
		break;
	case BARSZCZ:
		return true;
		break;
	default:
		return false;
		break;
	}
}


int Organizm::getX(){
	return poz_x;
}

int Organizm::getY(){
	return poz_y;
}

int Organizm::getInicjatywa(){
	return inicjatywa;
}

int Organizm::getDlugoscZycia(){
	return dlugoscZycia;
}

int Organizm::getSila(){
	return sila;
}

Rasa Organizm::getRasa(){
    return this->rasa;
}

const char* Organizm::NazwaString(){

	switch (rasa){
	case CZLOWIEK:
		return "CZLOWIEK";
		break;
	case WILK:
		return "WILK";
		break;
	case OWCA:
		return "OWCA";
		break;
	case LIS:
		return "LIS";
		break;
	case ZOLW:
		return "ZOLW";
		break;
	case ANTYLOPA:
		return "ANTYLOPA";
		break;
	case TRAWA:
		return "TRAWA";
		break;
	case MLECZ:
		return "MLECZ";
		break;
	case GUARANA:
		return "GUARANA";
		break;
	case JAGODY:
		return "WILCZEJAGODY";
		break;
	case BARSZCZ:
		return "BARSZCZSOSNOWSKIEGO";
		break;
	default:
		return "NIEZNANY";
		break;
	}
}


void Organizm::setX(int poz_x) {
	this->poz_x = poz_x;
}
void Organizm::setY(int poz_y) {
	this->poz_y = poz_y;
}
void Organizm::setSila(int sila){
	this->sila = sila;
}
void Organizm::setInicjatywa(int inicjatywa) {
	this->inicjatywa = inicjatywa;
}
void Organizm::setDlugosZycia(int dlugoscZycia) {
	this->dlugoscZycia = dlugoscZycia;
}

void Organizm::setRasa(Rasa rasa){
	this->rasa = rasa;
}

void Organizm::Postarz(){
	int dl = getDlugoscZycia();
	if (dl <= 0) {
		this->setDlugosZycia(1);
	}
	else {
		this->setDlugosZycia(dl + 1);
	}
	WyzerujRuchy();
}

void Organizm::WyzerujRuchy() {
	this->ruch = false;
}
bool Organizm::getRuch()
{
	return ruch;
}
void Organizm::Ruch(){
	this->ruch = true;
}
