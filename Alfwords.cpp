//Найти слова в строке, в которых буквы упорядочены 
//в алфавитном порядке.Сформировать массив таких слов.
//Отсортировать массив в порядке возрастания длины слова.
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n = 0, smb, lng1, lng2, i = 0, flag = 1, k = 1;
    cout << "Enter the length of the string: "; cin >> smb;
    char* str = new char[smb + 1];
    cout << "Entered string: ";
    const char* st = "/., ()?0123456789";
    cin.ignore();
    gets_s(str, smb + 1);
    char* strl = str;
    char* p1;
    strl = str;
    char** masstr = new char* [smb];
    while (*strl) {
        lng1 = strcspn(strl, st);
        p1 = strl;
        for (int i = 0; i < lng1-1; i++)
        {
            if ((p1[i]) != (p1[i+1]-1))
            {
                flag = 0; break;
            }
        }
        if (flag)
        {
            masstr[n] = new char[lng1 + 1];
            strncpy_s(masstr[n], lng1 + 1, strl, lng1);
            n++;
        }
        strl = strl + lng1;
        strl = strl + strspn(strl, st);
        flag = 1;
    }
    char* rab; 
    if (n == 1)
    {
        cout << "Array of strings: ";
        cout << masstr[0] << endl;
    }
    if (n >= 2)
    {
        while (flag) 
        {
            flag = 0;
            for (int i = 0; i < n - k; i++) 
            {
                lng1 = strlen(masstr[i]); 
                lng2 = strlen(masstr[i+1]);
                if (lng1 > lng2) 
                {
                    rab = masstr[i];	
                    masstr[i] = masstr[i + 1];	
                    masstr[i + 1] = rab;
                    flag = 1;
                }
            }
            k++;
        }
        cout << endl;
    };
    if (n>=2)
    {
        cout << "Array of strings after sorting: " << endl;
        for (int i = 0; i < n; i++)
            cout << masstr[i] << endl;
    }
    else { if (n == 0) cout << "There are no matching words in the string" << endl; }
    for (int i = 0; i < n; i++)
         delete[]masstr[i];
    delete[]masstr;
    delete[]str;
    system("pause");
}