#include<iostream>
#include<limits.h>

using namespace std;
int a, b;
int i = 1;
float wynik = 1;
float rozstep()
{
	float min = INT_MAX;
	float max = INT_MIN;
	float liczba;
	float rozstep = 0;
	cout << "Podaj liczby. 0 - konczy wpisywanie liczb." << endl;
	cin >> liczba;
	while(liczba!=0)
	{
		
		if (liczba > max)
			max = liczba;
		if (liczba < min)
			min = liczba;
		cin >> liczba;
	}
	rozstep = (max - min);
	return rozstep;
	
}
int potega()
{
	cout << "Podaj liczbe oraz jej potege." << endl;
	cin >> a >> b;
	wynik = 1;
	i = 1;
	if (a == 1)
		return a;

	if (b == 0)
		return 1;
	for (i; i <= b; i++)
		wynik *= a;
	
return wynik;
}

int main()
{
	//cout << rozstep() << endl;
	cout << potega() << endl;
	cout << potega() << endl;
}
