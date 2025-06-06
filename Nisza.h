#ifndef NISZA_H
#define NISZA_H

#include "sasiedztwo.h"
#include "mieszkaniec.h"
#include "srodowisko.h"

class Nisza {
private:
    Mieszkaniec* lokator;

public:
    Nisza();
    Nisza(Nisza& innaNisza);
    ~Nisza();

    Nisza& operator=(Nisza& innaNisza);

    void przyjmijLokatora(Mieszkaniec* lokatorBezdomny);

    Mieszkaniec* oddajLokatora();

    bool zajeta() const { return lokator != nullptr; }

    RodzajMieszkanca ktoTuMieszka() {
        return zajeta() ? lokator->kimJestes() : PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;

    ZamiarMieszkanca aktywujLokatora(
        Sasiedztwo sasiedztwo) {
        return lokator->wybierzAkcje(sasiedztwo);
    }

private:
    friend void Srodowisko::wykonajAkcje(unsigned int wiersz,
                                         unsigned int kolumna);

    Mieszkaniec* wypuscPotomka() {
        return lokator->dajPotomka();
    }

    void przyjmijZdobycz(Mieszkaniec* ofiara) {
        lokator->przyjmijZdobycz(ofiara);
    }
};


#endif
