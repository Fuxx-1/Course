/*
利用泰勒级数，计算sin(x) 的值（x由键盘输入），要求最后一项的绝对值小于10-5。
*/
#include <stdio.h>
#include <math.h>
int Factorial(int n)
{
    long Fac = 1;
    for (int i = 1; i <= n; i++)
    {
        Fac *= i;
    }
    return Fac;
}
int main(int argc, char const *argv[])
{
    int n = 0;
    double rand, S = 0;
    puts("输入sin(x)中的x(弧度制)");
    scanf("%lf", &rand);
    while ((pow(rand, 2 * n + 1) * 1.0 / Factorial(2 * n + 1)) > 1e-5)
    {
        S += pow(-1, n) * pow(rand, 2 * n + 1) * 1.0 / Factorial(2 * n + 1);
        n++;
    }
    printf("%.20lf", S);
    return 0;
}
