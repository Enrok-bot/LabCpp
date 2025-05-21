#include "zlab10.h"
#include "GeneratorLosowy.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

void ZLab10::wektor() {
    std::vector<double> wektor;

    wektor.push_back(2.3);
    wektor.push_back(4.5);
    wektor.push_back(-2.3);
    wektor.push_back(0.1);

    std::cout << "Rozmiar wektora: " << wektor.size() << std::endl;
    for (double d: wektor) std::cout << d << " ";
    std::cout << std::endl << std::endl;

    // for (unsigned long i = 5; i < 10; i++) wektor[i] = 3.2;
    // std::cout << "Rozmiar wektora: " << wektor.size() << std::endl;
    // for (double d: wektor) std::cout << d << " ";
    // std::cout << std::endl << std::endl;

    wektor.resize(12);
    for (unsigned long i = 5; i < 10; i++) wektor[i] = 3.2;
    std::cout << "Rozmiar wektora: " << wektor.size() << std::endl;
    for (double d: wektor) std::cout << d << " ";
    std::cout << std::endl << std::endl;

    for (unsigned long i = 0; i < wektor.size(); i++) wektor[i] = i;
    std::cout << "Rozmiar wektora: " << wektor.size() << std::endl;
    for (double d: wektor) std::cout << d << " ";
    std::cout << std::endl << std::endl;

    for (double & d: wektor) d = 3.14;

    for (double d: wektor) std::cout << d << " ";
    std::cout << std::endl << std::endl;

    wektor.clear();
    std::cout << "Rozmiar wektora: " << wektor.size() << std::endl;
    for (double d: wektor) std::cout << d << " ";
    std::cout << std::endl << std::endl;
}

void ZLab10::wektor_sortowanie()
{
    std::vector<int> wektor;

    wektor.resize(13);

    for(int & j: wektor) j = GEN::losujOdZera(20);

    std::cout << "Wektor wygenerowany" << std::endl;
    for(auto j: wektor) std::cout << j << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Wektor posortowany" << std::endl;
    sort(wektor.begin(), wektor.end());
    for(auto j : wektor) std::cout << j << " ";
    std::cout << std::endl << std::endl;

    std::cout << "Wektor pomieszany" << std::endl;
    random_shuffle(wektor.begin(), wektor.end(), GEN::losujOdZera);
    for(auto j : wektor) std::cout << j << " ";
    std::cout << std::endl << std::endl;
}

void ZLab10::zbior() {
    std::set<std::string> imiona;
    imiona.insert("Adam");
    imiona.insert("Ewa");
    imiona.insert("Maciek");

    for (std::string s: imiona) std::cout << s << " ";
    std::cout << std::endl << std::endl;


}
