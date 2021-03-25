#include <stdio.h>
#include <math.h>
int main(int argc, char const *argv[])
{
    double val;
    scanf("%lf", &val);
    if (val < 20 && val >= 0)
    {
        printf("%.2lf", val >= 10 ? cos(val) : sin(val));
    }
    else if (val >= 20 && val < 40)
    {
        printf("%.2f", val >= 30 ? log(val + 1) : exp(val) - 1);
    }
    else
    {
        printf("%.2f", pow(val, 4));
    }
    return 0;
}
