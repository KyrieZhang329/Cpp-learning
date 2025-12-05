#include<iostream>
#include<cstring>
#include<string>
using namespace std;

bool is_num(char a) 
{
    return a >= '0' && a <= '9';
}

bool is_op(char a) 
{
    return a == '+' || a == '-' || a == '*' || a == '/';
}


bool is_num_sign(char* str, int i, int len)
{
    if (str[i] != '+' && str[i] != '-') 
        return false;
    return (i == 0) || (str[i-1] == '(' || is_op(str[i-1]));
}

int main() 
{
    char str[41];
    cin.getline(str, 41);
    int len = strlen(str);
    for (int i = 0; i < len; ) 
    {
        if (is_num_sign(str, i, len) || is_num(str[i]) || str[i] == '.') 
        {
            string num_token;
            while (i < len && (is_num(str[i]) || str[i] == '.' || is_num_sign(str, i, len))) 
            {
                num_token += str[i];
                i++;
            }
            cout << num_token << endl;
        }
        else if (str[i] == '(' || str[i] == ')') 
        {
            cout << str[i] << endl;
            i++;
        }
        else if (is_op(str[i])) 
        {
            cout << str[i] << endl;
            i++;
        }
    }
    return 0;
}