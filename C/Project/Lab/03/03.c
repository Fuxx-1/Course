/*
输出100到200之间的所有双胞胎素数，相邻两个奇数都为素数的这样一对数叫双胞胎素数。
*/
#include <stdio.h>
#include <math.h>
int isPri(int val)
{
    for (int i = 2; i <= sqrt(val); i++)
    {
        if (!(val % i))
        {
            return 0;
        }
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    puts("100到200之间的双胞胎素数:");
    int flag = 1;
    static char a[400];
    for (int i = 101; i < 210; i += 2)
    {
        a[i] = isPri(i);
    }
    for (int i = 100; i < 201; i++)
    {
        if (a[i] && a[i + 2])
        {
            printf("第%d组：%d & %d\n", flag++, i, i + 2);
        }
    }
    return 0;
}
