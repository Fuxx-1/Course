#include <stdio.h>
int main(void)
{
    int val;
    scanf("%d", &val);
    printf("Celsius = %d", 5 * (val - 32) / 9);
    return 0;
}