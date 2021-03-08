#include <stdio.h>
int main(void)
{
    int a[4], max;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > max || !i)
        {
            max = a[i];
        }
    }
    printf("%d", max);
    return 0;
}