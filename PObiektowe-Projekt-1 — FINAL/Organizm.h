#pragma once
using namespace std;

class Swiat;

enum Rasa {
	CZLOWIEK,
	WILK,
	OWCA,
	LIS,
	ZOLW,
	ANTYLOPA,
	TRAWA,
	MLECZ,
	GUARANA,
	JAGODY,
	BARSZCZ,
	NIKT
};

class Organizm {
protected:
	int sila;
	int inicjatywa;
	int dlugoscZycia;
	bool ruch;
	int poz_x, poz_y;
	Rasa rasa;
	Swiat* swiat;
public:
	Organizm(int poz_x, int poz_y, Swiat* swiat, Rasa rasa, int sila, int inicjatywa, int dlugoscZycia);

	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* organizm, int x, int y) = 0;
	virtual bool CzyOdbilAtak(Organizm* atakujacy); 
	virtual bool CzyZwierze(Rasa rasa);
	virtual bool CzyRoslina(Rasa rasa);
	virtual Organizm* Dziecko(int poz_x, int poz_y, Swiat* swiat) = 0;
	void Rysuj();

	int getX();
	int getY();
	int getInicjatywa();
	int getDlugoscZycia();
	int getSila();
	Rasa getRasa();
	const char* NazwaString();
	void WyzerujRuchy();
	bool getRuch();

	void setX(int poz_x);
	void setY(int poz_y);
	void setSila(int sila);
	void setInicjatywa(int inicjatywa);
	void setDlugosZycia(int dlugoscZycia);
	void setRasa(Rasa rasa);
	void Postarz();
	void Ruch();

};