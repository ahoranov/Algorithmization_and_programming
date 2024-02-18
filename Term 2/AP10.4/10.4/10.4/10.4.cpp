// 10.4.cpp
// < Горанов Анастас >
// Лабораторна робота № 10.4
// Опрацювання рядків текстового файлу
// Варіант 10

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void Create(char* filename);
void Print(char* filename);
void count(char* filename, char* ofilename);
bool Same(string r);

int main() {

	int choice;
	char filename[101];

	do {
		cout << "--------------------------\n";
		cout << "Menu\n";
		cout << "[1] - Enter and save information\n";
		cout << "[2] - Load and display information\n";
		cout << "[3] - Get line count\n";
		cout << "[0] - Quit\n";
		cout << "--------------------------\n";
		cout << "Choose: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Entering and saving:\n";
			cin.get();
			cin.sync();
			cout << "Enter a file name: "; cin.getline(filename, sizeof(filename));
			Create(filename);
			break;

		case 2:
			cout << "Output of information:\n";
			cin.get();
			cin.sync();
			cout << "Enter a file name: "; cin.getline(filename, sizeof(filename));
			Print(filename);
			break;

		case 3:
			cin.get();
			cin.sync();
			char ofilename[101];
			cout << "Enter a file name: "; cin.getline(filename, sizeof(filename));
			cout << "Enter the name of the file to display the information: "; cin.getline(ofilename, sizeof(ofilename));
			count(filename, ofilename);
			break;

		case 0:
			break;

		default:
			cout << "--------------------------\n";
			cout << "Menu\n";
			cout << "[1] - Enter and save information\n";
			cout << "[2] - Load and display information\n";
			cout << "[3] - Get line count\n";
			cout << "[0] - Quit\n";
			cout << "--------------------------\n";
			cout << "Choose:";
			cin >> choice;
		}
	} while (choice != 0);
}

void Create(char* filename)
{
	ofstream f(filename);
	if (!f)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}

	char ch;
	char r[101];
	do
	{
		cout << endl;
		cout << "Choose line: "; cin.sync();
		cin >> r; cout << endl;

		if (!f.write((char*)&r, sizeof(r)))
		{
			cerr << "Error writing to file." << endl;
		}

		cout << "Continue? (Y/N) "; cin >> ch;
	} while (ch == 'Y' || ch == 'y');
	f.close();
}

void Print(char* filename)
{

	ifstream f(filename);
	char r[101];
	if (!f)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}

	while (f.read((char*)&r, sizeof(r)))
	{
		cout << endl;
		cout << r;
	}
	cout << endl;

	f.close();
}

bool Same(string s) {
	int s1 = 0; int s2 = 1;
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[s1] != s[s2])
			return false;
		s1++; s2++;
	}

	return true;
}


void count(char* filename, char* ofilename)
{
	fstream f(filename, ios::in | ios::binary);
	if (!f)
	{
		cerr << "Error opening file '" << filename << "'" << endl;
		return;
	}

	int first = 0; int first_and_last = 0; int same = 0; int empty = 0;

	string symbol;
	char s[101];

	cout << "Enter the first symbol: "; cin.sync(); cin >> symbol; cout << endl;
	cin.sync();

	while (f.read((char*)&s, sizeof(s)))
	{
		if (s[0] == symbol[0])
			first++;
		else if (Same(s) == true)
			same++;
		else if (s[0] == s[strlen(s) - 1])
			first_and_last++;
		else if (s[0] == '\0')
			empty++;
	}

	f.close();
	ofstream out(ofilename);

	out << "-----------------------------------\n";
	out << first << " - First symbol \n";
	out << first_and_last << " - The first and the last \n";
	out << same << " - A line of identical characters \n";
	out << empty << " - Empty line \n";

	out.close();
	string outp;
	ifstream out_print(ofilename);

	while (getline(out_print, outp)) {
		cout << outp << '\n';
	}
}
