// 9.1.2.cpp
// < Горанов Анастас >
// Лабораторна робота № 9.1.2
// Послідовний пошук в масиві структур
// Варіант 10

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

enum Specialnist { KN, ME, IN, FI, TN };
string specialnistList[] = { "KN", "ME", "IN", "FI", "TN" };
struct Student
{
	string surname;
	int course;
	Specialnist spec;
	int fiz;
	int mat;
	union
	{
		int prog;
		int chis_metod;
		int pedagog;
	};
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
double percent(Student* p, const int N);

int main()
{

	int N;
	cout << "Type the number of students: "; cin >> N;
	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);

	cout << "The percentage of students who have 5 in physics and math: " << percent(p, N) << "%" << endl;
	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "Surname: "; getline(cin, p[i].surname);
		cout << "Course: "; cin >> p[i].course;
		cout << "Grades in physics: "; cin >> p[i].fiz;
		cout << "Grades in math: "; cin >> p[i].mat;
		cout << "A specialty (0 - KN, 1 - ME, 2 - IN, 3 - FI, 4 - TN): ";  cin >> spec;
		if (spec > 4) {
			cout << "Wrong value, selected 2 (IN)" << endl;
			spec = 2;
		}

		p[i].spec = (Specialnist)spec;
		switch (p[i].spec)
		{
		case KN:
			cout << "Grades in programming: "; cin >> p[i].prog;
			break;
		case ME:
			cout << "Grades in pedagogy: "; cin >> p[i].pedagog;
			break;
		case IN:
			cout << "Grades in num.methods: "; cin >> p[i].chis_metod;
			break;
		case FI:
			cout << "Grades in pedagogy: "; cin >> p[i].pedagog;
			break;
		case TN:
			cout << "Grades in pedagogy: "; cin >> p[i].pedagog;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "==========================================================================================================="
		<< endl;
	cout << "| # | Surname | Course | Specilization | Physic | Mathematic | Programming | Numerical Methods | Pedagogy |"
		<< endl;
	cout << "-----------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(8) << left << p[i].surname
			<< "| " << setw(4) << right << p[i].course << "  "
			<< " | " << setw(14) << left << specialnistList[p[i].spec]
			<< setw(4) << "| " << setw(3) << left << p[i].fiz << "  "
			<< setw(6) << "| " << setw(6) << left << p[i].mat << " ";
		switch (p[i].spec)
		{
		case KN:
			cout << setw(8) << "| " << setw(5) << left << p[i].prog << setw(21)
				<< " | " << setw(10) << left
				<< "| " << left << " |" << endl;
			break;
		case ME:
			cout << "" << setw(13) << "| " << " "
				<< "" << setw(20) << "| "
				<< setw(6) << "| " << setw(4) << left << p[i].pedagog << " |" << endl;
			break;
		case IN:
			cout << "" << setw(13) << "| " << setw(10) << " |" << " "
				<< setw(9) << p[i].chis_metod << " |" << " "
				<< setw(8) << "" << " |" << endl;
			break;
		case FI:
			cout << "" << setw(13) << "| " << " "
				<< "" << setw(20) << "| "
				<< setw(6) << "| " << setw(4) << left << p[i].pedagog << " |" << endl;
			break;
		case TN:
			cout << "" << setw(13) << "| " << " "
				<< "" << setw(20) << "| "
				<< setw(6) << "| " << setw(4) << left << p[i].pedagog << " |" << endl;
			break;
		}
	}
	cout << "==========================================================================================================="
		<< endl;
	cout << endl;
}

double percent(Student* p, const int N)
{
	double k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].mat == 5 && p[i].fiz == 5)
			k++;
	}
	return k / N * 100;
}
