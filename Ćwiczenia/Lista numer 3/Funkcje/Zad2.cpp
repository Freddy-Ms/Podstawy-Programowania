#include <iostream>


int fibonacci(int n) {
    if (n <= 0) {
        std::cerr << "Podaj liczbe dodatnia do obliczenia n-tego elementu ciagu Fibonacciego." << std::endl;
        return -1;  
    }

    if (n == 1 || n == 2) {
        return 1;  
    }

    int a = 1, b = 1, wynik = 0;


    for (int i = 3; i <= n; ++i) {
        wynik = a + b;
        a = b;
        b = wynik;
    }

    return wynik;
}
int fibonacci_rec(int n) {
    if (n <= 0) {
        std::cerr << "Podaj liczbe dodatnia do obliczenia n-tego elementu ciagu Fibonacciego." << std::endl;
        return -1;  
    }

    if (n == 1 || n == 2) {
        return 1; 
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {

    int n;
    std::cout << "Podaj numer elementu ciagu Fibonacciego: ";
    std::cin >> n;

    int wynik = fibonacci(n);

    if (wynik != -1) {
        std::cout << "Element " << n << "-ty ciagu Fibonacciego to: " << wynik << std::endl;
    }

    return 0;
}
