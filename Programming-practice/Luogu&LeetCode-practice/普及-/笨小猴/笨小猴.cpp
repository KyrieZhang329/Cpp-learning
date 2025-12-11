#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return(a==0)?false:(b==0)?true:a<b;
}

bool isPrime(int n)
{
    if(n==2)
        return true;
    else if(n==1||n%2==0)
        return false;
    else
    {
        for(int i=3;i*i<=n;i+=2)
        {
            if(n%i==0)
                return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cin>>s;
    vector<int> v(26,0);
    for(int i:s)
        v[i-'a']++;
    int max_num=*max_element(v.begin(),v.end());
    int min_num=*min_element(v.begin(),v.end(),cmp);
    if(isPrime(max_num-min_num))
        cout<<"Lucky Word"<<endl<<max_num-min_num;
    else
        cout<<"No Answer"<<endl<<0;
    return 0;
}