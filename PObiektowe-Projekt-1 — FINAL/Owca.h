#pragma once

#include "Zwierze.h"	
using namespace std;

class Owca : public Zwierze {
public:
	Owca(int poz_x, int poz_y, Swiat* swiat);
	Owca* Dziecko(int poz_x, int poz_y, Swiat* swiat);
};