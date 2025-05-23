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
---
# **19.03**
### Odpowiedzi na pytania kontrolne:

1. **Typ wyliczeniowy w C++** to specjalny typ danych, który pozwala na przypisanie symbolicznych nazw do określonego zestawu wartości całkowitych. Przykładowo:
   ```cpp
   enum Kolor {CZERWONY, ZIELONY, NIEBIESKI};
   Kolor mojKolor = ZIELONY;
   ```
   Umożliwia to czytelniejsze i bezpieczniejsze operowanie stałymi wartościami.

2. **Składniki statyczne klasy** to elementy klasy (zmienne lub metody), które należą do klasy, a nie do konkretnych obiektów. Składniki statyczne są współdzielone przez wszystkie obiekty danej klasy. Przykład:
   ```cpp
   class Pracownik {
   public:
       static int liczbaPracownikow;
   };
   int Pracownik::liczbaPracownikow = 0;  // Definicja zmiennej statycznej
   ```

3. **Wzorzec projektowy klasy** to sprawdzony schemat organizacji kodu, który pomaga w rozwiązaniu konkretnego problemu programistycznego. Przykładem jest **Singleton**, który zapewnia istnienie tylko jednej instancji klasy:
   ```cpp
   class Singleton {
   private:
       Singleton() {}
   public:
       static Singleton& pobierzInstancje() {
           static Singleton instancja;
           return instancja;
       }
   };
   ```
   
---

### Odpowiedzi do listingu 4:

- **Listing 4.2, wiersz 1** → Typ wyliczeniowy `RodzajMieszkanca` przyjmuje wartości: `GLON, GRZYB, BAKTERIA, PUSTKA, SCIANA, TRUP, NIEZNANE`.

- **Listing 4.3, wiersze 5-12** → Znajduje się tu kilka instrukcji, takich jak deklaracje zmiennych i przypisania.

- **Listing 4.3, wiersze 14-28** → Ten fragment zawiera więcej instrukcji, w tym warunki i operacje logiczne.

- **Listing 4.3, wiersze 32-36** → `||` to operator logiczny „lub” (logical OR). Wartość wyrażenia jest `true`, jeśli przynajmniej jeden operand jest `true`.

- **Listing 4.3, wiersze 30-37** → Metoda `poprawnyZnakNiszy` sprawdza, czy dany znak należy do predefiniowanego zestawu znaków.

- **Listing 4.3, wiersze 38-41** → Metoda zwraca wartość poprzez sprawdzenie zgodności znaku.

- **Listing 4.3, wiersze 44, 44** → Są to konstruktory klasy. Jeden z nich używa `{}` do inicjalizacji, a drugi działa bez tego, ponieważ może polegać na domyślnych konstruktorach składowych.

- **Listing 4.4, wiersze 1-5** → Funkcja `wyswietl` nie zmienia trwale ustawień symulacji, tylko je wyświetla.

- **Listing 4.4** → Singleton `UstawieniaSymulacji` zapewnia, że istnieje tylko jeden obiekt tej klasy.

- **Listing 4.5** → Klasa `GeneratorLosowy` uniemożliwia tworzenie instancji dzięki prywatnemu konstruktorowi.

- **Listing 4.5, wiersz 6** → Można uniknąć `std::` poprzez `using namespace std;` lub `using std::random_device;`.

- **Listing 4.5, wiersz 17** → `typedef GeneratorLosowy GEN;` definiuje skrót `GEN`, co upraszcza kod.

- **Listing 4.6** → Składnik statyczny musi być zdefiniowany w pliku `.cpp`, ponieważ jego deklaracja w `.h` nie wystarczy.

- **Listing 4.7, wiersze 4-8** → Fragment kodu zamienia wartości, jeśli `min > max`, zapewniając poprawne działanie funkcji losującej.

- **Listing 4.9** → Metoda `losujOdZeraDo(int max)` nie może wywołać `losujPomiedzy(0, max)`, ponieważ `losujPomiedzy` wymaga dwóch argumentów o określonych typach.
---
# **26.03**
### **Pytania kontrolne**  

