#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int zliczLinieIPusteLinie(const string& nazwaPliku, int& liczbaPustychLinii) {
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku.\n";
        return -1; 
    }

    string linia;
    int liczbaWszystkichLinii = 0;
    liczbaPustychLinii = 0;

    while (getline(plik, linia)) {
        liczbaWszystkichLinii++;

        if (linia.empty()) {
            liczbaPustychLinii++;
        }
    }

    plik.close();

    return liczbaWszystkichLinii;
}

int main() {
    string nazwaPliku;
    int liczbaPustychLinii;

    cout << "Podaj nazwe pliku tekstowego: ";
    cin >> nazwaPliku;

    int liczbaWszystkichLinii = zliczLinieIPusteLinie(nazwaPliku, liczbaPustychLinii);

    if (liczbaWszystkichLinii == -1) {
        return 1;  
    }

    cout << "Liczba wszystkich linii: " << liczbaWszystkichLinii << "\n";
    cout << "Liczba pustych linii: " << liczbaPustychLinii << "\n";

    return 0;
}
