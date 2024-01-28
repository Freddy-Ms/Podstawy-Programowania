#include <iostream>
#include <string>

std::string arabicToRoman(int num) {
    if (num <= 0 || num >= 4000) {
        return "Nieobsługiwana liczba";
    }

    std::string result = "";

    // Definicje tablicy znaków rzymskich
    const char* romanNumerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    const int arabicValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    // Konwersja liczby arabskiej na rzymską
    for (int i = 0; i < 13; ++i) {
        while (num >= arabicValues[i]) {
            result += romanNumerals[i];
            num -= arabicValues[i];
        }
    }

    return result;
}

int main() {
    int arabicNumber;

    // Wprowadzanie liczby arabskiej z przedziału 0-3999
    std::cout << "Podaj liczbe arabska (0-3999): ";
    std::cin >> arabicNumber;

    // Konwersja i wyświetlenie wyniku
    std::string romanNumber = arabicToRoman(arabicNumber);
    std::cout << "Liczba rzymska: " << romanNumber << std::endl;

    return 0;
}
