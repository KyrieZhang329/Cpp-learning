#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
using namespace std;

struct stu{
    string name;
    vector<int> grade;
    int total;

    stu():grade(6,0){}
};

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(stu& i:v)
    {
        cin>>i.name;
        for(int& j:i.grade)
            cin>>j;
        i.total=accumulate(i.grade.begin(),i.grade.begin()+6,0);
    }
    sort(v.begin(),v.end(),[](const stu& a,const stu& b){
        if(a.total!=b.total)
            return a.total>b.total;
        return a.grade[5]>b.grade[5];
    });
    for(const stu& i:v)
        cout<<i.name<<" "<<i.total<<" "<<i.grade[5]<<endl;
    return 0;
}
