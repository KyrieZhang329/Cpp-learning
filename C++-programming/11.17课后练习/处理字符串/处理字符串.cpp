#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    char arr[101];
    cin.getline(arr,101);
    int len=strlen(arr);
    vector<char> v1,v2;
    int cnt1=0,cnt2=0;
    for(int i=1;i<len;i++)
    {
        if(arr[i]>arr[0])
        {
            v1.push_back(arr[i]);
            cnt1++;
        }
        else
        {
            v2.push_back(arr[i]);
            cnt2++;
        }
    }
    sort(v2.begin(),v2.end());
    v1.push_back(arr[0]);
    for(int i=0;i<v1.size();i++)
        cout<<v1.at(i);
    for(int i=0;i<v2.size();i++)
        cout<<v2.at(i);
    return 0;
}