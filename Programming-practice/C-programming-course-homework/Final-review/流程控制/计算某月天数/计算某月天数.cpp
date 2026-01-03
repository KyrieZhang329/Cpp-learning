#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    switch (b){
        case 4:
            cout<<30;
            break;
        case 6:
            cout<<30;
            break;
        case 9:
            cout<<30;
            break;
        case 11:
            cout<<30;
            break;
        case 2:
            if((a%4==0&&a%100!=0)||a%400==0)
                cout<<29;
            else
                cout<<28;
            break;
        default:
            cout<<31;
            break;
    }
    return 0;
}