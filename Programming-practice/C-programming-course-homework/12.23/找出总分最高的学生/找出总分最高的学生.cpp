#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct stu{
    int num;
    string name;
    int grade1;
    int grade2;
    int grade3;
    int total;
};

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(stu& i:v)
    {
        cin>>i.num>>i.name>>i.grade1>>i.grade2>>i.grade3;
        i.total=i.grade1+i.grade2+i.grade3;
    }    
    sort(v.begin(),v.end(),[](const stu& a,const stu& b){
        return a.total>b.total;
    });
    cout<<v[0].name<<" "<<v[0].num<<" "<<v[0].total;
    return 0;
}