#include <iostream>
#include <malloc.h>
using namespace std;
void usuwanie(char a[], char b[])
{
	int sizea = strlen(a);
	int sizeb = strlen(b);
	for (int i = 0; i < sizeb; i++)
	{
		for (int j = 0; j < sizea; j++)
		{
			if (a[j] == b[i])
			{
				for (int z = j; z < sizea; z++)
					a[z] = a[z + 1];
				j--;
			}
		}
	}
}
			
int* doklejenie(int* t1, int sizet1, int* t2, int sizet2)
{
	int* Tablica = new int[sizet1 + sizet2];
	int i = 0;
	for (int j = 0; j < sizet1; j++)
	{
		Tablica[i] = t1[j];
		i++;
	}
	for (int j = 0; j < sizet2; j++)
	{
		Tablica[i] = t2[j];
		i++;
	}
	delete[] t1;
	delete[] t2;
	return Tablica;
}
int main()
{
	char lok[] = "ala ma kota";
	char usun[] = "ak";
	usuwanie(lok, usun);
	cout << lok << endl;
	char* s1 = new char[64];
	//char* s1 = (char*)malloc(64);
	char* s2 = new char[64];
	//char* s2 = (char*)malloc(64);
	cout << "Podaj lancuch znakow:" << endl;
	cin >> s1;
	cout << "Podaj znaki jakie mam usunac." << endl;
	cin >> s2;
	usuwanie(s1, s2);
	cout << s1 << endl;
	delete[] s1;     
	// free(s1);
	delete[] s2;     
	// free(s2);

	cout << " Ile elementow w tablicy?" << endl;
	int x;
	cin >> x;
	int* tablica1 = new int[x];
	for (int i = 0; i < x; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe." << endl;
		cin >> tablica1[i];
	}
	cout << "Ile elementow w tablicy?" << endl;
	int y;
	cin >> y;
	int* tablica2 = new int[y];
	for (int i = 0; i < y; i++)
	{
		cout << "Podaj " << i + 1 << " liczbe." << endl;
		cin >> tablica2[i];
	}
	int* newTab = doklejenie(tablica1, x, tablica2, y);
	for (int i = 0; i < x + y; i++)
		cout << newTab[i] << " ";
	delete[] newTab;
}