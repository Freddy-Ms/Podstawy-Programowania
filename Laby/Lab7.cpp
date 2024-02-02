#include<iostream>
using namespace std;
int tab[2][3]={{3,4,2},{6,2,5}};

int Cmax(int x, int y)
{
	if (x == 0 && y == 0)
		return tab[0][0];                     // 1,1 return 11
	if (x == 0)
		return tab[x][y] + Cmax(x, y-1);
	if (y == 0)
		return tab[x][y] + Cmax(x-1, y);
	return tab[x][y] + max(Cmax(x-1, y), Cmax(x,y-1));
}
struct wartosc {
	int a;
	wartosc* nextpos;
};
struct Lista {
	wartosc* first;
};
void add(Lista& lista, int position, int value)
{
	wartosc* nowa = new wartosc;
	nowa->nextpos = 0;
	nowa->a = value;
	if (position == 0) 
	{
		nowa->nextpos = lista.first;
		lista.first = nowa;
	}
	else {
		wartosc* war = lista.first;
		for (int i = 0; i < position - 1; i++) {
			war = war->nextpos;
		}
		wartosc* nastepna = war->nextpos;
		nowa->nextpos = war->nextpos;
		war->nextpos = nowa;
	}
}
int usun(Lista& lista, int idx) {
	if (idx == 0) {
		wartosc* wartosc = lista.first;
		lista.first = wartosc->nextpos;
		int help = wartosc->a;
		delete wartosc;
		return help;
	}
	wartosc* xxx = lista.first;
	for (int i = 0; i < idx - 1; i++) {
		xxx = xxx->nextpos;
	}
	wartosc* curr = xxx->nextpos;
	xxx->nextpos = curr->nextpos;
	int help = curr->a;
	delete curr;
	return help;
}
int main()
{
	cout << Cmax(1,1) << endl;
	Lista lista{};
	add(lista, 0, 1);
	add(lista, 1, 2);
	add(lista, 2, 100);
	cout << usun(lista, 2);

}