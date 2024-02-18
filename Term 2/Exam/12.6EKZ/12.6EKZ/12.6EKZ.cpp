#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	int info;
};

void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void read(Elem*& first, Elem*& last);
void print(Elem* L);
void count(Elem* L);

int main()
{

	Elem* first = NULL,
		* last = NULL;
	read(first, last);

	cout << endl;
	print(first); // вивід черги
	cout << endl;
	count(first);
	cout << endl;


	cout << "Queue: " << endl << endl;
	while (first != NULL)
		cout << dequeue(first, last) << " ";
	cout << endl;

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first == NULL)
		last = NULL;
	return value;
}

void read(Elem*& first, Elem*& last)
{
	ifstream f("test.txt");
	Info symbol;
	while (!f.eof()) {
		f >> symbol;
		enqueue(first, last, symbol);
	}
}


void print(Elem* L)
{
	while (L != NULL)
	{
		cout << L->info << " ";
		L = L->link;
	}
	cout << endl;
}


void count(Elem* L)
{
	Info min = L->info;
	Info max = L->info;
	Info min_pos = 0;
	Info max_pos = 0;
	Info k = 0;

	while (L->link != NULL)
	{
		k++;
		if (L->info < min) {
			min = L->info;
			min_pos = k;
		}
		else if (L->info > max) {
			max = L->info;
			max_pos = k;
		}
		L = L->link;
	}

	if (L != NULL) {
		k++;
		if (L->info < min) {
			min = L->info;
			min_pos = k;
		}
		else if (L->info > max) {
			max = L->info;
			max_pos = k;
		}
	}

	cout << "Minimum " << min << " be in position " << min_pos << endl;
	cout << "Maximum " << max << " be in position " << max_pos << endl;

	cout << "Arithmetic average " << (max + min) / 2 << endl;
}
