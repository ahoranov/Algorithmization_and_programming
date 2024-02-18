// 10.3.cpp
// < Горанов Анастас >
// Лабораторна робота № 10.3
// Опрацювання текстового файлу
// Варіант 10

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cassert>

using namespace std;

struct route
{
    int nomer;
    char start[30];
    char end[30];
};

void Print(const string& filename);
void Create(const string& filename);
void Search(const string& filename);

int main() {
    int choice;
    string filename;

    do {
        cout << "--------------------------\n";
        cout << "Menu\n";
        cout << "[1] - Enter and save information\n";
        cout << "[2] - Load and display information\n";
        cout << "[3] - Search by route number\n";
        cout << "[0] - Exit\n";
        cout << "--------------------------\n";
        cout << "Select: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Entering and saving:\n";
            cin.ignore();
            cout << "Enter a file name: ";
            getline(cin, filename);
            Create(filename);
            break;

        case 2:
            cout << "Information output:\n";
            cin.ignore();
            cout << "Enter a file name: ";
            getline(cin, filename);
            Print(filename);
            break;

        case 3:
            cout << "Search by route number:\n";
            cin.ignore();
            cout << "Enter a file name: ";
            getline(cin, filename);
            Search(filename);
            break;

        case 0:
            break;

        default:
            cout << "--------------------------\n";
            cout << "Menu\n";
            cout << "[1] - Enter and save information\n";
            cout << "[2] - Load and display information\n";
            cout << "[3] - Search by route number\n";
            cout << "[0] - Exit\n";
            cout << "--------------------------\n";
            cout << "Select:";
            cin >> choice;
        }
    } while (choice != 0);
}

void Create(const string& filename)
{
    ofstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening file '" << filename << "'" << endl;
        return;
    }

    route r;
    char ch;

    do
    {
        cout << endl;
        cout << "Start: ";
        cin >> r.start;
        cout << "End: ";
        cin >> r.end;
        cout << "Number: ";
        cin >> r.nomer;
        cin.ignore();

        if (!file.write(reinterpret_cast<const char*>(&r), sizeof(route)))
        {
            cerr << "Error writing file." << endl;
            return;
        }

        cout << "Continue? [Y/n]: ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    file.close();
}

void Print(const string& filename)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening file '" << filename << "'" << endl;
        return;
    }

    route r;

    cout << "=============================="
        << endl;
    cout << "|  Start  |  End  | Number " << setw(3) << "|"
        << endl;
    cout << "------------------------------"
        << endl;

    while (file.read(reinterpret_cast<char*>(&r), sizeof(route)))
    {
        cout << "| " << setw(7) << left << r.start << " "
            << "| " << setw(6) << right << r.end << " "
            << "| " << setw(7) << left << r.nomer << " |" << endl;
    }

    cout << "------------------------------" << endl << endl;

    file.close();
}

void Search(const string& filename)
{
    int found = 0;
    int nomer;
    cout << "Enter route number: ";
    cin >> nomer;

    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Error opening file '" << filename << "'" << endl;
        return;
    }

    route r;

    while (file.read(reinterpret_cast<char*>(&r), sizeof(route)))
    {
        if (r.nomer == nomer)
        {
            found++;
            cout << endl;
            cout << " Route with a number " << nomer << " found: " << endl;
            cout << " Start: " << r.start << endl;
            cout << " End: " << r.end << endl;
        }
    }

    if (found == 0)
    {
        cout << "Route not found." << endl;
    }

    file.close();
}