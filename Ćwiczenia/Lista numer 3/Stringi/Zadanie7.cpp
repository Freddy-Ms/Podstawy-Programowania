#include <iostream>


std::string usunSpacjeNaKoncach(const std::string& tekst) {

    size_t poczatek = 0;
    while (poczatek < tekst.length() && (tekst[poczatek] == ' ' || tekst[poczatek] == '\t' || tekst[poczatek] == '\n' || tekst[poczatek] == '\r')) {
        ++poczatek;
    }


    size_t koniec = tekst.length() - 1;
    while (koniec > poczatek && (tekst[koniec] == ' ' || tekst[koniec] == '\t' || tekst[koniec] == '\n' || tekst[koniec] == '\r')) {
        --koniec;
    }


    if (poczatek > koniec) {
        return "";
    }


    return tekst.substr(poczatek, koniec - poczatek + 1);
}

int main() {

    std::string tekst = "   To jest przykładowy tekst z początkowymi i końcowymi spacjami.   ";
    
    std::string wynik = usunSpacjeNaKoncach(tekst);
    
    std::cout << "Przed: '" << tekst << "'" << std::endl;
    std::cout << "Po:    '" << wynik << "'" << std::endl;

    return 0;
}
