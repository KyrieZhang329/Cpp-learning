#include<stdio.h>
int main()
{
    int m;
    scanf("%d", &m);
    
    int sum_even = 0;   // 前m个大于100的偶数之和
    int sum_odd = 0;    // 前m-1个大于100的奇数之和
    int count_even = 0; // 已找到的偶数个数
    int count_odd = 0;  // 已找到的奇数个数
    int n = 1;          // 数列项数（从第1项开始）
    
    // 循环遍历数列，直到收集到足够的偶数和奇数
    while (count_even < m || count_odd < (m - 1)) {
        // 计算第n项的值（按通项公式）
        int a = 3 * (n - 1) * (n - 1) + 2 * (n - 1) + 1;
        
        // 只处理大于100的项
        if (a > 100) {
            if (a % 2 == 0) { // 偶数：累计前m个
                if (count_even < m) {
                    sum_even += a;
                    count_even++;
                }
            } else { // 奇数：累计前m-1个
                if (count_odd < (m - 1)) {
                    sum_odd += a;
                    count_odd++;
                }
            }
        }
        
        n++; // 检查下一项（最多到10000项，题目限定）
        if (n > 10000) break;
    }
    
    printf("%d %d", sum_even, sum_odd);
    return 0;
}
