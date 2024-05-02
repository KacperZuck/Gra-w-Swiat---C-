#pragma once
#include "Roslina.h"
using namespace std;

class Trawa : public Roslina {		// 0 - sily, 0 - inicjatywy
public:
	Trawa(int poz_x, int poz_y, Swiat* swiat);
	Trawa* Dziecko(int poz_x, int poz_y, Swiat* swiat);
};
