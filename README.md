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
---
### Odpowiedzi na pytania:

1. **Jakie rozszerzenie ma plik nagłówkowy i po co on jest?**
    - Plik nagłówkowy w C++ ma rozszerzenie **.h**. Służy do deklarowania klas, funkcji, zmiennych i stałych, które mogą być używane w innych plikach źródłowych. Dzięki temu kod jest bardziej modularny i łatwiejszy do zarządzania .

2. **Jakie rozszerzenie ma plik źródłowy i po co on jest?**
    - Plik źródłowy w C++ ma rozszerzenie **.cpp**. Zawiera definicje funkcji i metod zadeklarowanych w plikach nagłówkowych. Kompilator przetwarza pliki źródłowe, aby stworzyć plik wykonywalny .

3. **Listing 2.6, wiersze 1-3 → Jaki jest efekt dyrektywy include?**
    - Dyrektywa `#include` włącza zawartość wskazanego pliku do kodu źródłowego przed jego kompilacją. W listingu 2.6 `#include "zlab02.h"`, `#include <iostream>`, `#include <limits>` umożliwia korzystanie z deklaracji z pliku nagłówkowego oraz funkcji wejścia/wyjścia i funkcji określających zakresy typów liczbowych .

4. **Co oznacza operator `::` (np. w linii 4 na listingu 2.5)?**
    - Operator `::` (operator zakresu) pozwala na określenie, do której klasy lub przestrzeni nazw należy dana funkcja lub zmienna. W listingu 2.5 `void ZLab02::zadanie_2_3()` oznacza, że funkcja `zadanie_2_3()` należy do klasy `ZLab02` .

5. **Listing 2.7, wiersz 15 i 19 → Dlaczego zastosowany został typ long?**
    - Typ `long` został zastosowany, aby uniknąć przepełnienia wartości liczbowych podczas obliczeń zakresów dla typów `int` i `unsigned int` .

6. **Jaki jest efekt słowa `endl`?**
    - `endl` powoduje przejście do nowej linii i wymusza opróżnienie bufora strumienia wyjściowego `cout` .

7. **Dlaczego wyniki dzielenia są różne?**
    - Różnice wynikają z typów zmiennych. Jeśli `a` i `b` są typu `int`, to `a / b` wykonuje dzielenie całkowite, ignorując część ułamkową. Natomiast rzutowanie na `double` przed dzieleniem pozwala uzyskać precyzyjny wynik zmiennoprzecinkowy .

8. **Listing 2.9, wiersz 5 → Co tu się dzieje?**
    - W tym wierszu `double e = static_cast<double>(a)/static_cast<double>(b);` rzutuje `a` i `b` na `double`, dzięki czemu wynik dzielenia będzie precyzyjniejszy i uwzględni część ułamkową .

9. **Listing 2.12, wiersz 2 → Czy zmienna `wybor` może mieć typ `double`?**
    - Nie, ponieważ zmienna `wybor` jest używana w instrukcji `switch`, a `switch` działa tylko na typach całkowitych (`int`, `char`, `enum`) .

10. **Listing 2.12, wiersz 2 → Czy zmienna `wybor` może mieć typ `int`?**
    - Tak, zmienna `wybor` może być typu `int`, ponieważ jest używana w instrukcji `switch`, która obsługuje wartości całkowite .

11. **Listing 2.12, wiersz 11 → Co oznacza `||`?**
    - Operator `||` oznacza logiczne **lub**. Wyrażenie `wybor < 3 || wybor > 5` zwróci `true`, jeśli `wybor` będzie mniejsze niż 3 lub większe niż 5 .

12. **Listing 2.12, wiersze 14-16 → Jaka jest rola słowa `break`?**
    - `break` przerywa wykonanie `switch`, zapobiegając wykonaniu kolejnych przypadków w instrukcji wyboru .

13. **Listing 2.14, wiersz 5 → W jakim celu wskaźnikowi nadaje się wartość `nullptr`?**
    - `nullptr` oznacza, że wskaźnik nie wskazuje na żadną istotną wartość. Jest to dobry sposób na uniknięcie użycia niezainicjalizowanego wskaźnika .

14. **Listing 2.14, wiersz 11 → Jak działa operator `&`?**
    - Operator `&` pobiera adres zmiennej i zwraca wskaźnik na tę zmienną .

15. **Listing 2.14, wiersz 13 → Po co jest znak `*`?**
    - `*` oznacza dereferencję wskaźnika, czyli pozwala na dostęp do wartości, na którą wskazuje wskaźnik .

16. **Listing 2.17, wiersz 3 → Jaki będzie efekt wywołania instrukcji?**
    - `int tab[N];` deklaruje tablicę `tab` o `N` elementach, które będą przechowywać losowe liczby .

