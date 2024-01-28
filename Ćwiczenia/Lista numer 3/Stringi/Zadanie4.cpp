#include<iostream>
using namespace std;
int size(char* tab)
{
	int counter = 0;
	for (int i = 0; tab[i]; i++)
		counter++;
	return counter;
}
void Konkatenacja(char* napis1, char* napis2, char* kon)
{
	int i = 0;
	for (i; i < size(napis1); i++)
	{
		kon[i] = napis1[i];
	}
	for (int j = 0; j < size(napis2); j++,i++)
		kon[i] = napis2[j];
}
int main()
{
	char* napis1 = new char;
	cout << "Podaj pierwszy wyraz:" << endl;
	cin >> napis1;
	cout << "Podaj drugi wyraz:" << endl;
	char* napis2 = new char;
	cin >> napis2;
	int x = size(napis1) + size(napis2);
	char* kon = new char[x];
	Konkatenacja(napis1, napis2, kon);
	for (int i = 0 ;i < x; i++)
		cout << kon[i];
	free (napis1);
	free (napis2);
	delete [] kon;
}