1. **Różnica między wskaźnikiem do stałej a stałym wskaźnikiem:**  
   - **Wskaźnik do stałej:** `const int* ptr` – można zmieniać wskaźnik, ale nie wartość, na którą wskazuje.  
   - **Stały wskaźnik:** `int* const ptr` – nie można zmieniać wskaźnika, ale można zmieniać wartość.  
   - **Stały wskaźnik do stałej:** `const int* const ptr` – nie można zmieniać ani wskaźnika, ani wartości.  

2. **Po co przekazujemy wskaźnik/referencję do stałego obiektu?**  
   - Zmniejsza to **koszt kopiowania** dużych obiektów, jednocześnie zapobiegając modyfikacji danych.  
   - **Przykład:**  
     ```cpp
     void pokaz(const std::string& tekst) { 
         std::cout << tekst << std::endl; 
     }
     ```

3. **Polimorfizm statyczny:**  
   - Występuje, gdy **kompilator określa, którą metodę wywołać** na podstawie sygnatury.  
   - **Przykład przeciążania metod (`GeneratorLosowy`)**:  
     ```cpp
     class GeneratorLosowy {
     public:
         static int losuj(int min, int max);
         static double losuj(double min, double max);
     };
     ```

---

### **Dyskusja**  

- **Listing 5.1** → Typy `RodzajMieszkanca` i `Polozenie` są prawdopodobnie zdefiniowane w osobnych plikach nagłówkowych.  

- **Listing 5.1, wiersze 28-33** → Argumenty metody są przekazywane **przez referencję** (`long & wiersz, long & kolumna`), co umożliwia ich modyfikację w funkcji.  

- **Listing 5.2, wiersz 15** → `nullptr` oznacza **wskaźnik nie wskazujący na żadną pamięć** i zastępuje `NULL` w C++11.  

- **Listing 5.3, wiersze 4-5** → `static_cast<Polozenie>(GeneratorLosowy::losujPomiedzy(min, max))` konwertuje losową liczbę na wartość `Polozenie`.  

- **Listing 5.4** → `auto` automatycznie określa typ zmiennej na podstawie przypisanej wartości.  

- **Listing 5.5, linia 5** → `*elementWewnetrzny(polozenie) = rodzaj;` oznacza przypisanie wartości do wskaźnika.  

- **Listing 5.6** → Metoda `ktoJestSasiadem()` zwraca `RodzajMieszkanca` przez dereferencję wskaźnika.  

- **Listing 5.7** → Dwie pętle `for` iterują po tablicy `3x3`, omijając środek.  

- **Listing 5.8, wiersze 8-9** → Jeśli nie istnieje `RodzajMieszkanca` w sąsiedztwie, pętla `while` może się nie zakończyć.  

- **Listing 5.9** → Metoda zmienia indeksy macierzy `3x3` zgodnie z `Polozenie`, przesuwając `wiersz` i `kolumna`.  

- **Listing 5.10** → `static_cast<long>` rzutuje `unsigned int` na `long`, aby umożliwić operacje arytmetyczne.  

- **Listing 5.9 i 5.10 – polimorfizm?**  
  - Tak, ponieważ metody `zmienIdeksyWgPolozenia()` są przeciążone (polimorfizm statyczny).  

- **Listing 5.12, wiersz 49 – rzutowanie?**  
  - `static_cast<Polozenie>(i);` konwertuje `int` na `Polozenie`, aby uniknąć niejawnych konwersji.  

- **Listing 5.12, wiersze 52-53** → Wywołano `zmienIdeksyWgPolozenia(Polozenie, long&, long&)`, ponieważ argumenty to `long`.  

# **01.04**

### **Pytania kontrolne**

**1. Czym jest dziedziczenie?**  
Dziedziczenie w C++ pozwala jednej klasie (pochodnej) przejąć właściwości (składniki i metody) innej klasy (bazowej). Umożliwia to ponowne użycie kodu i wspiera polimorfizm.

**2. Jakie składniki się nie dziedziczą, a jakie się dziedziczą?**  
- **Dziedziczą się:**  
  - publiczne i chronione (protected) metody i pola klasy bazowej.  
- **Nie dziedziczą się:**  
  - prywatne (private) składniki,  
  - konstruktory,  
  - destruktory,  
  - przeciążenia operatorów klasy bazowej,  
  - metody oznaczone jako `final`.

