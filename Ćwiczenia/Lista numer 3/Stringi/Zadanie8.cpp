#include <iostream>

bool czyPalindrom(const std::string& wyraz) {

    int dlugosc = wyraz.length();


    for (int  i = 0; i < dlugosc / 2; ++i) {

        if (std::tolower(wyraz[i]) != std::tolower(wyraz[dlugosc - 1 - i])) {
            return false;
        }
    }

    return true; 
}

int main() {

    std::string wyraz;

    std::cout << "Podaj wyraz do sprawdzenia: ";
    std::cin >> wyraz;

    if (czyPalindrom(wyraz)) {
        std::cout << "To jest palindrom." << std::endl;
    } else {
        std::cout << "To nie jest palindrom." << std::endl;
    }

    return 0;
}
