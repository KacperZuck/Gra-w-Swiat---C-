#pragma once
#include "Roslina.h"
using namespace std;

class Mlecz : public Roslina {		// 0 - sily, 0 - inicjatywy
public:
	Mlecz(int poz_x, int poz_y, Swiat* swiat);
	Mlecz* Dziecko(int poz_x, int poz_y, Swiat* swiat);
	void Akcja();
};
