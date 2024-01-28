#include<iostream>
#include<string>
using namespace std;
int Bledy(string&t, string& s)
{
	int counter = 0;
	for (int i = 0; i < t.length(); i++)
	{
		
		if (t[i] == s[i])
			continue;
		counter++;
	}
	return counter;
}

int main()
{
	cout << "Nauczyciel: " << endl;
	string teacher;
	getline(cin, teacher);
	cout << teacher.length();
	cout << "Student:" << endl;
	string student;
	getline(cin, student);
	cout << "Ilosc bledow wynosi - " << Bledy(teacher, student) << endl;
}