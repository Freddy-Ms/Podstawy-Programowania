#include<iostream>

int main(){
	cout << "Podaj ilosc liczb, ktore bedziesz podawac." << endl;
	int n;
	cin >> n;
	int* tab = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe." << endl;
		cin >> tab[i];
		tab[i] *= tab[i];
		cout << "Podniesiona do kwadratu wynosi - " << tab[i] << endl;
	}
	delete[] tab;

}