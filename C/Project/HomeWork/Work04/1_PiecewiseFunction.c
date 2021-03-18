#include <stdio.h>
#include <math.h>
int main(void)
{
    double x = 0;
    scanf("%lf", &x);
    if (x > 10)
    {
        printf("%.2lf", log(x + 3));
    }
    else if (x > -3 && x <= 10)
    {
        printf("%.2lf", exp(x));
    }
    else
    {
        printf("%.2lf", sin(x) / (cos(x) + 4));
    }
    return 0;
}