**3. Jak sterować widocznością składników przy dziedziczeniu?**  
Za pomocą specyfikatorów:
```cpp
class B : public A // składniki A zachowują swoją widoczność
class B : protected A // public + protected stają się protected
class B : private A // wszystko staje się private
```

**4. Jak utworzyć metodę wirtualną?**  
Poprzez dodanie słowa kluczowego `virtual`:
```cpp
class Bazowa {
public:
    virtual void wypisz();
};
```
Jeśli klasa ma mieć metodę czysto wirtualną (abstrakcyjną), to:
```cpp
virtual void wypisz() = 0;
```


**5. Na czym polega polimorfizm dynamiczny?**  
Pozwala na wywoływanie metod odpowiednich dla faktycznego typu obiektu, nawet jeśli odwołujemy się do niego przez wskaźnik lub referencję do klasy bazowej. Działa tylko przy metodach `virtual`.

---

### **Dyskusja** 


- **Listing 6.2, wiersz 4 → Skąd się wzięła metoda `doTekstu` w klasie `Kwadrat`?**  
Pochodzi z klasy bazowej `Figura`. `Kwadrat` dziedziczy `doTekstu` jako metodę wirtualną i może ją przesłaniać (override).


- **Listing 6.2, wiersz 6 → Dlaczego to nie zadziała?**  
Ponieważ metoda `doTekstu` w klasie `Figura` może być czysto wirtualna (`=0`), a nie została zaimplementowana w `Kwadrat`, lub obiekt nie ma kontekstu dynamicznego (brak `virtual`).


- **Listing 6.3, wiersze 5–6 → Jak działa konstruktor klasy `Kwadrat`?**  
Wywołuje konstruktor klasy bazowej `Figura` z parametrem, następnie inicjalizuje własne pole `bok`.


- **Listing 6.6, wiersz 12 → Po co jest znak `&`?**  
To referencja — przekazujemy obiekt `Kwadrat` przez referencję, by uniknąć kopiowania i umożliwić polimorfizm.


- **Listing 6.7, wiersz 12 → Czy można byłoby użyć tutaj pierwszej referencji?**  
Tak, ale jeśli `const Figura&`, to tylko do metod `const`. W przeciwnym razie nie.


- **Listing 6.8, wiersze 5 i 6 → Co oznacza `=0`?**  
To metoda czysto wirtualna – klasa staje się abstrakcyjna i nie można jej instancjonować.


- **Listing 6.10 → Czy zamiast referencji można użyć wskaźnika?**  
Tak, referencję `Figura&` można zastąpić `Figura*`, ale trzeba jawnie dereferencjonować.


- **Czy można utworzyć obiekt klasy `Mieszkaniec`?**  
Nie, jeśli zawiera metody czysto wirtualne (`=0`). Wtedy jest klasą abstrakcyjną.


- **Czy można utworzyć obiekt klasy `ZamiarMieszkanca`?**  
Tak, jeśli nie zawiera metod czysto wirtualnych.


- **Listing 6.11, wiersze 6 i 7 → Co oznaczają „= NIC” oraz „= NIGDZIE”?**  
To inicjalizacja pól wartościami domyślnymi – zapewnia, że obiekt ma określony stan początkowy.


- **Listing 6.12, wiersz 1 → Czy `class Sasiedztwo` można zastąpić `#include "sasiedztwo.h"`?**  
Nie zawsze. `class Sasiedztwo;` to tzw. **forward declaration**. Używane, gdy wystarczy informacja o istnieniu klasy. `#include` jest potrzebny, jeśli korzystasz z jej definicji.

- **Listing 6.12, wiersz 13 → Jak nazywa się ta metoda?**  
To **konstruktor klasy**, nosi nazwę klasy `Sasiedztwo`.


- **Listing 6.15, wiersz 15 → Co powoduje słowo `final`?**  
Oznacza, że metoda nie może być dalej przesłaniana (override) w klasach pochodnych.

- **Listing 6.12 → Które metody są abstrakcyjne?**  
Wszystkie oznaczone `=0`, czyli np. `opis() = 0;` lub `dzialaj() = 0;` w klasach bazowych.

# **Lab 9**

