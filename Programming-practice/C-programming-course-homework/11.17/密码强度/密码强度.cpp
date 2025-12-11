#include<iostream>
#include<cstring>
#include<numeric>
using namespace std;

int main()
{
    char arr[50];
    int cnt=0;
    int jud[4]={0};
    cin.getline(arr,51);
    int len = strlen(arr);
    if(len>0)
        cnt++;
    if(len>8)
        cnt++;
    for(int i=0;i<len;i++)
    {
        if(arr[i]>='0'&&arr[i]<='9')
            jud[0]=1;
        else if(arr[i]>='a'&&arr[i]<='z')
            jud[1]=1;
        else if(arr[i]>='A'&&arr[i]<='Z')
            jud[2]=1;
        else 
            jud[3]=1;
    }
    int sum=accumulate(jud,jud+4,0);
    switch(sum)
    {
        case 2:
        cnt++;
        break;
        case 3:
        cnt+=2;
        break;
        case 4:
        cnt+=3;
        break;
        default:
        break;
    }
    cout<<cnt;
    return 0;
}