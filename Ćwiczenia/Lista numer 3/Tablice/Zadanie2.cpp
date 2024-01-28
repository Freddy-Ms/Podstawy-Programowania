#include <iostream>
#include <algorithm>

// Funkcja obliczająca sumę i średnią arytmetyczną
void sumaISrednia(const int tablica[], int rozmiar, int& suma, double& srednia) {
    suma = 0;

    for (int i = 0; i < rozmiar; ++i) {
        suma += tablica[i];
    }

    srednia = static_cast<double>(suma) / rozmiar;
}

// Funkcja sprawdzająca porządek rosnący/malejący
bool czyRosnace(const int tablica[], int rozmiar) {
    for (int i = 1; i < rozmiar; ++i) {
        if (tablica[i - 1] > tablica[i]) {
            return false;  // Nie jest rosnące
        }
    }
    return true;  // Jest rosnące
}

bool czyMalejace(const int tablica[], int rozmiar) {
    for (int i = 1; i < rozmiar; ++i) {
        if (tablica[i - 1] < tablica[i]) {
            return false;  // Nie jest malejące
        }
    }
    return true;  // Jest malejące
}

// Funkcja sprawdzająca symetryczność
bool czySymetryczne(const int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar / 2; ++i) {
        if (tablica[i] != tablica[rozmiar - i - 1]) {
            return false;  // Nie jest symetryczne
        }
    }
    return true;  // Jest symetryczne
}

// Funkcja sprawdzająca czy elementy się powtarzają
bool czyPowtarzajaSie(const int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = i + 1; j < rozmiar; ++j) {
            if (tablica[i] == tablica[j]) {
                return true;  // Znaleziono powtórzoną wartość
            }
        }
    }
    return false;  // Nie ma powtórzeń
}


void przesunWGore(int tablica[], int rozmiar) {
    if (rozmiar <= 1) {
        // Nie ma potrzeby przesuwania, gdy mamy zero lub jedną liczbę
        return;
    }

    int temp = tablica[rozmiar - 1];

    for (int i = rozmiar - 1; i > 0; --i) {
        tablica[i] = tablica[i - 1];
    }

    tablica[0] = temp;
}


void odwrocKolejnosc(int *tablica, int rozmiar) {
	for (int i = 0; i < (rozmiar / 2); i++)
	{
		int help;
		help = tab[i];
		tab[i] = tab[rozmiar - i-1];
		tab[rozmiar - i - 1] = help;

	}
}


void sortowanieBabelkowe(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tablica[j] > tablica[j + 1]) {
                std::swap(tablica[j], tablica[j + 1]);
            }
        }
    }
}

int main() {
    const int rozmiar = 10;
    int tablica[rozmiar];

 
    std::cout << "Podaj 10 kolejnych cyfr oddzielonych spacją: ";
    for (int i = 0; i < rozmiar; ++i) {
        std::cin >> tablica[i];
    }


    int suma;
    double srednia;

    sumaISrednia(tablica, rozmiar, suma, srednia);

    std::cout << "a) Suma: " << suma << ", Srednia: " << srednia << std::endl;
    std::cout << "b) " << (czyRosnace(tablica, rozmiar) ? "Rosnace" : "Nie rosnace") << std::endl;
    std::cout << "   " << (czyMalejace(tablica, rozmiar) ? "Malejace" : "Nie malejace") << std::endl;
    std::cout << "c) " << (czySymetryczne(tablica, rozmiar) ? "Symetryczne" : "Nie symetryczne") << std::endl;
    std::cout << "d) " << (czyPowtarzajaSie(tablica, rozmiar) ? "Powtarzaja sie" : "Nie powtarzaja sie") << std::endl;


    przesunWGore(tablica, rozmiar);
    std::cout << "e) Po przesunieciu w gore: ";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;


    odwrocKolejnosc(tablica, rozmiar);
    std::cout << "f) Po odwroceniu kolejnosci: ";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;

    sortowanieBabelkowe(tablica, rozmiar);
    std::cout << "g) Po sortowaniu babelkowym: ";
    for (int i = 0; i < rozmiar; ++i) {
        std::cout << tablica[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
