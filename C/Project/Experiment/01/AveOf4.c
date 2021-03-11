#include <stdio.h>
int main(void)
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%.2f", (a + b + c + d) / 4.0);
    return 0;
}