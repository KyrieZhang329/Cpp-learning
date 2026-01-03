#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    if(a==0||b==0)
    {
        cout<<max(a,b);
        return 0;
    }
    int max_num=max(a,b),min_num=min(a,b);
    while(max_num%min_num!=0)
    {
        int temp=min_num;
        min_num=max_num%temp;
        max_num=temp;
    }
    cout<<min_num;
    return 0;
}