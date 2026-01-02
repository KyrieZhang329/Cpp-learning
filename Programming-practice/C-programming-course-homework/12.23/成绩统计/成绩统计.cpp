#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iomanip>
using namespace std;

struct stu{
    int num;
    string name;
    int grade_1;
    int grade_2;
    int grade_3;
    double average;
};

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(stu& i:v)
    {
        cin>>i.num>>i.name>>i.grade_1>>i.grade_2>>i.grade_3;
        i.average=round((i.grade_1+i.grade_2+i.grade_3)*10.0/3.0)/10.0;

    }
    sort(v.begin(),v.end(),[](const stu& a,const stu& b){
        if(a.average!=b.average)
            return a.average>b.average;
        return a.num<b.num;
    });
    cout<<fixed<<setprecision(1);
    for(const stu& i:v)
        cout<<i.num<<" "<<i.name<<" "<<i.average<<endl;
    return 0;
}