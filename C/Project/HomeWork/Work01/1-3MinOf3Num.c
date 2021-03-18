#include <stdio.h>
int main(void)
{
    printf("请输入三个整数。\n");
    int a[4], min;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] < min || !i)
        {
            min = a[i];
        }
    }
    printf("其中的最小值为%d。\n", min);
    return 0;
}