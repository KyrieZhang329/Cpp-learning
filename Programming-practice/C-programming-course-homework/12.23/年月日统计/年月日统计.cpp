#include<iostream>
#include<numeric>
#include<cstdio>
#include<vector>
using namespace std;

struct index{
    int year;
    int month;
    int day;
};

bool judge(const int& i)
{
    if((i%4==0&&i%100!=0)||i%400==0)
        return true;
    return false;
}

int main()
{
    index t;
    scanf("%d,%d,%d",&t.year,&t.month,&t.day);
    vector<pair<int,int> > v(12);
    for(int i=0;i<12;i++)
        v[i].first=i+1;
    for(int i=0;i<12;i++)
    {
        switch(i+1)
        {
            case 2:
                if(judge(t.year))
                    v[i].second=29;
                else
                    v[i].second=28;
                break;
            case 4:
                v[i].second=30;
                break;
            case 6:
                v[i].second=30;
                break;
            case 9:
                v[i].second=30;
                break;
            case 11:
                v[i].second=30;
                break;
            default:
                v[i].second=31;
                break;
        }
    }
    int sum=0;
    for(int i=0;i<t.month-1;i++)
        sum+=v[i].second;
    sum+=t.day;
    cout<<sum;
    return 0;
}