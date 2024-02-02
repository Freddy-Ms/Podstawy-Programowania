#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<vector<int>> wczytajMacierz(const string& nazwaPliku) {
    vector<vector<int>> macierz;
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku.\n";
        return macierz;  
    }

    int liczba;
    int liczbaWierszy, liczbaKolumn;

    plik >> liczbaWierszy >> liczbaKolumn;

    macierz.resize(liczbaWierszy, vector<int>(liczbaKolumn, 0));

    for (int i = 0; i < liczbaWierszy; ++i) {
        for (int j = 0; j < liczbaKolumn; ++j) {
            if (!(plik >> macierz[i][j])) {
                cout << "Blad przy wczytywaniu elementow macierzy.\n";
                return macierz;  
            }
        }
    }

    plik.close();
    return macierz;
}


void zapiszMacierz(const vector<vector<int>>& macierz, const string& nazwaPliku) {
    ofstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku do zapisu.\n";
        return;
    }

    int liczbaWierszy = macierz.size();
    int liczbaKolumn = macierz[0].size();

    plik << liczbaWierszy << " " << liczbaKolumn << "\n";

    for (int i = 0; i < liczbaWierszy; ++i) {
        for (int j = 0; j < liczbaKolumn; ++j) {
            plik << macierz[i][j] << " ";
        }
        plik << "\n";
    }

    cout << "Macierz zostala zapisana do pliku: " << nazwaPliku << "\n";

    plik.close();
}

int main() {
    string nazwaPliku;
    vector<vector<int>> mojaMacierz;

    cout << "Podaj nazwe pliku z macierza: ";
    cin >> nazwaPliku;

    mojaMacierz = wczytajMacierz(nazwaPliku);

    if (mojaMacierz.empty()) {
        return 1;
    }

    cout << "Wczytana macierz:\n";
    for (const auto& wiersz : mojaMacierz) {
        for (int element : wiersz) {
            cout << element << " ";
        }
        cout << "\n";
    }

    zapiszMacierz(mojaMacierz, "wynikowa_macierz.txt");

    return 0;
}
