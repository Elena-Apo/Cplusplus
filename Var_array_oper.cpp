//В массиве А(N, M) удалить строки, не содержащие положительных элементов,
//а остальные строки расположить в порядке возрастания количества 
//положительных элементов в каждой строке.Дополнительный массив не 
//использовать Указатели на строки.
//Определить для каждого из двух созданных  объектов количество 
//удалённых  строк, и в каком объекте больше.
//Использовать друж.функцию или внешнюю.
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

void compar(int kol1, int kol2);

class Massiv
{
    int n, m, kol;
    int** p;
public:
    ~Massiv() { cout << "Destructor:" << endl; delete[] p; }
    Massiv(int n, int m);
    void sherach();
    void sort();
    void show();
    void inpt();
    int outkol() { return kol; }
};

Massiv::Massiv(int n1, int m1)
{
    n = n1; m = m1;
    cout << "Constructor: " << endl;
    p = new int* [n];
    for (int i = 0; i < n; i++)
        p[i] = new int[m];
}

void Massiv::inpt()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            p[i][j] = rand() % 56 - rand() % 34;
            //cout << p[i][j] << "  ";
        }
        /*  cout << p[i] << endl;*/
    }
}

void Massiv::sherach()
{
    int flag = 0; kol = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[i][j] % 2 == 0) { flag++; }
        }
        if (flag == 0)
        {
            for (int k = i; k < n; k++)
                {
                    p[k] = p[k + 1];
                }
            n -= 1; kol++; i--;
        }
        flag = 0;
        if (i == n - 1) { break; }
    }
    cout << "Number of deleted rows: " << kol << endl;
};

void  Massiv::show()
{
    cout << "Massiv: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout.width(4);
            cout << p[i][j];
        }
        cout << endl;
    }
}

void Massiv::sort()
{
    int kolvo = 0;
    int* ptr = new int[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (p[i][j] > 0) { kolvo++; }
        }
        ptr[i] = kolvo;
        kolvo = 0;
    }
    /*cout << "provrka " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ptr[i] << endl;
    }*/
    int* rab; bool flag = 1;
    int r;
    for (int i = 0; i < n - 1; i++)
    {
        if (flag)
        {
            flag = 0;
            for (int j = 0; j < n - i - 1; j++)
            {
                if (ptr[j] > ptr[j + 1])
                {
                    rab = p[j]; p[j] = p[j + 1]; p[j + 1] = rab;
                    r = ptr[j]; ptr[j] = ptr[j + 1]; ptr[j + 1] = r;
                    flag = 1;
                }
            }
        }
        else break;
    }
    /* cout << "provrka " << endl;
     for (int i = 0; i < n; i++)
     {
         cout << ptr[i] << endl;
     }*/
};

int main()
{
    int n, m;
    cout << "Enter the number of rows and the number of elements in them: ";
    cin >> n >> m;
    cout << endl << "The first massiv: " << endl;
    Massiv ob1(n, m);
    ob1.inpt();
    ob1.show();
    ob1.sherach();
    ob1.sort();
    int kol1 = ob1.outkol();/* cout << "kol1: " << kol1 << endl;*/
    ob1.show();
    cout << endl << "The second massiv: " << endl;
    Massiv ob2(n, m);
    ob2.inpt();
    ob2.show();
    ob2.sherach();
    ob2.sort();
    int kol2 = ob2.outkol();/* cout << "kol2: " << kol2 << endl;*/
    ob2.show();
    compar(kol1, kol2);
    system("pause");
}

void compar(int kol1, int kol2)
{
    if (kol1 > kol2) { cout << "The first massiv has more deleted rows " << endl; }
    else
    {
        if (kol1 < kol2) { cout << "The second massiv has more deleted rows " << endl; }
        else { cout << "The numbers of deleted rows are the same " << endl; }
    }
}