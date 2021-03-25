#include <stdio.h>
int main(void)
{
    int a[4], min;
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < min || !i)
        {
            min = a[i];
        }
    }
    printf("%d", min);
    return 0;
}