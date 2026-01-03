#include<iostream>
using namespace std;

int main()
{
    int day,index;
    string num;
    cin>>day>>index>>num;
    char a=num[4];
    if(day>=6)
        cout<<a<<" no";
    else
    {
        if(index<200)  
            cout<<a<<" no";
        else if(index<400)
        {
            switch (day){
                case 1:
                    if(a=='1'||a=='6')
                        cout<<a<<" yes";
                    else
                        cout<<a<<" no";
                    break;
                case 2:
                    if(a=='2'||a=='7')
                        cout<<a<<" yes";
                    else
                        cout<<a<<" no";
                    break;
                case 3:
                    if(a=='3'||a=='8')
                        cout<<a<<" yes";
                    else
                        cout<<a<<" no";
                    break;
                case 4:
                    if(a=='4'||a=='9')
                        cout<<a<<" yes";
                    else
                        cout<<a<<" no";
                    break;
                default:
                    if(a=='5'||a=='0')
                        cout<<a<<" yes";
                    else
                        cout<<a<<" no";
                    break;
            }
        }
        else
        {
            if(day==1||day==3||day==5)
            {
                if(a=='1'||a=='3'||a=='5'||a=='7'||a=='9')
                    cout<<a<<" yes";
                else
                    cout<<a<<" no";
            }
            else
            {
                if(a=='0'||a=='2'||a=='4'||a=='6'||a=='8')
                    cout<<a<<" yes";
                else
                    cout<<a<<" no";
            }
        }
    }
    return 0;
}