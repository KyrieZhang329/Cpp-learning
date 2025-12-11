#include<stdio.h>

// 判断数字是否需要跳过（7的倍数或含7）
int skip(int num)
{
    if(num % 7 == 0)
        return 1;
    while(num > 0)
    {
        if(num % 10 == 7)
            return 1;
        num /= 10;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    int count = 0; // 已报出的有效数字数量
    int num = 1;   // 当前要报的数字
    int a = 0, b = 0, c = 0; // 三人跳过的次数
    
    while(count < n)
    {
        // 计算当前轮到第几个人（1、2、3循环）
        int person = (num - 1) % 3 + 1;
        
        if(skip(num))
        {
            // 数字需要跳过，统计对应人的跳过次数
            if(person == 1)
                a++;
            else if(person == 2)
                b++;
            else
                c++;
        }
        else
        {
            // 数字有效，计数加1
            count++;
        }
        
        num++; // 下一个数字
    }
    
    printf("%d %d %d", a, b, c);
    return 0;
}
