#include<iostream>
using namespace std;

double function(int n);

int main() 
{ 
    int n; 
    cin>>n;
    cout<<function(n); 
    return 0; 
} 

double function(int n)
{
    int i=1;
    double a=1.0;
    while(i++<n)
        a=1.0/(1+a);
    return a;
}