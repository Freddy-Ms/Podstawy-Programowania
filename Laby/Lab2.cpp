#include<iostream>
using namespace std;
int main()
{
	//Zadanie 1
	cout << "Podaj pierwszy kat w stopniach." << endl; 
	float stopnie;
	float radiany;
	float r;
	float pi = 3.14;
	cin >> stopnie;
	cout << "Podaj 2gi kat w radianach." << endl;
	cin >> radiany;
	cout << "Podaj promien kola." << endl;
	cin >> r;
	float dl1, dl2;
	dl1 = (stopnie / 360) * 2 * r * pi;
	dl2 = ((radiany * 180) / 360) * 2 * r;
	if (dl1 > dl2)
		cout << dl1 << " " << dl2 << endl;
	else if (dl2 > dl1)
		cout << dl2 << " " << dl1 << endl;
	else if (dl1 == dl2)
		cout << "Dlugosci lukow sa rowne.\n" << dl1 << endl;
	
	// Zadanie2
	cout << "Podaj 2 liczby calkowite." << endl;
	int liczba1, liczba2;
	cin >> liczba1 >> liczba2;
	cout << "Wybierz opcje:\n1.+\n2.-\n3.*\n4./\n5.%" << endl;
	char a;
	cin >> a;
	switch (a)
	{
	case '+':
	{
		cout << liczba1 << " + " << liczba2 << " = " << liczba1 + liczba2 << endl;
		break;
	}
	case '-':
	{
		cout << liczba1 << " - " << liczba2 << " = " << liczba1 - liczba2 << endl;

		break;
	}
	case '*':
	{
		cout << liczba1 << " * " << liczba2 << " = " << liczba1 * liczba2 << endl;

		break;
	}
	case '/':
	{
		if (liczba2 == 0)
			cout << " Nie dziel przez zero" << endl;
		cout << liczba1 << " / " << liczba2 << " = " << liczba1 / liczba2 << endl;
		
		break;
	}
	case '%':
	{
		cout << liczba1 << " % " << liczba2 << " = " << liczba1 % liczba2 << endl;

		break;
	}
	}
	
	//Zadanie 3
	cout << "Podaj przedzial liczbowy. (od do)" << endl;
	int a1, a2, b1, b2;
	cin >> a1 >> b1;
	cout << "Podaj 2gi przdzial liczbowy. (od do)" << endl;
	cin >> a2 >> b2;
	string x;
	x = ((a1 < b2 && a2 < b1) || (b1 < a2 && b2<a1)) ? "Nie." : "Tak.";
	cout << x << endl;
}