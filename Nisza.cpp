#include "Nisza.h"

#include "osobniki.h"

Nisza::Nisza() : lokator(nullptr){
}

Nisza::Nisza(Nisza &innaNsza) {
    if (innaNsza.zajeta()) {
        lokator = innaNsza.lokator;
        innaNsza.lokator = nullptr;
    }else lokator = nullptr;
}

Nisza::~Nisza() {
    if (lokator != nullptr) delete lokator;
}

Nisza & Nisza::operator=(Nisza &innaNsza) {
    Mieszkaniec * tmp = lokator;
    lokator = innaNsza.lokator;
    innaNsza.lokator = tmp;
    return *this;
}

void Nisza::przyjmijLokatora(Mieszkaniec *lokatorBezdomny) {
    if (!zajeta()) {
        lokator = lokatorBezdomny;
        lokatorBezdomny = nullptr;
    }
}

Mieszkaniec * Nisza::oddajLokatora() {
    Mieszkaniec * tmp = lokator;

    if (zajeta()) {
        tmp = lokator;
        lokator = nullptr;
    }
    return tmp;
}

bool Nisza::lokatorZywy() const {
    if (zajeta()) {
        RodzajMieszkanca r = lokator->kimJestes();
        return r==GLON || r==GRZYB || r== BAKTERIA;
    }
}

char Nisza::jakiSymbol() const {
}
