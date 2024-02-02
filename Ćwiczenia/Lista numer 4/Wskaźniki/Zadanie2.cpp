#include <iostream>

using namespace std;  // Dodanie using namespace std;

// Funkcja do wczytania tablicy
void wczytajTablice(int *tablica, int rozmiar) {
    cout << "Wczytaj " << rozmiar << " liczb do tablicy:\n";
    for (int i = 0; i < rozmiar; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> *(tablica + i);  
    }
}

// Funkcja do wyświetlenia tablicy
void wyswietlTablice(const int *tablica, int rozmiar) {
    cout << "Tablica: ";
    for (int i = 0; i < rozmiar; ++i) {
        cout << *(tablica + i) << " "; 
    }
    cout << "\n";
}

// Funkcja znajdująca minimum w tablicy
int znajdzMinimum(const int *tablica, int rozmiar) {
    int minimum = *tablica;  
    for (int i = 1; i < rozmiar; ++i) {
        if (*(tablica + i) < minimum) {  
            minimum = *(tablica + i);
        }
    }
    return minimum;
}

// Funkcja znajdująca maksimum w tablicy
int znajdzMaximum(const int *tablica, int rozmiar) {
    int maksimum = *tablica;  
    for (int i = 1; i < rozmiar; ++i) {
        if (*(tablica + i) > maksimum) {  
            maksimum = *(tablica + i);
        }
    }
    return maksimum;
}

// Funkcja obliczająca średnią arytmetyczną tablicy
double obliczSrednia(const int *tablica, int rozmiar) {
    int suma = 0;
    for (int i = 0; i < rozmiar; ++i) {
        suma += *(tablica + i);  
    }
    return static_cast<double>(suma) / rozmiar;
}

int main() {
    const int rozmiar = 5;
    int tablica[rozmiar];
    wczytajTablice(tablica, rozmiar);
    wyswietlTablice(tablica, rozmiar);
    cout << "Minimum: " << znajdzMinimum(tablica, rozmiar) << "\n";
    cout << "Maksimum: " << znajdzMaximum(tablica, rozmiar) << "\n";
    cout << "Średnia: " << obliczSrednia(tablica, rozmiar) << "\n";

    return 0;
}
