#ifndef GENERATORLOSOWY_H
#define GENERATORLOSOWY_H
#include <random>

class Index2D {
public:
    unsigned int wiersz, kolumna;

    Index2D(unsigned int _w = 0, unsigned int _k = 0) : wiersz(_w), kolumna(_k) {}
};

typedef std::vector<Index2D> WektorIndeksow2D;

class GeneratorLosowy {
private:
    static std::random_device device;

    GeneratorLosowy() {
    }

public:
    static unsigned short losujPomiedzy(unsigned short min, unsigned short max);

    static long losujPomiedzy(long min, long max);

    static int losujOdZera(int max);

    static WektorIndeksow2D  indeksyLosowe(unsigned int wiersze, unsigned int kolumny);
};

typedef GeneratorLosowy GEN;

#endif //GENERATORLOSOWY_H
