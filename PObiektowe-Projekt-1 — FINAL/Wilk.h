#pragma once
#include "Zwierze.h"	
using namespace std;

class Wilk : public Zwierze{   
public:
	Wilk(int poz_x, int poz_y, Swiat* swiat);
	Wilk* Dziecko(int poz_x, int poz_y, Swiat* swiat);
};