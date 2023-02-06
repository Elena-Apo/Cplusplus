//Из массива А(N) удалить все элементы, сумма цифр
//которых чётная, стоящие между первым минимальным
//и последним максимальным элементами
#include <iostream>
using namespace std;
void out(int*, int, int& kolvo);
int* vvod(int& n);
int podhod(int* p);
int del(int& nMIN, int& nMAX, int* p, int n, int& kolvo);
void search(int& nMIN, int& nMAX, int* p, int n);
void peredelka(int& nMIN, int& nMAX, int* p, int n, int& kolvo);
int main() {
    int n, kol = 0, k, l, & kolvo = kol;
    int* p = 0; int& nMIN = k; int& nMAX = l;
    int vibor; bool flag = true;
    while (flag) {
        cout << "\n Menu:\n";
        cout << "enter----->1" << endl
            << "out------->2" << endl
            << "search---->3" << endl
            << "delete---->4" << endl
            << "exit------>5" << endl;
        cin >> vibor;
        switch (vibor) {
        case 1:	system("cls"); 	p = vvod(n);	        break;
        case 2:	out(p, n, kolvo);	                    break;
        case 3: search(nMIN, nMAX, p, n);	            break;
        case 4:	del(nMIN, nMAX, p, n, kolvo);	break;
        case 5:	cout << "End!"; 	flag = 0;	        break;
        }
    }
    cout << endl;
    delete[] p;
}
int* vvod(int& n) {
    cout << "Enter the number of array elements: ";	cin >> n;
    int* p = new int[n];
    srand(n);
    cout << "Enter array: ";
    for (int i = 0; i < n; i++)
        cin >> *(p + i);
    return p;
}
void out(int* p, int n, int& kolvo) {
    cout << "\n\t Array: " << endl;
    for (int i = 0; i < n - kolvo; i++)
    {
        cout << *(p + i) << ' ';
    }
    cout << endl;
}
void search(int& nMIN, int& nMAX, int* p, int n)
{
    int min = *p, max = *p;
    for (int j = 0; j < n; j++)
    {
        if ((*(p + j) <= min)&&(*(p + j)!= -1))
        {
            nMIN = j; min = *(p + j);
        }
        else {
            if (*(p + j) >= max)
            {
                nMAX = j;  max = *(p + j);
            }
        }
    }
    cout << "min & max " << min << "  " << max << endl;
    cout << "nMIN & nMAX " << nMIN << "  " << nMAX << endl;
}
int del(int& nMIN, int& nMAX, int* p, int n, int& kolvo)
{
    search(nMIN, nMAX, p, n);
    peredelka(nMIN, nMAX, p, n, kolvo);
    return 0;
}
void peredelka(int& nMIN, int& nMAX, int* p, int n, int& kolvo)
{
    int count = 0;
    int t;
    int max = *(p + nMAX);

    if (nMIN >= nMAX)
    {
        cout << " nMIN >= nMAX" << endl;
        return;
    }

    cout << "min & max " << *(p + nMIN) << "  " << *(p + nMAX) << endl;

    for (int s = nMIN + 1; s < nMAX; s++)
    {
        if (*(p + s) == max)
            break;

        if (*(p + s) == *(p + nMAX))
            continue;

        t = podhod(p + s);
       /* cout << " podhod=" << t << endl;*/
        if (t == 0)
        {
            count++;
            for (int z = s + 1; z < n; z++)
            {
                *(p + z - 1) = *(p + z);
            }
            s -= 1;
        }
    }
   /* cout << "kolvo= " << count;*/
    cout << endl << "Out array ";
    cout << endl;
    if (count) { kolvo = count; }

    for (int i = n - kolvo; i < n; i++)
        *(p + i) = -1;

    for (int i = 0; i < n - kolvo; i++)
        cout << *(p + i) << ' ';

    cout << endl;
}
int podhod(int* p)
{
    int q = *p; int s = 0;
    while (q)
    {
        s = s + q % 10;
        q = q / 10;
    }
    if (s % 2) { cout << " even sum " << s % 2 << endl; }
    else { cout << " odd sum " << s % 2 << endl; }
    return (s % 2);
}
