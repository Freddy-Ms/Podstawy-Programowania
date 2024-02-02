#include <iostream>
#include <string>

using namespace std;

struct Osoba {
    string imie;
    string nazwisko;
    int wiek;
    Osoba* poprzedni; 
    Osoba* nastepny; 
};

Osoba* inicjujListe() {
    return nullptr; 
}


Osoba* stworzOsobe(const string& imie, const string& nazwisko, int wiek) {
    Osoba* nowaOsoba = new Osoba;
    nowaOsoba->imie = imie;
    nowaOsoba->nazwisko = nazwisko;
    nowaOsoba->wiek = wiek;
    nowaOsoba->poprzedni = nullptr; 
    nowaOsoba->nastepny = nullptr; 
    return nowaOsoba;
}


Osoba* dodajNaKoniec(Osoba* ogon, Osoba* nowaOsoba) {
    if (ogon == nullptr) {
        return nowaOsoba; 
    }
    ogon->nastepny = nowaOsoba; 
    nowaOsoba->poprzedni = ogon; 
    return nowaOsoba; 
}

void usunElement(Osoba*& glowa, Osoba*& ogon, Osoba* doUsuniecia) {
    if (doUsuniecia == nullptr) {
        return; 
    }
    if (doUsuniecia == glowa) {
        glowa = doUsuniecia->nastepny; 
        if (glowa != nullptr) {
            glowa->poprzedni = nullptr; 
        }
    } else {
        if (doUsuniecia->poprzedni != nullptr) {
            doUsuniecia->poprzedni->nastepny = doUsuniecia->nastepny; 
        }
    }

    if (doUsuniecia == ogon) {
        ogon = doUsuniecia->poprzedni; 
        if (ogon != nullptr) {
            ogon->nastepny = nullptr; 
        }
    } else {
        if (doUsuniecia->nastepny != nullptr) {
            doUsuniecia->nastepny->poprzedni = doUsuniecia->poprzedni; 
        }
    }

    delete doUsuniecia; 
}


void wyswietlListeOdPoczatku(Osoba* glowa) {
    Osoba* aktualny = glowa;
    while (aktualny != nullptr) {
        cout << "Imie: " << aktualny->imie << ", Nazwisko: " << aktualny->nazwisko << ", Wiek: " << aktualny->wiek << "\n";
        aktualny = aktualny->nastepny;
    }
}


void wyswietlListeOdKonca(Osoba* ogon) {
    Osoba* aktualny = ogon;
    while (aktualny != nullptr) {
        cout << "Imie: " << aktualny->imie << ", Nazwisko: " << aktualny->nazwisko << ", Wiek: " << aktualny->wiek << "\n";
        aktualny = aktualny->poprzedni;
    }
}

void zwolnijListe(Osoba*& glowa, Osoba*& ogon) {
    while (glowa != nullptr) {
        Osoba* doUsuniecia = glowa;
        glowa = glowa->nastepny;
        delete doUsuniecia;
    }

    ogon = nullptr; 
}

int main() {
    Osoba* listaGlowa = nullptr;
    Osoba* listaOgon = nullptr;

    Osoba* nowaOsoba1 = stworzOsobe("Jan", "Kowalski", 25);
    Osoba* nowaOsoba2 = stworzOsobe("Anna", "Nowak", 30);
    Osoba* nowaOsoba3 = stworzOsobe("Marek", "Wójcik", 22);

    listaOgon = dodajNaKoniec(listaOgon, nowaOsoba1);
    listaOgon = dodajNaKoniec(listaOgon, nowaOsoba2);
    listaOgon = dodajNaKoniec(listaOgon, nowaOsoba3);

    usunElement(listaGlowa, listaOgon, nowaOsoba2);

    cout << "Lista od poczatku:\n";
    wyswietlListeOdPoczatku(listaGlowa);

    cout << "\nLista od konca:\n";
    wyswietlListeOdKonca(listaOgon);

    zwolnijListe(listaGlowa, listaOgon);

    return 0;
}
