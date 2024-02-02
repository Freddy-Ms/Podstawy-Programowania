#include <iostream>

using namespace std;

struct ElementStosu {
    int wartosc;
    ElementStosu* poprzedni; 
};

struct Stos {
    ElementStosu* wierzcholek; 
};

void inicjujStos(Stos& stos) {
    stos.wierzcholek = nullptr; 
}

void push(Stos& stos, int wartosc) {
    ElementStosu* nowyElement = new ElementStosu; 
    nowyElement->wartosc = wartosc;
    nowyElement->poprzedni = stos.wierzcholek; 
    stos.wierzcholek = nowyElement; 
}

void pop(Stos& stos) {
    if (stos.wierzcholek != nullptr) {
        ElementStosu* doUsuniecia = stos.wierzcholek; 
        stos.wierzcholek = stos.wierzcholek->poprzedni; 
        delete doUsuniecia; 
    } else {
        cout << "Stos jest pusty. Nie mozna usunac elementu.\n";
    }
}

void wyswietlStos(const Stos& stos) {
    ElementStosu* aktualny = stos.wierzcholek;
    cout << "Zawartosc stosu:\n";
    while (aktualny != nullptr) {
        cout << aktualny->wartosc << "\n";
        aktualny = aktualny->poprzedni;
    }
}

void zwolnijStos(Stos& stos) {
    while (stos.wierzcholek != nullptr) {
        pop(stos); 
    }
}

int main() {
    Stos mojStos;

    inicjujStos(mojStos);

    push(mojStos, 10);
    push(mojStos, 20);
    push(mojStos, 30);

    wyswietlStos(mojStos);

    pop(mojStos);

    wyswietlStos(mojStos);

    zwolnijStos(mojStos);

    return 0;
}
