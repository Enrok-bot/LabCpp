#include "zlab02.h"
#include <iostream>
#include <limits>
#include <cmath>
#include <random>

using namespace std;

void ZLab02::zadanie_2_3() {
    int a = -3;
    unsigned int b;
    b = 5;

    int int_min = numeric_limits<int>::min();
    int int_max = numeric_limits<int>::max();

    unsigned int uint_min = numeric_limits<unsigned int>::min();
    unsigned int uint_max = numeric_limits<unsigned int>::max();

    long int_zakres = static_cast<long>(int_max) - static_cast<long>(int_min);
    long uint_zakres = static_cast<long>(uint_max) - static_cast<long>(uint_min);

    cout << "Zmienna a jest typu: " << typeid(a).name()
            << " ma rozmiar: " << sizeof (a) << " bajtów"
            << endl << "Zakres tej zmiennej to: " << int_min
            << " -> " << int_max << ", to oznacza "
            << int_zakres << " różnych wartości" << endl
            << "Aktualna wartość zmiennej to: " << a
            << endl << endl;

    cout << "Zmienna b jest typu: " << typeid(b).name()
            << " ma rozmiar: " << sizeof (b) << " bajtów"
            << endl << "Zakres tej zmiennej to: " << uint_min
            << " -> " << uint_max << ", to oznacza "
            << uint_zakres << " różnych wartości" << endl
            << "Aktualna wartość zmiennej to: " << b
            << endl << endl;
}

void ZLab02::zadanie_2_4() {
    int a = 5, b = 3;
    int c = a / b;
    double d = a / b;
    double e = static_cast<double>(a) / static_cast<double>(b);

    cout << "a=" << a << " b=" << b << endl
            << " a/b=" << c << endl
            << " a/b=" << d << endl
            << " a/b=" << e << endl;
}

void ZLab02::zadanie_2_5() {
    cout.precision(10);
    double eps = numeric_limits<double>::min();
    cout << "Dzielenie z dokładnością: " << eps << endl;
    double x, y;
    cout << "Podaj dzielną: " << endl;
    cin >> x;
    cout << "Podaj dzielnik: " << endl;
    cin >> y;
    if (fabs(y) > eps) cout << x << "/" << y << "=" << x / y << endl;
    else cout << "Dzielnik jest za mały" << endl;
}

void ZLab02::zadanie_2_7() {
    long liczba1 = 3, liczba2 = -5, liczba3 = 0;

    long *wskaznikDoLong = nullptr;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;

    wskaznikDoLong = &liczba3;

    *wskaznikDoLong = liczba1;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;

    wskaznikDoLong = &liczba1;

    liczba2 = *wskaznikDoLong;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;
}

void ZLab02::zadanie_2_8() {
    long liczba1 = 3, liczba2 = -5, liczba3 = 0;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;

    long &referencjaDoLong = liczba2;

    referencjaDoLong = 10;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;

    long &referencjaDoLongInna = liczba3;

    referencjaDoLongInna = liczba1;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;

    long &referencjaDoLongKolejna = liczba1;

    liczba3 = referencjaDoLongInna;

    cout << "liczba1=" << liczba1 << " liczba2=" << liczba2 << "liczba3=" << liczba3 << endl;
}

void ZLab02::zadanie_2_9() {
    const short N = 10;
    int tablica[N];

    random_device maszynkaLosujaca;
    uniform_int_distribution<short> dystrybucja(-3, 4);

    for (unsigned short i = 0; i < N; i++) {
        tablica[i] = dystrybucja(maszynkaLosujaca);
    }
    for (int j: tablica) cout << j << " ";

    cout << endl;
}

void ZLab02::zadanie_2_10(short min, short max) {
    const short N = 10;
    int tab[N];

    random_device maszynka;
    uniform_int_distribution<short> dystr(min, max);

    for (unsigned short i = 0; i < N; i++)
        while ((tab[i] = dystr(maszynka)) < tab[i - 1]);

    for (int liczba: tab) cout << liczba << " ";

    cout << endl;
}

double ZLab02::pobierzLiczbe() {
    double x = 0;
    bool sukces = true;
    string linia;

    do {
        if (!sukces) cout << "!To ma być liczba." << endl;
        getline(cin, linia);
        try {
            x = stod(linia);
            sukces = true;
        } catch (const invalid_argument &) {
            sukces = false;
        }
    } while (!sukces);

    return x;
}

void ZLab02::menu() {
    unsigned short wybor;

    do {
        cout << "Które zadanie uruchomić?" << endl;
        for (int i = 3; i <= 11; i++) {
            cout << i << " -> zadanie 2." << i << endl;
        }
        cin >> wybor;
        cin.ignore(); //czyści bufor
    } while (wybor < 3 || wybor > 12 || wybor == 6);

    short min, max;

    if (wybor == 10) {
        cout << "Podaj dolny zakres: " << endl;
        cin >> min;
        cout << "Podaj górny zakres: " << endl;
        cin >> max;
    }


    switch (wybor) {
        case 3: zadanie_2_3();
            break;
        case 4: zadanie_2_4();
            break;
        case 5: zadanie_2_5();
            break;
        case 7: zadanie_2_7();
            break;
        case 8: zadanie_2_8();
            break;
        case 9: zadanie_2_9();
            break;
        case 10: zadanie_2_10(min, max);
            break;
        case 11: pobierzLiczbe();
            break;
        default: cout << "Nie ma takiego zadania" << endl;
    }
}
