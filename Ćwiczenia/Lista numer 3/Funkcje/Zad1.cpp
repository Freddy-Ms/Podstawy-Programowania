#include <iostream>


void wspolneDzielniki(int liczba1, int liczba2) {

    int mniejszaLiczba = (liczba1 < liczba2) ? liczba1 : liczba2;


    for (int i = 1; i <= mniejszaLiczba; ++i) {

        if (liczba1 % i == 0 && liczba2 % i == 0) {
            std::cout << i << " ";
        }
    }
}

int main() {

    int liczba1, liczba2;
    std::cout << "Podaj dwie liczby: ";
    std::cin >> liczba1 >> liczba2;


    std::cout << "Wspolne dzielniki: ";
    wspolneDzielniki(liczba1, liczba2);
    std::cout << std::endl;

    return 0;
}
