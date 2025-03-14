#include "samochod.h"

float Samochod::obliczZasieg() {
    return ilosc_paliwa / zuzycie_paliwa * 100;
}

Samochod::Samochod(std::string model, float spalanie, float bak) : model(model), zuzycie_paliwa(spalanie), ilosc_paliwa(bak){}

std::string Samochod::jakiModel() {
    return model;
}

float Samochod::jakieZuzycie() {
    return zuzycie_paliwa;
}

float Samochod::ilePaliwa() {
    return ilosc_paliwa;
}

std::string Samochod::doTekstu() {
    std::string napis;
    napis = model;
    napis += " Paliwa starczy na ";
    napis += std::to_string(obliczZasieg());
    napis += " km";
    return napis;
}
