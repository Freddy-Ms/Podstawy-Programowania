#include <iostream>
#include <fstream>

using namespace std;

// Funkcja obliczająca sumę i średnią arytmetyczną z liczb całkowitych z pliku
void obliczSumeISrednia(const string& nazwaPliku) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku.\n";
        return;
    }

    int liczba;
    int suma = 0;
    int iloscElementow = 0;
    
    // Wczytaj liczby z pliku
    while (plik >> liczba) {
        suma += liczba;
        iloscElementow++;
    }

    plik.close();

    if (iloscElementow == 0) {
        cout << "Plik jest pusty.\n";
        return;
    }

    double srednia = static_cast<double>(suma) / iloscElementow;

    cout << "Suma: " << suma << "\n";
    cout << "Srednia: " << srednia << "\n";
}

int main() {
    string nazwaPliku;

    cout << "Podaj nazwe pliku z liczbami calkowitymi: ";
    cin >> nazwaPliku;

    obliczSumeISrednia(nazwaPliku);

    return 0;
}
