/*
一个数如果恰好等于它的因子之和,这个数就称为“完数”编程序找出1000之内的所有完数，并按下面的格式输出其因子：6 its factors are 1，2，3
*/
#include <stdio.h>
#include <math.h>
int SumFactor(int val)
{
    int Sum = 0;
    for (int i = 1; i < val; i++)
    {
        if (!(val % i))
        {
            Sum += i;
        }
    }
    return Sum;
}
void PrintFactor(int val)
{
    int Sum = 0;
    for (int i = 1; i < val; i++)
    {
        if (!(val % i))
        {
            printf(" %d", i);
        }
    }
    return;
}
int main(int argc, char const *argv[])
{
    for (int i = 1; i < 1001; i++)
    {
        if (i == SumFactor(i))
        {
            printf("%d\n因子:", i);
            PrintFactor(i);
            puts("");
        }
    }
    return 0;
}
