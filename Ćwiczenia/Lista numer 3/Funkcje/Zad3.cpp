#include <iostream>
#include <string>

std::string jednosci[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
std::string nastki[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
std::string dziesiatki[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
std::string setki[] = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};

std::string numberToWords(unsigned int num) {
    if (num == 0) {
        return "Zero";
    }

    std::string result;


    result += jednosci[num % 10];


    if (num >= 10 && num <= 19) {
        result = nastki[num % 10];
    }


    else if (num >= 20 && num <= 99) {
        result = dziesiatki[num / 10] + " " + result;
    }


    else if (num >= 100 && num <= 999) {
        result = setki[num / 100] + " " + result;
    }

    return result;
}

int main() {
    unsigned int liczba;
    std::cout << "Podaj liczbe (0 - 4294967295): ";
    std::cin >> liczba;

    if (liczba > 4294967295) {
        std::cerr << "Liczba przekracza zakres (0 - 4294967295)." << std::endl;
        return 1;
    }

    std::cout << "Słownie: " << numberToWords(liczba) << std::endl;

    return 0;
}
