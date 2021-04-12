/*
编程求S=1/1!-1/2!+…+(-1)n-1/n! ，直到 |(-1)n-1/n!| <=1e-6为止。
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
    int n = 1;
    double S = 0;
    while ((1.0 / Factorial(n)) > 1e-6)
    {
        S += pow(-1, n - 1) / (double)Factorial(n);
        n++;
    }
    printf("%.20lf", S);
    return 0;
}
