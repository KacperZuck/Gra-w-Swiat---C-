
#include "Mlecz.h"
#include "Swiat.h"

Mlecz::Mlecz(int poz_x, int poz_y, Swiat* swiat) : Roslina(poz_x, poz_y, swiat, MLECZ, 0, 0 ,0){
}

Mlecz* Mlecz::Dziecko(int poz_x, int poz_y, Swiat* swiat)
{
    return new Mlecz(poz_x,poz_y,swiat);
}

void Mlecz::Akcja(){
    for (int i = 0; i < 3; i++) {
        Roslina::Akcja();
    }
}
