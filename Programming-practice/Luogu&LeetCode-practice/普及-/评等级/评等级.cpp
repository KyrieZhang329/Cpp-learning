#include<iostream>
#include<vector>
using namespace std;

struct stu{
    int num;
    int a_grades;
    int b_grades;
    double c_grades;

    int total() const
    {
        return a_grades+b_grades;
    }
};

bool excellent(const stu& s)
{
    int total_grades=s.total();
    return total_grades>140&&(s.a_grades*7+s.b_grades*3)>=800;
}

int main()
{
    int n;
    cin>>n;
    vector<stu> v(n);
    for(stu& i:v)
    {
        cin>>i.num>>i.a_grades>>i.b_grades;
        i.c_grades=i.a_grades*0.7+i.b_grades*0.3;
    }
    for(const stu i:v)
    {
        if(excellent(i))
            cout<<"Excellent"<<endl;
        else
            cout<<"Not excellent"<<endl;
    }
    return 0;
}