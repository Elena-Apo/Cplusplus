#include <iostream>
#include <cstring>
using namespace std;

void delet(char*, int&);
int poisk(char* ps, int i, int& lng);

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
    len = strlen(ps);
    delet(ps, lng);
    cout << "Очищенная строка: ";
    puts(ps);   
    delete[] ps;
    system("pause");
}

void delet(char* ps, int& lng)
{
    for (int i = 0; i < lng; i++)
    {
        if (ps[i] == '(' )
        {
           i= poisk(ps, i, lng);
        }
    }
}

int poisk(char* ps, int i, int& lng)
{
    int flag = 0, end = 0, j = i + 1;
     while (ps[i+1] != ')')
            {                        
              flag++; i++;
            }
     if (flag % 2 == 0) 
        {
             for (int k=0;k < flag;k++)
                {
                 for (int m=j; m < lng-1; m++)
                        ps[m] = ps[m + 1]; 
                }
             lng -= flag;
             ps[lng] = '\0';
             return i-flag;
         }
    else return i;
}