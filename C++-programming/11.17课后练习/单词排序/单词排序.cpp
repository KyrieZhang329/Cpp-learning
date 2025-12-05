#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<string> strarr(n);
    for(int i=0;i<n;i++)
        cin>>strarr[i];
    sort(strarr.begin(),strarr.end());
    for(int i=0;i<n;i++)
        cout<<strarr[i]<<endl<<endl;
    return 0;
}