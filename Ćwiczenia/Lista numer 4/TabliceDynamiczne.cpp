#include <iostream>

float* utworzIWypelnijTablice(int rozmiar) {
    float* dynamicznaTablica = new float[rozmiar]; 
    for (int i = 0; i < rozmiar; ++i) {
        dynamicznaTablica[i] = 0.0; 
    }
    return dynamicznaTablica;
}

void wyswietlTablice(const float* tablica, int rozmiar) {
    std::cout << "Zawartość tablicy:\n";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << "\n";
}

void zwolnijPamiec(float* tablica) {
    delete[] tablica; 
}

int main() {
    int rozmiarTablicy;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> rozmiarTablicy;

    float* mojaTablica = utworzIWypelnijTablice(rozmiarTablicy);

    wyswietlTablice(mojaTablica, rozmiarTablicy);

    zwolnijPamiec(mojaTablica);

    return 0;
}
