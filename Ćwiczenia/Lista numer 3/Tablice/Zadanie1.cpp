#include <iostream>
#include <cstdlib>
#include <ctime>


void wypelnijTabliceLosowymi(int tablica[], int rozmiar) {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));


    for (int i = 0; i < rozmiar; ++i) {
        tablica[i] = std::rand() % 46 - 15;  
    }
}


void wyswietlTablice(const int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int n;
    std::cout << "Podaj rozmiar tablicy: ";
    std::cin >> n;


    int* mojaTablica = new int[n];


    wypelnijTabliceLosowymi(mojaTablica, n);


    std::cout << "Tablica liczb losowych: ";
    wyswietlTablice(mojaTablica, n);


    delete[] mojaTablica;

    return 0;
}
