#include<stdio.h>
int main(void)
{
    int arr[12];
    for(int i=0;i<10;i++)
    {
        int index;
        scanf("%d",&index);
        arr[i]=index;
    }
    int h;
    scanf("%d",&h);
    int cnt=0;
    for(int i=0;i<10;i++)
    {
        if(arr[i]<=h+30)
            cnt++;
    }
    printf("%d",cnt);
    return 0;
}