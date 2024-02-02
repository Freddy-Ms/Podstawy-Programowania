#include<iostream>
#include<fstream>
using namespace std;
struct Pokoj {
	float metraz;
	float wysokoscpowyzej;
	float stan;
	bool uzytkowe;
};
struct Dom {
	int cenam2;
	Pokoj pokoje[5];
	int ilepokoji;
};

float powuzytkowa(Pokoj& a)
{
	if (a.uzytkowe)
		return a.metraz * (a.wysokoscpowyzej / 100);

	return 0;
}
float CenaDomu(Dom& x) {
	float cena = 0;
	for (int i = 0; i < x.ilepokoji; i++)
		cena += powuzytkowa(x.pokoje[i]) * (x.pokoje[i].stan / 100) * x.cenam2;
	
	return cena;
}
void doPliku(Pokoj& a)
{
	ofstream plik;
	plik.open("pokoj.txt");
	plik << a.metraz << endl;
	plik << a.wysokoscpowyzej << endl;
	plik << a.stan << endl;
	plik << a.uzytkowe;
	plik.close();
}
void zPliku(Pokoj& a) {
	ifstream plik;
	plik.open("pokoj.txt");
	plik >> a.metraz;
	plik >> a.wysokoscpowyzej;
	plik >> a.stan;
	plik >> a.uzytkowe;
	plik.close();
}

int main()
{
	Pokoj x;
	x.metraz = 12;
	x.wysokoscpowyzej = 50;
	x.stan = 95;
	x.uzytkowe = 1;
	doPliku(x);
	Pokoj z;
	zPliku(z);
	cout << z.metraz << z.wysokoscpowyzej << z.stan  << endl;
	cout << z.uzytkowe;
	cout << powuzytkowa(z) << endl;
	cout << powuzytkowa(x);
	Dom b;
	b.cenam2 = 10;
	b.pokoje[0].metraz = 15;
	b.pokoje[0].stan = 80;
	b.pokoje[0].uzytkowe = 0;
	b.pokoje[0].wysokoscpowyzej = 88;
	b.pokoje[1].metraz = 25;
	b.pokoje[1].stan = 100;
	b.pokoje[1].uzytkowe = 0;
	b.pokoje[1].wysokoscpowyzej = 88;
	b.pokoje[2].metraz = 12;
	b.pokoje[2].stan = 50;
	b.pokoje[2].uzytkowe = 1;
	b.pokoje[2].wysokoscpowyzej = 50;
	b.ilepokoji = 3;
	cout << endl << endl << CenaDomu(b);

}