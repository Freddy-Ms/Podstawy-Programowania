#include<iostream>
#include<string>
using namespace std;
void Szyfrowanie(string& napis, int klucz)
{
	int size = napis.length() - 1;
	klucz = klucz % 26;
	for (int i = 0; i <= size; i++)
	{
		if (napis[i] >= 'A' && napis[i] <= 'Z')
		{
			if (napis[i] + klucz > 'Z')
				napis[i] = napis[i] - 26 + klucz;
			else if (napis[i] + klucz < 'A')
				napis[i] = napis[i] + 26 + klucz;
			else
				napis[i] = napis[i] + klucz;
		}
		if (napis[i] >= 'a' && napis[i] <= 'z')
		{
			if (napis[i] + klucz > 'z')
				napis[i] = napis[i] - 26 + klucz;
			else if (napis[i] + klucz < 'a')
				napis[i] = napis[i] + 26 + klucz;
			else
				napis[i] = napis[i] + klucz;
		}
		if (napis[i] >= '0' && napis[i] <= '9')
		{
			if (napis[i] + klucz > '9')
				napis[i] = napis[i] + klucz - 10;
			else if (napis[i] + klucz < '0')
				napis[i] += klucz + 10;
			else
				napis[i] += klucz;

		}


	}
}
int main(){
	string napis;
	cout << "Podaj napis,ktory chcesz zaszyfrowac." << endl;
	getline(cin, napis);
	int klucz;
	cout << "Podaj klucz szyfrowania." << endl;
	cin >> klucz;
	cout << "Uwaga! Szyfruje napis:" << endl;
	Szyfrowanie(napis, klucz);
	cout << napis << endl;
	cout << "Uwaga! Deszyfracja napisu:" << endl;
	Szyfrowanie(napis, -klucz);
	cout << napis << endl;
}