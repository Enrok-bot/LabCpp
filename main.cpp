#include <iostream>
#include "Nisza.h"
#include "osobniki.h"

static Nisza n1, n2, n3;
static char sep = UstawieniaSymulacji::pobierzUstawienia().znakSeparator;

void wyswietlNisze() {
    std::cout << n1.jakiSymbol() << sep << n2.jakiSymbol() << sep << n3.jakiSymbol() << std::endl;
}

int main() {
    std::cout << "Puste nisze: ";
    wyswietlNisze();

    std::cout << "Lokowanie mieszkancow: ";
    n1.przyjmijLokatora(new Glon());
    n3.przyjmijLokatora(new Grzyb());
    wyswietlNisze();

    std::cout << "Przesuwanie lokatorow: ";
    n2 = n1;
    wyswietlNisze();

    std::cout << std::endl;
    return 0;
}
