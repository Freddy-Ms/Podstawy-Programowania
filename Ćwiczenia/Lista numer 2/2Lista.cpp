#include<iostream>
#include<Windows.h>
#include<chrono>
#include<conio.h>
#include<ctime>
using namespace std;

void Zad1()
{
	cout << "Wybierz ocene:" << endl;
	cout << "1\n2\n3\n4\n5\n6\n";
	int ocena;
	cin >> ocena;
	switch (ocena)
	{
	case 1:
		cout << "Niedostateczny" << endl;
		break;
	case 2:
		cout << "Dopuszczajacy" << endl;
		break;
	case 3:
		 cout << "Dostateczny" << endl;
		break;
	case 4:
		cout << "Dobry" << endl;
		break;
	case 5:
		cout << "Bardzo dobry" << endl;
		break;
	case 6:
		cout << "Celujacy" << endl;
		break;
	}
}
void Zad2()
{
	cout << "Kalkulator! Podaj dwie liczby:" << endl;
	float x, y;
	cin >> x >> y;
	cout << "Co chcesz zrobic z wybranymi liczbami?" << endl;
	cout << "1.Dodawanie\n2.Odejmowanie\n3.Dzielenie\n4.Mnozenie" << endl;
	int k;
	cin >> k;
	switch(k)
	{
	case 1:
		cout << x << " + " << y << " = " << x + y;
		break;
	case 2:
		cout << x << " - " << y << " = " << x - y;
		break;
	case 3:
		cout << x << " / " << y << " = " << (x / y);
		break;
	case 4:
		cout << x << " * " << y << " = " << (x * y);
		break;
	}
}
void Zad3() 
{
	int n = 0;
	while (n < 101)
	{
		cout << n << endl;
		n++;
	}
}
void Zad4()
{
	int n = 99;
	while (n > 16)
	{
		cout << n << endl;
		n--;
	}
}
void Zad5()
{
	cout << "Podaj liczbe." << endl;
	int x;
	cin >> x;
	int y = 1;
	while (y<=x)
	{
		if (x % y == 0)
			cout << y << endl;
		y++;
	}
}
void Zad6()
{
	int x = 99;
	cout << "Zgadnij liczbe." << endl;
	int y;
	cin >> y;
	int liczbaprob = 1;
	int counter = 0;
	if (y == x)
		counter++;
	while (x != y)
	{
		if (y <= 5 && y >= -5)
			cout << "Podana liczba jest z zakresu od -5 do 5." << endl;
		if (y % 2 == 1)
			counter++;
		cout << "Try again!" << endl;
		cin >> y;
		liczbaprob++;
	}
	cout << "Udalo sie!" << endl;
	cout << "Liczba prob - " << liczbaprob << endl;
	cout << "Ilosc nieparzystych liczb - " << counter << endl;
}
void Zad7()
{
	cout << "Podaj ilosc sekund." << endl;
	int x;
	cin >> x;
	while (x != 0)
	{
		Sleep(1000);
		system("cls");
		cout << x << endl;
		x--;
	}
	cout << "Czas minal";
}
void Zad8() 
{
	int x = 1;
	do
	{
		cout << x << endl;
		x++;
	} while (x <= 100);
}
void Zad9()
{
	int a;
	int counter = 0;
	int suma = 0;
	int iloczyn = 1;
	do
	{
		cin >> a;
		if (a > 0)
			suma += a;
		if (a % 2 == 1)
			iloczyn = iloczyn * a;
		counter++;
	}
	while (counter != 10);
	cout << suma << endl;
	cout << iloczyn << endl;
}
void Zad10()
{
	int x = 99;
	cout << "Zgadnij liczbe." << endl;
	int a;
	int counter = 0;
	int liczbaprob = 0;
	do
	{
		cin >> a;
		liczbaprob++;
		if (a >= -5 && a <= 5)
			cout << "Podana liczba jest z zakresu -5 do 5." << endl;
		if (a % 2 == 1)
			counter++;
	} while (a != x);
	cout << "Liczba prob: " << liczbaprob << endl;
	cout << "Liczba prob(nieparzystych): " << counter;
}
void Zad11()
{
	cout << "Podaj ilosc sekund." << endl;
	int x;
	cin >> x;
	do
	{
		Sleep(1000);
		system("cls");
		cout << x << endl;
		x--;
	} while (x != 0);
	cout << "Czas minal";
}
void Zad12()
{
	int sec = 0;
	int min = 0;
	int hrs = 0;
	char userInput = 'X';
	time_t timeStart = time(0);
	boolean doWhile = true;
	do
	{
		if (time(0) - timeStart > sec) {
			sec = time(0) - timeStart;
			system("cls");
			cout << "Hours: " << sec/3600 << "  Minutes: " << (sec/60)%60 << "  Seconds: " << sec%60 << endl;
		}
		
		if (_kbhit()) {
			userInput = _getch();
			if (userInput == 'q' || userInput == 'Q') {
				doWhile = false;
			}
		}
	} while (doWhile);
}
void Zad13()
{
	cout << "Podaj liczbe." << endl;
	int x;
	cin >> x;
	int counter = 0;
	cout << "Dzielniki podanej liczby:" << endl;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
			counter++,cout << i << endl;
	}
	if (counter == 2)
		cout << "Podana liczba jest liczba pierwsza." << endl;
	else
		cout << "Podana liczba nie jest liczba pierwsza." << endl;
}

void Zad14()
{
	cout << "Podaj gorny zakres." << endl;
	int x;
	cin >> x;
	int counter = 0;
	for (int i = 1; i <= x; i++) // 3
	{
		for (int j = 2; j < i; j++) // 2
		{
			if (i % j == 0)
				counter++;
		}
		if (counter == 0 && i >1)
			cout << i << endl;
		counter = 0;
	}
}
void Zad15()
{
	cout << "Liczba podzielne przez 13 z zakresu 0 do 10000." << endl;
	for (int i = 13; i < 10000; i += 13)
		cout << i << endl;
}
void Zad16()
{
	cout << "Para punktow spelniajaca rownanie x^2 + y^2 < 1000. Dla x,y nalezacego do przedzialu od 0 do 100" << endl;
	for (int x = 0; x <= 100; x++)
	{
		for (int y = 0; y <= 100; y++)
		{
			if (pow(x, 2) + pow(y, 2) < 1000)
				cout << "(" << x << "," << y << ")" << " ";
		}
	}
}

void Zad17()
{
	cout << "Podaj liczbe potegowana i jej potegnik." << endl;
	int x, n;
	cin >> x >> n;
	int pot = pow(x, n);
	cout << "Wynik: " << pot << endl;
}
void Zad17a()
{
	cout << "Podaj liczbe potegowana i jej potegnik." << endl;
	int x, n;
	int wynik = 1;
	cin >> x >> n;
	for (int i = 1; i <= n; i++)
		wynik *= x;
	cout << "Wynik: " << wynik << endl;
}


int main() 
{
	Zad16();
}