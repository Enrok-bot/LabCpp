#ifndef URZADZENIEELEKTRYCZNE_H
#define URZADZENIEELEKTRYCZNE_H
#include <string>


class UrzadzenieElektryczne {
protected:
    std::string marka;
    bool stan;

public:
    UrzadzenieElektryczne(std::string marka, bool stan = false);

    void wlacz();

    void wylacz();

    std::string jakaMarka() const ;

    bool jakiStan() const ;

    virtual void wypisz() const ;
};

class TV : public UrzadzenieElektryczne {
private:
    int kanal;
    int glosnosc;

public:
    TV(std::string marka1, bool stan = false, int kanal1 = 1, int glosnosc1 = 0);

    void podglosnij();

    void scisz();

    void zmienKanal(int kanal1);

    void wypisz() const override;
};

#endif
