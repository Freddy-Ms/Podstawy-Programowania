#include <iostream>
#include<stdio.h>

using namespace std;
int main()
{
	//zad1
	cout << "Maciej Skrzypa" << endl << "Informatyczne Systemy Automatyki" << endl << "272598" << endl;
	//zad2
	cout << "Podaj liczbe calkowita i zmiennoprzecinkowa:" << endl;
	int x;
	double y;
	cin >> x >> y;
	cout << "Wprowadzona liczba calkowita: " << x << endl << "Wprowadzona liczba zmiennoprzecinkowa: " << y << endl;
	//zad3 i zad4
	printf("Liczba calkowita : %5d\n", x);
	printf("Liczba calkowita : %010d\n", x);
	printf("Liczba zmiennoprzecinkowa z precyzja 3 miejsc po przecinku: %4.3f\n", y);
	printf("Liczba zmiennoprzecinkowa %e\n ", y);
	int i;
	float c;
	printf("Podaj liczbe calkowita:\n");
	scanf_s("%x", &i);
	printf("Wprowadziles %#x (%d).\n", i, i);
	printf("Podaj liczbe zmiennoprzecinkowa:\n");
	scanf_s("%f", &c);
	printf("Wprowadzona liczba zmiennoprzecinkowa:%4.2e %.2f\n", c, c);
	
}