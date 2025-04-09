#include "UrzadzenieElektryczne.h"

#include <iostream>
#include <ostream>

UrzadzenieElektryczne::UrzadzenieElektryczne(std::string marka, bool stan) : marka(marka), stan(stan) {
}

void UrzadzenieElektryczne::wlacz() {
    stan = true;
}

void UrzadzenieElektryczne::wylacz() {
    stan = false;
}

std::string UrzadzenieElektryczne::jakaMarka() const{
    return marka;
}

bool UrzadzenieElektryczne::jakiStan() const{
    return stan;
}

void UrzadzenieElektryczne::wypisz() const{
    std::string marka = jakaMarka();
    if (jakiStan()) {
        std::cout << marka << " jest wlaczony" << std::endl;
    } else {
        std::cout << marka << " jest wylaczony" << std::endl;
    }
}

TV::TV(std::string marka1, bool stan, int kanal1, int glosnosc1) : UrzadzenieElektryczne(marka1, stan), kanal(kanal1),
                                                                   glosnosc(glosnosc1) {
}

void TV::podglosnij(){
    if (glosnosc < 10) {
        glosnosc++;
    }
}

void TV::scisz(){
    if (glosnosc > 0) {
        glosnosc--;
    }
}

void TV::zmienKanal(int kanal1){
    if (kanal1 <= 40 && kanal1 >= 1) {
        kanal = kanal1;
    } else {
        std::cout << "Nie ma takiego kanału"<<std::endl;
    }
    if (!jakiStan()) {
        stan = true;
    }
}

void TV::wypisz() const{
    if (stan) {
        std::cout << marka << " jest wlaczony na kanale " << kanal << "(glosnosc " << glosnosc << ")" << std::endl;
    } else {
        std::cout << marka << " jest wylaczony" << std::endl;
    }
}
