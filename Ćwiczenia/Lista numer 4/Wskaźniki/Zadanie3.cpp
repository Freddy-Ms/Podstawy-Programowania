#include <iostream>
using namespace std;
void ZerujWieksze(int* pierwszy, int* ostatni, int wartosc) {
    for (int* ptr = pierwszy; ptr <= ostatni; ++ptr) {
        if (*ptr > wartosc) {
            *ptr = 0;  
        }
    }
}

int main() {
    const int rozmiar = 5;
    int tablica[rozmiar] = {10, 5, 8, 12, 3};
    
    cout << "Tablica przed wywołaniem funkcji ZerujWieksze:\n";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << "\n";

    
    ZerujWieksze(tablica, tablica + rozmiar - 1, 8);

    cout << "Tablica po wywołaniu funkcji ZerujWieksze:\n";
    for (int i = 0; i < rozmiar; ++i) {
        cout << tablica[i] << " ";
    }
    cout << "\n";

    return 0;
}
