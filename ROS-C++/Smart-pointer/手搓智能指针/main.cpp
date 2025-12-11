#include<iostream>
#include"SmartPtr.hpp"
using namespace std;

int main()
{
    SmartPtr ptr(new int(100));
    cout<<*ptr<<endl;

    *ptr=200;
    cout<<*ptr;
    return 0;
}