#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    char a;
    cin>>a;
    if(a>='a'&&a<='z')
        cout<<static_cast<char>(toupper(a));
    else if(a>='A'&&a<='Z')
        cout<<static_cast<char>(tolower(a));
    else
        cout<<a;
    return 0;
}