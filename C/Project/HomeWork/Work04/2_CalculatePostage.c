#include <stdio.h>
int main(void)
{
    int Weight;
    char choose;
    scanf("%d %c", &Weight, &choose);
    if (Weight < 1000)
    {
        printf("%d\n", 8 + (choose == 'y' ? 5 : 0));
    }
    else
    {
        printf("%d\n", (Weight - 501) / 500 * 4 + (choose == 'y' ? 13 : 8));
    }
    return 0;
}