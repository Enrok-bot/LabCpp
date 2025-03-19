#include "ustawienia.h"
#include <iostream>

using namespace std;

void wyswietl(UstawieniaSymulacji &UST) {
    cout << "Znak glon:" << UST.znakGlon
            << " zycieMin=" << UST.glonZycieMin
            << " zycieMax=" << UST.glonZycieMax << endl;
}

int main() {
    UstawieniaSymulacji &UST1
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji &UST2
            = UstawieniaSymulacji::pobierzUstawienia();
    UstawieniaSymulacji &UST3
            = UstawieniaSymulacji::pobierzUstawienia();

    cout << "Pobranie ustawien 3x" << endl;
    cout << "UST1: ";
    wyswietl(UST1);
    cout << "UST2: ";
    wyswietl(UST2);
    cout << "UST3: ";
    wyswietl(UST3);

    cout << endl << "Zmiana wartości tylko 1x" << endl;
    UST2.glonZycieMax = 100;
    cout << "UST1: ";
    wyswietl(UST1);
    cout << "UST2: ";
    wyswietl(UST2);
    cout << "UST3: ";
    wyswietl(UST3);
    return 0;
}
