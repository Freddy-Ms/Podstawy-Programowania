#include <iostream>
#include <cctype>  

void Histogram(char* word, int size, int* his) {
    int help;
    for (int i = 0; i < size; i++) {

        char lowercaseChar = std::tolower(word[i]);


        if (lowercaseChar >= 'a' && lowercaseChar <= 'z') {
            help = (int)lowercaseChar - 'a';
            his[help] += 1;
        }
    }
}


void clear(int* array) {
    for (int i = 0; i < 26; i++) {
        array[i] = 0;
    }
}


int dlugosc(const char* word) {
    int length = 0;
    while (word[length] != '\0') {
        length++;
    }
    return length;
}


void wyswietl1(const int* array) {
    for (int i = 0; i < 26; i++) {
        std::cout << (char)('a' + i) << ": " << array[i] << std::endl;
    }
}

int main() {
    int his[26];
    clear(his);
    char slowo[100];
    int x = 1;
    do {
        system("cls");
        std::cout << "Podaj zdanie (kazde slowo osobno):" << std::endl;
        std::cin >> slowo;
        std::cout << std::endl;
        int length = dlugosc(slowo);
        Histogram(slowo, length, his);
        wyswietl1(his);
        std::cout << "Jezeli chcesz zakonczyc prace programu wpisz 0, jezeli chcesz kontynuowac wpisz dowolna liczbe." << std::endl;
        std::cin >> x;
    } while (x);
}
