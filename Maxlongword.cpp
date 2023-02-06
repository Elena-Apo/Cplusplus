#include <iostream>
#include <cstring>
using namespace std;
const int M = 50;
int main() {
    char str[M];
    int loong = 1, maxlong = 0, kol, len;
    cout << "Vvedi stroku: ";
    gets_s(str);
    len = strlen(str);
    cout << "strlen(str): " << strlen(str) << endl;
    str[len + 1] = ' ';
    for (int i = 0; i < len; i++) 
    {
        if (str[i] != ' ')
        {
            while ((str[i + 1] != ' ')&&((i+1)!= len))
            {
                loong++;
                i++;
            }
            if (loong > maxlong) { kol = 1; maxlong = loong;  }
            else  if (loong == maxlong) { kol++; }
            loong = 1;
        }
    }
    cout << "maxlong: " << maxlong<< " kolvo: "<< kol << endl;
    system("pause");
}