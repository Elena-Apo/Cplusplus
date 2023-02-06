//9. ***Если количество максимальных цифр в натуральном 
//числе n(поиск за один просмотр) является чётным, 
//то заменить их единицами.Массив цифр не создавать.
#include <iostream>
using namespace std;
class cLongs
{
	int iN;
public:
	cLongs(int n) { iN = n; };
	void Change();
};
void cLongs::Change()
{
	int r = iN, imax = r % 10, ikol = 1, rab = 0; r /= 10;
	while (r % 10)
	{
		if (r % 10 > imax) { imax = r % 10; ikol = 1; }
		else if (r % 10 == imax) ikol++;
		r /= 10;
	}
	if (ikol % 2 == 0)
	{
		r = iN; 
		do
		{
			rab *= 10;
			if (r % 10 != imax) { rab += r % 10; }
			else { rab += 1; }
			r /= 10;
		} while (r % 10);
		r = rab % 10; rab /= 10;
		while (rab % 10)
		{
			r *= 10;
			r += rab % 10;
			rab /= 10;
		}
		iN = r;
		cout << " New = " << iN << endl;
	}
	else { cout << "The number of maximum digits in the number is odd= " << ikol << endl; }
}
int main()
{
	int n = 0;
	cout << "Enter n= "; cin >> n;
	cLongs N1(n);
	N1.Change();
	return 0;
	system("pause");
}