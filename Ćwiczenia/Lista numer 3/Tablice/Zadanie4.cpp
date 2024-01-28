#include <iostream>
using namespace std;


int main()
{
    cout << "Podaj liczbe wierszy i kolumn w macierzy (max 3x3)" << endl;
    int wiersz, kolumna;
    cin >> wiersz >> kolumna;
    int tab[3][3];
    for (int i = 0; i < wiersz; i++)
    {
        for (int j = 0; j < kolumna; j++)
        {
            cout << "Podaj liczbe - " << i+1 << "wiersz, " << j+1 << " kolumna" <<   endl;
            cin >> tab[i][j];
        }
    }
    for (int i = 0; i < wiersz; i++)
    {
      
        for (int j = 0; j < kolumna; j++)
        {
            cout << tab[i][j];
        }
        cout << "\n";
    }
    int transpon[3][3];
    for (int i = 0; i < wiersz; i++)
    {
        for (int j = 0; j < kolumna; j++)
        {
            transpon[j][i] = tab[i][j];
        }
    }
    for (int i = 0; i < wiersz; i++)
    {

        for (int j = 0; j < kolumna; j++)
        {
            cout << transpon[i][j];
        }
        cout << "\n";
    }
    int wyznacznik = 0;
    wyznacznik = transpon[0][0] * transpon[1][1] * transpon[2][2] + transpon[1][0] * transpon[2][1] * transpon[0][2] + transpon[2][0] * transpon[0][1] * transpon[1][2] -
        transpon[0][2] * transpon[1][1] * transpon[2][0] - transpon[1][2] * transpon[2][1] * transpon[0][0] - transpon[2][2] * transpon[0][1] * transpon[1][0];
    cout << wyznacznik << endl;
}