#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    double a;
    scanf("%lf", &a);
    if (a < 20 && a >= 0)
    {
        printf("%.2lf", a >= 10 ? cos(a) : sin(a));
    }
    else if (a >= 20 && a < 40)
    {
        printf("%.2f", a >= 30 ? log(a + 1) : exp(a) - 1);
    }
    else
    {
        printf("%.2f", pow(a, 4));
    }
    return 0;
}
