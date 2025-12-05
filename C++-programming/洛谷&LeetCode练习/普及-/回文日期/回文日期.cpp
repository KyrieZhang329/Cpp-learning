#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int start,end;
    cin>>start>>end;
    vector<int> v(12);
    for(int i=0;i<12;i++)
    {
        if(i+1<8)
        {
            if((i+1)%2!=0)
                v[i]=31;
            else if(i+1!=2)
                v[i]=30;
        }
        else
        {
            if((i+1)%2!=0)
                v[i]=30;
            else if(i+1!=2)
                v[i]=31;
        }
    }
    int cnt=0;
    for(int i=start;i<=end;i++)
    {
        int date=i%100;
        int month=(i%10000)/100;
        int year=i/10000;
        if((year%4==0&&year%100!=0)||(year%400)==0)
            v[1]=29;
        else
            v[1]=28;
        if(month>12||date>v[month-1])
            continue;
        vector<int> digits(8);
        int temp = i;
        int divisor = 10000000;
        for (int j = 0; j < 8; j++)
        {
            digits[j] = temp / divisor;
            temp = temp % divisor;
            divisor /= 10;
        }
        bool index=true;
        for(int j=0;j<4;j++)
        {
            if(digits[j]!=digits[7-j])
            {
                index=false;
                break;
            }
        }
        if(index)
            cnt++;
    }
    cout<<cnt;
    return 0;
}