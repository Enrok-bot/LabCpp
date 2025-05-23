#ifndef OSOBNIKI_H
#define OSOBNIKI_H
#include "Mieszkaniec.h"
#include "organizm.h"
#include "ustawienia.h"
#include "GeneratorLosowy.h"
#include "sasiedztwo.h"


class Glon : protected Organizm, public Mieszkaniec {
public:
    Glon();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);
};

class Grzyb : protected Organizm, public Mieszkaniec {
public:
    Grzyb();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);
};

class Bakteria : protected Organizm, public Mieszkaniec {
public:
    Bakteria();

    virtual RodzajMieszkanca kimJestes() final;

    virtual ZamiarMieszkanca wybierzAkcje(Sasiedztwo sasiedztwo);

    virtual Mieszkaniec *dajPotomka();

    virtual void przyjmijZdobycz(Mieszkaniec *mieszkaniec);
};
#endif //OSOBNIKI_H
