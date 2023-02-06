//Полями структуры являются координаты точки 
//на плоскости и расстояние точки от начала координат.
//В созданном массиве структур  определить индекс точки, 
//максимально удаленной от начала координат.
#include <math.h> 
#include <iostream>
using namespace std;

struct Numbers
{
	int x;
	int y;
	double r;
};
void input(Numbers* mas, int);
void show(Numbers* mas, int);
int check(Numbers* mas, int );

int main() {
	int n, ind;
	cout << "Enter kol: ";
	cin >> n;
	Numbers* st = new Numbers[n];
	input(st, n);
	show(st, n);
	ind = check(st, n);
	cout << "The maximum index: " << ind << endl;
	delete[] st;
}
void input(Numbers* mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Enter x & y №" << i << ": ";
		cin >> mas[i].x;
		cin >> mas[i].y;
		mas[i].r = sqrt(mas[i].x * mas[i].x + mas[i].y * mas[i].y);
	}
}

void show(Numbers* mas, int n)
{
	cout << "Massive: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << " ("<<mas[i].x << ";" << mas[i].y << ")  " << mas[i].r <<endl;
	}
}

int check(Numbers* mas, int n)
{
	double max;
	int ind = 0;
	max = mas[0].r;
	for (int i = 1; i < n; i++)
	{
		if (mas[i].r > max) ind = i;
	}
	return ind;
}
