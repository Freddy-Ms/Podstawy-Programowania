#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void stworzStatystyke(const string& nazwaPliku) {
    ifstream plik(nazwaPliku, ios::binary);

    if (!plik.is_open()) {
        cout << "Nie udalo sie otworzyc pliku.\n";
        return;
    }

    vector<int> statystyka(256, 0);  

    char znak;
    while (plik.get(znak)) {
        statystyka[static_cast<unsigned char>(znak)]++;
    }

    plik.close();

    ofstream wyniki("wyniki.txt");

    if (!wyniki.is_open()) {
        cout << "Nie udalo sie utworzyc pliku wyniki.txt.\n";
        return;
    }

    for (int i = 0; i < 256; ++i) {
        wyniki << i << ": " << statystyka[i] << "\n";
    }

    cout << "Statystyka zostala zapisana do pliku wyniki.txt.\n";

    wyniki.close();
}

int main() {
    string nazwaPliku;

    cout << "Podaj nazwe pliku: ";
    cin >> nazwaPliku;

    stworzStatystyke(nazwaPliku);

    return 0;
}
