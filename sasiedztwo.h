#ifndef SASIEDZTWO_H
#define SASIEDZTWO_H
#include "ustawienia.h"

class Sasiedztwo {
private:
    RodzajMieszkanca sasiad[3][3];

    RodzajMieszkanca *elementWewnetrzny(Polozenie polozenie);

    static Polozenie losujPolozenie();

public:
    Sasiedztwo(RodzajMieszkanca rodzaj = NIEZNANE);

    void okreslSasiada(Polozenie polozenie, RodzajMieszkanca rodzaj);

    RodzajMieszkanca ktoJestSasiadem(Polozenie polozenie);

    unsigned short ile(RodzajMieszkanca rodzaj) const;

    Polozenie losujSasiada(RodzajMieszkanca rodzaj);

    static void zmienIndeksyWgPolozenia(Polozenie polozenie, long &wiersz, long &kolumna);

    static void zmienIndeksyWgPolozenia(Polozenie polozenie, unsigned int &wiersz, unsigned int &kolumna);
};


#endif //SASIEDZTWO_H
/**
 #include "sasiedztwo.h"
#include <iostream>

std::string nazwaRodzaju(RodzajMieszkanca rodzaj);

int main() {
    Sasiedztwo sasiedztwo;

    sasiedztwo.okreslSasiada(P, GLON);
    sasiedztwo.okreslSasiada(PG, GRZYB);
    sasiedztwo.okreslSasiada(G, GRZYB);
    sasiedztwo.okreslSasiada(LG, GLON);
    sasiedztwo.okreslSasiada(L, BAKTERIA);
    sasiedztwo.okreslSasiada(LD, BAKTERIA);
    sasiedztwo.okreslSasiada(D, GLON);
    sasiedztwo.okreslSasiada(PD, PUSTKA);

    std::cout << "Przegląd sąsiedztwa:" << std::endl;

    for (int i = 0; i < 8; i++) {
        Polozenie p = static_cast<Polozenie>(i);
        RodzajMieszkanca
                r = sasiedztwo.ktoJestSasiadem(p);

        std::cout << "polozenie=" << p << " rodzaj="
                << nazwaRodzaju(r) << std::endl;
    }

    std::cout << std::endl << "Policzenie sasiadów"
            << "określonego rodzaju:" << std::endl
            << " glony=" << sasiedztwo.ile(GLON) << std::endl
            << " grzyby=" << sasiedztwo.ile(GRZYB) << std::endl
            << " trupy=" << sasiedztwo.ile(TRUP) << std::endl;

    std::cout << std::endl << "Wylosowanie sasiada:" << std::endl
            << " glon -> "
            << sasiedztwo.losujSasiada(GLON) << std::endl
            << " pustka -> "
            << sasiedztwo.losujSasiada(PUSTKA) << std::endl
            << " trup -> "
            << sasiedztwo.losujSasiada(TRUP) << std::endl;


    long wiersz, kolumna;
    std::cout << std::endl
            << "Zmiana indeksów [5][7] "
            << "wg polozenia:" << std::endl;

    for (int i = 0; i < 8; i++) {
        Polozenie p = static_cast<Polozenie>(i);
        wiersz = 5;
        kolumna = 7;

        Sasiedztwo::
                zmienIndeksyWgPolozenia(p, wiersz, kolumna);

        std::cout << " położenie: " << p << " ->[" << wiersz
                << "][" << kolumna << "]" << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

std::string nazwaRodzaju(RodzajMieszkanca rodzaj) {
        switch (rodzaj) {
                case GLON: return "GLON";
                case GRZYB: return "GRZYB";
                case BAKTERIA: return "BAKTERIA";
                case PUSTKA: return "PUSTKA";
                case SCIANA: return "ŚCIANA";
                case TRUP: return "TRUP";
                case NIEZNANE: return "NIEZNANE";
        }
}
**/