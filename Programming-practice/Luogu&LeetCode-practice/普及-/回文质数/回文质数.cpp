#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPrime(int num)
{
    if(num==2)
        return true;
    else if(num==1||num%2==0)
        return false;
    else
    {
        for(int i=3;i*i<=num;i+=2)
        {
            if(num%i==0)
                return false;
        }
    }
    return true;
}

bool palindromes(string s)
{
    int size=(int)s.size();
    for(int i=0;i<size/2;i++)
    {
        if(s[i]!=s[size-1-i])
            return false;
    }
    return true;
}

int main()
{
    int a,b;
    cin>>a>>b;
    vector<int> v;
    for(int i=a;i<=b;i++)
    {
        string s=to_string(i);
        if(palindromes(s))
            v.push_back(i);
    }
    for(int i:v)
    {
        if(isPrime(i))
            cout<<i<<endl;
    }
    return 0;
}