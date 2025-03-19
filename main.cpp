#include "samochod.h"
#include <iostream>

int main() {
    Samochod s("Mazda6",8,20);
    std::cout << s.jakiModel() << std::endl;
    std::cout << s.jakieZuzycie() << " l/100 km" << std::endl;
    std::cout << "W baku: " << s.jakieZuzycie() << " litrow" << std::endl;

    std::cout << s.doTekstu() << std::endl;
}