17. **Listing 2.17, wiersz 6 → Co tu się dzieje?**
    - `uniform_int_distribution<short> dystr(min,max);` tworzy generator liczb losowych w zadanym przedziale `min` do `max` .

18. **Listing 2.16, wiersz 11 → Jakie instrukcje znajdują się w bloku pętli `while`?**
    - Wewnętrzna pętla `while` losuje liczbę i sprawdza, czy jest większa od poprzedniej, w przeciwnym razie ponawia losowanie .

19. **Listing 2.16, wiersz 11 → Jak w ogóle działa pętla `while`?**
    - `while` wykonuje kod w swojej pętli dopóki warunek jest spełniony. W tym przypadku generuje liczby do momentu uzyskania ciągu niemalejącego .

20. **Czy może zdarzyć się, że warunek zakończenia pętli `while` nie wystąpi?**
    - Tak, jeśli generator liczb losowych nie wygeneruje odpowiedniej wartości, pętla `while` może teoretycznie wykonywać się w nieskończoność .

21. **Czy zaproponowany algorytm można zastosować do wygenerowania ciągu rosnącego?**
    - Tak, można zmodyfikować algorytm tak, aby generował liczby w sposób ściśle rosnący, na przykład dodając inkrementację zamiast losowania do momentu spełnienia warunku .
---
# **12.03**
### 1. Różnica między klasą a obiektem klasy

* **Klasa** to szablon definiujący strukturę i zachowanie obiektów, określający atrybuty (pola) oraz metody.
 * **Obiekt klasy** to konkretna instancja klasy, która istnieje w pamięci i posiada własne wartości atrybutów.

### 2. Składniki klasy

* **Pola (zmienne członkowskie)** – przechowują dane obiektu.
* **Metody (funkcje członkowskie)** – operują na danych klasy.
* **Konstruktory** – metody wywoływane przy tworzeniu obiektu.
* **Destruktor** – metoda wywoływana przy usuwaniu obiektu.
* **Metody statyczne i pola statyczne** – wspólne dla wszystkich obiektów danej klasy.
* **Modyfikatory dostępu** – `public`, `private`, `protected`.

### 3. Proces tworzenia obiektu:
- Najpierw definiujemy klasę:
 ```cpp
 class Samochod {
 public:
     string marka;
     string model;

     // Konstruktor
     Samochod(string m, string mo) {
         marka = m;
         model = mo;
     }
 };
 ```  
- Następnie tworzymy obiekt:
 ```cpp
 Samochod auto("Toyota", "Corolla");
 ```  
- Obiekt `auto` posiada swoje własne wartości pól `marka` i `model`.

4. **Metoda uruchamiana przy usuwaniu obiektu z pamięci:**
- W C++ jest to **destruktor**, który ma nazwę `~NazwaKlasy()`, np.:
  ```cpp
  class Przykladowa {
  public:
      ~Przykladowa() {
          cout << "Obiekt został usunięty" << endl;
      }
  };
  ```  
- Jest on wywoływany automatycznie przy końcu zasięgu obiektu lub przy użyciu `delete` dla obiektów dynamicznych.

### Odpowiedzi na pytania:

### **Listing 3.2**
1. **Wiersz 10 – Jakie wartości można podstawić pod zmienną `nazwa`?**
    - Można przypisać dowolny ciąg znaków (`std::string`). Domyślną wartością jest `"?"` .

2. **Wiersz 11 – Czy w `main()` można podstawić `obiektKlasy.bok1 = 3`?**
    - Nie, ponieważ `bok1` jest **prywatnym** polem klasy `Prostokat` .

3. **Wiersz 15 – Jaką wartość zwraca metoda `czyPoprawny`?**
    - Zwraca `true`, jeśli długości boków są dodatnie, w przeciwnym razie `false` .

4. **Wiersz 16 – Czy można wywołać `obiektKlasy.obliczObwod()` w `main()`?**
    - Nie, `obliczObwod()` jest metodą **prywatną** .

5. **Wiersz 20 – Efekt użycia domyślnych wartości argumentów metody**
    - Jeśli obiekt zostanie utworzony jako `Prostokat p;`, wartości domyślne to `"?"`, `1.0`, `2.0` .

6. **Wiersz 15 i 22 – Czym różnią się metody?**
    - `czyPoprawny(double, double)` sprawdza podane wartości, natomiast `czyPoprawny()` zwraca stan obiektu. Jest to **przeciążenie metod** .

7. **Wiersz 23 – Co zwraca metoda?**
    - `const std::string&` – zwraca referencję na `nazwa` .

8. **Wiersz 28 – Co oznacza `std::`? Czy jest konieczne?**
    - `std::` odnosi się do przestrzeni nazw standardowej biblioteki C++. Można go pominąć, jeśli wcześniej użyto `using namespace std;` .