**1. Na czym polega polimorfizm statyczny?**
Polimorfizm statyczny (kompilacyjny) polega na wyborze wersji funkcji w czasie kompilacji, np. przez przeciążanie funkcji (ang. *function overloading*) lub szablony (ang. *templates*). Kompilator decyduje, którą wersję funkcji wywołać, na podstawie liczby i typów argumentów.

---

**2. Na czym polega polimorfizm dynamiczny?**
Polimorfizm dynamiczny (czasowy, wykonania) polega na wywołaniu odpowiedniej wersji metody zależnie od rzeczywistego typu obiektu, a nie typu wskaźnika lub referencji. Wymaga użycia słowa kluczowego `virtual` w klasie bazowej i zazwyczaj działa przez tablicę wskaźników do funkcji wirtualnych (vtable).

---

**3. Czy w języku C++ jest możliwe połączenie polimorfizmu dynamicznego i statycznego? Jeśli tak, przygotuj prosty program demonstracyjny.**
Tak, możliwe jest połączenie obu rodzajów polimorfizmu. Przykład:

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { cout << "Base\n"; }
    void overload(int x) { cout << "Overloaded with int\n"; }
    void overload(double x) { cout << "Overloaded with double\n"; }
};

class Derived : public Base {
public:
    void show() override { cout << "Derived\n"; }
};

