#ifndef URZADZENIEELEKTRYCZNE_H
#define URZADZENIEELEKTRYCZNE_H
#include <string>


class UrzadzenieElektryczne {
protected:
    std::string marka;
    bool stan;

public:
    UrzadzenieElektryczne(std::string marka, bool stan = false);

    const void wlacz();

    const void wylacz();

    const std::string jakaMarka();

    const bool jakiStan();

    const void wypisz();
};

class TV : public UrzadzenieElektryczne {
private:
    int kanal;
    int glosnosc;

public:
    TV(std::string marka1, bool stan = false, int kanal1 = 1, int glosnosc1 = 0);

    const void podglosnij();

    const void scisz();

    const void zmienKanal(int kanal1);

    const void wypisz();
};

#endif
