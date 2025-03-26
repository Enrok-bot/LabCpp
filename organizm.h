#ifndef ORGANIZM_H
#define ORGANIZM_H


class Organizm {
public:
    const unsigned short limitPosilkow;
    const unsigned short kosztPotomka;

private:
    unsigned short licznikZycia;
    unsigned short licznikPosilkow;

public:
    Organizm(unsigned short dlugoscZycia, unsigned short limitPosilkow, unsigned short kosztPotomka);

    bool zywy() const { return licznikZycia > 0; }

    bool glodny() const { return zywy() && licznikPosilkow < limitPosilkow; }

    bool paczkujacy() const { return zywy() && licznikPosilkow > kosztPotomka; }

    unsigned short stanLicznikaZycia() const { return licznikZycia; }

    unsigned short stanLicznikaPosilkow() const { return licznikPosilkow; }

    bool posilek();

    bool potomek();

    void krokSymulacji();
};


#endif

/**
 #include <iostream>
#include "organizm.h"

void drukujOrganizm(const Organizm &o);

int main() {
    //1. Test kreacji obiektów
    Organizm organizm1(8, 3, 2);
    Organizm organizm2 = organizm1;
    Organizm organizm3(organizm1);

    std::cout << "Wynik testu kreacji obiektów:"
            << std::endl << std::endl;
    std::cout << "Organizm1:" << std::endl;
    drukujOrganizm(organizm1);
    std::cout << "Organizm2" << std::endl;
    drukujOrganizm(organizm2);
    std::cout << "Organizm3" << std::endl;
    drukujOrganizm(organizm3);

    //2. Test niezależności obiektów
    organizm1.posilek();
    organizm1.posilek();
    organizm2.posilek();
    organizm3.krokSymulacji();

    std::cout << "Wynik testu niezależności obiektów:"
            << std::endl << std::endl;

    std::cout << "Organizm1:" << std::endl;
    drukujOrganizm(organizm1);
    std::cout << "Organizm2" << std::endl;
    drukujOrganizm(organizm2);
    std::cout << "Organizm3" << std::endl;
    drukujOrganizm(organizm3);

    //3. Test symulacji
    Organizm organizm4(8, 3, 2);

    std::cout << "Wynik testu symulacji:"
            << std::endl << std::endl;
    std::cout << "Stan początkowy:" << std::endl;
    drukujOrganizm(organizm4);

    for (int i = 1; i < 11; i++) {
        organizm4.krokSymulacji();

        if (organizm4.paczkujacy()) {
            organizm4.potomek();
            std::cout << "---> Potomek" << std::endl;
        } else organizm4.posilek();

        std::cout << "Po wykonaniu kroku symulacji: "
                << i << std::endl;
        drukujOrganizm(organizm4);
    }

    return 0;
}

void drukujOrganizm(const Organizm &o) {
    std::cout << "licznikZycia: "
            << o.stanLicznikaZycia()
            << " licznikPosilkow: "
            << o.stanLicznikaPosilkow() << std::endl
            << "limitPosilkow: "
            << o.limitPosilkow
            << " kosztPotomka: "
            << o.kosztPotomka << std::endl
            << "głodny: " << o.glodny()
            << " pączkujący: "
            << o.paczkujacy() << std::endl << std::endl;
}
**/