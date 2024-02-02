#include <iostream>
using namespace std;
int main()
{
    char litera = 'a';
    int liczba = 12;
    long longliczba = 42352;

    int *pointer_liczba = &liczba;
    char *pointer_litera = &litera;
    long *pointer_long = &longliczba;


    *pointer_liczba = 15;
    *pointer_litera = 'c';
    *pointer_long = 99999;

    cout << litera << " " << liczba << " " << longliczba;   
}