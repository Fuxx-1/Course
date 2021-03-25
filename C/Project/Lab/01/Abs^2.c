#include <stdio.h>
int main(void)
{
    int val = 0;
    scanf("%d", &val);
    printf("%d\n", val > 0 ? val : -val);
    printf("%d", val * val);
    return 0;
}