int main() {
    Base* ptr = new Derived();
    ptr->show();         // Polimorfizm dynamiczny
    ptr->overload(5);    // Polimorfizm statyczny (przeciążenie funkcji)
    delete ptr;
}
```

---

**4. Czy mechanizm wartości domyślnych argumentów metod zalicza się do polimorfizmu?**
Nie, wartości domyślne nie są formą polimorfizmu. Ułatwiają korzystanie z funkcji, ale nie zmieniają liczby implementacji funkcji. Kompilator podstawia domyślne wartości podczas kompilacji, ale nie wybiera między różnymi wersjami funkcji jak przy przeciążeniu.

---

**5. Czy polimorfizm statyczny się dziedziczy?**
Polimorfizm statyczny sam w sobie nie jest dziedziczony, ponieważ związany jest z przeciążeniem funkcji, które jest rozstrzygane w czasie kompilacji. Można jednak przeciążać funkcje również w klasach pochodnych.

---

**6. Czy argumenty domyślne się dziedziczy?**
Argumenty domyślne **nie są dziedziczone automatycznie**. Jeśli klasa pochodna nadpisuje metodę, to nie dziedziczy domyślnych wartości z klasy bazowej – trzeba je jawnie podać, jeśli są potrzebne.

---

**7. Co się dzieje, gdy istnieje już polimorfizm, ale usunie się słowo `virtual`?**
Jeśli usunie się `virtual` w klasie bazowej, to wywołanie metody przez wskaźnik lub referencję do klasy bazowej nie spowoduje wywołania wersji z klasy pochodnej – wywołana zostanie metoda z klasy bazowej. To „wyłącza” polimorfizm dynamiczny.

---

**8. Po co są te „polimorfizmy”?**
Polimorfizm zwiększa elastyczność i możliwość rozszerzania kodu. Pozwala pisać kod, który działa dla różnych typów danych lub różnych klas pochodnych, bez konieczności znajomości szczegółów implementacji. Ułatwia to m.in. programowanie obiektowe, projektowanie interfejsów i pisanie kodu ogólnego (np. z użyciem szablonów).

---

**9. W jaki sposób w języku C++ pobiera się i zwalnia pamięć?**
W C++ dynamicznie przydzieloną pamięć rezerwuje się za pomocą `new`, a zwalnia się ją za pomocą `delete`. Przykład:

```cpp
int* ptr = new int; // przydzielenie pamięci
*ptr = 10;
delete ptr;         // zwolnienie pamięci
```

Dla tablic używa się `new[]` i `delete[]`:

```cpp
int* tab = new int[5];
delete[] tab;
```

### **Dyskusja** 

### Czy rozmiar zmiennej wskaźnikowej zależy od typu, na jaki ten wskaźnik pokazuje?

**Nie.** Rozmiar wskaźnika jest niezależny od typu, na który pokazuje. Jest to rozmiar potrzebny do przechowywania adresu w pamięci, a nie danych. Na przykład: `sizeof(int*) == sizeof(double*)` na danej architekturze (zwykle 4 bajty na 32-bitowym i 8 bajtów na 64-bitowym systemie).

---

### Listing 9.2, wiersz 11 → Jaki byłby efekt, gdyby tego wiersza nie było?

Wiersz `delete wskInt1D;` zwalnia wcześniej zaalokowaną pamięć. Jeśli ten wiersz zostanie usunięty, dojdzie do **wycieku pamięci** – zaalokowany obszar nie zostanie zwolniony.

---

### Listing 9.2, wiersze 5–7 → Po co jest znak `*`?

Znak `*` służy do **dostępu do wartości**, na którą wskazuje wskaźnik.

* `*wskInt1D = 5;` – przypisanie wartości do zmiennej, na którą wskazuje wskaźnik.
* `*wskInt1D + 3` – dodanie wartości 3 do tej zmiennej.

---

### Co oznacza zapis: `int **wskInt2D = nullptr;`?

Jest to wskaźnik do wskaźnika na `int`, używany np. przy dynamicznej alokacji tablicy dwuwymiarowej. Ustawienie na `nullptr` oznacza, że nie wskazuje on na żadną zaalokowaną pamięć.

---

### Listing 9.3, wiersz 4 → Ile pamięci zostanie zalokowane?

`wskInt1D = new int[3];` – zaalokowane zostaną **3 elementy typu `int`**, czyli np. 12 bajtów (3 × 4 bajty).

---

### Listing 9.3, wiersze 7 i 11 → Co powoduje operator `+`?

Operator `+` w kontekście wskaźnika powoduje **przesunięcie o odpowiednią liczbę elementów typu wskaźnikowego**. Np. `wskInt1D + 1` wskazuje na drugi element tablicy.

---

### Listing 9.3, wiersze 15 i 17 → Co powoduje operator `++`?

Operator `++` przesuwa wskaźnik o **jeden element dalej w pamięci**. Działa analogicznie jak `wskInt1D + 1`, ale zmienia wartość wskaźnika (`iter`).

---

### Listing 9.5, wiersze 5, 6 → Dlaczego to nie zadziała?

Te linie próbują przypisać referencji:

* `int & refInt = new int;` – niepoprawne, bo `new int` zwraca wskaźnik, a nie zmienną.
* `int & refInt = 4;` – niepoprawne, bo referencja nie może odnosić się bezpośrednio do literału (chyba że to `const &`).

---

### Listing 9.5, wiersz 14 → Co się tutaj dzieje?

`refInt = b;` – to **przypisanie wartości `b` do zmiennej `a`**, ponieważ `refInt` jest referencją do `a`. To **nie jest przełączenie referencji na `b`**, co jest niemożliwe – referencje nie mogą zmieniać obiektu, na który wskazują.

---

### Listing 9.5, wiersze 14 i 24 → Jaka jest różnica?

* `refInt = b;` – przypisuje wartość `b` do `a`.
* `wskInt = &B;` – **zmienia wskaźnik**, by wskazywał teraz na `B`. Wskaźniki mogą być przekierowywane, referencje nie.

---

### Czy rozmiar referencji zależy od typu, na jaki ta referencja pokazuje? Czy takie pytanie ma sens?

Rozmiar referencji **jest taki sam jak rozmiar odpowiadającego wskaźnika** – zatem w praktyce jest **niezależny od typu**. Pytanie ma sens teoretyczny, ale w implementacjach referencje często są traktowane jak wskaźniki, więc ich rozmiar jest stały.

---

### Dlaczego lokowanie pamięci odbywa się dwuetapowo?

W przypadku np. tablicy 2D `int**`, alokujemy najpierw tablicę wskaźników (`new int*[w]`), a potem każdą „linię” (`new int[k]`). Dzięki temu można tworzyć nieregularne struktury (macierze o różnych długościach wierszy).

---

### Dlaczego zwalnianie pamięci odbywa się dwuetapowo?

Bo każda „linia” była alokowana osobno – trzeba więc osobno ją usunąć (`delete[] wskInt2D[i]`), a na końcu wskaźnik główny (`delete[] wskInt2D`).

