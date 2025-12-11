#include<stdio.h>
#include<math.h>

int main()
{
    int arr[20];
    for(int i=0;i<12;i++)
    {
        int a;
        scanf("%d",&a);
        arr[i]=a;
    }
    int save=0;
    int rest=0;
    int index=0;
    for(int i=0;i<12;i++)
    {
        rest+=300-arr[i];
        if(rest>=100)
        {
            save+=(rest/100)*100;
            rest-=(rest/100)*100;
        }
        else if(rest<0)
        {
            index=-(i+1);
            break;
        }
    }
    if(index!=0)
    {
        printf("%d",index);
    }
    else
    {
        save*=1.2;
        save=int(save)+rest;
        printf("%d",save);
    }
    return 0;
}
