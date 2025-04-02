#include <iostream>
#include "zlab03.h"

class Obliczenia {
protected:
    const double pi = 3.14;

public:
    virtual double promienKolaWgPola() = 0;

    virtual double promienOkreguWgObwodu() = 0;

    virtual ~Obliczenia();
};

class Kwadrat : public Prostokat, public Obliczenia {
public:
    Kwadrat(string nazwa = "?", double bok = 0): Prostokat(nazwa, bok, bok) {
    }

    ~Kwadrat() {
        cout << "Kwadrat: " << nazwa << " kończy działanie." << endl;
    }

    virtual string doTekstu();

    double promienKolaWgPola() override;

    double promienOkreguWgObwodu() override;
};
