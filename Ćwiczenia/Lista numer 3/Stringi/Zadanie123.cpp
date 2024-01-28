#include<iostream>
using namespace std;

void clear(char *napis)
{
	for (int i = 0; i < 100; i++)
	{
		napis[i] = ' ';
	}
	
}

int dlugosc(char* napis)
{
	int counter = 0;
	for (int i = 0; napis[i]; i++)
		counter++;
	return counter;
}
int porownaj(std::string& napis1, std::string& napis2) {
    if (napis1 == napis2) {
        return 1; 
    } else {
        return 0; 
    }
}
int main()
{
	char napis[100];
	clear(napis);
	cin >> napis;
	cout << dlugosc(napis);

}
