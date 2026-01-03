#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++)
    {
        vector<int> v;
        for(int j=1;j<=i/2;j++)
        {
            if(i%j==0)
                v.push_back(j);
        }
        if(accumulate(v.begin(),v.end(),0)==i)
            cout<<i<<endl;
    }
    return 0;
}