---

### **Listing 3.3**
9. **Wiersz 1 – Co oznacza `Prostokat::`?**
    - To **operator zakresu**, który określa, że metoda `czyPoprawny()` należy do klasy `Prostokat` .

10. **Wiersz 2 – Skąd bierze się zwracana wartość?**
    - `czyPoprawny()` zwraca wartość zmiennej `poprawny`, która została ustawiona podczas tworzenia obiektu .

---

### **Listing 3.6**
11. **Wiersz 1 – Co oznacza `:nazwa(n)`?**
    - To **lista inicjalizacyjna**, która przypisuje `n` do `nazwa`. Można to zastąpić przypisaniem w `{ }`, ale lista inicjalizacyjna jest preferowana dla `const` i referencji .

12. **Wiersz 11 – Jaką wartość będzie miało `bok2`?**
    - Jeśli `bok1` i `bok2` są niepoprawne, zostaną ustawione na `0` .

---

### **Listing 3.7**
13. **Czy `std::` jest konieczne?**
    - Tylko jeśli wcześniej nie użyto `using namespace std;` .

---

### **Listing 3.12**
14. **Jak działa metoda? Dlaczego można wywoływać metody prywatne?**
    - Metoda `zmienBoki()` wywołuje `czyPoprawny()`, `obliczObwod()` i `obliczPole()`, które są prywatne. Można to zrobić, ponieważ są częścią tej samej klasy .

---

### **Listing 3.13**
15. **Wiersze 5, 6, 9 – Co robi `std::to_string()`?**
    - Konwertuje liczby (`double`) na `std::string` .

---

### **Listing 3.14**
16. **Wiersze 14-16 – Jak uzyskać dostęp do pola/metody obiektu?**
    - Za pomocą operatora `.` np. `p2.podajObwod()` .

17. **Wiersz 9 – Jakie wartości przyjmuje konstruktor?**
    - Ciąg znaków `n` oraz dwie liczby zmiennoprzecinkowe `a` i `b` .

18. **Wiersz 13 – Co robi `precision` na `cout`?**
    - Ustawia liczbę cyfr po przecinku .

19. **Wiersze 14-16 – Dlaczego `precision` nie działa tu?**
    - `to_string()` formatuje liczby niezależnie od `cout.precision()` .

20. **Wiersze 21-25 – Ile instrukcji jest w tych wierszach?**
    - Cztery wywołania metod na `p2` .

21. **Czy można zmienić `p1.nazwa = "Inna nazwa"`?**
    - Nie, ponieważ `nazwa` jest prywatna .

22. **Czy destruktor się uruchamia?**
    - Tak, ponieważ każdy obiekt ma automatycznie wywołany destruktor przy końcu zasięgu .

---

### **Listing 3.15**
23. **Co oznacza „pączkujący” obiekt klasy `Organizm`?**
    - `paczkujacy()` zwraca `true`, jeśli organizm zjadł więcej niż `kosztPotomka` .

24. **Wiersze 4-5 – Efekt `const`?**
    - `limitPosilkow` i `kosztPotomka` nie mogą być zmieniane po inicjalizacji .

25. **Wiersze 8-9 – Dlaczego `licznikZycia` i `licznikPosilkow` nie mogą być `const`?**
    - Ponieważ zmieniają swoją wartość w trakcie symulacji .

26. **Wiersz 16 – Co oznacza `const` w metodzie?**
    - Metoda nie może zmieniać pól obiektu .

27. **Które metody można wywołać na obiekcie `Organizm`?**
    - Wszystkie publiczne metody .

28. **Które metody można wywołać na `const Organizm`?**
    - Tylko metody oznaczone jako `const` .

29. **Czy można utworzyć `Organizm organizmPusty;`?**
    - Nie, ponieważ nie ma domyślnego konstruktora .

---

### **Listing 3.16-3.22**
30. **Co robi metoda `posilek`?**
    - Zwiększa `licznikPosilkow` .

31. **Co robi metoda `potomek`?**
    - Sprawdza, czy organizm może się rozmnożyć .

32. **Co robi metoda `krokSymulacji`?**
    - Zmniejsza `licznikZycia`, jeśli organizm żyje .

33. **Co robi funkcja `drukujOrganizm()`?**
    - Wyświetla stan organizmu .

34. **Jaki konstruktor został użyty w `Listing 3.22`?**
    - Konstruktor z trzema parametrami .

35. **Na czym polega test niezależności obiektów?**
    - Sprawdza, czy zmiana jednego obiektu nie wpływa na inny .

36. **Na czym polega test symulacji?**
    - Sprawdza działanie organizmu w ekosystemie .
