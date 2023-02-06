
//Заменить на '*' мне символы между '(' и ')'

#include <iostream>
#include <cstring>
using namespace std;
const int M = 50;
int main() {
    char str[M];
    int len;
    cout << "Vvedi stroku: ";
    gets_s(str);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '(') 
        {
            while ((str[i + 1] != ' ') && (str[i + 1] != ')'))
            {
                str[i + 1] = '*'; i++;
            }
        }        
    }
    cout << "  " << str << endl;
    system("pause");
}