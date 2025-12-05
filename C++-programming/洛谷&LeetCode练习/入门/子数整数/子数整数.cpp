#include<iostream>
using namespace std;

int main(void)
{
    int k,cnt=0;
    cin>>k;
    for(int i=10000;i<=30000;i++)
    {
        int a1,a2,a3,a4,a5;
        a5=i%10;
        a4=(i%100)/10;
        a3=(i%1000)/100;
        a2=(i%10000)/1000;
        a1=i/10000;
        int sub1=a1*100+a2*10+a3;
        int sub2=a2*100+a3*10+a4;
        int sub3=a3*100+a4*10+a5;
        if(sub1%k==0&&sub2%k==0&&sub3%k==0)
        {
            cnt=1;
            cout<<i<<endl;
        }
    }
    if(cnt==0)
        cout<<"No"<<endl;
    return 0;
}