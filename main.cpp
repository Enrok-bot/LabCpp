#include "zapaswody.h"

int main() {
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

    return 0;
}
