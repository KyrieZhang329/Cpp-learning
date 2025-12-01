#include<iostream>
using namespace std;

void hanoi(int n,char src,char dest,char aux);

int main() 
{
    int n;
    cin>>n; 
    hanoi(n,'a','b','c');
    return 0;
}

void hanoi(int n,char src,char dest,char aux) 
{
    if (n==1) 
    {
        cout<<src<<"->"<<dest<<endl;
        return;
    }
    hanoi(n-1,src,aux,dest);
    cout<<src<<"->"<<dest<<endl;
    hanoi(n-1,aux,dest,src);
}
