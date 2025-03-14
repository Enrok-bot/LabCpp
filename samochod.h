#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>


class Samochod {
private:
    const std::string model;
    const float zuzycie_paliwa; // zużycie paliwa w litrach na 100 km
    const float ilosc_paliwa;

    float obliczZasieg();

public:
    Samochod(std::string model, float spalanie, float bak);

    std::string jakiModel();

    float jakieZuzycie();

    float ilePaliwa();

    std::string doTekstu();
};


#endif
