#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num, Digit;
    scanf("%d%d", &num, &Digit);
    int val[num];
    Digit %= num;
    for (int i = num - Digit; i < num; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 0; i < num - Digit; i++)
    {
        scanf("%d", &val[i]);
    }
    for (int i = 0; i < num; i++)
    {
        if (i != num - 1)
        {
            printf("%d ", val[i]);
        }
        else
        {
            printf("%d", val[i]);
        }
    }
    return 0;
}
