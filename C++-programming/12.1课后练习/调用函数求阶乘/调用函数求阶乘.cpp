#include<iostream>
#include<vector>
using namespace std;

int fun(vector<int> &v,int x);

int main()
{
    int x;
    cin>>x;
    vector<int> v;
    cout<<fun(v,x)<<endl;
    for(int i:v)
        cout<<i<<" ";
    return 0;
}

int fun(vector<int>& v,int x)
{
    for(int i=1;i<=x;i++)
    {
        if(i==2)
        {
            v.push_back(i);
            continue;
        }
        else if(i==1||i%2==0)
            continue;
        else
        {
            bool index=true;
            for(int j=3;j*j<=i;j++)
            {
                if(i%j==0)
                {
                    index=false;
                    break;
                }
            }
            if(index)
                v.push_back(i);
        }
    }
    return (int)v.size();
}