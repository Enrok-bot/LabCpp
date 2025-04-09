#ifndef NISZA_H
#define NISZA_H
#include "Mieszkaniec.h"
#include "sasiedztwo.h"

class Nisza {
private:
    Mieszkaniec *lokator;

public:
    Nisza();

    Nisza(Nisza &innaNsza);

    ~Nisza();

    Nisza &operator=(Nisza &innaNsza);

    void przyjmijLokatora(Mieszkaniec *lokatorBezdomny);

    Mieszkaniec *oddajLokatora();

    bool zajeta() const { return lokator != nullptr; }

    RodzajMieszkanca ktoTuMieszka() {
        return zajeta() ? lokator->kimJestes(): PUSTKA;
    }

    bool lokatorZywy() const;

    char jakiSymbol() const;

    ZamiarMieszkanca aktywujLokatora(Sasiedztwo sasiedztwo) {
        return lokator->wybierzAkcje(sasiedztwo);
    }

private:
    Mieszkaniec * wypuscPotomka() {
        return lokator->dajPotomka();
    }
    void przyjmijZdobycz(Mieszkaniec *ofiara) {
        lokator->przyjmijZdobycz(ofiara);
    }
};


#endif //NISZA_H
