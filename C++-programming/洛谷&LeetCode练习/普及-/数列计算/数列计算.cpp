#include<iostream>
using namespace std;

int recurse(int a, int cnt)
{
    for(int i=1;i<=a/2;i++)
    {
        cnt++;
        if(i/2>=1)
            cnt=recurse(i,cnt);
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;
    int cnt=1;
    cnt=recurse(n,cnt);
    cout<<cnt;
    return 0;
}