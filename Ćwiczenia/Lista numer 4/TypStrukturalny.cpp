#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definicja typu strukturalnego do przechowywania informacji o książkach
struct Ksiazka {
    string tytul;
    string autor;
    int indeks;
    float cena;
    int liczbaStron;
    bool wypozyczona;
};

// Funkcja do wczytywania danych o książkach
void wczytajBaze(Ksiazka baza[], int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        cout << "Podaj dane o ksiazce #" << i + 1 << ":\n";
        cout << "Tytul: ";
        getline(cin, baza[i].tytul);
        cout << "Autor: ";
        getline(cin, baza[i].autor);
        cout << "Indeks: ";
        cin >> baza[i].indeks;
        cout << "Cena: ";
        cin >> baza[i].cena;
        cout << "Liczba stron: ";
        cin >> baza[i].liczbaStron;
        cout << "Status wypożyczenia (0-nie, 1-tak): ";
        cin >> baza[i].wypozyczona;
        cin.ignore();  // Ignoruj znak nowej linii pozostawiony po cin
    }
}

// Funkcja do wyświetlania danych o książkach
void wyswietlBaze(const Ksiazka baza[], int rozmiar) {
    cout << "Zawartosc bazy:\n";
    for (int i = 0; i < rozmiar; ++i) {
        cout << "Ksiazka #" << i + 1 << ":\n";
        cout << "Tytul: " << baza[i].tytul << "\n";
        cout << "Autor: " << baza[i].autor << "\n";
        cout << "Indeks: " << baza[i].indeks << "\n";
        cout << "Cena: " << baza[i].cena << " zł\n";
        cout << "Liczba stron: " << baza[i].liczbaStron << "\n";
        cout << "Status wypożyczenia: " << (baza[i].wypozyczona ? "Wypożyczona" : "Dostępna") << "\n";
        cout << "---------------------------\n";
    }
}

// Funkcja wyświetlająca tanie książki (cena < 10 zł)
void wyswietlTanieKsiazki(const Ksiazka baza[], int rozmiar) {
    cout << "Tanie ksiazki (cena < 10 zł):\n";
    for (int i = 0; i < rozmiar; ++i) {
        if (baza[i].cena < 10.0f) {
            cout << baza[i].tytul << " (Cena: " << baza[i].cena << " zł)\n";
        }
    }
}

// Funkcja wyświetlająca nazwy niewypożyczonych książek z ilością stron > 50
void wyswietlNiewypozyczoneWiekszeNiz50(const Ksiazka baza[], int rozmiar) {
    cout << "Niewypozyczone ksiazki z iloscia stron > 50:\n";
    for (int i = 0; i < rozmiar; ++i) {
        if (!baza[i].wypozyczona && baza[i].liczbaStron > 50) {
            cout << baza[i].tytul << "\n";
        }
    }
}

// Funkcja wyświetlająca koszt jednej strony książki
void wyswietlKosztJednejStrony(const Ksiazka baza[], int rozmiar) {
    cout << "Koszt jednej strony dla kazdej ksiazki:\n";
    for (int i = 0; i < rozmiar; ++i) {
        float kosztJednejStrony = baza[i].cena / baza[i].liczbaStron;
        cout << baza[i].tytul << ": " << kosztJednejStrony << " zł/strona\n";
    }
}

// Funkcja wyświetlająca wszystkie książki zaczynające się na literę 'K'
void wyswietlKsiazkiZaczynajaceSieNaK(const Ksiazka baza[], int rozmiar) {
    cout << "Ksiazki zaczynajace sie na litere 'K':\n";
    for (int i = 0; i < rozmiar; ++i) {
        if (baza[i].tytul[0] == 'K' || baza[i].tytul[0] == 'k') {
            cout << baza[i].tytul << "\n";
        }
    }
}

// Funkcja eksportująca bazę do pliku
void eksportujDoPliku(const Ksiazka baza[], int rozmiar, const string& nazwaPliku) {
    ofstream plik(nazwaPliku);
    if (plik.is_open()) {
        for (int i = 0; i < rozmiar; ++i) {
            plik << baza[i].tytul << ";" << baza[i].autor << ";" << baza[i].indeks << ";"
                 << baza[i].cena << ";" << baza[i].liczbaStron << ";" << baza[i].wypozyczona << "\n";
        }
        cout << "Dane zostaly wyeksportowane do pliku: " << nazwaPliku << "\n";
        plik.close();
    } else {
        cout << "Blad przy eksportowaniu do pliku!\n";
    }
}

// Funkcja importująca bazę z pliku
void importujZPliku(Ksiazka baza[], int rozmiar, const string& nazwaPliku) {
    ifstream plik(nazwaPliku);
    if (plik.is_open()) {
        for (int i = 0; i < rozmiar; ++i) {
            getline(plik, baza[i].tytul, ';');
            getline(plik, baza[i].autor, ';');
            plik >> baza[i].indeks;
            plik.ignore();  // Ignoruj znak nowej linii pozostawiony po cin
            plik >> baza[i].cena;
            plik.ignore();
            plik >> baza[i].liczbaStron;
            plik.ignore();
            plik >> baza[i].wypozyczona;
            plik.ignore();
        }
        cout << "Dane zostaly zaimportowane z pliku: " << nazwaPliku << "\n";
        plik.close();
    } else {
        cout << "Blad przy importowaniu z pliku!\n";
    }
}

int main() {
    const int rozmiarBazy = 100;
    Ksiazka baza[rozmiarBazy];

    // (a) Wczytaj dane o książkach
    wczytajBaze(baza, rozmiarBazy);

    // (a) Wyświetl zawartość bazy
    wyswietlBaze(baza, rozmiarBazy);

    // (b) Wyświetl tanie książki (cena < 10 zł)
    wyswietlTanieKsiazki(baza, rozmiarBazy);

    // (c) Wyświetl nazwy niewypożyczonych książek z ilością stron > 50
    wyswietlNiewypozyczoneWiekszeNiz50(baza, rozmiarBazy);

    // (d) Wyświetl koszt jednej strony książki
    wyswietlKosztJednejStrony(baza, rozmiarBazy);

    // (e) Wyświetl wszystkie książki zaczynające się na literę 'K'
    wyswietlKsiazkiZaczynajaceSieNaK(baza, rozmiarBazy);

    // (f) Eksportuj dane do pliku
    eksportujDoPliku(baza, rozmiarBazy, "baza_ksiazek.txt");

    // (f) Importuj dane z pliku
    importujZPliku(baza, rozmiarBazy, "baza_ksiazek.txt");

    return 0;
}
