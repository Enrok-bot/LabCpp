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
/*
    UrzadzenieElektryczne u1("LG");
    u1.wypisz();
    std::cout << std::endl;
    u1.wlacz();
    u1.wypisz();
    std::cout << (u1.jakiStan() ? "wlaczony" : "wylaczony") << std::endl;
    std::cout << u1.jakaMarka() << std::endl;

    TV tv1("Samsung", true);
    tv1.wypisz();
    std::cout << std::endl;
    tv1.zmienKanal(50);
    tv1.podglosnij();
    tv1.scisz();
    tv1.scisz();
    tv1.wypisz();
    std::cout << std::endl;

    TV tv2("Philips");
    tv2.wypisz();
    std::cout << std::endl;
    tv2.wlacz();
    tv2.wypisz();
    std::cout << std::endl;

    UrzadzenieElektryczne *u2 = &tv2;
    u2->wypisz();
    u2->wylacz();
    std::cout << std::endl;
    u2->wypisz();
 */