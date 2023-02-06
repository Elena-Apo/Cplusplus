/*В строке удалить лишние пробелы и найти слово,
которое содержит минимальное количество цифр*/
#include <iostream>
#include <cstring>
using namespace std;

void delet(char*, int&);
char* search(char*, int);
char* subOut(char*, char*, char*);

int main() {
    setlocale(LC_ALL, "Russian");
    int n, len, flag = 0, kol = 0;
    int& lng = len;
    cout << "Размер строки:";
    cin >> n;
    char* ps = new char[n + 1];
    cin.ignore();
    cout << "Строка: ";
    gets_s(ps, n + 1);
    len = strlen(ps);
    delet(ps, lng);
    cout << "Очищенная строка: ";
    puts(ps);
    char* begin;
    begin = search(ps, n);
    cout << "Слово с минимальным количеством цифр: ";
    char* sub = new char[strlen(ps) + 1];
    sub = subOut(ps, begin, sub);
    cout << endl;
    delete[] ps;
    delete[] sub;
    system("pause");
}

void delet(char* ps, int& lng)
{
    int flag = 0;
    char* k;
    while (*ps)
    {
        if (k = strstr(ps, " "))
        {
            while (*(k + 1) == ' ')
            {
                for (int i = 1; i < lng - 1; i++)
                {
                    *(k + i) = *(k + i + 1);
                }
                if (*(k + 1) != ' ') { *ps++; }
                flag++;
            }
            *ps++;
        }
        else { *ps++; }
    }
    lng -= flag;
    ps[lng] = '\0';
}

char* search(char* ps, int n)
{
    int flag = 0, kolvo = n;
    char* nom; char* begin = ps;
    while (*ps)
    {
        nom = ps;

        while (*ps != ' ' && *ps != '\0')
        {
            if ((*ps <= '9') && (*ps >= '0'))
            {
                flag++;
            }
            *ps++;
        }
        if (flag < kolvo) { kolvo = flag; begin = nom; }
        if (*ps == '\0') break;
        else { *ps++; }
        flag = 0;
    }
    return begin;
}

char* subOut(char* ps, char* begin, char* sub) {
    int kol = 0;
    while (*begin != ' ' && *begin != '\0')
    {
        kol++; begin++;
    }
    begin -= kol;
    int sizebuf = strlen(ps) + 1;
    strncpy_s(sub, sizebuf, begin, kol);
    cout << sub << endl;
    return sub;
}

