#include "samochod.h"

float Samochod::obliczZasieg() const{
    return ilosc_paliwa / zuzycie_paliwa * 100;
}

Samochod::Samochod(std::string model, float spalanie, float bak) : model(model), zuzycie_paliwa(spalanie), ilosc_paliwa(bak){}

std::string Samochod::jakiModel() const{
    return model;
}

float Samochod::jakieZuzycie() const{
    return zuzycie_paliwa;
}

float Samochod::ilePaliwa() const{
    return ilosc_paliwa;
}

std::string Samochod::doTekstu() const{
    std::string napis;
    napis = model;
    napis += " Paliwa starczy na ";
    napis += std::to_string(obliczZasieg());
    napis += " km";
    return napis;
}
