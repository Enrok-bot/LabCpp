#include <iostream>
#include "UrzadzenieElektryczne.h"


int main() {
    UrzadzenieElektryczne u1("LG");
    u1.wypisz();
    u1.wlacz();
    u1.wypisz();
    std::cout << (u1.jakiStan() ? "wlaczony" : "wylaczony") << std::endl;
    std::cout << u1.jakaMarka() << std::endl;

    TV tv1("Samsung", true);
    tv1.wypisz();
    tv1.zmienKanal(50);
    tv1.podglosnij();
    tv1.scisz();
    tv1.scisz();
    tv1.wypisz();

    TV tv2("Philips");
    tv2.wypisz();
    tv2.wlacz();
    tv2.wypisz();

    UrzadzenieElektryczne *u2 = &tv2;
    u2->wypisz();
    u2->wylacz();
}
