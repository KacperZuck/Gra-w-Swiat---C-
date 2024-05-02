#pragma once
#include "Zwierze.h"	
using namespace std;

class Lis : public Zwierze {
public:
	Lis(int poz_x, int poz_y, Swiat* swiat);
	Lis* Dziecko(int poz_x, int poz_y, Swiat* swiat);
	void Akcja();
};