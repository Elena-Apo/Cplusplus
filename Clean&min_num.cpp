/*В строке удалить лишние пробелы и найти слово,
которое содержит минимальное количество цифр*/
#include <iostream>
#include <cstring>
using namespace std;

void delet(char*, int&);
int search(char*, int&, int);

int main() {
    setlocale(LC_ALL, "Russian");
    int n, len, begin, flag = 0;
    int& lng = len;
    cout << "Размер строки:";
    cin >> n;
    char* ps = new char[n + 1];
    cin.ignore();
    cout << "Строка: ";
    gets_s(ps, n + 1);
    //puts(ps);
    len = strlen(ps);
    delet(ps, lng);
    cout << "Очищенная строка: ";
    puts(ps);
    begin = search(ps, lng, n);
    int i = 0;
    cout << "Слово с минимальным количеством цифр: ";
    while (ps[begin + i] != ' ')
    {
        cout << ps[begin + i];
        i++;
    }
    cout << endl;
    delete[] ps;
    system("pause");
}

void delet(char* ps, int& lng)
{
    int flag = 0;
    for (int i = 0; i < lng; i++)
    {
        if (ps[i] == ' ')
        {
            while (ps[i + 1] == ' ')
            {
                for (int j = i + 1; j < lng - 1; j++)
                {
                    ps[j] = ps[j + 1];
                }
                if (ps[i] != ' ') { i++; }
                flag++;
            }

        }
    }
    lng -= flag;
    ps[lng] = '\0';
}

int search(char* ps, int& lng, int n)
{
    int flag = 0, begin = 0, nom, kolvo = n ;
    for (int i = 0; i < lng; i++)
    {
        nom = i;

        while (ps[i] != ' ')
        {
            if ((ps[i] <= '9') && (ps[i] >= '0'))
            {
                flag++;
               // cout << "flag " << flag << endl;;
            }
            i++;
        }
        if (flag < kolvo) { kolvo = flag; begin = nom; }//cout << "kolvo & nom" << kolvo << " & " << nom << endl;
        flag = 0;
    }
    return begin;
}