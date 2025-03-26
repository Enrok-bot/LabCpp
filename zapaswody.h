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

/**
// Zmiana pojemności dużej butelki na 2.5l przed utworzeniem obiektu
ZapasWody::ustawPojemnoscDuzej(2);

// Tworzenie obiektu ZapasWody z domyślnymi wartościami
ZapasWody zw;

// Dodawanie butelek
zw.dodajDuza(2);
zw.dodajSrednia(1);
zw.dodajMala(3);

// Wyświetlenie informacji o zapasie wody
zw.wyswietl();
**/