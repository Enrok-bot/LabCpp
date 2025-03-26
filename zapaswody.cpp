#include "zapaswody.h"

// Inicjalizacja pól statycznych (domyślne wartości)
double ZapasWody::pojemnoscDuzej = 2.0;
double ZapasWody::pojemnoscSredniej = 1.0;
double ZapasWody::pojemnoscMalej = 0.5;

// Konstruktor
ZapasWody::ZapasWody(int Duzych, int Srednich, int Malych)
    : liczbaDuzych(Duzych), liczbaSrednich(Srednich), liczbaMalych(Malych) {
}

// Metody dodające butelki (bez const, bo zmieniają stan obiektu)
void ZapasWody::dodajDuza(int duzych) {
    liczbaDuzych += duzych;
}

void ZapasWody::dodajSrednia(int srednich) {
    liczbaSrednich += srednich;
}

void ZapasWody::dodajMala(int malych) {
    liczbaMalych += malych;
}

// Metody do ustawiania pojemności butelek
void ZapasWody::ustawPojemnoscDuzej(double nowaPojemnosc) {
    pojemnoscDuzej = nowaPojemnosc;
}

void ZapasWody::ustawPojemnoscSredniej(double nowaPojemnosc) {
    pojemnoscSredniej = nowaPojemnosc;
}

void ZapasWody::ustawPojemnoscMalej(double nowaPojemnosc) {
    pojemnoscMalej = nowaPojemnosc;
}

// Metody do pobierania pojemności butelek
double ZapasWody::pobierzPojemnoscDuzej() {
    return pojemnoscDuzej;
}

double ZapasWody::pobierzPojemnoscSredniej() {
    return pojemnoscSredniej;
}

double ZapasWody::pobierzPojemnoscMalej() {
    return pojemnoscMalej;
}

// Gettery dla liczby butelek
int ZapasWody::getLiczbaDuzych() const {
    return liczbaDuzych;
}

int ZapasWody::getLiczbaSrednich() const {
    return liczbaSrednich;
}

int ZapasWody::getLiczbaMalych() const {
    return liczbaMalych;
}

// Obliczanie całkowitej objętości wody
double ZapasWody::getCalkowitaObjetosc() const {
    return (liczbaDuzych * pojemnoscDuzej) +
           (liczbaSrednich * pojemnoscSredniej) +
           (liczbaMalych * pojemnoscMalej);
}

// Metoda wyświetlająca informacje o zapasie wody
void ZapasWody::wyswietl() const {
    std::cout << "Mam teraz " << getCalkowitaObjetosc() << " litrów wody.\n";
    std::cout << "Dużych butelek: " << liczbaDuzych << std::endl;
    std::cout << "Średnich butelek: " << liczbaSrednich << std::endl;
    std::cout << "Małych butelek: " << liczbaMalych << std::endl;
}
