#include<iostream>
#include<limits>
#include <limits.h>
using namespace std;
void Wczytaj(int* tab, int ile)
{
	for (int i = 0; i < ile; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe." << endl;
		cin >> tab[i];
	}
}
void Wyswietl(int* tab, int ile)
{
	for (int i = 0; i < ile; i++)
		cout << tab[i] << endl;
}
void wPrawo(int* tab, int ile)
{
	int last;
	last = tab[ile - 1];
	for (int i = ile - 1; i > 0; i--)
	{
		tab[i] = tab[i - 1];
	}
	tab[0] = last;
}
void Zadanie2(int* max, int* counter, int ile)
{
	int liczba;
	int counterwew;
	*max = INT_MIN;
	*counter = 0;
	for (int i = 0; i < ile; i++)
	{
		counterwew = 0;
		cout << "Podaj " << i + 1 << " liczbe." << endl;
		cin >> liczba;
		if (*max < liczba)
			*max = liczba;
		for (int j = 1; j <= liczba; j++)
		{
			if (liczba % j == 0)
				counterwew++;
		}
		if (counterwew == 2)
			*counter = *counter + 1;
	}
}

int main()
{
	int tab[10];
	cout << "Ile liczb mam wczytac? (10 max)" << endl;
	int n;
	do
	{
		cin >> n;
	} while (n < 0 || n>10);
	Wczytaj(tab, n);
	Wyswietl(tab, n);
	cout << "_____________________" << endl;
	wPrawo(tab, n);
	Wyswietl(tab, n);
	cout << "_______________" << endl;
	wPrawo(tab, n);
	Wyswietl(tab, n);
	
	int max;
	int lpcounter;
	cout << "Podaj ilosc wpisywanych liczb.";
	int x;
	cin >> x;
	Zadanie2(&max, &lpcounter, x);
	cout << "Liczba max: " << max << endl;
	cout << "Ilosc liczb pierwszych: " << lpcounter << endl;
	Zadanie2(&max, &lpcounter, x);
	cout << "Liczba max: " << max << endl;
	cout << "Ilosc liczb pierwszych: " << lpcounter << endl;

}