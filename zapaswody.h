#ifndef ZAPASWODY_H
#define ZAPASWODY_H

#include <iostream>

class ZapasWody {
private:
    // Pola niestatyczne przechowujące liczbę butelek
    int liczbaDuzych;
    int liczbaSrednich;
    int liczbaMalych;

    // Pojemności butelek - statyczne
    static double pojemnoscDuzej;
    static double pojemnoscSredniej;
    static double pojemnoscMalej;

public:
    // Konstruktor domyślny z wartościami domyślnymi
    ZapasWody(int Duzych = 0, int Srednich = 0, int Malych = 0);

    // Metody dodające butelki
    void dodajDuza(int duzych);
    void dodajSrednia(int srednich);
    void dodajMala(int malych);

    // Metody statyczne do zmiany/odczytu pojemności butelek
    static void ustawPojemnoscDuzej(double nowaPojemnosc);
    static void ustawPojemnoscSredniej(double nowaPojemnosc);
    static void ustawPojemnoscMalej(double nowaPojemnosc);

    static double pobierzPojemnoscDuzej();
    static double pobierzPojemnoscSredniej();
    static double pobierzPojemnoscMalej();

    // Gettery do pobierania liczby butelek i objętości wody
    int getLiczbaDuzych() const;
    int getLiczbaSrednich() const;
    int getLiczbaMalych() const;
    double getCalkowitaObjetosc() const;

    // Metoda do wyświetlania zapasu wody
    void wyswietl() const;
};

#endif // ZAPASWODY_H
