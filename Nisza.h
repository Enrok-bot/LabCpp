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

/*
*    Nisza nisza;
nisza.przyjmijLokatora(new Bakteria());

std::cout << "Kto w niszy: "
<< nisza.ktoTuMieszka() << std::endl;
std::cout << "Czy żywy: "
<< nisza.lokatorZywy() << std::endl;

Sasiedztwo sasiedztwo;
sasiedztwo.okreslSasiada(P,GLON);
sasiedztwo.okreslSasiada(PG,GRZYB);
sasiedztwo.okreslSasiada(G,GRZYB);
sasiedztwo.okreslSasiada(LG,GLON);
sasiedztwo.okreslSasiada(L,BAKTERIA);
sasiedztwo.okreslSasiada(LD,BAKTERIA);
sasiedztwo.okreslSasiada(D,GLON);
sasiedztwo.okreslSasiada(PD,PUSTKA);

ZamiarMieszkanca zamiar =
nisza.aktywujLokatora(sasiedztwo);

std::cout << "Akcja: " << zamiar.akcja << " gdzie: "
<< zamiar.gdzie << std::endl;

std::cout << std::endl;
return 0;
*/