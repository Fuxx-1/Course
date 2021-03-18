#include <stdio.h>
int main(void)
{
    int Mult_3, Mult_5;
    double temp;
    scanf("%lf", &temp);
    if (temp <= 0 || temp != (int)temp || !((int)temp % 15))
    {
        return 0;
    }
    Mult_3 = (int)temp % 3, Mult_5 = (int)temp % 5;
    printf("%d\n", (int)temp % ((Mult_3 ? 3 : 1) * (Mult_5 ? 5 : 1)));
    return 0;
}