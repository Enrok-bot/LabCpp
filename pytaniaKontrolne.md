# **26.02**
### 1. Zintegrowane Środowisko Programistyczne (IDE)
Zintegrowane środowisko programistyczne (ang. **Integrated Development Environment**, IDE) to aplikacja, która wspomaga programistów w tworzeniu, edytowaniu, kompilowaniu i debugowaniu kodu. IDE zazwyczaj łączy w sobie kilka narzędzi, takich jak:

- **Edytor kodu źródłowego** – umożliwia pisanie i edytowanie kodu.
- **Kompilator/interpreter** – tłumaczy kod na język maszynowy.
- **Debugger** – pomaga w wykrywaniu i naprawianiu błędów w programie.
- **System zarządzania plikami i projektami** – organizuje kod źródłowy i pliki projektu.

Przykłady popularnych IDE: Visual Studio, Code::Blocks, CLion, Eclipse, PyCharm.

---

### 2. Związek pomiędzy językiem C i C++
C++ wywodzi się z języka C i jest jego rozszerzeniem. Główne zależności:

- **Kompatybilność** – większość kodu napisanego w C można skompilować jako program w C++.
- **Paradigma programowania** – C jest językiem proceduralnym, natomiast C++ wspiera zarówno programowanie proceduralne, jak i obiektowe.
- **Nowe funkcjonalności** – C++ wprowadza m.in. klasy, przeciążanie operatorów, przestrzenie nazw, obsługę wyjątków i szablony.
- **Większa abstrakcja** – C++ pozwala na bardziej złożone struktury danych i mechanizmy programowania, ułatwiając zarządzanie dużymi projektami.

---

### 3. Struktura najprostszego programu w C++
Najprostszy program w C++ wygląda następująco:

```cpp
#include <iostream>                // Biblioteka do operacji wejścia/wyjścia

int main() {                       // Główna funkcja programu
    std::cout << "Hello, World!";  // Wyświetlenie tekstu na ekranie
    return 0;                      // Zakończenie programu z kodem wyjścia 0
}
```

#### Składniki programu:
1. **`#include <iostream>`** – dołączenie biblioteki umożliwiającej korzystanie z `std::cout`.
2. **`int main()`** – główna funkcja programu, od niej rozpoczyna się wykonanie kodu.
3. **`std::cout << "Hello, World!";`** – wypisuje tekst na ekran.
4. **`return 0;`** – zwraca kod wyjścia 0, co oznacza poprawne zakończenie programu.
---
# **5.03**
### 1. Różnica między statycznym a dynamicznym typowaniem w C++

C++ jest językiem ze **statycznym typowaniem**, co oznacza, że typy zmiennych są określane w czasie kompilacji. Oznacza to, że każda zmienna musi mieć określony typ, który nie może się zmieniać w trakcie działania programu.

#### Przykład statycznego typowania w C++:
```cpp
int liczba = 10;  // liczba jest typu int i nie można przypisać do niej wartości innego typu
liczba = "tekst"; // Błąd kompilacji – nie można przypisać stringa do int
```

Jednak C++ posiada pewne mechanizmy zwiększające elastyczność, np. **`auto`**, które pozwala kompilatorowi samemu określić typ zmiennej na podstawie przypisanej wartości:

```cpp
auto x = 3.14; // x jest typu double
auto y = 42;   // y jest typu int
```

Mimo że `auto` ułatwia kodowanie, typowanie nadal pozostaje **statyczne**, bo raz ustalony typ nie może się zmienić.

---

### 2. Hermetyzacja w C++

Hermetyzacja (ang. **encapsulation**) to zasada programowania obiektowego polegająca na ukrywaniu szczegółów implementacji klasy i udostępnianiu tylko tych danych oraz metod, które są niezbędne do interakcji z obiektem.

W C++ hermetyzację osiągamy dzięki **modyfikatorom dostępu**:
- `private` – składniki klasy dostępne tylko wewnątrz tej klasy,
- `protected` – dostępne wewnątrz klasy oraz dla klas dziedziczących,
- `public` – dostępne dla wszystkich.

#### Przykład hermetyzacji w C++:
```cpp
#include <iostream>

class KontoBankowe {
private:
    double saldo; // Prywatny atrybut – nie można go zmodyfikować bezpośrednio spoza klasy

public:
    KontoBankowe(double poczatkoweSaldo) {
        saldo = poczatkoweSaldo;
    }

    void wplac(double kwota) {
        if (kwota > 0) {
            saldo += kwota;
        }
    }

    double pobierzSaldo() const {
        return saldo;
    }
};

int main() {
    KontoBankowe konto(1000); // Utworzenie obiektu z początkowym saldem 1000
    konto.wplac(500); // Wpłata 500
    std::cout << "Saldo: " << konto.pobierzSaldo() << std::endl; // Wyświetli: Saldo: 1500

    // konto.saldo = 2000; // Błąd! saldo jest prywatne i nie można go modyfikować bezpośrednio

    return 0;
}
```
W tym przykładzie:  
✅ `saldo` jest prywatnym atrybutem (`private`), więc nie można go zmienić bezpośrednio spoza klasy.  
✅ Do modyfikacji salda służy publiczna metoda `wplac()`, co zapewnia kontrolę nad poprawnością operacji.  
✅ `pobierzSaldo()` zwraca saldo w bezpieczny sposób.

### 3.Jaką wartość będzie miała zmienna k we wskazanych miejscach na listingach

```cpp
int k = 0;
while(k<10) if(k<3) k++; else k+=2;
//k=11
k=13;
do{
    if(k<7) k -= 3;
    else if(k >= 2) --k;
}while (k < 4 && k > 2);
//k=12
k=3;
switch (k) {
    case 2: k *= 5;
    case 3: k++;
    case 1: k -= 3;
    case 5: k = 3;
    default: k =0;
} // k=0
k = 5;
for(int i=-1; i<5; i+=3) k—;
// k=3
```