#ifndef SAMOCHOD_H
#define SAMOCHOD_H
#include <string>


class Samochod {
private:
    const std::string model;
    const float zuzycie_paliwa; // zużycie paliwa w litrach na 100 km
    float ilosc_paliwa;

    float obliczZasieg() const;

public:
    Samochod(std::string model, float spalanie, float bak);

    std::string jakiModel() const;

    float jakieZuzycie() const;

    float ilePaliwa() const;

    std::string doTekstu() const;
};


#endif
