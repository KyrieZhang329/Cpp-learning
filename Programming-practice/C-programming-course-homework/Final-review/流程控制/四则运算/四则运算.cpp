#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int a, b, result;
    char op;
    scanf("%d%c%d", &a, &op, &b);
    switch(op)
    {
        case '+':
            result = a + b;
            printf("%d%c%d=%d\n", a, op, b, result);
            break;
        case '-':
            result = a - b;
            printf("%d%c%d=%d\n", a, op, b, result);
            break;
        case '*':
            result = a * b;
            printf("%d%c%d=%d\n", a, op, b, result);
            break;
        case '/':
            result = a / b;
            printf("%d%c%d=%d\n", a, op, b, result);
            break;
        case '%':
            result = a % b;
            printf("%d%c%d=%d\n", a, op, b, result);
            break;
        default:
            break;
    }
    return 0;
}