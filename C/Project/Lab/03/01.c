/*
已知S=1+1/2+1/3+1/4+...+1/N，编程求写出满足不等式S>15最小的N值，同时输出S值 。
*/
#include <stdio.h>
int main(int argc, char const *argv[])
{
    double S = 0;
    int ans;
    for (int i = 1; S <= 15; i++)
    {
        S += (1.0 / i);
        ans = i;
    }
    printf("N:%d S:%.20lf", ans, S);
    return 0;
}
