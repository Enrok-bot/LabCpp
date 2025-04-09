#include <iostream>
#include "Nisza.h"
#include "osobniki.h"
#include "sasiedztwo.h"

int main() {
    Nisza nisza;
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
}
